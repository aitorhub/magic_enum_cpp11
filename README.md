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

## Quick start

```cpp
#include "magic_enum_cpp11.hpp"
#include <stdio.h>

enum Option {
    Minus = -1,
    Zero = 0,
    One = 1,
};

enum class Color : uint32_t {
    Red = 5,
    Green,
    Blue = 8,
    Black = 0x80000000,
};

// Create the reflection function GetMagicEnumMap<Option>()
ENUM_MAP_FUNCTION(Option);    // By default, values from -32 to 32 are considered.

// Registers reflection for Color.
// The extra value is required because 0x80000000 is outside the default range.
ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(Color, 0x80000000);

int main() {
    const auto& colorMap = GetMagicEnumMap<Color>();

    for (const auto& entry : colorMap) {
        printf("Color: key: 0x%X, value: %s\n", static_cast<unsigned int>(entry.first), entry.second.c_str());
    }

    const auto& optionMap = GetMagicEnumMap<Option>();

    for (const auto& entry : optionMap) {
        printf("Option: key: %d, value: %s\n", static_cast<int>(entry.first), entry.second.c_str());
    }

    return 0;
}
```

Expected output:

```text
0x5 => Red
0x6 => Green
0x8 => Blue
0x80000000 => Black
```

## Installation

Copy `magic_enum_cpp11.hpp` into your project and include it:

```cpp
#include "magic_enum_cpp11.hpp"
```

No build system integration or external dependencies are required.

## Reflection macros

Register an enumeration before using `GetMagicEnumMap<T>()`.

| Macro | Registered range |
|---|---|
| `ENUM_MAP_FUNCTION(T)` | `-32` to `32` |
| `ENUM_MAP_MAX_FUNCTION(T, max)` | `0` to `max` |
| `ENUM_MAP_MINMAX_FUNCTION(T, min, max)` | `min` to `max` |
| `ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(T, extra)` | `-32` to `32`, plus `extra` |
| `ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(T, min, max, extra)` | `min` to `max`, plus `extra` |

Use the `EXTRA_VALUE` macros when an enumeration contains a value outside
the configured range.

## Requirements

- C++11 or later.
- No third-party libraries.

## License

Distributed under the [MIT License](LICENSE).
