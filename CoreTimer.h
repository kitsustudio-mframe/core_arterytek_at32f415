/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CORE_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8
#define CORE_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415.h"
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace core {
  class CoreTimer;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreTimer : public mframe::lang::Object,
                        public mframe::hal::Timer,
                        public mframe::hal::InterruptEvent,
                        public mframe::hal::TimerEventCancel,
                        public mframe::hal::TimerEventTrigger {
  /* **************************************************************************
   * Variable
   */
 private:
  chip::tmr::Register& mReg;
  mframe::hal::TimerEventTrigger* mTimerEventTrigger;
  mframe::hal::TimerEventCancel* mTimerEventCancel;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
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
   * Public Method <Override> - mframe::hal::Timer
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

  virtual void setTimerEventTrigger(mframe::hal::TimerEventTrigger* event) override;

  virtual void setTimerEventCancel(mframe::hal::TimerEventCancel* event) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::EventCencel
   */
 public:
  virtual void onTimerCancel(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::EventCencel
   */
 public:
  virtual void onTimerTrigger(void) override;

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

#endif /* CORE_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8 */
