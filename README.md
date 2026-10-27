[![Compiler explorer](https://img.shields.io/badge/compiler_explorer-online-blue.svg)](https://godbolt.org/z/f7cxEah8T)

# Magic Enum C++

Header-only C++11 library for static reflection for enums

## [Features & Examples](example/)

```cpp
  #include "magic_enum_cpp11.hpp"
  #include <iostream>

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


  int main() {
    Color c1 = Color::RED;
    std::cout << magic_enum::enum_name(c1) << std::endl; // RED
    return 0;
  }
  ```
## Licensed under the [MIT License](LICENSE)

