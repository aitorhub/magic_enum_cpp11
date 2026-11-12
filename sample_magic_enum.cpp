
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

namespace MainScope {
    namespace NestedScope {
        enum class Property {
            Activated = 5,
            PowerOff,
        };
    } 
}

void testing_function_macros();

int main()
{
    // ----------------------------------------------
    // DECLARE Macros
    // ----------------------------------------------
    ENUM_MAP_DECLARE(OptionMap, Option);
    for (auto& it : OptionMap) {
        printf("OptionMap: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    ENUM_MAP_AND_EXTRA_VALUE_DECLARE(ColorMap, Color, 0x80000000);
    for (auto& it : ColorMap) {
        printf("ColorMap: key: 0x%X value: %s \n", (uint32_t)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    {
        using namespace MainScope::NestedScope;

        ENUM_MAP_DECLARE(myPropertyList, Property);
        for (auto& it : myPropertyList) {
            printf("MyPropertyMap: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
        }
        putchar('\n');
    }

    printf("---- Function Macros ---- \n"); 
    testing_function_macros();

    return 0;
}

// ----------------------------------------------
// FUNCTION Macros
// ----------------------------------------------

// this generates the GetMagicEnumMap<> functions (default range [-32, 32]
/** Important: the ENUM_MAP_FUNCTION() function must be put
 *  OUTSIDE any namespace in order to work */
ENUM_MAP_FUNCTION(Option);

ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(Color, 0x80000000);

enum class MiniOption { NOK = -3, OK =  1 };
ENUM_MAP_MINMAX_FUNCTION(MiniOption, 3, 1);

ENUM_MAP_FUNCTION(MainScope::NestedScope::Property);

void testing_function_macros()
{
    auto myPropertyList = MagicEnum::GetMagicEnumMap<MainScope::NestedScope::Property>();
    for (auto& it : myPropertyList) {
        printf("myPropertyList: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');

    auto myColorMap = MagicEnum::GetMagicEnumMap<Color>();
    for (auto& it : myColorMap) {
        printf("myColorMap: key: 0x%X value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');
    /** output:
        myColorMap: key: 0x5 value: Red 
        myColorMap: key: 0x6 value: Green 
        myColorMap: key: 0x8 value: Blue 
        myColorMap: key: 0x80000000 value: Black 
    **/

    auto myOptionMap = MagicEnum::GetMagicEnumMap<Option>();
    for (auto& it : myOptionMap) {
        printf("myOptionMap: key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');
    /** output:
        myOptionMap: key: -1 value: Minus 
        myOptionMap: key: 0 value: Zero 
        myOptionMap: key: 1 value: One 
    **/

    /** ************************************************
      * Other ways: First declare your enum map, and later populate it
      ************************************************ */
    std::map<Color, std::string> colorMap;
    ENUM2TEXT_FILL_MAP(Color, colorMap);
    for (auto& it : colorMap) {
        printf("key: 0x%X value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');
    /** output:
        myColorMap: key: 0x5 value: Red 
        myColorMap: key: 0x6 value: Green 
        myColorMap: key: 0x8 value: Blue 
    **/

    // ... and later add the extra field with the big number
    ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE(Color, colorMap, 0x80000000);
    for (auto& it : colorMap) {
        printf("key: 0x%X value: %s \n", (uint32_t)it.first, it.second.c_str() ); 
    }
    putchar('\n');
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
    for (auto& it : optionMap) {
        printf("key: %d value: %s \n", (int)it.first, it.second.c_str() ); 
    }
    putchar('\n');
}
