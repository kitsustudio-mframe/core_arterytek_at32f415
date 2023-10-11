/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#define using_chip_ProcessorCore
#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------------------
#include "CoreInterrupt.h"

/* ****************************************************************************************
 * Namespace
 */
namespace core {
  struct CoreInterruptConfig {
    IRQn irq[CoreInterrupt::IRQ_MAX_QUANTITY];

  } const coreInterruptConfig = {
      {/*  IRQ_ADC1          = 0,  */ ADC1_IRQn,
       /*  IRQ_CMP1          = 1,  */ CMP1_IRQn,
       /*  IRQ_CMP2          = 2,  */ CMP2_IRQn,
       /*  IRQ_DMA1_1        = 3,  */ DMA1_Channel1_IRQn,
       /*  IRQ_DMA1_2        = 4,  */ DMA1_Channel2_IRQn,
       /*  IRQ_DMA1_3        = 5,  */ DMA1_Channel3_IRQn,
       /*  IRQ_DMA1_4        = 6,  */ DMA1_Channel4_IRQn,
       /*  IRQ_DMA1_5        = 7,  */ DMA1_Channel5_IRQn,
       /*  IRQ_DMA1_6        = 8,  */ DMA1_Channel6_IRQn,
       /*  IRQ_DMA1_7        = 9,  */ DMA1_Channel7_IRQn,
       /*  IRQ_DMA2_1        = 10, */ DMA2_Channel1_IRQn,
       /*  IRQ_DMA2_2        = 11, */ DMA2_Channel2_IRQn,
       /*  IRQ_DMA2_3        = 12, */ DMA2_Channel3_IRQn,
       /*  IRQ_DMA2_4        = 13, */ DMA2_Channel4_5_IRQn,
       /*  IRQ_DMA2_5        = 14, */ DMA2_Channel4_5_IRQn,
       /*  IRQ_DMA2_6        = 15, */ DMA2_Channel6_7_IRQn,
       /*  IRQ_DMA2_7        = 16, */ DMA2_Channel6_7_IRQn,
       /*  IRQ_ERTC_WKUP     = 17, */ ERTC_WKUP_IRQn,
       /*  IRQ_ERTC_WKUP     = 18, */ ERTCAlarm_IRQn,
       /*  IRQ_EXINT0        = 19, */ EXINT0_IRQn,
       /*  IRQ_EXINT1        = 20, */ EXINT1_IRQn,
       /*  IRQ_EXINT2        = 21, */ EXINT2_IRQn,
       /*  IRQ_EXINT3        = 22, */ EXINT3_IRQn,
       /*  IRQ_EXINT4        = 23, */ EXINT4_IRQn,
       /*  IRQ_EXINT5        = 24, */ EXINT9_5_IRQn,
       /*  IRQ_EXINT6        = 25, */ EXINT9_5_IRQn,
       /*  IRQ_EXINT7        = 26, */ EXINT9_5_IRQn,
       /*  IRQ_EXINT8        = 27, */ EXINT9_5_IRQn,
       /*  IRQ_EXINT9        = 28, */ EXINT9_5_IRQn,
       /*  IRQ_EXINT10       = 29, */ EXINT15_10_IRQn,
       /*  IRQ_EXINT11       = 30, */ EXINT15_10_IRQn,
       /*  IRQ_EXINT12       = 31, */ EXINT15_10_IRQn,
       /*  IRQ_EXINT13       = 32, */ EXINT15_10_IRQn,
       /*  IRQ_EXINT14       = 33, */ EXINT15_10_IRQn,
       /*  IRQ_EXINT15       = 34, */ EXINT15_10_IRQn,
       /*  IRQ_FLASH         = 35, */ FLASH_IRQn,
       /*  IRQ_I2C1_ERR      = 36, */ I2C1_ERR_IRQn,
       /*  IRQ_I2C1_EVT      = 37, */ I2C1_EVT_IRQn,
       /*  IRQ_I2C2_ERR      = 38, */ I2C2_ERR_IRQn,
       /*  IRQ_I2C2_EVT      = 39, */ I2C2_EVT_IRQn,
       /*  IRQ_CRM           = 40, */ CRM_IRQn,
       /*  IRQ_SDIO1         = 41, */ SDIO1_IRQn,
       /*  IRQ_SPI1          = 42, */ SPI1_IRQn,
       /*  IRQ_SPI2          = 43, */ SPI2_IRQn,
       /*  IRQ_TMR1          = 44, */ TMR1_OVF_TMR10_IRQn,
       /*  IRQ_TMR1_BRK      = 45, */ TMR1_BRK_TMR9_IRQn,
       /*  IRQ_TMR1_TRG_COM  = 46, */ TMR1_TRG_HALL_TMR11_IRQn,
       /*  IRQ_TMR1_CC       = 47, */ TMR1_CH_IRQn,
       /*  IRQ_TMR2          = 48, */ TMR2_GLOBAL_IRQn,
       /*  IRQ_TMR3          = 49, */ TMR3_GLOBAL_IRQn,
       /*  IRQ_TMR4          = 50, */ TMR4_GLOBAL_IRQn,
       /*  IRQ_TMR5          = 51, */ TMR5_GLOBAL_IRQn,
       /*  IRQ_TMR9          = 52, */ TMR1_BRK_TMR9_IRQn,
       /*  IRQ_TMR10         = 53, */ TMR1_OVF_TMR10_IRQn,
       /*  IRQ_TMR11         = 54, */ TMR1_TRG_HALL_TMR11_IRQn,
       /*  IRQ_OTGFS         = 55, */ OTGFS1_IRQn,
       /*  IRQ_WWDT          = 56, */ WWDT_IRQn,
       /*  IRQ_PVM           = 57, */ PVM_IRQn,
       /*  IRQ_TAMP_STAMP    = 58, */ TAMP_STAMP_IRQn,
       /*  IRQ_USART1        = 59, */ USART1_IRQn,
       /*  IRQ_USART2        = 60, */ USART2_IRQn,
       /*  IRQ_USART3        = 61, */ USART3_IRQn,
       /*  IRQ_UART4         = 62, */ UART4_IRQn,
       /*  IRQ_UART5         = 63, */ UART5_IRQn,
       /*  IRQ_OTGFS_WAKE    = 64, */ OTGFS1_WKUP_IRQn},
  };
  
