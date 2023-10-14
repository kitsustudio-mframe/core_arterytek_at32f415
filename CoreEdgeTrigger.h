/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0
#define CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0

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
  class CoreEdgeTrigger;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreEdgeTrigger : public mframe::lang::Object,
                              public mframe::hal::EdgeTrigger,
                              public mframe::hal::InterruptEvent,
                              public mframe::hal::EdgeTriggerEventFall,
                              public mframe::hal::EdgeTriggerEventRise {
  /* **************************************************************************
   * Variable
   */
 private:
  mframe::hal::EdgeTriggerEventRise* mEdgeTriggerEventRise;
  mframe::hal::EdgeTriggerEventFall* mEdgeTriggerEventFall;
  chip::exint::Line mLine;
  bool mStatusRise;
  bool mStatusFall;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
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
   * Public Method <Override> - mframe::hal::EdgeTrigger
   */
 public:
  virtual void enableAll(bool enable) override;

  virtual void enableFall(bool enable) override;

  virtual void enableRise(bool enable) override;

  virtual void setEdgeTriggerEventRise(mframe::hal::EdgeTriggerEventRise* event) override;

  virtual void setEdgeTriggerEventFall(mframe::hal::EdgeTriggerEventFall* event) override;

  virtual bool readRise(void) override;

  virtual bool readFall(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::EdgeTriggerEventFall
   */
 public:
  virtual void onEdgeTriggerFall(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::EdgeTriggerEventRise
   */
 public:
  virtual void onEdgeTriggerRise(void) override;

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

#endif /* CHIP_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0 */
