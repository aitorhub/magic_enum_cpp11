#ifndef _MAGIC_ENUM_CPP11_H
#define _MAGIC_ENUM_CPP11_H

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <map>

// --------------------------------------------------------
// MACRO trick to repeat a command
// --------------------------------------------------------
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
#define REPEAT_N_IMPL_33(N, FUNCTION, ...)   REPEAT_N_IMPL_32((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_34(N, FUNCTION, ...)   REPEAT_N_IMPL_33((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_35(N, FUNCTION, ...)   REPEAT_N_IMPL_34((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_36(N, FUNCTION, ...)   REPEAT_N_IMPL_35((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_37(N, FUNCTION, ...)   REPEAT_N_IMPL_36((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_38(N, FUNCTION, ...)   REPEAT_N_IMPL_37((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_39(N, FUNCTION, ...)   REPEAT_N_IMPL_38((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_40(N, FUNCTION, ...)   REPEAT_N_IMPL_39((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_41(N, FUNCTION, ...)   REPEAT_N_IMPL_40((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_42(N, FUNCTION, ...)   REPEAT_N_IMPL_41((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_43(N, FUNCTION, ...)   REPEAT_N_IMPL_42((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_44(N, FUNCTION, ...)   REPEAT_N_IMPL_43((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_45(N, FUNCTION, ...)   REPEAT_N_IMPL_44((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_46(N, FUNCTION, ...)   REPEAT_N_IMPL_45((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_47(N, FUNCTION, ...)   REPEAT_N_IMPL_46((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_48(N, FUNCTION, ...)   REPEAT_N_IMPL_47((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_49(N, FUNCTION, ...)   REPEAT_N_IMPL_48((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_50(N, FUNCTION, ...)   REPEAT_N_IMPL_49((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_51(N, FUNCTION, ...)   REPEAT_N_IMPL_50((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_52(N, FUNCTION, ...)   REPEAT_N_IMPL_51((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_53(N, FUNCTION, ...)   REPEAT_N_IMPL_52((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_54(N, FUNCTION, ...)   REPEAT_N_IMPL_53((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_55(N, FUNCTION, ...)   REPEAT_N_IMPL_54((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_56(N, FUNCTION, ...)   REPEAT_N_IMPL_55((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_57(N, FUNCTION, ...)   REPEAT_N_IMPL_56((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_58(N, FUNCTION, ...)   REPEAT_N_IMPL_57((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_59(N, FUNCTION, ...)   REPEAT_N_IMPL_58((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_60(N, FUNCTION, ...)   REPEAT_N_IMPL_59((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_61(N, FUNCTION, ...)   REPEAT_N_IMPL_60((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_62(N, FUNCTION, ...)   REPEAT_N_IMPL_61((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_63(N, FUNCTION, ...)   REPEAT_N_IMPL_62((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_64(N, FUNCTION, ...)   REPEAT_N_IMPL_63((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_65(N, FUNCTION, ...)   REPEAT_N_IMPL_64((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_66(N, FUNCTION, ...)   REPEAT_N_IMPL_65((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_67(N, FUNCTION, ...)   REPEAT_N_IMPL_66((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_68(N, FUNCTION, ...)   REPEAT_N_IMPL_67((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_69(N, FUNCTION, ...)   REPEAT_N_IMPL_68((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_70(N, FUNCTION, ...)   REPEAT_N_IMPL_69((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_71(N, FUNCTION, ...)   REPEAT_N_IMPL_70((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_72(N, FUNCTION, ...)   REPEAT_N_IMPL_71((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_73(N, FUNCTION, ...)   REPEAT_N_IMPL_72((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_74(N, FUNCTION, ...)   REPEAT_N_IMPL_73((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_75(N, FUNCTION, ...)   REPEAT_N_IMPL_74((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_76(N, FUNCTION, ...)   REPEAT_N_IMPL_75((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_77(N, FUNCTION, ...)   REPEAT_N_IMPL_76((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_78(N, FUNCTION, ...)   REPEAT_N_IMPL_77((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_79(N, FUNCTION, ...)   REPEAT_N_IMPL_78((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_80(N, FUNCTION, ...)   REPEAT_N_IMPL_79((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_81(N, FUNCTION, ...)   REPEAT_N_IMPL_80((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_82(N, FUNCTION, ...)   REPEAT_N_IMPL_81((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_83(N, FUNCTION, ...)   REPEAT_N_IMPL_82((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_84(N, FUNCTION, ...)   REPEAT_N_IMPL_83((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_85(N, FUNCTION, ...)   REPEAT_N_IMPL_84((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_86(N, FUNCTION, ...)   REPEAT_N_IMPL_85((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_87(N, FUNCTION, ...)   REPEAT_N_IMPL_86((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_88(N, FUNCTION, ...)   REPEAT_N_IMPL_87((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_89(N, FUNCTION, ...)   REPEAT_N_IMPL_88((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_90(N, FUNCTION, ...)   REPEAT_N_IMPL_89((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_91(N, FUNCTION, ...)   REPEAT_N_IMPL_90((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_92(N, FUNCTION, ...)   REPEAT_N_IMPL_91((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_93(N, FUNCTION, ...)   REPEAT_N_IMPL_92((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_94(N, FUNCTION, ...)   REPEAT_N_IMPL_93((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_95(N, FUNCTION, ...)   REPEAT_N_IMPL_94((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_96(N, FUNCTION, ...)   REPEAT_N_IMPL_95((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_97(N, FUNCTION, ...)   REPEAT_N_IMPL_96((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_98(N, FUNCTION, ...)   REPEAT_N_IMPL_97((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_99(N, FUNCTION, ...)   REPEAT_N_IMPL_98((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_100(N, FUNCTION, ...)  REPEAT_N_IMPL_99((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_101(N, FUNCTION, ...)  REPEAT_N_IMPL_100((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_102(N, FUNCTION, ...)  REPEAT_N_IMPL_101((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_103(N, FUNCTION, ...)  REPEAT_N_IMPL_102((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_104(N, FUNCTION, ...)  REPEAT_N_IMPL_103((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_105(N, FUNCTION, ...)  REPEAT_N_IMPL_104((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_106(N, FUNCTION, ...)  REPEAT_N_IMPL_105((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_107(N, FUNCTION, ...)  REPEAT_N_IMPL_106((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_108(N, FUNCTION, ...)  REPEAT_N_IMPL_107((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_109(N, FUNCTION, ...)  REPEAT_N_IMPL_108((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_110(N, FUNCTION, ...)  REPEAT_N_IMPL_109((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_111(N, FUNCTION, ...)  REPEAT_N_IMPL_110((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_112(N, FUNCTION, ...)  REPEAT_N_IMPL_111((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_113(N, FUNCTION, ...)  REPEAT_N_IMPL_112((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_114(N, FUNCTION, ...)  REPEAT_N_IMPL_113((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_115(N, FUNCTION, ...)  REPEAT_N_IMPL_114((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_116(N, FUNCTION, ...)  REPEAT_N_IMPL_115((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_117(N, FUNCTION, ...)  REPEAT_N_IMPL_116((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_118(N, FUNCTION, ...)  REPEAT_N_IMPL_117((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_119(N, FUNCTION, ...)  REPEAT_N_IMPL_118((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_120(N, FUNCTION, ...)  REPEAT_N_IMPL_119((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_121(N, FUNCTION, ...)  REPEAT_N_IMPL_120((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_122(N, FUNCTION, ...)  REPEAT_N_IMPL_121((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_123(N, FUNCTION, ...)  REPEAT_N_IMPL_122((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_124(N, FUNCTION, ...)  REPEAT_N_IMPL_123((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_125(N, FUNCTION, ...)  REPEAT_N_IMPL_124((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_126(N, FUNCTION, ...)  REPEAT_N_IMPL_125((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_127(N, FUNCTION, ...)  REPEAT_N_IMPL_126((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)
#define REPEAT_N_IMPL_128(N, FUNCTION, ...)  REPEAT_N_IMPL_127((N-1), FUNCTION, __VA_ARGS__) FUNCTION(N, __VA_ARGS__)

