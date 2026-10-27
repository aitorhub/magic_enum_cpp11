[![Compiler explorer](https://img.shields.io/badge/compiler_explorer-online-blue.svg)](https://godbolt.org/z/f7cxEah8T)
# Magic Enum C++

Header-only C++11 library for static reflection for enums

## Example

```cpp
#include "magic_enum_cpp11.hpp"
#include <stdio.h>

enum Option {
    Minus = -1,
    Zero  =  0,
    One   =  1,
};

enum class Color : uint32_t {
    Red = 5,
    Green,
    Blue = 8,
    Black = 0x80000000,
};

ENUM_MAP_FUNCTION(Option);

ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(Color, 0x80000000);

int main()
{
    auto myColorMap = GetMagicEnumMap<Color>();
    for (auto& it : myColorMap) {
        printf("myColorMap: key: 0x%X value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    printf("\n");

    auto myOptionMap = GetMagicEnumMap<Option>();
    for (auto& it : myOptionMap) {
        printf("myOptionMap: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    printf("\n");
}
```

## Documentation
```cpp
/** ************************************ **/
/** ENUM_MAP_EXTRA_VALUE_FUNCTION()
  *  @brief compile-time enum parsing from (-)minusValue to maxValue and extraValue
 **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(enumType, minusValue, maxValue, extraValue)

/** *************************************** **/
/** ENUM_MAP_AND_EXTRA_VALUE_FUNCTION()
  *  @brief compile-time enum parsing from -32 to 32
  *         and also the extraValue
 **/
/** *************************************** **/
#define ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(enumType, extraValue)

/** ************************************ **/
/** ENUM_MAP_MINMAX_FUNCTION()
  *  @brief compile-time enum parsing from (-)minusValue to maxValue
 **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_FUNCTION(enumType, minusValue, maxValue)

/** ************************************ **/
/** ENUM_MAP_MAX_FUNCTION()
  *  @brief compile-time enum parsing from 0 to maxValue
 **/
/** ************************************ **/
#define ENUM_MAP_MAX_FUNCTION(enumType, maxValue)

/** ************************************ **/
/** ENUM_MAP_FUNCTION()
  *  @brief compile-time enum parsing from -32 to 32
 **/
/** ************************************ **/
#define ENUM_MAP_FUNCTION(enumType)
```
