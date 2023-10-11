/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8
#define CHIP_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8

/* ****************************************************************************************
 * Include
 */

#include "mframe.h"

#define USING_CHIP_TMR
#include "chip_arterytek_at32f415.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace core {
  class CoreTimer;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreTimer : public mframe::lang::Object,
                        public mframe::hal::timer::Timer,
                        public mframe::hal::InterruptEvent,
                        public mframe::hal::timer::EventCancel,
                        public mframe::hal::timer::EventTrigger {
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
  chip::tmr::Register& mReg;
  mframe::hal::timer::EventTrigger* mEventTrigger;
  mframe::hal::timer::EventCancel* mEventCancel;

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
   * @brief Construct a new Core Timer object
   *
   * @param reg
   */
  CoreTimer(chip::tmr::Register& reg);

  /**
   * @brief Destroy the Core Timer object
   *
   */
  virtual ~CoreTimer(void) override;

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
   * Public Method <Override> - mframe::hal::timer::Timer
   */
 public:
  virtual void cancel(void) override;

  virtual bool isBusy(void) override;

  virtual bool isDone(void) override;

  virtual void waitDone(void) override;

  virtual uint32_t getTimerClock(void) override;

  virtual bool startAtTick(uint32_t tick) override;

  virtual bool startAtTime(float second) override;

  virtual bool startAtHertz(float hertz) override;

  virtual void resetTick(uint32_t tick) override;

  virtual void setEventTrigger(mframe::hal::timer::EventTrigger* event) override;

  virtual void setEventCancel(mframe::hal::timer::EventCancel* event) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::timer::EventCencel
   */
 public:
  virtual void onTimerCancel(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::timer::EventCencel
   */
 public:
  virtual void onTimerTrigger(void) override;

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

#endif /* CHIP_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8 */
