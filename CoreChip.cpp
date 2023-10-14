/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "CoreChip.h"

#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace core {
#pragma pack(4)
  static uint8_t mCoreChipMemory[sizeof(CoreChip)];
#pragma pack()
}  // namespace core

/* ****************************************************************************
 * Using
 */
using core::CoreChip;
//-----------------------------------------------------------------------------

using chip::crm::CRM;
using chip::crm::DividerAHB;
using chip::crm::DividerAPB1;
using chip::crm::DividerAPB2;
using chip::crm::Flag;
using chip::crm::MultPLL;
using chip::crm::SourceClockCore;
using chip::crm::SourceClockPLL;
using chip::crm::SourceClockSCLK;
using chip::crm::SourceClockUSB;
using chip::flash::FLASH;
using chip::flash::WaitCycle;

/* ****************************************************************************
 * Extern
 */



CoreChip *CoreChip::mInstance = nullptr;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic pop
/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
CoreChip::CoreChip(void) : mPortA(chip::gpio::GPIOA),
                           mPortB(chip::gpio::GPIOB),
                           mPortC(chip::gpio::GPIOC),
                           mPortD(chip::gpio::GPIOD),
                           mPortF(chip::gpio::GPIOF) {
  return;
}

//-----------------------------------------------------------------------------
CoreChip::~CoreChip(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */
//-----------------------------------------------------------------------------
uint32_t CoreChip::getSystemCoreClock(void) {
  return chip::Processor::systemCoreClockHz;
}

//-----------------------------------------------------------------------------
bool CoreChip::setSystemCoreClock(uint32_t mhz) {
  if ((mhz > 256) || (mhz < 16))
    return false;

  if (mhz & 0x00000003)
    return false;

  /* config flash psr register */
  if (mhz <= 128)
    FLASH::psrSet(static_cast<WaitCycle>((mhz - 1) >> 5));

  else
    FLASH::psrSet(WaitCycle::WAIT_CYCLE4);

  /* reset crm */
  CRM::reset();

  /* enable hick */
  CRM::clockSourceEnable(SourceClockCore::CLOCK_HICK, true);

  /* wait till hick is ready */
  while (CRM::flagGet(Flag::HICK_STABLE) != true) {
  }

  /* config pll clock resource */
  if (mhz <= 60)
    CRM::pllConfig(SourceClockPLL::HICK, static_cast<MultPLL>((mhz >> 2) - 2));

  else
    CRM::pllConfig(SourceClockPLL::HICK, static_cast<MultPLL>((mhz >> 2) - 1));

  /* enable pll */
  CRM::clockSourceEnable(SourceClockCore::CLOCK_PLL, true);

  /* wait till pll is ready */
  while (CRM::flagGet(Flag::PLL_STABLE) != true) {
  }

  if (mhz <= 150) {
    CRM::ahbDivSet(DividerAHB::DIV1);

    if (mhz <= 75) {
      CRM::apb2DivSet(DividerAPB2::DIV1);
      CRM::apb1DivSet(DividerAPB1::DIV1);
    } else {
      CRM::apb2DivSet(DividerAPB2::DIV2);
      CRM::apb1DivSet(DividerAPB1::DIV2);
    }
  } else {
    CRM::ahbDivSet(DividerAHB::DIV2);
    CRM::apb2DivSet(DividerAPB2::DIV2);
    CRM::apb1DivSet(DividerAPB1::DIV2);
  }

  /* enable auto step mode */
  CRM::autoStepModeEnable(true);

  /* select pll as system clock source */
  CRM::sysclkSwitch(SourceClockSCLK::PLL);

  /* wait till pll is used as system clock source */
  while (CRM::sysclkSwitchStatusGet() != SourceClockSCLK::PLL) {
  }

  /* disable auto step mode */
  CRM::autoStepModeEnable(false);

  /* config usbclk from hick48 */
  CRM::usbClockSourceSelect(SourceClockUSB::HICK);

  /* update system_core_clock global variable */
  chip::Processor::systemCoreClockUpdate();

  return true;
}

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * Static Variable
 */

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
void CoreChip::instantiation(void) {
  if (CoreChip::mInstance)
    return;

  CoreChip::mInstance = new (&core::mCoreChipMemory) CoreChip();
  CoreChip::mInstance->setSystemCoreClock(144);

  CoreInterrupt::instantiation();
  CoreIomux::instantiation();
  CoreIomux::getInstance().init();

  CoreChip::mInstance->getPortA().init();
  CoreChip::mInstance->getPortB().init();
  CoreChip::mInstance->getPortC().init();
  CoreChip::mInstance->getPortD().init();
  CoreChip::mInstance->getPortF().init();

  CoreIomux::getInstance().remapSWDIO(CoreIomux::MapSWDIO::JTAGDISABLE);
  return;
}
/* ****************************************************************************
 * End of file
 */
