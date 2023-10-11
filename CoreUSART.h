/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_25C7B452_0536_494F_9927_E6F526433BAC
#define CHIP_25C7B452_0536_494F_9927_E6F526433BAC

/* ****************************************************************************************
 * Include
 */
#define USING_CHIP_USART
#include "chip_arterytek_at32f415.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace core {
  class CoreUSART;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreUSART : public mframe::lang::Object,
                        public mframe::hal::usart::USART,
                        public mframe::hal::InterruptEvent,
                        public mframe::hal::usart::EventTransfer,
                        public mframe::hal::usart::EventReceiver {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
 private:
  chip::usart::Register& mReg;
  mframe::hal::usart::EventTransfer* mEventTransfer;
  mframe::hal::usart::EventReceiver* mEventReceiver;
  uint32_t mBaudrate;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
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

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::Base
   */
 public:
  virtual bool deinit(void) override;

  virtual bool init(void) override;

  virtual bool isInit(void) override;
  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::usart::USART
   */
 public:
  virtual uint32_t setBaudrate(uint32_t baudrate) override;

  virtual uint32_t getBaudrate(void) override;

  virtual void beginTransfer(bool enable) override;

  virtual void beginReceiver(bool enable) override;

  virtual void setEventTransfer(mframe::hal::usart::EventTransfer* event) override;

  virtual void setEventReceiver(mframe::hal::usart::EventReceiver* event) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::usart::EventReceiver
   */
 public:
  virtual bool onUartReceiver(const uint8_t data) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::usart::EventTransfer
   */
 public:
  virtual bool onUartTransfer(uint8_t& data) override;
  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_25C7B452_0536_494F_9927_E6F526433BAC */
