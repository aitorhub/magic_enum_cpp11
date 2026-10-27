#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <map>

namespace details {
    struct StringView {
        const char* data;
        int32_t     size;
    };

    constexpr int32_t constexpr_strchr(const char* str, char c, uint32_t idx = 0) {
        return str[idx] == '\0' ? -1 : (str[idx] == c ? idx : constexpr_strchr(str, c, idx + 1));
    }

    template<typename T, T eValue>
    constexpr
    StringView
    GetEnumName()
    {
        // constexpr StringView GetEnumName() [with T = Color; T eValue = Color::Red]
        // "; T eValue = "
        // 012345678901234
        return { __PRETTY_FUNCTION__ + constexpr_strchr(__PRETTY_FUNCTION__, ';') + 13,
                constexpr_strchr(
                                __PRETTY_FUNCTION__ + constexpr_strchr(__PRETTY_FUNCTION__, ';') + 13,
                                /** search of **/ ']'
                                )
            };
    }
} //! details

#define ENUM2TEXT_MACRO(enumValue, enumType, pStr, enumMap)                    \
    {                                                                          \
        using namespace details;                                               \
        constexpr auto strview = GetEnumName<enumType, (enumType)enumValue>(); \
        memcpy(pStr, strview.data, strview.size);                              \
        pStr[strview.size] = '\0';                                             \
        if (constexpr_strchr(pStr, '(') == -1) {                               \
            enumMap.insert( { (enumType)enumValue, pStr } );                   \
        }                                                                      \
    }

#define REPEAT_N_MINUS_0(N, FUNCTION, ...)
#define REPEAT_N_MINUS_1(N, FUNCTION, ...)   FUNCTION(-1, __VA_ARGS__)
#define REPEAT_N_MINUS_2(N, FUNCTION, ...)   REPEAT_N_MINUS_1((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_3(N, FUNCTION, ...)   REPEAT_N_MINUS_2((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_4(N, FUNCTION, ...)   REPEAT_N_MINUS_3((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_5(N, FUNCTION, ...)   REPEAT_N_MINUS_4((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_6(N, FUNCTION, ...)   REPEAT_N_MINUS_5((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_7(N, FUNCTION, ...)   REPEAT_N_MINUS_6((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_8(N, FUNCTION, ...)   REPEAT_N_MINUS_7((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_9(N, FUNCTION, ...)   REPEAT_N_MINUS_8((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_10(N, FUNCTION, ...)  REPEAT_N_MINUS_9((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_11(N, FUNCTION, ...)  REPEAT_N_MINUS_10((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_12(N, FUNCTION, ...)  REPEAT_N_MINUS_11((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_13(N, FUNCTION, ...)  REPEAT_N_MINUS_12((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_14(N, FUNCTION, ...)  REPEAT_N_MINUS_13((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_15(N, FUNCTION, ...)  REPEAT_N_MINUS_14((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_16(N, FUNCTION, ...)  REPEAT_N_MINUS_15((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_17(N, FUNCTION, ...)  REPEAT_N_MINUS_16((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_18(N, FUNCTION, ...)  REPEAT_N_MINUS_17((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_19(N, FUNCTION, ...)  REPEAT_N_MINUS_18((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_20(N, FUNCTION, ...)  REPEAT_N_MINUS_19((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_21(N, FUNCTION, ...)  REPEAT_N_MINUS_20((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_22(N, FUNCTION, ...)  REPEAT_N_MINUS_21((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_23(N, FUNCTION, ...)  REPEAT_N_MINUS_22((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_24(N, FUNCTION, ...)  REPEAT_N_MINUS_23((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_25(N, FUNCTION, ...)  REPEAT_N_MINUS_24((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_26(N, FUNCTION, ...)  REPEAT_N_MINUS_25((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_27(N, FUNCTION, ...)  REPEAT_N_MINUS_26((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_28(N, FUNCTION, ...)  REPEAT_N_MINUS_27((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_29(N, FUNCTION, ...)  REPEAT_N_MINUS_28((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_30(N, FUNCTION, ...)  REPEAT_N_MINUS_29((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_31(N, FUNCTION, ...)  REPEAT_N_MINUS_30((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)
#define REPEAT_N_MINUS_32(N, FUNCTION, ...)  REPEAT_N_MINUS_31((N-1), FUNCTION, __VA_ARGS__) FUNCTION(-N, __VA_ARGS__)

#define REPEAT_N_MINUS_HELPER(N, FUNCTION, ...) REPEAT_N_MINUS_##N(N, FUNCTION, __VA_ARGS__)
#define REPEAT_N_MINUS(N, FUNCTION, ...)        REPEAT_N_MINUS_HELPER(N, FUNCTION, __VA_ARGS__)