#define REPEAT_N_HELPER(N, FUNCTION, ...)    REPEAT_N_IMPL_##N(N, FUNCTION, __VA_ARGS__)
#define REPEAT_N(N, FUNCTION, ...)           REPEAT_N_HELPER(N, FUNCTION, __VA_ARGS__)

// --------------------------------------------------------
// MACRO trick END
// --------------------------------------------------------

namespace details {
    struct StringView {
        const char* data;
        int32_t     size;
    };

    constexpr int32_t 
    strchr_constexpr(const char* str, char c, uint32_t idx = 0) {
        return str[idx] == '\0' ? -1 : (str[idx] == c ? idx : strchr_constexpr(str, c, idx + 1));
    }
    constexpr int32_t
    strlen_constexpr(const char* pStr, int index = 0) {
        return (*pStr == '\0')? index : strlen_constexpr(pStr + 1, index + 1);
    }
    
    constexpr const char* strrchr_constexpr_impl(const char* pStr, char c, int len) {
        return len == 0? NULL : (pStr[len] == c)? pStr + len : strrchr_constexpr_impl(pStr, c, len - 1);
    }
    constexpr const char* strrchr_constexpr(const char* str, char c) {
        return strrchr_constexpr_impl(str, c, strlen_constexpr(str));
    }

