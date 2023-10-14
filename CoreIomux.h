/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_BD2A9420_72E7_485B_886F_F8FEF77E69C0
#define CHIP_BD2A9420_72E7_485B_886F_F8FEF77E69C0

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
  class CoreIomux;
}

/* ****************************************************************************
 * Class Object
 */
class core::CoreIomux : public mframe::lang::Object,
                        public mframe::hal::Base {
  /* **************************************************************************
   * Enum MapCAN  <MAP6[10] - [0-3]>
   */
 public:
  enum struct MapCAN : uint32_t {
    PA11_PA12 = 0x00000000,
    PB08_PB09 = 0x00000002,
    MASK = 0x0000000F
  };

  /* **************************************************************************
   * Enum MapCOMP <MAP2[6] - [26-27]>
   */
 public:
  enum struct MapCOMP : uint32_t {
    PA00_PA02 = 0x00000000,
    PA06_PA07 = 0x04000000,
    PA11_PA12 = 0x08000000,
    MASK = 0x0C000000
  };

  /* **************************************************************************
   * Enum MapSWDIO  <MAP7[11] - [16-18]>
   */
 public:
  enum struct MapSWDIO : uint32_t {
    FULL = 0x00000000,
    NOJNTRST = 0x00010000,
    JTAGDISABLE = 0x00020000,
    ALLDISABLE = 0x00040000,
    MASK = 0x00070000
  };

  /* **************************************************************************
   * Enum MapEXTI
   */
 public:
  enum struct MapEXINT : uint32_t {
    PORTA = 0x00000000,
    PORTB = 0x00000001,
    PORTC = 0x00000002,
    PORTD = 0x00000003,
    PORTF = 0x00000005,
    MASK = 0x0000000F
  };

  /* **************************************************************************
   * Enum MapI2C1 <MAP5[9] - [4-7]>
   */
 public:
  enum struct MapI2C1 : uint32_t {
    PB06_PB07_PB05 = 0x00000000,
    PB08_PB09_PB05 = 0x00000010,
    PF06_PF07_PB05 = 0x00000020,
    MASK = 0x000000F0
  };

  /* **************************************************************************
   * Enum MapI2C2 <MAP5[9] - [8-11]>
   */
 public:
  enum struct MapI2C2 : uint32_t {
    PB10_PB11_PB12 = 0x00000000,
    PA08_PC09_PA09 = 0x00000100,
    PA08_PB04_PA09 = 0x00000200,
    PF06_PF07_PA09 = 0x00000300,
    MASK = 0x00000F00
  };

  /* **************************************************************************
   * Enum MapSDIO <MAP6[10] - [8-11]>
   */
 public:
  enum struct MapSDIO : uint32_t {
    PC08_PC09_PC10_PC11_PB08_PB09_PC06_PC07_PC12_PD02 = 0x00000000,
    PC00_PC01_PC02_PC03_PA04_PA05_PA06_PA07_PC04_PC05 = 0x00000400,
    PA04_PA05_PA06_PA07_NC___NC___NC___NC___PC04_PC05 = 0x00000500,
    PC00_PC01_PC02_PC03_PA04_PA05_PA06_PA07_PA02_PA03 = 0x00000600,
    PA04_PA05_PA06_PA07_NC___NC___NC___NC___PA02_PA03 = 0x00000700,
    MASK = 0x00000F00
  };

  /* **************************************************************************
   * Enum MapSPI1 <MAP5[9] - [16-19]>
   */
 public:
  enum struct MapSPI1 : uint32_t {
    PA04_PA05_PA06_PA07_PB00 = 0x00000000,
    PA15_PB03_PB04_PB05_PB06 = 0x00010000,
    MASK = 0x000F0000
  };

  /* **************************************************************************
   * Enum MapSPI2 <MAP5[9] - [20-23]>
   */
 public:
  enum struct MapSPI2 : uint32_t {
    PB12_PB13_PB14_PB15_PC06 = 0x00000000,
    PA15_PB03_PB04_PB05_PC07 = 0x00100000,
    MASK = 0x00F00000
  };

  /* **************************************************************************
   * Enum MapUSART1 <MAP6[10] - [16-19]>
   */
 public:
  enum struct MapUSART1 : uint32_t {
    PA09_PA10 = 0x00000000,
    PB06_PB07 = 0x00010000,
    MASK = 0x000F0000
  };

  /* **************************************************************************
   * Enum MapUSART3 <MAP6[10] - [24-27]>
   */
 public:
  enum struct MapUSART3 : uint32_t {
    PB10_PB11_PB12_PB13_PB14 = 0x00000000,
    PC10_PC11_PC12_PB13_PB14 = 0x01000000,
    PA07_PA06_PA05_PB01_PB00 = 0x02000000,
    MASK = 0x0F000000
  };

  /* **************************************************************************
   * Enum MapUART4  <MAP6[10] - [28-31]>
   */
 public:
  enum struct MapUART4 : uint32_t {
    PC10_PC11 = 0x00000000,
    PF04_PF05 = 0x10000000,
    MASK = 0xF0000000
  };

  /* **************************************************************************
   * Enum MapTmr1  <MAP4[8] - [0-3]>
   */
 public:
  enum struct MapTMR1 : uint32_t {
    PA12_PA08_PA09_PA10_PA11_PB12_PB13_PB14_PB15 = 0x00000000,
    PA12_PA08_PA09_PA10_PA11_PA06_PA07_PB00_PB01 = 0x00000001,
    PA00_PC06_PC07_PC08_PC09_PA06_PA07_PB00_PB01 = 0x00000002,
    MASK = 0x0000000F
  };

  /* **************************************************************************
   * Enum MapTmr2  <MAP4[8] - [4-6]>
   */
 public:
  enum struct MapTMR2 : uint32_t {
    PA00_PA01_PA02_PA03 = 0x00000000,
    PA15_PB03_PA02_PA03 = 0x00000010,
    PA00_PA01_PB10_PB11 = 0x00000020,
    PA15_PB03_PB10_PB11 = 0x00000030,
    MASK = 0x00000070
  };

  /* **************************************************************************
   * Enum MapTmr3  <MAP4[8] - [8-11]>
   */
 public:
  enum struct MapTMR3 : uint32_t {
    PA06_PA07_PB00_PB01 = 0x00000000,
    PB04_PB05_PB00_PB01 = 0x00000200,
    PC06_PC07_PC08_PC09 = 0x00000300,
    MASK = 0x00000F00
  };

  /* **************************************************************************
   * Enum MapTmr5  <MAP4[8] - [16-18]>
   */
 public:
  enum struct MapTMR5 : uint32_t {
    PA00_PA01_PA02_PA03 = 0x00000000,
    PF04_PF05_PA02_PA03 = 0x00010000,
    MASK = 0x00070000
  };

  /* **************************************************************************
   * Enum MapTmr9  <MAP3[7] - [0-3]>
   */
 public:
  enum struct MapTMR9 : uint32_t {
    PA02_PA03 = 0x00000000,
    PB14_PB15 = 0x00000001,
    MASK = 0x0000000F
  };

  /* **************************************************************************
   * Enum MapTmr10  <MAP3[7] - [4-7]>
   */
 public:
  enum struct MapTMR10 : uint32_t {
    PB08 = 0x00000000,
    PA06 = 0x00000010,
    MASK = 0x000000F0
  };

  /* **************************************************************************
   * Enum MapTmr11  <MAP3[7] - [4-7]>
   */
 public:
  enum struct MapTMR11 : uint32_t {
    PB09 = 0x00000000,
    PA07 = 0x00000100,
    MASK = 0x00000F00
  };

  /* **************************************************************************
   * Subclass
   */

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
   * @brief Construct a new Core Iomux object
   *
   */
  CoreIomux(void);

  /**
   * @brief Destroy the Core Iomux object
   *
   */
  virtual ~CoreIomux(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */
 public:
  virtual bool deinit(void) override;

  virtual bool init(void) override;

  virtual bool isInit(void) override;

 public:
  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 啟用內部震盪器。
   *
   * @param enable 啟用。
   */
  void enableHEXT(bool enable);

  /**
   * @brief 重新定向EXINT。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapEXINT::PORTA
   *            - MapEXINT::PORTB
   *            - MapEXINT::PORTC
   *            - MapEXINT::PORTD
   *            - MapEXINT::PORTF
   * @param pin 腳位，0~15。
   */
  void remapEXINT(MapEXINT map, uint8_t pin);

  /**
   * @brief SWDIO啟用。
   *
   * @param enable 啟用。
   */
  void enableSWDIO(bool enable);

  /**
   * @brief 重新定向CAN。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapCAN::PA11_PA12
   *            - MapCAN::PB08_PB09
   */
  void remapCAN(MapCAN map);

  /**
   * @brief 重新定向比較器。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapCOMP::PA00_PA02
   *            - MapCOMP::PA06_PA07
   *            - MapCOMP::PA11_PA12
   */
  void remapCOMP(MapCOMP map);

  /**
   * @brief 重新定向SWDIO。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapSWDIO::FULL
   *            - MapSWDIO::NOJNTRST
   *            - MapSWDIO::JTAGDISABLE
   *            - MapSWDIO::ALLDISABLE
   */
  void remapSWDIO(MapSWDIO map);

  /**
   * @brief 重新定向I2C1。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapI2C1::PB06_PB07_PB05
   *            - MapI2C1::PB08_PB09_PB05
   *            - MapI2C1::PF06_PF07_PB05
   */
  void remapI2C1(MapI2C1 map);

  /**
   * @brief 重新定向I2C2。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapI2C2::PB10_PB11_PB12
   *            - MapI2C2::PA08_PC09_PA09
   *            - MapI2C2::PA08_PB04_PA09
   *            - MapI2C2::PF06_PF07_PA09
   */
  void remapI2C2(MapI2C2 map);

  /**
   * @brief 重新定向SDIO。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapSDIO::PC08_PC09_PC10_PC11_PB08_PB09_PC06_PC07_PC12_PD02
   *            - MapSDIO::PC00_PC01_PC02_PC03_PA04_PA05_PA06_PA07_PC04_PC05
   *            - MapSDIO::PA04_PA05_PA06_PA07_NC___NC___NC___NC___PC04_PC05
   *            - MapSDIO::PC00_PC01_PC02_PC03_PA04_PA05_PA06_PA07_PA02_PA03
   *            - MapSDIO::PA04_PA05_PA06_PA07_NC___NC___NC___NC___PA02_PA03
   */
  void remapSDIO(MapSDIO map);

  /**
   * @brief 重新定向SPI1。
   *
   * @param map 定向選擇，可選列表如下：
   *            - PA04_PA05_PA06_PA07_PB00
   *            - PA15_PB03_PB04_PB05_PB06
   */
  void remapSPI1(MapSPI1 map);

  /**
   * @brief 重新定向SPI2。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapSPI2::PB12_PB13_PB14_PB15_PC06
   *            - MapSPI2::PA15_PB03_PB04_PB05_PC07
   */
  void remapSPI2(MapSPI2 map);

  /**
   * @brief 重新定向TMR1。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR1::PA12_PA08_PA09_PA10_PA11_PB12_PB13_PB14_PB15
   *            - MapTMR1::PA12_PA08_PA09_PA10_PA11_PA06_PA07_PB00_PB01
   *            - MapTMR1::PA00_PC06_PC07_PC08_PC09_PA06_PA07_PB00_PB01
   */
  void remapTMR1(MapTMR1 map);

  /**
   * @brief 重新定向TMR2。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR2::PA00_PA01_PA02_PA03
   *            - MapTMR2::PA15_PB03_PA02_PA03
   *            - MapTMR2::PA00_PA01_PB10_PB11
   *            - MapTMR2::PA15_PB03_PB10_PB11
   */
  void remapTMR2(MapTMR2 map);

  /**
   * @brief 重新定向TMR3。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR3::PA06_PA07_PB00_PB01
   *            - MapTMR3::PB04_PB05_PB00_PB01
   *            - MapTMR3::PC06_PC07_PC08_PC09
   */
  void remapTMR3(MapTMR3 map);

  /**
   * @brief 重新定向TMR5。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR5::PA00_PA01_PA02_PA03
   *            - MapTMR5::PF04_PF05_PA02_PA03
   */
  void remapTMR5(MapTMR5 map);

  /**
   * @brief 重新定向TMR9。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR9::PA02_PA03
   *            - MapTMR9::PB14_PB15
   */
  void remapTMR9(MapTMR9 map);

  /**
   * @brief 重新定向TMR10。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR10::PB08
   *            - MapTMR10::PA06
   */
  void remapTMR10(MapTMR10 map);

  /**
   * @brief 重新定向TMR11。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapTMR11::PB09
   *            - MapTMR11::PA07
   */
  void remapTMR11(MapTMR11 map);

  /**
   * @brief 重新定向USART1。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapUSART1::PA09_PA10
   *            - MapUSART1::PB06_PB07
   */
  void remapUSART1(MapUSART1 map);

  /**
   * @brief 重新定向USART3。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapUSART3::PB10_PB11_PB12_PB13_PB14
   *            - MapUSART3::PC10_PC11_PC12_PB13_PB14
   *            - MapUSART3::PA07_PA06_PA05_PB01_PB00
   */
  void remapUSART3(MapUSART3 map);

  /**
   * @brief 重新定向UART4。
   *
   * @param map 定向選擇，可選列表如下：
   *            - MapUART4::PC10_PC11
   *            - MapUART4::PF04_PF05
   */
  void remapUART4(MapUART4 map);

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */
 private:
  void remap(volatile uint32_t* reg, uint32_t mask, uint32_t value);

  /* **************************************************************************
   * Static Variable
   */
 private:
  static CoreIomux* mInstance;
  
  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief 取得CoreChip的實例
   *
   * @return CoreChip&
   */
  static inline CoreIomux& getInstance(void) {
    return *CoreIomux::mInstance;
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

#endif /* CHIP_BD2A9420_72E7_485B_886F_F8FEF77E69C0 */
