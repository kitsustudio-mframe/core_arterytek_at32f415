/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_B783141D_7465_4A74_900D_2B6244C11E04
#define CHIP_B783141D_7465_4A74_900D_2B6244C11E04

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "core_arterytek_at32f415/CoreGeneralPort.h"
#include "core_arterytek_at32f415/CoreInterrupt.h"
#include "core_arterytek_at32f415/CoreIomux.h"

/* ****************************************************************************
 * Namespace
 */

namespace core {
  class CoreChip;
}

/* ****************************************************************************
 * Class Object
 */
class core::CoreChip : public mframe::lang::Object {
  /* **************************************************************************
   * Subclass
   */

  /* **************************************************************************
   * Variable <Static>
   */
 private:
  static CoreChip* mInstance;

  /* **************************************************************************
   * Variable
   */
 public:
  CoreGeneralPort mPortA;
  CoreGeneralPort mPortB;
  CoreGeneralPort mPortC;
  CoreGeneralPort mPortD;
  CoreGeneralPort mPortF;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 private:
  /**
   * @brief Construct a new Core Chip object
   *
   */
  CoreChip(void);

  /**
   * @brief Destroy the Core Chip object
   *
   */
  virtual ~CoreChip(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief Get the System Core Clock object
   *
   * @return uint32_t
   */
  uint32_t getSystemCoreClock(void);

  /**
   * @brief Set the System Core Clock object
   *
   * @param mhz
   * @return true
   * @return false
   */
  bool setSystemCoreClock(uint32_t mhz);

 public:
  /**
   * @brief Get the Port A object
   *
   * @return CoreGeneralPort&
   */
  inline CoreGeneralPort& getPortA(void) {
    return this->mPortA;
  }

  /**
   * @brief Get the Port B object
   *
   * @return CoreGeneralPort&
   */
  inline CoreGeneralPort& getPortB(void) {
    return this->mPortB;
  }

  /**
   * @brief Get the Port C object
   *
   * @return CoreGeneralPort&
   */
  inline CoreGeneralPort& getPortC(void) {
    return this->mPortC;
  }

  /**
   * @brief Get the Port D object
   *
   * @return CoreGeneralPort&
   */
  inline CoreGeneralPort& getPortD(void) {
    return this->mPortD;
  }

  /**
   * @brief Get the Port F object
   *
   * @return CoreGeneralPort&
   */
  inline CoreGeneralPort& getPortF(void) {
    return this->mPortF;
  }

  /**
   * @brief Get the Interrupt Service object
   *
   * @return CoreInterrupt&
   */
  inline CoreInterrupt& getInterruptService(void) {
    return CoreInterrupt::getInstance();
  }

  /**
   * @brief Get the Iomux object
   *
   * @return CoreIomux&
   */
  inline CoreIomux& getIomux(void) {
    return CoreIomux::getInstance();
  }

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
 public:
  /**
   * @brief 取得CoreChip的實例
   *
   * @return CoreChip&
   */
  static inline CoreChip& getInstance(void) {
    return *CoreChip::mInstance;
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

#endif /* CHIP_B783141D_7465_4A74_900D_2B6244C11E04 */
