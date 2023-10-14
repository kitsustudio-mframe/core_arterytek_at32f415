/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_7658BF00_E759_4C0A_83D5_FAE155AB2283
#define CHIP_7658BF00_E759_4C0A_83D5_FAE155AB2283

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
  class CoreHardwareInfo;
}  // namespace core

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class core::CoreHardwareInfo : public mframe::lang::Object,
                               public mframe::sys::HardwareInfo {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Core Hardware Info object
   *
   */
  CoreHardwareInfo(void);

  /**
   * @brief Destroy the Core Hardware Info object
   *
   */
  virtual ~CoreHardwareInfo(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::management::HardwareInfo
   */
 public:
  virtual int systemClock(void) override;

  virtual const char* manufacturer(void) override;

  virtual const char* model(void) override;
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

#endif /* CHIP_7658BF00_E759_4C0A_83D5_FAE155AB2283 */
