/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_BA1F141E_4C52_4D14_ADD3_852400BDE8F1
#define CHIP_BA1F141E_4C52_4D14_ADD3_852400BDE8F1

/* ****************************************************************************************
 * Include
 */

#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace core::digital {
  enum struct InputMode : char;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
enum struct core::digital::InputMode : char {
  OPEN,
  ANALOG,
  PULLDOWN,
  PULLUP
};

/* *****************************************************************************************
 * End of file
 */

#endif /* CHIP_BA1F141E_4C52_4D14_ADD3_852400BDE8F1 */