#define REPEAT_N_IMPL_0(N, FUNCTION, ...)    FUNCTION(0, __VA_ARGS__)
#define REPEAT_N_IMPL_1(N, FUNCTION, ...)    REPEAT_N_IMPL_0((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_2(N, FUNCTION, ...)    REPEAT_N_IMPL_1((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_3(N, FUNCTION, ...)    REPEAT_N_IMPL_2((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_4(N, FUNCTION, ...)    REPEAT_N_IMPL_3((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_5(N, FUNCTION, ...)    REPEAT_N_IMPL_4((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_6(N, FUNCTION, ...)    REPEAT_N_IMPL_5((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_7(N, FUNCTION, ...)    REPEAT_N_IMPL_6((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_8(N, FUNCTION, ...)    REPEAT_N_IMPL_7((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_9(N, FUNCTION, ...)    REPEAT_N_IMPL_8((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_10(N, FUNCTION, ...)   REPEAT_N_IMPL_9((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_11(N, FUNCTION, ...)   REPEAT_N_IMPL_10((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_12(N, FUNCTION, ...)   REPEAT_N_IMPL_11((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_13(N, FUNCTION, ...)   REPEAT_N_IMPL_12((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_14(N, FUNCTION, ...)   REPEAT_N_IMPL_13((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_15(N, FUNCTION, ...)   REPEAT_N_IMPL_14((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_16(N, FUNCTION, ...)   REPEAT_N_IMPL_15((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_17(N, FUNCTION, ...)   REPEAT_N_IMPL_16((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_18(N, FUNCTION, ...)   REPEAT_N_IMPL_17((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_19(N, FUNCTION, ...)   REPEAT_N_IMPL_18((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_20(N, FUNCTION, ...)   REPEAT_N_IMPL_19((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_21(N, FUNCTION, ...)   REPEAT_N_IMPL_20((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_22(N, FUNCTION, ...)   REPEAT_N_IMPL_21((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_23(N, FUNCTION, ...)   REPEAT_N_IMPL_22((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_24(N, FUNCTION, ...)   REPEAT_N_IMPL_23((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_25(N, FUNCTION, ...)   REPEAT_N_IMPL_24((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_26(N, FUNCTION, ...)   REPEAT_N_IMPL_25((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_27(N, FUNCTION, ...)   REPEAT_N_IMPL_26((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_28(N, FUNCTION, ...)   REPEAT_N_IMPL_27((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_29(N, FUNCTION, ...)   REPEAT_N_IMPL_28((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_30(N, FUNCTION, ...)   REPEAT_N_IMPL_29((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_31(N, FUNCTION, ...)   REPEAT_N_IMPL_30((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_32(N, FUNCTION, ...)   REPEAT_N_IMPL_31((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)

#define REPEAT_N_HELPER(N, FUNCTION, ...)    REPEAT_N_IMPL_##N(N, FUNCTION, __VA_ARGS__)
#define REPEAT_N(N, FUNCTION, ...)           REPEAT_N_HELPER(N, FUNCTION, __VA_ARGS__)

/** *********************************** **/
//  ENUM2TEXT_FILL_MAP_MINMAX()
/** *********************************** **/
#define ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, minusValue, maxValue)    \
    enumMap.clear();                                                          \
    {                                                                         \
    char enumName[255];                                                       \
    REPEAT_N_MINUS(minusValue, ENUM2TEXT_MACRO, enumType, enumName, enumMap); \
    REPEAT_N(maxValue, ENUM2TEXT_MACRO, enumType, enumName, enumMap);         \
    }

/** *********************************** **/
/** ENUM2TEXT_FILL_MAP_MAX()            **/
/** *********************************** **/
#define ENUM2TEXT_FILL_MAP_MAX(enumType, enumMap, maxValue) ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, 0, maxValue)

/** *********************************** **/
/** ENUM2TEXT_FILL_MAP()                **/
/** *********************************** **/
#define ENUM2TEXT_FILL_MAP(enumType, enumMap)               ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, 32, 32)

/** ************************************ **/
/** ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE() **/
/** ************************************ **/
#define ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE(enumType, enumMap, enumValue) \
{                                                                        \
    char enumName[255];                                                  \
    ENUM2TEXT_MACRO(enumValue, enumType, enumName, enumMap);             \
}

// just declare the generic function, but never to use it
template<typename enumType>
std::map<enumType, std::string>& GetMagicEnumMap() = delete;

/** ************************************ **/
/** ENUM_MAP_MINMAX_FUNCTION_IMPL()      **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, minusValue, maxValue)       \
template<>                                                                  \
std::map<enumType, std::string>&                                            \
GetMagicEnumMap<enumType>()                                                 \
{                                                                           \
    static std::map<enumType, std::string> enumMap;                         \
    static bool isInit = false;                                             \
    if (isInit == false) {                                                  \
        isInit = true;                                                      \
        ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, minusValue, maxValue); \
    }                                                                       \
    return enumMap;                                                         \
}

/** ************************************ **/
/** ENUM_MAP_EXTRA_VALUE_FUNCTION()  **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(enumType, minusValue, maxValue, extraValue)    \
template<>                                                                                      \
std::map<enumType, std::string>&                                                                \
GetMagicEnumMap<enumType>()                                                                     \
{                                                                                               \
    static std::map<enumType, std::string> enumMap;                                             \
    static bool isInit = false;                                                                 \
    if (isInit == false) {                                                                      \
        isInit = true;                                                                          \
        ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, minusValue, maxValue);                     \
        ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE(enumType, enumMap, extraValue);                      \
    }                                                                                           \
    return enumMap;                                                                             \
}

/** *************************************** **/
/** ENUM_MAP_AND_EXTRA_VALUE_FUNCTION()     **/
/** *************************************** **/
#define ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(enumType, extraValue)     ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(enumType, 32, 32, extraValue)

/** ************************************ **/
/** ENUM_MAP_MINMAX_FUNCTION()           **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_FUNCTION(enumType, minusValue, maxValue)    ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, minusValue, maxValue)

/** ************************************ **/
/** ENUM_MAP_MAX_FUNCTION()              **/
/** ************************************ **/
#define ENUM_MAP_MAX_FUNCTION(enumType, maxValue)                   ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, 0, maxValue)

/** ************************************ **/
/** ENUM_MAP_FUNCTION()                  **/
/** ************************************ **/
#define ENUM_MAP_FUNCTION(enumType)                                 ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, 32, 32)
