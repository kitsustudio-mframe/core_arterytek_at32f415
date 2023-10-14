/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776
#define CHIP_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415.h"

//-----------------------------------------------------------------------------
#include "core_arterytek_at32f415/InputMode.h"
#include "core_arterytek_at32f415/OutputMode.h"

/* ****************************************************************************
 * Namespace
 */
namespace core {
  class CoreGeneralPort;
}  // namespace core

/* ****************************************************************************
 * Class Object
 */
class core::CoreGeneralPort : public mframe::lang::Object,
                              public mframe::hal::GeneralPort {
  /* **************************************************************************
   * Variable
   */

 private:
  chip::gpio::Register& mReg;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Core General Port object
   *
   * @param reg
   */
  CoreGeneralPort(chip::gpio::Register& reg);

  /**
   * @brief Destroy the Core General Port object
   *
   */
  virtual ~CoreGeneralPort(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> mframe::hal::Base
   */
 public:
  /**
   * @brief uninitialze hardware.
   *
   * @return true
   * @return false
   */
  virtual bool deinit(void) override;

  /**
   * @brief initialze hardware.
   *
   * @return true
   * @return false
   */
  virtual bool init(void) override;

  /**
   * @brief get hardware initialzed status.
   *
   * @return true initd
   * @return false not init
   */
  virtual bool isInit(void) override;

  /* **************************************************************************
   * Public Method <Override>
   */
 public:
  /**
   * @brief
   *
   * @param port
   * @return uint32_t
   */
  virtual uint32_t dir(uint32_t port) override;

  /**
   * @brief
   *
   * @param port
   * @param value
   */
  virtual void dir(uint32_t port, uint32_t value) override;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void dirClear(uint32_t port, uint32_t mask) override;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void dirSet(uint32_t port, uint32_t mask) override;

  /**
   * @brief
   *
   * @param port
   * @return uint32_t
   */
  virtual uint32_t pin(uint32_t port) override;

  /**
   * @brief
   *
   * @param port
   * @param value
   */
  virtual void pin(uint32_t port, uint32_t value) override;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void pinClear(uint32_t port, uint32_t mask) override;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void pinSet(uint32_t port, uint32_t mask) override;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void pinToggle(uint32_t port, uint32_t mask) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param pin
   * @param mode
   * @return true
   * @return false
   */
  bool configInput(uint32_t pin, InputMode mode);

  /**
   * @brief
   *
   * @param pin
   * @param mode
   * @param opendrain
   * @param function
   * @param value
   * @return true
   * @return false
   */
  bool configOutput(uint32_t pin, OutputMode mode,
                    bool opendrain,
                    bool function,
                    bool value);

  /**
   * @brief Set the Function object
   *
   * @param pin
   * @param enable
   * @return true
   * @return false
   */
  bool setFunction(uint32_t pin, bool opendrain);

  /**
   * @brief Set the Analog object
   *
   * @param pin
   * @return true
   * @return false
   */
  bool setAnalog(uint32_t pin);

  /**
   * @brief
   *
   * @return chip::gpio::Register&
   */
  chip::gpio::Register& getRegister(void);

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
  static chip::crm::PeriphClock getPeriphClock(chip::gpio::Register& reg);
};

/* *****************************************************************************
 * End of file
 */

#endif /* CHIP_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776 */
