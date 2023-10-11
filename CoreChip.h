/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_B783141D_7465_4A74_900D_2B6244C11E04
#define CHIP_B783141D_7465_4A74_900D_2B6244C11E04

/* ****************************************************************************************
 * Include
 */

#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "CoreInterrupt.h"
#include "CoreIomux.h"
#include "digital/CoreGeneralPort.h"

/* ****************************************************************************************
 * Namespace
 */

namespace core {
  class CoreChip;
}

/* ****************************************************************************************
 * Class Object
 */
class core::CoreChip : public mframe::lang::Object {
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Static>
   */
 private:
  static CoreChip* mInstance;

  /* **************************************************************************************
   * Variable
   */
 public:
  digital::CoreGeneralPort mPortA;
  digital::CoreGeneralPort mPortB;
  digital::CoreGeneralPort mPortC;
  digital::CoreGeneralPort mPortD;
  digital::CoreGeneralPort mPortF;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 private:
  /**
   *
   */
  CoreChip(void);

  /**
   *
   */
  virtual ~CoreChip(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
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

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
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

  /* **************************************************************************************
   * Public Method <Inline>
   */
 public:

  /**
   * @brief Get the Port A object
   * 
   * @return digital::CoreGeneralPort& 
   */
  inline digital::CoreGeneralPort& getPortA(void) {
    return this->mPortA;
  }

  /**
   * @brief Get the Port B object
   * 
   * @return digital::CoreGeneralPort& 
   */
  inline digital::CoreGeneralPort& getPortB(void) {
    return this->mPortB;
  }

  /**
   * @brief Get the Port C object
   * 
   * @return digital::CoreGeneralPort& 
   */
  inline digital::CoreGeneralPort& getPortC(void) {
    return this->mPortC;
  }

  /**
   * @brief Get the Port D object
   * 
   * @return digital::CoreGeneralPort& 
   */
  inline digital::CoreGeneralPort& getPortD(void) {
    return this->mPortD;
  }

  /**
   * @brief Get the Port F object
   * 
   * @return digital::CoreGeneralPort& 
   */
  inline digital::CoreGeneralPort& getPortF(void) {
    return this->mPortF;
  }

  /**
   * @brief Get the Interrupt Service object
   * 
   * @return CoreInterrupt& 
   */
  inline CoreInterrupt& getInterruptService(void){
    return CoreInterrupt::getInstance();
  }

  /**
   * @brief Get the Iomux object
   * 
   * @return CoreIomux& 
   */
  inline CoreIomux& getIomux(void){
    return CoreIomux::getInstance();
  }

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

/* *****************************************************************************************
 * End of file
 */

#endif /* CHIP_B783141D_7465_4A74_900D_2B6244C11E04 */
