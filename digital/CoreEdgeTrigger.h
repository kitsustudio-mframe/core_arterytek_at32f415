/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0
#define CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0

/* ****************************************************************************************
 * Include
 */
#define USING_CHIP_EXINT
#include "chip_arterytek_at32f415.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace core::digital {
  class CoreEdgeTrigger;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::digital::CoreEdgeTrigger : public mframe::lang::Object,
                                       public mframe::hal::trigger::EdgeTrigger,
                                       public mframe::hal::InterruptEvent,
                                       public mframe::hal::trigger::EventFall,
                                       public mframe::hal::trigger::EventRise {
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
  mframe::hal::trigger::EventRise* mEventRise;
  mframe::hal::trigger::EventFall* mEventFall;
  chip::exint::Line mLine;
  bool mStatusRise;
  bool mStatusFall;

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
   * @brief Construct a new Core Edge Trigger object
   *
   * @param line
   */
  CoreEdgeTrigger(chip::exint::Line line);

  /**
   * @brief Destroy the Core Edge Trigger object
   *
   */
  virtual ~CoreEdgeTrigger(void) override;

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
   * Public Method <Override> - mframe::hal::trigger::EdgeTrigger
   */
 public:
  virtual void enableAll(bool enable) override;

  virtual void enableFall(bool enable) override;

  virtual void enableRise(bool enable) override;

  virtual void setEventRise(mframe::hal::trigger::EventRise* event) override;

  virtual void setEventFall(mframe::hal::trigger::EventFall* event) override;

  virtual bool readRise(void) override;

  virtual bool readFall(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::trigger::EventFall
   */
 public:
  virtual void onEdgeTriggerFall(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::trigger::EventRise
   */
 public:
  virtual void onEdgeTriggerRise(void) override;

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

#endif /* CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0 */
