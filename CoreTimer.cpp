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
#include "CoreTimer.h"

#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------
#include "core_arterytek_at32f415/CoreChip.h"

/* ****************************************************************************
 * Namespace
 */
namespace core {
  static chip::crm::PeriphClock getPeriphClock(chip::tmr::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      //------------------------------------------
      case chip::Processor::BASE_TMR1:
        return chip::crm::PeriphClock::TMR1;

      //------------------------------------------
      case chip::Processor::BASE_TMR2:
        return chip::crm::PeriphClock::TMR2;

      //------------------------------------------
      case chip::Processor::BASE_TMR3:
        return chip::crm::PeriphClock::TMR3;

      //------------------------------------------
      case chip::Processor::BASE_TMR4:
        return chip::crm::PeriphClock::TMR4;

      //------------------------------------------
      case chip::Processor::BASE_TMR5:
        return chip::crm::PeriphClock::TMR5;

      //------------------------------------------
      case chip::Processor::BASE_TMR9:
        return chip::crm::PeriphClock::TMR9;

      //------------------------------------------
      case chip::Processor::BASE_TMR10:
        return chip::crm::PeriphClock::TMR10;

      //------------------------------------------
      case chip::Processor::BASE_TMR11:
        return chip::crm::PeriphClock::TMR11;
    }

    return chip::crm::PeriphClock::NONE;
  }

  static core::CoreInterrupt::Service getInterruptService(chip::tmr::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      //------------------------------------------
      case chip::Processor::BASE_TMR1:
        return core::CoreInterrupt::IRQ_TMR1;

      //------------------------------------------
      case chip::Processor::BASE_TMR2:
        return core::CoreInterrupt::IRQ_TMR2;

      //------------------------------------------
      case chip::Processor::BASE_TMR3:
        return core::CoreInterrupt::IRQ_TMR3;

      //------------------------------------------
      case chip::Processor::BASE_TMR4:
        return core::CoreInterrupt::IRQ_TMR4;

      //------------------------------------------
      case chip::Processor::BASE_TMR5:
        return core::CoreInterrupt::IRQ_TMR5;

      //------------------------------------------
      case chip::Processor::BASE_TMR9:
        return core::CoreInterrupt::IRQ_TMR9;

      //------------------------------------------
      case chip::Processor::BASE_TMR10:
        return core::CoreInterrupt::IRQ_TMR10;

      //------------------------------------------
      case chip::Processor::BASE_TMR11:
        return core::CoreInterrupt::IRQ_TMR11;
    }

    return core::CoreInterrupt::IRQ_MAX_QUANTITY;
  }
}  // namespace core

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */
using core::CoreTimer;

//-----------------------------------------------------------------------------
using chip::crm::CRM;
using chip::tmr::TMR;
using core::CoreInterrupt;

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
CoreTimer::CoreTimer(chip::tmr::Register& reg) : mReg(reg) {
  this->mTimerEventCancel = this;
  this->mTimerEventTrigger = this;
  return;
}

