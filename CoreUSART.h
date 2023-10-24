/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CORE_25C7B452_0536_494F_9927_E6F526433BAC
#define CORE_25C7B452_0536_494F_9927_E6F526433BAC

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace core {
  class CoreUSART;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreUSART : public mframe::lang::Object,
                        public mframe::hal::Uart,
                        public mframe::hal::InterruptEvent,
                        public mframe::hal::UartEventTransfer,
                        public mframe::hal::UartEventReceiver {
  /* **************************************************************************
   * Variable
   */

 private:
  chip::usart::Register& mReg;
  mframe::hal::UartEventTransfer* mUartEventTransfer;
  mframe::hal::UartEventReceiver* mUartEventReceiver;
  uint32_t mBaudrate;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Core USART object
   *
   * @param reg
   */
  CoreUSART(chip::usart::Register& reg);

  /**
   * @brief Destroy the Core USART object
   *
   */
  virtual ~CoreUSART(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::Base
   */
 public:
  virtual bool deinit(void) override;

  virtual bool init(void) override;

  virtual bool isInit(void) override;
  /* **************************************************************************
   * Public Method <Override> - mframe::hal::Uart
   */
 public:
  virtual uint32_t setBaudrate(uint32_t baudrate) override;

  virtual uint32_t getBaudrate(void) override;

  virtual void beginTransfer(bool enable) override;

  virtual void beginReceiver(bool enable) override;

  virtual void setUartEventTransfer(mframe::hal::UartEventTransfer* event) override;

  virtual void setUartEventReceiver(mframe::hal::UartEventReceiver* event) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::UartEventReceiver
   */
 public:
  virtual bool onUartReceiver(const uint8_t data) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::UartEventTransfer
   */
 public:
  virtual bool onUartTransfer(uint8_t& data) override;
  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CORE_25C7B452_0536_494F_9927_E6F526433BAC */
