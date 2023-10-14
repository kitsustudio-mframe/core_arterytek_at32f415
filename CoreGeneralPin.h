/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856
#define CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------
#include "core_arterytek_at32f415/CoreGeneralPort.h"

/* ****************************************************************************
 * Namespace
 */
namespace core {
  class CoreGeneralPin;
}

/* ****************************************************************************
 * Class Object
 */
class core::CoreGeneralPin : public mframe::lang::Object,
                             public mframe::hal::GeneralPin {
  /* **************************************************************************
   * Variable
   */
 private:
  chip::gpio::Register& mReg;
  uint32_t mPin;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Core General Pin object
   *
   * @param base
   * @param pin
   */
  CoreGeneralPin(core::CoreGeneralPort& base, uint32_t pin);

  /**
   * @brief Destroy the Core General Pin object
   *
   */
  virtual ~CoreGeneralPin(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
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

  /* **************************************************************************
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

  /* **************************************************************************
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

/* *****************************************************************************
 * End of file
 */

#endif /* CHIP_EF4F5B70_C257_44EE_8874_9BBD7AFAD856 */