//-----------------------------------------------------------------------------
CoreTimer::~CoreTimer(void) {
  this->cancel();
  this->deinit();
  this->mTimerEventCancel = nullptr;
  this->mTimerEventTrigger = nullptr;
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::hal::Base
 */
//-----------------------------------------------------------------------------
bool CoreTimer::deinit(void) {
  if (!this->isInit())
    return false;

  CoreInterrupt::getInstance().serviceEnable(getInterruptService(this->mReg), false);
  CoreInterrupt::getInstance().setHandler(getInterruptService(this->mReg), nullptr);
  return true;
}

//-----------------------------------------------------------------------------
bool CoreTimer::init(void) {
  if (this->isInit())
    return false;

  CRM::periphClockEnable(getPeriphClock(this->mReg), true);
  CoreInterrupt::getInstance().setHandler(getInterruptService(this->mReg), this);
  return false;
}

//-----------------------------------------------------------------------------
bool CoreTimer::isInit(void) {
  return CRM::getPeriphClockEnable(getPeriphClock(this->mReg));
}

/* ****************************************************************************
 * Public Method <Override> - mframe::hal::Timer
 */

//-----------------------------------------------------------------------------
void CoreTimer::cancel(void) {
  CoreInterrupt::getInstance().serviceEnable(getInterruptService(this->mReg), false);
  TMR::interruptEnable(this->mReg, chip::tmr::Interrupt::OVF, false);
  this->mTimerEventCancel->onTimerCancel();
  return;
}

//-----------------------------------------------------------------------------
bool CoreTimer::isBusy(void) {
  return this->mReg.swevt_bit.ovfswtr;
}

//-----------------------------------------------------------------------------
bool CoreTimer::isDone(void) {
  if (this->mReg.ists_bit.ovfif) {
    this->mReg.ists_bit.ovfif = false;
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------
void CoreTimer::waitDone(void) {
  while (this->mReg.ists_bit.ovfif) {
  }
  this->mReg.ists_bit.ovfif = false;
  return;
}

//-----------------------------------------------------------------------------
uint32_t CoreTimer::getTimerClock(void) {
  return CoreChip::getInstance().getSystemCoreClock();
}

//-----------------------------------------------------------------------------
bool CoreTimer::startAtTick(uint32_t tick) {
  if (this->isBusy())
    return false;

  this->resetTick(tick);

  TMR::cntDirSet(this->mReg, chip::tmr::CountMode::UP);
  TMR::clockSourceDivSet(this->mReg, chip::tmr::ClockDivision::DIV1);

  TMR::interruptEnable(this->mReg, chip::tmr::Interrupt::OVF, true);
  TMR::counterEnable(this->mReg, true);
  CoreInterrupt::getInstance().serviceEnable(getInterruptService(this->mReg), true);
  return true;
}

//-----------------------------------------------------------------------------
bool CoreTimer::startAtTime(float second) {
  chip::crm::CoreClock coreClock;
  chip::crm::CRM::clocksFreqGet(coreClock);

  uint32_t sourceClock = coreClock.apb2_freq;

  switch (reinterpret_cast<uint32_t>(&this->mReg)) {
    //------------------------------------------
    case chip::Processor::BASE_TMR1:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR2:
      sourceClock = coreClock.apb1_freq;
      break;
    //------------------------------------------
    case chip::Processor::BASE_TMR3:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR4:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR5:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR9:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR10:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case chip::Processor::BASE_TMR11:
      sourceClock = coreClock.apb2_freq;
      break;
  }

  return this->startAtTick(static_cast<uint32_t>(static_cast<float>(sourceClock) * second));
}

//-----------------------------------------------------------------------------
bool CoreTimer::startAtHertz(float hertz) {
  return this->startAtTime(1.0f / hertz);
}

//-----------------------------------------------------------------------------
void CoreTimer::resetTick(uint32_t tick) {
  uint32_t div = 1 + (tick >> 16);
  uint32_t period = (tick / div);
  TMR::baseInit(this->mReg, period, div);
}

//-----------------------------------------------------------------------------
void CoreTimer::CoreTimer::setTimerEventTrigger(mframe::hal::TimerEventTrigger* event) {
  if (event == nullptr)
    this->mTimerEventTrigger = this;

  else
    this->mTimerEventTrigger = event;

  return;
}

//-----------------------------------------------------------------------------
void CoreTimer::setTimerEventCancel(mframe::hal::TimerEventCancel* event) {
  if (event == nullptr)
    this->mTimerEventCancel = this;

  else {
    this->mTimerEventCancel = event;
    if (this->isBusy())
      TMR::interruptEnable(this->mReg, chip::tmr::Interrupt::OVF, true);
  }

  return;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::hal::InterruptEvent
 */

//-----------------------------------------------------------------------------
void CoreTimer::interruptEvent(void) {
  if (TMR::flagGet(this->mReg, chip::tmr::Flag::OVF) == false)
    return;

  TMR::flagClear(this->mReg, chip::tmr::Flag::OVF);

  this->mTimerEventTrigger->onTimerTrigger();
  return;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::hal::TimerEventCancel
 */

//-----------------------------------------------------------------------------
void CoreTimer::onTimerCancel(void) {
  return;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::hal::TimerEventTrigger
 */

//-----------------------------------------------------------------------------
void CoreTimer::onTimerTrigger(void) {
  TMR::interruptEnable(this->mReg, chip::tmr::Interrupt::OVF, false);
  return;
}
/* ****************************************************************************
 * Public Method
 */

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

/* ****************************************************************************
 * End of file
 */
