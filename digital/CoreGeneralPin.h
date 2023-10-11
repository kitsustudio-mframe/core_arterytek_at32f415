/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856
#define CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856

/* ****************************************************************************************
 * Include
 */
#define USING_CHIP_GPIO
#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------------------
#include "CoreGeneralPort.h"

/* ****************************************************************************************
 * Namespace
 */

namespace core::digital {
  class CoreGeneralPin;
}

/* ****************************************************************************************
 * Class Object
 */
class core::digital::CoreGeneralPin : public mframe::lang::Object,
                                      public mframe::hal::GeneralPin {
  /* **************************************************************************************
   * Subclass
   */

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
  chip::gpio::Register& mReg;
  uint32_t mPin;

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
   * Construct.
   */
  CoreGeneralPin(core::digital::CoreGeneralPort& base, uint32_t pin);

  /**
   * Dis:.
   */
  virtual ~CoreGeneralPin(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::GeneralOutput
   */
 public:
  /**
   * @brief Set the High object
   *
   */
  virtual void setHigh(void) override;

  /**
   * @brief Set the Low object
   *
   */
  virtual void setLow(void) override;

  /**
   * @brief Set the Toggle object
   *
   */
  virtual void setToggle(void) override;

  /**
   * @brief
   *
   * @param level
   */
  virtual void setValue(bool level) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::GeneralInput
   */
 public:
  /**
   * @brief Get io pin.
   *
   * @return true high
   * @return false low
   */
  virtual bool getValue(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::GeneralPin
   */
  /**
   * @brief
   *
   * @return PinMode
   */
  virtual mframe::hal::GeneralPinMode getPinMode(void) override;

  /**
   * @brief Set the Pin Mode object
   *
   * @param mode
   * @return mframe::hal::GeneralPinMode 返回設定模式
   */
  virtual mframe::hal::GeneralPinMode setPinMode(mframe::hal::GeneralPinMode mode) override;

  /**
   * @brief  Get io direction.
   *
   * @return true output
   * @return false input
   */
  virtual bool getDir(void) override;

  /**
   * @brief Set io direction.
   *
   * @param dir false = input, true = output.
   */
  virtual void setDir(bool dir) override;

  /**
   * @brief Set the Input object
   *
   */
  virtual void setInput(void) override;

  /**
   * @brief Set the Output object
   *
   */
  virtual void setOutput(void) override;

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

/* *****************************************************************************************
 * End of file
 */

#endif /* CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856 */
