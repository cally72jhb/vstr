#include <stdio.h>

#include "vstr.h"

// Defines

#define PRINT_SUCCESS 0

// Unit Tests

void test_bool(cstr message, bool input, bool assert);
void test_string(vstr message, cstr input, cstr assert);

void test_u32(vstr message, u32 input, u32 assert);

// Global Variables

u32 test_count = 0;

u32 failed_count = 0;
bool failed = false;

// Main Function

int main() {
    printf("[info] starting tests...\n");
    printf("\n");

    // TODO: finish unit tests

    // Variables

    str temp = NULL;

    // vstr_equ

    printf("[info] testing vstr_%s...\n", "equ");

    test_bool("\"abc-def\" == \"abc-def\"", vstr_equ("abc-def", "abc-def"), true);
    test_bool("\"abc-def\" != \"abc-de\"", vstr_equ("abc-def", "abc-de"), false);
    test_bool("\"abc-def\" != \"bc-def\"", vstr_equ("abc-def", "bc-def"), false);
    test_bool("\"a\" == \"a\"", vstr_equ("a", "a"), true);
    test_bool("\"\" == \"\"", vstr_equ("", ""), true);
    test_bool("\"a\" != \"\"", vstr_equ("a", ""), false);
    test_bool("\"\" != \"a\"", vstr_equ("", "a"), false);
    test_bool("\"abc\" != \"\"", vstr_equ("abc", ""), false);
    test_bool("\"\" != \"abc\"", vstr_equ("", "abc"), false);

    // vstr_alloc

    printf("[info] testing vstr_%s...\n", "alloc");

    test_string("alloc(\"abc-def\")", vstr_alloc("abc-def"), "abc-def");
    test_string("alloc(\"a\")", vstr_alloc("a"), "a");
    test_string("alloc(\"\")", vstr_alloc(""), "");

    // vstr_alloc_len

    printf("[info] testing vstr_%s...\n", "alloc_len");

    test_string("alloc_len(\"abc-def\", 10)", vstr_alloc_len("abc-def", 10), "abc-def");
    test_string("alloc_len(\"abc-def\", 7)", vstr_alloc_len("abc-def", 7), "abc-def");
    test_string("alloc_len(\"a\", 1)", vstr_alloc_len("a", 1), "a");
    test_string("alloc_len(\"\", 0)", vstr_alloc_len("", 0), "");
    test_string("alloc_len(\"abc-def\", 3)", vstr_alloc_len("abc-def", 3), "abc");
    test_string("alloc_len(\"abc-def\", 0)", vstr_alloc_len("abc-def", 0), "");
    test_string("alloc_len(\"a\", 1)", vstr_alloc_len("a", 1), "a");
    test_string("alloc_len(\"\", 0)", vstr_alloc_len("", 0), "");

    // vstr_alloc_slen

    printf("[info] testing vstr_%s...\n", "alloc_slen");

    test_string("alloc_slen(\"abc-def\", 10)", vstr_alloc_slen("abc-def", 10), "abc-def");
    test_string("alloc_slen(\"abc-def\", 7)", vstr_alloc_slen("abc-def", 7), "abc-def");
    test_string("alloc_slen(\"a\", 1)", vstr_alloc_slen("a", 1), "a");
    test_string("alloc_slen(\"\", 0)", vstr_alloc_slen("", 0), "");
    test_string("alloc_slen(\"abc-def\", 3)", vstr_alloc_slen("abc-def", 3), "abc");
    test_string("alloc_slen(\"abc-def\", 0)", vstr_alloc_slen("abc-def", 0), "");
    test_string("alloc_slen(\"a\", 1)", vstr_alloc_slen("a", 1), "a");
    test_string("alloc_slen(\"\", 0)", vstr_alloc_slen("", 0), "");

    // vstr_alloc_empty

    printf("[info] testing vstr_%s...\n", "alloc_empty");

    test_string("alloc_empty()", vstr_alloc_empty(), "");

    // vstr_alloc_empty_len

    printf("[info] testing vstr_%s...\n", "alloc_empty_len");

    test_string("alloc_empty_len(0)", vstr_alloc_empty_len(0), "");

    // vstr_from_bool

    printf("[info] testing vstr_%s...\n", "from_bool");

    test_string("from_bool(true)", vstr_from_bool(true), "true");
    test_string("from_bool(false)", vstr_from_bool(false), "false");

    // vstr_from_s8

    printf("[info] testing vstr_%s...\n", "from_s8");

    test_string("from_s8(0)", vstr_from_s8(0), "0");
    test_string("from_s8(1)", vstr_from_s8(1), "1");
    test_string("from_s8(72)", vstr_from_s8(72), "72");
    test_string("from_s8(127)", vstr_from_s8(127), "127");
    test_string("from_s8(-0)", vstr_from_s8(-0), "0");
    test_string("from_s8(-1)", vstr_from_s8(-1), "-1");
    test_string("from_s8(-72)", vstr_from_s8(-72), "-72");
    test_string("from_s8(-127)", vstr_from_s8(-127), "-127");
    test_string("from_s8(-128)", vstr_from_s8(-128), "-128");

    // vstr_from_u8

    printf("[info] testing vstr_%s...\n", "from_u8");

    test_string("from_u8(0)", vstr_from_u8(0), "0");
    test_string("from_u8(1)", vstr_from_u8(1), "1");
    test_string("from_u8(72)", vstr_from_u8(72), "72");
    test_string("from_u8(254)", vstr_from_u8(254), "254");
    test_string("from_u8(255)", vstr_from_u8(255), "255");

    // vstr_from_s16

    printf("[info] testing vstr_%s...\n", "from_s16");

    test_string("from_s16(0)", vstr_from_s16(0), "0");
    test_string("from_s16(1)", vstr_from_s16(1), "1");
    test_string("from_s16(72)", vstr_from_s16(72), "72");
    test_string("from_s16(32767)", vstr_from_s16(32767), "32767");
    test_string("from_s16(-0)", vstr_from_s16(-0), "0");
    test_string("from_s16(-1)", vstr_from_s16(-1), "-1");
    test_string("from_s16(-72)", vstr_from_s16(-72), "-72");
    test_string("from_s16(-32767)", vstr_from_s16(-32767), "-32767");
    test_string("from_s16(-32768)", vstr_from_s16(-32768), "-32768");

    // vstr_from_u16

    printf("[info] testing vstr_%s...\n", "from_u16");

    test_string("from_u16(0)", vstr_from_u16(0), "0");
    test_string("from_u16(1)", vstr_from_u16(1), "1");
    test_string("from_u16(72)", vstr_from_u16(72), "72");
    test_string("from_u16(65534)", vstr_from_u16(65534), "65534");
    test_string("from_u16(65535)", vstr_from_u16(65535), "65535");

    // vstr_from_s32

    printf("[info] testing vstr_%s...\n", "from_s32");

    test_string("from_s32(0)", vstr_from_s32(0), "0");
    test_string("from_s32(1)", vstr_from_s32(1), "1");
    test_string("from_s32(72)", vstr_from_s32(72), "72");
    test_string("from_s32(2147483647)", vstr_from_s32(2147483647), "2147483647");
    test_string("from_s32(-0)", vstr_from_s32(-0), "0");
    test_string("from_s32(-1)", vstr_from_s32(-1), "-1");
    test_string("from_s32(-72)", vstr_from_s32(-72), "-72");
    test_string("from_s32(-2147483647)", vstr_from_s32(-2147483647), "-2147483647");
    test_string("from_s32(-2147483648)", vstr_from_s32(-2147483648), "-2147483648");

    // vstr_from_u32

    printf("[info] testing vstr_%s...\n", "from_u32");

    test_string("from_u32(0)", vstr_from_u32(0), "0");
    test_string("from_u32(1)", vstr_from_u32(1), "1");
    test_string("from_u32(72)", vstr_from_u32(72), "72");
    test_string("from_u32(4294967294)", vstr_from_u32(4294967294), "4294967294");
    test_string("from_u32(4294967295)", vstr_from_u32(4294967295), "4294967295");

    // vstr_from_s64

    printf("[info] testing vstr_%s...\n", "from_s64");

    test_string("from_s64(0)", vstr_from_s64(0), "0");
    test_string("from_s64(1)", vstr_from_s64(1), "1");
    test_string("from_s64(72)", vstr_from_s64(72), "72");
    test_string("from_s64(9223372036854775807)", vstr_from_s64(9223372036854775807), "9223372036854775807");
    test_string("from_s64(-0)", vstr_from_s64(-0), "0");
    test_string("from_s64(-1)", vstr_from_s64(-1), "-1");
    test_string("from_s64(-72)", vstr_from_s64(-72), "-72");
    test_string("from_s64(-9223372036854775807)", vstr_from_s64(-9223372036854775807), "-9223372036854775807");
    test_string("from_s64(-9223372036854775808)", vstr_from_s64(-9223372036854775807 - 1), "-9223372036854775808");

    // vstr_from_u64

    printf("[info] testing vstr_%s...\n", "from_u64");

    test_string("from_u64(0)", vstr_from_u64(0), "0");
    test_string("from_u64(1)", vstr_from_u64(1), "1");
    test_string("from_u64(72)", vstr_from_u64(72), "72");
    test_string("from_u64(18446744073709551614)", vstr_from_u64(18446744073709551614ULL), "18446744073709551614");
    test_string("from_u64(18446744073709551615)", vstr_from_u64(18446744073709551615ULL), "18446744073709551615");

    // vstr_from_f32

    printf("[info] testing vstr_%s...\n", "from_f32");

    test_string("from_f32(0.0F)", vstr_from_f32(0.0F), "0.00000");
    test_string("from_f32(0.1F)", vstr_from_f32(0.1F), "0.10000");
    test_string("from_f32(1.0F)", vstr_from_f32(1.0F), "1.00000");
    test_string("from_f32(72.0F)", vstr_from_f32(72.0F), "72.00000");
    test_string("from_f32(-0.0F)", vstr_from_f32(-0.0F), "0.00000");
    test_string("from_f32(-0.1F)", vstr_from_f32(-0.1F), "-0.10000");
    test_string("from_f32(-1.0F)", vstr_from_f32(-1.0F), "-1.00000");
    test_string("from_f32(-72.0F)", vstr_from_f32(-72.0F), "-72.00000");
    test_string("from_f32(NAN)", vstr_from_f32(NAN), "NaN");
    test_string("from_f32(-INF)", vstr_from_f32(NF_INF), "-INF");
    test_string("from_f32(+INF)", vstr_from_f32(PF_INF), "+INF");

    // vstr_from_f64

    printf("[info] testing vstr_%s...\n", "from_f64");

    test_string("from_f64(0.0F)", vstr_from_f64(0.0F), "0.00000");
    test_string("from_f64(0.1F)", vstr_from_f64(0.1F), "0.10000");
    test_string("from_f64(1.0F)", vstr_from_f64(1.0F), "1.00000");
    test_string("from_f64(72.0F)", vstr_from_f64(72.0F), "72.00000");
    test_string("from_f64(-0.0F)", vstr_from_f64(-0.0F), "0.00000");
    test_string("from_f64(-0.1F)", vstr_from_f64(-0.1F), "-0.10000");
    test_string("from_f64(-1.0F)", vstr_from_f64(-1.0F), "-1.00000");
    test_string("from_f64(-72.0F)", vstr_from_f64(-72.0F), "-72.00000");
    test_string("from_f64(NAN)", vstr_from_f64(NAN), "NaN");
    test_string("from_f64(-INF)", vstr_from_f64(ND_INF), "-INF");
    test_string("from_f64(+INF)", vstr_from_f64(PD_INF), "+INF");

    // vstr_from_f32_p

    printf("[info] testing vstr_%s...\n", "from_f32_p");

    test_string("from_f32_p(0.0F, 0)", vstr_from_f32_p(0.0F, 0), "0");
    test_string("from_f32_p(0.1F, 0)", vstr_from_f32_p(0.1F, 0), "0");
    test_string("from_f32_p(1.0F, 0)", vstr_from_f32_p(1.0F, 0), "1");
    test_string("from_f32_p(72.0F, 0)", vstr_from_f32_p(72.0F, 0), "72");
    test_string("from_f32_p(-0.0F, 0)", vstr_from_f32_p(-0.0F, 0), "0");
    test_string("from_f32_p(-0.1F, 0)", vstr_from_f32_p(-0.1F, 0), "-0");
    test_string("from_f32_p(-1.0F, 0)", vstr_from_f32_p(-1.0F, 0), "-1");
    test_string("from_f32_p(-72.0F, 0)", vstr_from_f32_p(-72.0F, 0), "-72");
    test_string("from_f32_p(NAN, 0)", vstr_from_f32_p(NAN, 0), "NaN");
    test_string("from_f32_p(-INF, 0)", vstr_from_f32_p(NF_INF, 0), "-INF");
    test_string("from_f32_p(+INF, 0)", vstr_from_f32_p(PF_INF, 0), "+INF");

    test_string("from_f32_p(0.0F, 1)", vstr_from_f32_p(0.0F, 1), "0.0");
    test_string("from_f32_p(0.1F, 1)", vstr_from_f32_p(0.1F, 1), "0.1");
    test_string("from_f32_p(1.0F, 1)", vstr_from_f32_p(1.0F, 1), "1.0");
    test_string("from_f32_p(72.0F, 1)", vstr_from_f32_p(72.0F, 1), "72.0");
    test_string("from_f32_p(-0.0F, 1)", vstr_from_f32_p(-0.0F, 1), "0.0");
    test_string("from_f32_p(-0.1F, 1)", vstr_from_f32_p(-0.1F, 1), "-0.1");
    test_string("from_f32_p(-1.0F, 1)", vstr_from_f32_p(-1.0F, 1), "-1.0");
    test_string("from_f32_p(-72.0F, 1)", vstr_from_f32_p(-72.0F, 1), "-72.0");
    test_string("from_f32_p(NAN, 1)", vstr_from_f32_p(NAN, 1), "NaN");
    test_string("from_f32_p(-INF, 1)", vstr_from_f32_p(NF_INF, 1), "-INF");
    test_string("from_f32_p(+INF, 1)", vstr_from_f32_p(PF_INF, 1), "+INF");

    test_string("from_f32_p(0.0F, 5)", vstr_from_f32_p(0.0F, 5), "0.00000");
    test_string("from_f32_p(0.1F, 5)", vstr_from_f32_p(0.1F, 5), "0.10000");
    test_string("from_f32_p(1.0F, 5)", vstr_from_f32_p(1.0F, 5), "1.00000");
    test_string("from_f32_p(72.0F, 5)", vstr_from_f32_p(72.0F, 5), "72.00000");
    test_string("from_f32_p(-0.0F, 5)", vstr_from_f32_p(-0.0F, 5), "0.00000");
    test_string("from_f32_p(-0.1F, 5)", vstr_from_f32_p(-0.1F, 5), "-0.10000");
    test_string("from_f32_p(-1.0F, 5)", vstr_from_f32_p(-1.0F, 5), "-1.00000");
    test_string("from_f32_p(-72.0F, 5)", vstr_from_f32_p(-72.0F, 5), "-72.00000");
    test_string("from_f32_p(NAN, 5)", vstr_from_f32_p(NAN, 5), "NaN");
    test_string("from_f32_p(-INF, 5)", vstr_from_f32_p(NF_INF, 5), "-INF");
    test_string("from_f32_p(+INF, 5)", vstr_from_f32_p(PF_INF, 5), "+INF");

    // vstr_from_f64_p

    printf("[info] testing vstr_%s...\n", "from_f64_p");

    test_string("from_f64_p(0.0, 0)", vstr_from_f64_p(0.0, 0), "0");
    test_string("from_f64_p(0.1, 0)", vstr_from_f64_p(0.1, 0), "0");
    test_string("from_f64_p(1.0, 0)", vstr_from_f64_p(1.0, 0), "1");
    test_string("from_f64_p(72.0, 0)", vstr_from_f64_p(72.0, 0), "72");
    test_string("from_f64_p(-0.0, 0)", vstr_from_f64_p(-0.0, 0), "0");
    test_string("from_f64_p(-0.1, 0)", vstr_from_f64_p(-0.1, 0), "-0");
    test_string("from_f64_p(-1.0, 0)", vstr_from_f64_p(-1.0, 0), "-1");
    test_string("from_f64_p(-72.0, 0)", vstr_from_f64_p(-72.0, 0), "-72");
    test_string("from_f64_p(NAN, 0)", vstr_from_f64_p(NAN, 0), "NaN");
    test_string("from_f64_p(-INF, 0)", vstr_from_f64_p(NF_INF, 0), "-INF");
    test_string("from_f64_p(+INF, 0)", vstr_from_f64_p(PF_INF, 0), "+INF");

    test_string("from_f64_p(0.0, 1)", vstr_from_f64_p(0.0, 1), "0.0");
    test_string("from_f64_p(0.1, 1)", vstr_from_f64_p(0.1, 1), "0.1");
    test_string("from_f64_p(1.0, 1)", vstr_from_f64_p(1.0, 1), "1.0");
    test_string("from_f64_p(72.0, 1)", vstr_from_f64_p(72.0, 1), "72.0");
    test_string("from_f64_p(-0.0, 1)", vstr_from_f64_p(-0.0, 1), "0.0");
    test_string("from_f64_p(-0.1, 1)", vstr_from_f64_p(-0.1, 1), "-0.1");
    test_string("from_f64_p(-1.0, 1)", vstr_from_f64_p(-1.0, 1), "-1.0");
    test_string("from_f64_p(-72.0, 1)", vstr_from_f64_p(-72.0, 1), "-72.0");
    test_string("from_f64_p(NAN, 1)", vstr_from_f64_p(NAN, 1), "NaN");
    test_string("from_f64_p(-INF, 1)", vstr_from_f64_p(NF_INF, 1), "-INF");
    test_string("from_f64_p(+INF, 1)", vstr_from_f64_p(PF_INF, 1), "+INF");

    test_string("from_f64_p(0.0, 5)", vstr_from_f64_p(0.0, 5), "0.00000");
    test_string("from_f64_p(0.1, 5)", vstr_from_f64_p(0.1, 5), "0.10000");
    test_string("from_f64_p(1.0, 5)", vstr_from_f64_p(1.0, 5), "1.00000");
    test_string("from_f64_p(72.0, 5)", vstr_from_f64_p(72.0, 5), "72.00000");
    test_string("from_f64_p(-0.0, 5)", vstr_from_f64_p(-0.0, 5), "0.00000");
    test_string("from_f64_p(-0.1, 5)", vstr_from_f64_p(-0.1, 5), "-0.10000");
    test_string("from_f64_p(-1.0, 5)", vstr_from_f64_p(-1.0, 5), "-1.00000");
    test_string("from_f64_p(-72.0, 5)", vstr_from_f64_p(-72.0, 5), "-72.00000");
    test_string("from_f64_p(NAN, 5)", vstr_from_f64_p(NAN, 5), "NaN");
    test_string("from_f64_p(-INF, 5)", vstr_from_f64_p(NF_INF, 5), "-INF");
    test_string("from_f64_p(+INF, 5)", vstr_from_f64_p(PF_INF, 5), "+INF");

    // vstr_len

    printf("[info] testing vstr_%s...\n", "len");

    test_u32("len(\"abc-def\") == 7", vstr_len("abc-def"), 7);
    test_u32("len(\"abc\") == 3", vstr_len("abc"), 3);
    test_u32("len(\"a\") == 1", vstr_len("a"), 1);
    test_u32("len(\"\") == 0", vstr_len(""), 0);

    // vstr_lenx

    printf("[info] testing vstr_%s...\n", "lenx");

    test_u32("lenx(\"abc-def\", 7) == 7", vstr_lenx("abc-def", 7), 7);
    test_u32("lenx(\"abc\", 3) == 3", vstr_lenx("abc", 3), 3);
    test_u32("lenx(\"a\", 1) == 1", vstr_lenx("a", 1), 1);
    test_u32("lenx(\"\", 0) == 0", vstr_lenx("", 0), 0);
    test_u32("lenx(\"abc-def\", 3) == 3", vstr_lenx("abc-def", 3), 3);
    test_u32("lenx(\"abc-def\", 1) == 1", vstr_lenx("abc-def", 1), 1);
    test_u32("lenx(\"abc-def\", 0) == 0", vstr_lenx("abc-def", 0), 0);

    // vstr_is_empty

    printf("[info] testing vstr_%s...\n", "is_empty");

    test_bool("is_empty(\"\")", vstr_is_empty(""), true);
    test_bool("is_empty(\"a\")", vstr_is_empty("a"), false);
    test_bool("is_empty(\"abc\")", vstr_is_empty("abc"), false);
    test_bool("is_empty(\"abc-def\")", vstr_is_empty("abc-def"), false);

    // vstr_starts_with

    printf("[info] testing vstr_%s...\n", "starts_with");

    test_bool("starts_with(\"abc-def\", \"abc\")", vstr_starts_with("abc-def", "abc"), true);
    test_bool("starts_with(\"abc-def\", \"a\")", vstr_starts_with("abc-def", "a"), true);
    test_bool("starts_with(\"abc-def\", \"\")", vstr_starts_with("abc-def", ""), true);
    test_bool("starts_with(\"abc\", \"\")", vstr_starts_with("abc", "abc"), true);
    test_bool("starts_with(\"a\", \"a\")", vstr_starts_with("a", "a"), true);
    test_bool("starts_with(\"a\", \"\")", vstr_starts_with("a", ""), true);
    test_bool("starts_with(\"\", \"\")", vstr_starts_with("", ""), true);
    test_bool("starts_with(\"\", \"a\")", vstr_starts_with("", "a"), false);
    test_bool("starts_with(\"\", \"abc\")", vstr_starts_with("", "abc"), false);
    test_bool("starts_with(\"abc-def\", \"def\")", vstr_starts_with("abc-def", "def"), false);
    test_bool("starts_with(\"abc-def\", \"d\")", vstr_starts_with("abc-def", "d"), false);
    test_bool("starts_with(\"a\", \"d\")", vstr_starts_with("a", "d"), false);

    // vstr_starts_with_c

    printf("[info] testing vstr_%s...\n", "starts_with_c");

    test_bool("starts_with_c(\"abc-def\", 'a')", vstr_starts_with_c("abc-def", 'a'), true);
    test_bool("starts_with_c(\"abc\", 'a')", vstr_starts_with_c("abc", 'a'), true);
    test_bool("starts_with_c(\"a\", 'a')", vstr_starts_with_c("a", 'a'), true);
    test_bool("starts_with_c(\"a\", 'null')", vstr_starts_with_c("a", '\0'), true);
    test_bool("starts_with_c(\"\", 'null')", vstr_starts_with_c("", '\0'), true);
    test_bool("starts_with_c(\"\", 'a')", vstr_starts_with_c("", 'a'), false);
    test_bool("starts_with_c(\"abc-def\", 'd')", vstr_starts_with_c("abc-def", 'f'), false);
    test_bool("starts_with_c(\"a\", 'd')", vstr_starts_with_c("a", 'd'), false);

    // vstr_ends_with

    printf("[info] testing vstr_%s...\n", "ends_with");

    test_bool("ends_with(\"abc-def\", \"abc\")", vstr_ends_with("abc-def", "def"), true);
    test_bool("ends_with(\"abc-def\", \"a\")", vstr_ends_with("abc-def", "f"), true);
    test_bool("ends_with(\"abc-def\", \"\")", vstr_ends_with("abc-def", ""), true);
    test_bool("ends_with(\"abc\", \"\")", vstr_ends_with("abc", "abc"), true);
    test_bool("ends_with(\"a\", \"a\")", vstr_ends_with("a", "a"), true);
    test_bool("ends_with(\"a\", \"\")", vstr_ends_with("a", ""), true);
    test_bool("ends_with(\"\", \"\")", vstr_ends_with("", ""), true);
    test_bool("ends_with(\"\", \"a\")", vstr_ends_with("", "a"), false);
    test_bool("ends_with(\"\", \"abc\")", vstr_ends_with("", "abc"), false);
    test_bool("ends_with(\"abc-def\", \"def\")", vstr_ends_with("abc-def", "abc"), false);
    test_bool("ends_with(\"abc-def\", \"d\")", vstr_ends_with("abc-def", "a"), false);
    test_bool("ends_with(\"a\", \"d\")", vstr_ends_with("a", "d"), false);

    // vstr_ends_with_c

    printf("[info] testing vstr_%s...\n", "ends_with_c");

    test_bool("ends_with_c(\"abc-def\", 'a')", vstr_ends_with_c("abc-def", 'f'), true);
    test_bool("ends_with_c(\"abc\", 'a')", vstr_ends_with_c("abc", 'c'), true);
    test_bool("ends_with_c(\"a\", 'a')", vstr_ends_with_c("a", 'a'), true);
    test_bool("ends_with_c(\"a\", 'null')", vstr_ends_with_c("a", '\0'), true);
    test_bool("ends_with_c(\"\", 'null')", vstr_ends_with_c("", '\0'), true);
    test_bool("ends_with_c(\"\", 'a')", vstr_ends_with_c("", 'a'), false);
    test_bool("ends_with_c(\"abc-def\", 'd')", vstr_ends_with_c("abc-def", 'a'), false);
    test_bool("ends_with_c(\"a\", 'd')", vstr_ends_with_c("a", 'd'), false);

    // vstr_setc

    printf("[info] testing vstr_%s...\n", "setc");

    temp = vstr_alloc("abc-def");
    test_string("setc(\"abc-def\", '-')", vstr_setc(temp, '-'), "-------");
    vstr_free(temp);

    temp = vstr_alloc("abc");
    test_string("setc(\"abc\", '-')", vstr_setc(temp, '-'), "---");
    vstr_free(temp);

    temp = vstr_alloc("a");
    test_string("setc(\"a\", '-')", vstr_setc(temp, '-'), "-");
    vstr_free(temp);

    temp = vstr_alloc("");
    test_string("setc(\"\", '-')", vstr_setc(temp, '-'), "");
    vstr_free(temp);

    // vstr_setcx

    printf("[info] testing vstr_%s...\n", "setcx");

    temp = vstr_alloc("abc-def");
    test_string("setcx(\"abc-def\", '-', 7)", vstr_setcx(temp, '-', 7), "-------");
    vstr_free(temp);

    temp = vstr_alloc("abc");
    test_string("setcx(\"abc-def\", '-', 3)", vstr_setcx(temp, '-', 3), "---");
    vstr_free(temp);

    temp = vstr_alloc("a");
    test_string("setcx(\"a\", '-', 1)", vstr_setcx(temp, '-', 1), "-");
    vstr_free(temp);

    temp = vstr_alloc("");
    test_string("setcx(\"\", '-', 1)", vstr_setcx(temp, '-', 1), "");
    vstr_free(temp);

    temp = vstr_alloc("abc");
    test_string("setcx(\"abc\", '-', 0)", vstr_setcx(temp, '-', 0), "abc");
    vstr_free(temp);

    temp = vstr_alloc("a");
    test_string("setcx(\"a\", '-', 0)", vstr_setcx(temp, '-', 0), "a");
    vstr_free(temp);

    temp = vstr_alloc("");
    test_string("setcx(\"\", '-', 0)", vstr_setcx(temp, '-', 0), "");
    vstr_free(temp);

    // vstr_clear

    printf("[info] testing vstr_%s...\n", "clear");

    temp = vstr_alloc("abc-def");
    test_string("clear(\"abc-def\")", vstr_clear(&temp), "");
    vstr_free(temp);

    temp = vstr_alloc("abc");
    test_string("clear(\"abc\")", vstr_clear(&temp), "");
    vstr_free(temp);

    temp = vstr_alloc("a");
    test_string("clear(\"a\")", vstr_clear(&temp), "");
    vstr_free(temp);

    temp = vstr_alloc("");
    test_string("clear(\"\")", vstr_clear(&temp), "");
    vstr_free(temp);

    // End Results

    if (!failed) {
        printf("\n[info] all %i tests passed...\n", test_count);
    } else {
        printf("\n[info] %i of %i tests failed...\n", failed_count, test_count);
    }

    return 0;
}

// Unit Tests

void failed_message(cstr message) {
    printf("[failed] vstr_%s\n", message);
    failed = true;
    failed_count++;
}

void test_bool(cstr message, bool input, bool assert) {
    test_count++;

    if (input != assert) {
        failed_message(message);
    } else {
#if PRINT_SUCCESS == 1
        printf("[success] vstr_%s\n", message);
#endif
    }
}

void test_string(vstr message, cstr input, cstr assert) {
    test_count++;

    if (!vstr_equ(input, assert)) {
        failed_message(message);
    } else {
#if PRINT_SUCCESS == 1
        printf("[success] vstr_%s\n", message);
#endif
    }
}

void test_u32(vstr message, u32 input, u32 assert) {
    test_count++;

    if (input != assert) {
        failed_message(message);
    } else {
#if PRINT_SUCCESS == 1
        printf("[success] vstr_%s\n", message);
#endif
    }
}