    template<typename T, T eValue>
    constexpr
    StringView
    GetEnumName()
    {
        // constexpr StringView GetEnumName() [with T = Color; T eValue = Color::Red]
        // "; T eValue = "
        // 012345678901234
        return { __PRETTY_FUNCTION__ + strchr_constexpr(__PRETTY_FUNCTION__, ';') + 13,
                strchr_constexpr(__PRETTY_FUNCTION__ + strchr_constexpr(__PRETTY_FUNCTION__, ';') + 13, ']' )
            };
    }
} //! details

#define ENUM2TEXT_MACRO(enumValue, enumType, pStr, enumMap)                             \
    {                                                                                   \
        using namespace details;                                                        \
        constexpr auto strview = GetEnumName<enumType, (enumType)enumValue>();          \
        if (strchr_constexpr(strview.data, '(') == -1) {                                \
            memcpy(pStr, strview.data, strview.size);                                   \
            pStr[strview.size] = '\0';                                                  \
            const char* pLastStr = strrchr_constexpr(pStr, ':'); /** find last "::" **/ \
            enumMap.insert( { (enumType)enumValue,                                      \
                               pLastStr == nullptr? pStr : pLastStr + 1 } );            \
        }                                                                               \
    }

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
#define ENUM2TEXT_FILL_MAP(enumType, enumMap)               ENUM2TEXT_FILL_MAP_MINMAX(enumType, enumMap, 10, 128)

/** ************************************ **/
/** ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE() **/
/** ************************************ **/
#define ENUM2TEXT_FILL_MAP_ADD_EXACT_VALUE(enumType, enumMap, enumValue) \
{                                                                        \
    char enumName[255];                                                  \
    ENUM2TEXT_MACRO(enumValue, enumType, enumName, enumMap);             \
}

/** ************************************ **/
/** MagicEnum::GetMagicEnumMap()         **/
/** ************************************ **/
namespace MagicEnum {
// just declare the generic function
template<typename enumType>
std::map<enumType, std::string>& GetMagicEnumMap() = delete;
} //! MagicEnum

/** ************************************ **/
/** ENUM_MAP_MINMAX_FUNCTION_IMPL()      **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, minusValue, maxValue)       \
template<>                                                                  \
inline std::map<enumType, std::string>&                                     \
MagicEnum::GetMagicEnumMap<enumType>()                                      \
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
/** ENUM_MAP_EXTRA_VALUE_FUNCTION()      **/
/** ************************************ **/
#define ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(enumType, minusValue, maxValue, extraValue)    \
template<>                                                                                      \
inline std::map<enumType, std::string>&                                                         \
MagicEnum::GetMagicEnumMap<enumType>()                                                          \
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
#define ENUM_MAP_AND_EXTRA_VALUE_FUNCTION(enumType, extraValue)     ENUM_MAP_MINMAX_AND_EXTRA_VALUE_FUNCTION(enumType, 8, 128, extraValue)

/** *************************************** **/
/** ENUM_MAP_MINMAX_FUNCTION()              **/
/** *************************************** **/
#define ENUM_MAP_MINMAX_FUNCTION(enumType, minusValue, maxValue)    ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, minusValue, maxValue)

/** *************************************** **/
/** ENUM_MAP_MAX_FUNCTION()                 **/
/** *************************************** **/
#define ENUM_MAP_MAX_FUNCTION(enumType, maxValue)                   ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, 0, maxValue)

/** *************************************** **/
/** ENUM_MAP_FUNCTION()                     **/
/** *************************************** **/
#define ENUM_MAP_FUNCTION(enumType)                                 ENUM_MAP_MINMAX_FUNCTION_IMPL(enumType, 8, 128)

#endif // _MAGIC_ENUM_CPP11_H
