# magic_enum_cpp11

[![C++11](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.cppreference.com/w/cpp/11)
[![Header-only](https://img.shields.io/badge/header--only-yes-brightgreen.svg)](#installation)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

A lightweight, header-only C++11 library for compile-time enumeration
reflection. It maps enumeration values to their names without RTTI,
macros in the enumeration definition, or external code generation.

## Features

- Single-header, zero-dependency C++11 library.
- Works with `enum` and `enum class`.
- Supports negative, explicit, and sparse enumeration values.
- Generates an `std::map` from enumeration value to name.
- Easy integration: copy one header into your project.

| Macro | Registered range |
|---|---|
| `ENUM_MAP_FUNCTION(T)` | `-32` to `32` |
| `ENUM_MAP_MAX_FUNCTION(T, max)` | `0` to `max` |
| `ENUM_MAP_MINMAX_FUNCTION(T, min, max)` | `min` to `max` |
| `ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(T, extra)` | `-32` to `32`, plus `extra` |
| `ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(T, min, max, extra)` | `min` to `max`, plus `extra` |

Use the `EXTRA_VALUE` macros when an enumeration contains a value outside
the configured range.

## Quick start

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

// this generates the GetMagicEnumMap<> functions (default range [-32, 32]
/** Important: the ENUM_MAP_FUNCTION() function must be put OUTSIDE any namespace in order to work **/
ENUM_MAP_FUNCTION(Option);

// scan enum from -32 to 32 and an extra value given by the user
ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(Color, 0x80000000);

enum class MiniOption { NOK = -3, OK =  1 };
ENUM_MAP_MINMAX_FUNCTION(MiniOption, 3, 1);

namespace MainScope {
    namespace NestedScope {
        enum class Property {
            Activated = 5,
            PowerOff,
        };
    }
}

ENUM_MAP_FUNCTION(MainScope::NestedScope::Property);

int main()
{
    auto myColorMap = MagicEnum::GetMagicEnumMap<Color>();
    for (auto& it : myColorMap) {
        printf("myColorMap: key: 0x%X value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    auto myOptionMap = MagicEnum::GetMagicEnumMap<Option>();
    for (auto& it : myOptionMap) {
        printf("myOptionMap: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    auto myPropertyList = MagicEnum::GetMagicEnumMap<MainScope::NestedScope::Property>();
    for (auto& it : myPropertyList) {
        printf("myPropertyList: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    /** ************************************************
      * Other ways: First declare your enum map, and later populate it
      ************************************************ */
    std::map<Color, std::string> colorMap;
    ENUM2TEXT_FILL_MAP(Color, colorMap);
    /** output:
        myColorMap: key: 0x5 value: Red 
        myColorMap: key: 0x6 value: Green 
        myColorMap: key: 0x8 value: Blue 
    **/

    // ... and later add the extra field with the big number
    ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE(Color, colorMap, 0x80000000);
    /** output:
        myColorMap: key: 0x5 value: Red 
        myColorMap: key: 0x6 value: Green 
        myColorMap: key: 0x8 value: Blue 
        myColorMap: key: 0x80000000 value: Black 
    **/
  
    /** ************************************************
      * Explicitly put the range, in this case, from -5 to 10 
      ************************************************ */
    std::map<Option, std::string> optionMap;
    ENUM2TEXT_FILL_MAP_MINMAX(Option, optionMap, 5, 10);

    return 0;
}
```

Output:
```text
myColorMap: key: 0x5 value: Red 
myColorMap: key: 0x6 value: Green 
myColorMap: key: 0x8 value: Blue 
myColorMap: key: 0x80000000 value: Black

myOptionMap: key: -1 value: Minus 
myOptionMap: key: 0 value: Zero 
myOptionMap: key: 1 value: One

myPropertyList: key: 5 value: Activated 
myPropertyList: key: 6 value: PowerOff 
```

## Installation

Copy `magic_enum_cpp11.hpp` into your project and include it:

```cpp
#include "magic_enum_cpp11.hpp"
```

No build system integration or external dependencies are required.

## Reflection macros

Register an enumeration before using `MagicEnum::GetMagicEnumMap<T>()`.

## Requirements

- C++11 or later.
- No third-party libraries.

## License

Distributed under the [MIT License](LICENSE).
