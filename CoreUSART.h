/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_25C7B452_0536_494F_9927_E6F526433BAC
#define CHIP_25C7B452_0536_494F_9927_E6F526433BAC

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
                        public mframe::hal::usart::Uart,
                        public mframe::hal::InterruptEvent,
                        public mframe::hal::usart::UartEventTransfer,
                        public mframe::hal::usart::UartEventReceiver {
  /* **************************************************************************
   * Variable
   */

 private:
  chip::usart::Register& mReg;
  mframe::hal::usart::UartEventTransfer* mUartEventTransfer;
  mframe::hal::usart::UartEventReceiver* mUartEventReceiver;
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
   * Public Method <Override> - mframe::hal::usart::Uart
   */
 public:
  virtual uint32_t setBaudrate(uint32_t baudrate) override;

  virtual uint32_t getBaudrate(void) override;

  virtual void beginTransfer(bool enable) override;

  virtual void beginReceiver(bool enable) override;

  virtual void setUartEventTransfer(mframe::hal::usart::UartEventTransfer* event) override;

  virtual void setUartEventReceiver(mframe::hal::usart::UartEventReceiver* event) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::usart::UartEventReceiver
   */
 public:
  virtual bool onUartReceiver(const uint8_t data) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::usart::UartEventTransfer
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

#endif /* CHIP_25C7B452_0536_494F_9927_E6F526433BAC */
