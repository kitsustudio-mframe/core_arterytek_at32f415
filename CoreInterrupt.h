/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CORE_F1908D49_0286_4F03_95AD_EC7128B908B9
#define CORE_F1908D49_0286_4F03_95AD_EC7128B908B9

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */

namespace core {
  class CoreInterrupt;
}

/* ****************************************************************************
 * Class Object
 */
class core::CoreInterrupt : public mframe::lang::Object, mframe::hal::InterruptEvent {
  /* **************************************************************************
   * Enum Service
   */
 public:
  enum Service {
    IRQ_ADC1 = 0,
    IRQ_CMP1 = 1,
    IRQ_CMP2 = 2,
    IRQ_DMA1_1 = 3,
    IRQ_DMA1_2 = 4,
    IRQ_DMA1_3 = 5,
    IRQ_DMA1_4 = 6,
    IRQ_DMA1_5 = 7,
    IRQ_DMA1_6 = 8,
    IRQ_DMA1_7 = 9,
    IRQ_DMA2_1 = 10,
    IRQ_DMA2_2 = 11,
    IRQ_DMA2_3 = 12,
    IRQ_DMA2_4 = 13,
    IRQ_DMA2_5 = 14,
    IRQ_DMA2_6 = 15,
    IRQ_DMA2_7 = 16,
    IRQ_ERTC_WKUP = 17,
    IRQ_ERTC_ALARM = 18,
    IRQ_EXINT0 = 19,
    IRQ_EXINT1 = 20,
    IRQ_EXINT2 = 21,
    IRQ_EXINT3 = 22,
    IRQ_EXINT4 = 23,
    IRQ_EXINT5 = 24,
    IRQ_EXINT6 = 25,
    IRQ_EXINT7 = 26,
    IRQ_EXINT8 = 27,
    IRQ_EXINT9 = 28,
    IRQ_EXINT10 = 29,
    IRQ_EXINT11 = 30,
    IRQ_EXINT12 = 31,
    IRQ_EXINT13 = 32,
    IRQ_EXINT14 = 33,
    IRQ_EXINT15 = 34,
    IRQ_FLASH = 35,
    IRQ_I2C1_ERR = 36,
    IRQ_I2C1_EVT = 37,
    IRQ_I2C2_ERR = 38,
    IRQ_I2C2_EVT = 39,
    IRQ_CRM = 40,
    IRQ_SDIO1 = 41,
    IRQ_SPI1 = 42,
    IRQ_SPI2 = 43,
    IRQ_TMR1 = 44,
    IRQ_TMR1_BRK = 45,
    IRQ_TMR1_TRG_COM = 46,
    IRQ_TMR1_CC = 47,
    IRQ_TMR2 = 48,
    IRQ_TMR3 = 49,
    IRQ_TMR4 = 50,
    IRQ_TMR5 = 51,
    IRQ_TMR9 = 52,
    IRQ_TMR10 = 53,
    IRQ_TMR11 = 54,
    IRQ_OTGFS = 55,
    IRQ_WWDT = 56,
    IRQ_PVM = 57,
    IRQ_TAMP_STAMP = 58,
    IRQ_USART1 = 59,
    IRQ_USART2 = 60,
    IRQ_USART3 = 61,
    IRQ_UART4 = 62,
    IRQ_UART5 = 63,
    IRQ_OTGFS_WAKE = 64,
    IRQ_MAX_QUANTITY
  };

  /* **************************************************************************
   * Enum Flag
   */
 public:
  enum Flag {
    FLAG_TMR1_BRK_TMR9,
    FLAG_TMR1_OV_TMR10,
    FLAG_TMR1_TRG_COM_TMR11,
    FLAG_EXINT9_5,
    FLAG_EXINT15_10,
    FLAG_DMA2_Channel4_5,
    FLAG_DMA2_Channel6_7
  };

  /* **************************************************************************
   * Variable
   */
 private:
  uint8_t mFlag[8];

 public:
  mframe::hal::InterruptEvent* mHandle[IRQ_MAX_QUANTITY];

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 private:
  /**
   * @brief Construct a new Core Interrupt object
   *
   */
  CoreInterrupt(void);

  /**
   * @brief Destroy the Core Interrupt object
   *
   */
  virtual ~CoreInterrupt(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  void interruptEvent(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 設定中斷服務事件。
   *
   * @param service 中斷服務。
   * @param runnable 中斷事件，null為預設值。
   */
  void setHandler(Service service, mframe::hal::InterruptEvent* runnable);

  /**
   * @brief 啟用中斷服務事件
   *
   * @param service
   * @param enable
   */
  void serviceEnable(Service service, bool enable);

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */
 private:
  static CoreInterrupt* mInstance;

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief 取得該類單例實例。
   *
   * @return CoreInterrupt&
   */
  static CoreInterrupt& getInstance(void) {
    return *CoreInterrupt::mInstance;
  }

  /**
   * @brief 類單例實例化。
   *
   */
  static void instantiation(void);
};

/* *****************************************************************************
 * End of file
 */

#endif /* CORE_F1908D49_0286_4F03_95AD_EC7128B908B9 */