  #pragma pack (4)
  static uint8_t mCoreInterruptMemory[sizeof(CoreInterrupt)];
  #pragma pack ()
}  // namespace core

/* ****************************************************************************************
 * Using
 */
using core::CoreInterrupt;
using mframe::hal::InterruptEvent;

/* ****************************************************************************************
 * Macro
 */

#define CONFIG coreInterruptConfig

#define IRQ_CTRL(irq, enable) ((enable) ? NVIC_EnableIRQ(irq) : NVIC_DisableIRQ(irq))
#define IRQ_FLAG(source, shift, enable) ((enable) ? (source |= (1 << shift)) : (source &= (~(1 << shift))))

/* ****************************************************************************************
 * Variable <Static>
 */
CoreInterrupt* CoreInterrupt::mInstance = nullptr;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

//-----------------------------------------------------------------------------------------
CoreInterrupt::CoreInterrupt(void) {
  for (int i = 0; i < IRQ_MAX_QUANTITY; ++i) {
    this->mHandle[i] = this;
  }

  return;
}

//-----------------------------------------------------------------------------------------
CoreInterrupt::~CoreInterrupt(void) {
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */

//-----------------------------------------------------------------------------------------
void CoreInterrupt::instantiation(void){
  if(CoreInterrupt::mInstance)
    return;
  
  CoreInterrupt::mInstance = new(&mCoreInterruptMemory) CoreInterrupt();
  return;
}


/* ****************************************************************************************
 * Public Method <Override>
 */

//-----------------------------------------------------------------------------------------
void CoreInterrupt::interruptEvent(void) {
  return;
}

/* ****************************************************************************************
 * Public Method
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"

//-----------------------------------------------------------------------------------------
void CoreInterrupt::setHandler(Service service, InterruptEvent* runnable) {
  if (!runnable)
    runnable = this;

  switch (service) {
    //-------------------------------------------------------------------------------------
    case IRQ_TMR1:
      this->mHandle[IRQ_TMR1] = runnable;
      this->mHandle[IRQ_TMR1_BRK] = runnable;
      this->mHandle[IRQ_TMR1_TRG_COM] = runnable;
      this->mHandle[IRQ_TMR1_CC] = runnable;
      break;

    //-------------------------------------------------------------------------------------
    default:
      this->mHandle[service] = runnable;
      break;
  }
}

//-----------------------------------------------------------------------------------------
void CoreInterrupt::serviceEnable(Service service, bool enable) {
  uint8_t* flag;
  uint8_t shift = 0;

  switch (service) {
    //-------------------------------------------------------------------------------------
    case IRQ_TMR1:
      IRQ_FLAG(this->mFlag[FLAG_TMR1_BRK_TMR9], 0, enable);
      IRQ_CTRL(TMR1_BRK_TMR9_IRQn, this->mFlag[FLAG_TMR1_BRK_TMR9]);

      IRQ_FLAG(this->mFlag[FLAG_TMR1_TRG_COM_TMR11], 0, enable);
      IRQ_CTRL(TMR1_TRG_HALL_TMR11_IRQn, this->mFlag[FLAG_TMR1_TRG_COM_TMR11]);

      IRQ_CTRL(TMR1_CH_IRQn, enable);

      flag = &this->mFlag[FLAG_TMR1_OV_TMR10];
      shift = 0;
      break;

    //-------------------------------------------------------------------------------------
    case IRQ_TMR9:
      flag = &this->mFlag[FLAG_TMR1_BRK_TMR9];
      shift = 1;
      break;

    //-------------------------------------------------------------------------------------
    case IRQ_TMR10:
      flag = &this->mFlag[FLAG_TMR1_OV_TMR10];
      shift = 2;
      break;

    //-------------------------------------------------------------------------------------
    case IRQ_TMR11:
      flag = &this->mFlag[FLAG_TMR1_TRG_COM_TMR11];
      shift = 3;
      break;

    case IRQ_EXINT5:
    case IRQ_EXINT6:
    case IRQ_EXINT7:
    case IRQ_EXINT8:
    case IRQ_EXINT9:
      flag = &this->mFlag[FLAG_EXINT9_5];
      shift = IRQ_EXINT5 - service;
      break;

    //-------------------------------------------------------------------------------------
    case IRQ_EXINT10:
    case IRQ_EXINT11:
    case IRQ_EXINT12:
    case IRQ_EXINT13:
    case IRQ_EXINT14:
    case IRQ_EXINT15:
      flag = &this->mFlag[FLAG_EXINT15_10];
      shift = IRQ_EXINT10 - service;
      break;

    //-------------------------------------------------------------------------------------
    default:
      flag = nullptr;
      break;
  }

  if (flag) {
    IRQ_FLAG(*flag, shift, enable);
    IRQ_CTRL(CONFIG.irq[service], *flag);
  } else {
    IRQ_CTRL(CONFIG.irq[service], enable);
  }

  return;
}

#pragma clang diagnostic pop

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
