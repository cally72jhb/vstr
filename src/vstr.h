#ifndef VECTOR_STRING
#define VECTOR_STRING

// Includes

#include <stdbool.h>
#include <stdlib.h>

// Defines

#define STRING_NULL   ((char*) (0))
#define STRING_EMPTY  ((char*) ("\0"))
#define STRING_NULL_TERMINATOR ('\0')

#define CHAR_NULL        (0)

#define CHAR_SPACE       (32)
#define CHAR_NUM_0       (48)
#define CHAR_NUM_9       (57)
#define CHAR_UPPERCASE_A (65)
#define CHAR_UPPERCASE_Z (90)
#define CHAR_LOWERCASE_A (97)
#define CHAR_LOWERCASE_Z (122)

#define CHAR_CASE_DIFF (-(CHAR_UPPERCASE_A - CHAR_LOWERCASE_A))

#define FLOAT_PRECISION     (5)
#define FLOAT_PRECISION_MAX (8 - 1)

#define DOUBLE_PRECISION     (5)
#define DOUBLE_PRECISION_MAX (16 - 1)

// Util Defines

#define min2(a, b) ((a) < (b) ? (a) : (b))
#define max2(a, b) ((a) > (b) ? (a) : (b))

#define min3(a, b, c) min2(min2(a, b), c)
#define max3(a, b, c) max2(max2(a, b), c)

// Technical Defines

#define S8_MIN (-128)
#define S8_MAX (127)
#define U8_MAX (0xFF)

#define S16_MIN (-32768)
#define S16_MAX (32767)
#define U16_MAX (0xFFFF)

#define S32_MIN (-2147483647 - 1)
#define S32_MAX (2147483647)
#define U32_MAX (0xFFFFFFFF)

#define S64_MIN (-9223372036854775807ULL - 1)
#define S64_MAX (9223372036854775807ULL)
#define U64_MAX (0xFFFFFFFFFFFFFFFFULL)

#define F32_MIN (1.175494351E-38F)
#define F32_MAX (3.402823466E+38F)

#define F64_MIN (2.2250738585072014E-308)
#define F64_MAX (1.7976931348623158E+308)

// Infinitives

#define HUGE_NUM 1E+300

#define INF ((float) (HUGE_NUM * HUGE_NUM))

#define NF_INF (-(float) (INF * INF))
#define PF_INF (+(float) (INF * INF))

#define ND_INF (-(double) (INF * INF))
#define PD_INF (+(double) (INF * INF))

// NAN (Not a Number)

#define NAN (INF * 0.0)

#define NF_NAN (-(float) (INF * 0.0F))
#define PF_NAN (+(float) (INF * 0.0F))

#define ND_NAN (-(double) (INF * 0.0))
#define PD_NAN (+(double) (INF * 0.0))

// Typedefs

typedef char* vstr;

typedef char* str;
typedef const char* cstr;

// Util Typedefs

typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef float  f32;
typedef double f64;

// Mathematical Functions

f32 f32_pow10(s32 exp);
f64 f64_pow10(s32 exp);

// Dynamically Allocated String Functions [ return NULL/U32_MAX on fail/notfound ] ( in total 128 vstr_... functions )

// Allocating Strings

inline str vstr_alloc(cstr string); // Create new String with Unknown Length
inline str vstr_alloc_len(cstr string, u32 length); // Create new String with Length @length
inline str vstr_alloc_slen(cstr string, u32 length); // Create new String with Length of @string or @length depending on which of both is smaller
inline str vstr_alloc_empty(); // Create new Empty String with Length 0
inline str vstr_alloc_empty_len(u32 length); // Create new Empty String with Length @length

// Creating new Strings from Primitive Types

inline str vstr_from_bool(bool value); // Create a new String from a Boolean Value

inline str vstr_from_s8(s8 num); // Create a new String from a Signed Char Value
inline str vstr_from_u8(u8 num); // Create a new String from an Unsigned Char Value
inline str vstr_from_s16(s16 num); // Create a new String from a Signed Short Value
inline str vstr_from_u16(u16 num); // Create a new String from an Unsigned Short Value
inline str vstr_from_s32(s32 num); // Create a new String from a Signed Integer Value
inline str vstr_from_u32(u32 num); // Create a new String from an Unsigned Integer Value
inline str vstr_from_s64(s64 num); // Create a new String from a Signed Long-Long Value
inline str vstr_from_u64(u64 num); // Create a new String from an Unsigned Long-Long Value

inline str vstr_from_f32(f32 num); // Create a new String from a Float Value
inline str vstr_from_f64(f64 num); // Create a new String from a Double Value

inline str vstr_from_f32_p(f32 num, u32 precision); // Create a new String from a Float Value with @precision digits
inline str vstr_from_f64_p(f64 num, u32 precision); // Create a new String from a Double Value with @precision digits

// Comparison & Length

inline u32 vstr_len(cstr string); // Return Length of @string
inline u32 vstr_lenx(cstr string, u32 length); // Return Length of @string or @length depending on what is smaller

inline bool vstr_equ(cstr string1, cstr string2); // Return true when both Strings are exactly equal [ string1 == string2 ]

inline bool vstr_is_empty(cstr string); // Return true when @string is empty

inline bool vstr_starts_with(cstr string1, cstr string2); // Return true when @string starts with @string2
inline bool vstr_starts_with_c(cstr string, char character); // Return true when @string starts with @character

inline bool vstr_ends_with(cstr string1, cstr string2); // Return true when @string ends with @string2
inline bool vstr_ends_with_c(cstr string, char character); // Return true when @string ends with @character

// String Setter

inline str vstr_setc(str string, char character); // Set all Characters of @string to @character
inline str vstr_setcx(str string, char character, u32 length); // Set all Characters from 0 to @length of @string to @character

inline str vstr_clear(str* string); // Clears @string [ returns string with length 0 || however result is already assigned to @string ]

inline str vstr_set(str dest, cstr src); // Set @dest to @src [assuming both strings are equal length]
inline str vstr_sset(str* dest, cstr src); // Set @dest to @src & Return new String Length
inline str vstr_setx(str dest, cstr src, u32 length); // Set @dest to the first @length characters of @src [assuming both strings are equal length or src is smaller]
inline str vstr_ssetx(str* dest, cstr src, u32 length); // Set @dest to the first @length characters of @src

// Concatenation & Push / Pop Chars

inline str vstr_cat(str* dest, str src); // Concat @dest with @src [ @dest + @src ]
inline str vstr_catn(str dest, str src); // Concat @dest with @src & Return new String [ @dest + @src ] [ catn = Concat String & Return new String ]

inline str vstr_push_fc(str* dest, char character); // Concat @src with @dest
inline str vstr_pushn_fc(str dest, char character); // Concat @src with @dest & Return new String
inline str vstr_push_bc(str* dest, char character); // Concat @dest with @src
inline str vstr_pushn_bc(str dest, char character); // Concat @dest with @src & Return new String

inline str vstr_pop_fc(str* string); // Remove First Char of @string [ pop_fc = Pop First Char ]
inline str vstr_popn_fc(str string); // Remove First Char of @string & Return new String [ popn_fc = Pop First Char & Return new String ]
inline str vstr_pop_bc(str* string); // Remove Last Char of @string [ pop_bc = Pop Back ]
inline str vstr_popn_bc(str string); // Remove Last Char of @string & Return new String [ popn_bc = Pop Back & Return new String ]

// Substring of Strings

inline str vstr_rsub(str string, u32 index); // Returns a Reference to the Element at @index of @string
inline str vstr_rssub(str string, u32 index); // Returns a Reference to the Element at @index of @string [ if @index > length of @string it will return the last element of @string ]

inline str vstr_sub(str* string, u32 length); // Substring of @string from 0 to @length
inline str vstr_subx(str* string, u32 start); // Substring of @string from @start to end of @string
inline str vstr_subxx(str* string, u32 start, u32 end); // Substring of @string from @start to @end
inline str vstr_subxn(str* string, u32 start, u32 length); // Substring of @string from @start to @start + @length

inline str vstr_nsub(str string, u32 length); // Substring of @string from 0 to @length & Return new String
inline str vstr_nsubx(str string, u32 start); // Substring of @string from @start to end of @string & Return new String
inline str vstr_nsubxx(str string, u32 start, u32 end); // Substring of @string from @start to @end & Return new String
inline str vstr_nsubxn(str string, u32 start, u32 length); // Substring of @string from @start to @start + @length & Return new String

// String Resize

inline str vstr_resize(str* string, u32 length); // Resize @string to @length
inline str vstr_fit(str* string); // Reallocate @string with its String Length
inline str vstr_grow(str* string, u32 elements); // Grow @string by @elements
inline str vstr_size(str* string, u32 length); // Reallocate @string to be @length long or its Original Length

// Finding & Replacing in Strings

inline u32 vstr_find_fs(cstr string1, cstr string2); // Find First Occurrence of @string2 in @string1 [ bfind_fs = Bruteforce Search Find First String ]
inline u32 vstr_find_ls(cstr string1, cstr string2); // Find Last Occurrence of @string2 in @string1 [ bfind_ls = Bruteforce Search Find Last String ]

inline str vstr_rfind_fs(cstr string1, cstr string2); // Find First Occurrence of @string2 in @string1 & Return Reference [ rfind_fs = Find First String & Return Reference ]
inline str vstr_rfind_ls(cstr string1, cstr string2); // Find Last Occurrence of @string2 in @string1 & Return Reference [ rfind_ls = Find Last String & Return Reference ]

inline bool vstr_cont_s(cstr string1, cstr string2); // Return true when @string1 contains @string2 [ bcont = Bruteforce Search Contains ]

inline str vstr_rep_fs(str* dest, cstr old, cstr new); // Replace First Occurrence of @old with @new in @dest [ fs = First String ]
inline str vstr_rep_ls(str* dest, cstr old, cstr new); // Replace Last Occurrence of @old with @new in @dest [ ls = Last String ]
inline str vstr_repn_fs(str string, cstr old, cstr new); // Replace First Occurrence of @old with @new in @string & Return new String [ fs = First String ]
inline str vstr_repn_ls(str string, cstr old, cstr new); // Replace Last Occurrence of @old with @new in @string & Return new String [ ls = Last String ]

// Finding & Replacing Characters

inline u32 vstr_find_fc(cstr string, char character); // Find First Occurrence of @character in @string [ fc = First Char ]
inline u32 vstr_find_lc(cstr string, char character); // Find Last Occurrence of @character in @string [ lc = Last Char ]

inline str vstr_rfind_fc(cstr string, char character); // Find First Occurrence of @character in @string & Return Reference [ rfind_fc = Find First Char & Return Reference ]
inline str vstr_rfind_lc(cstr string, char character); // Find Last Occurrence of @character in @string & Return Reference [ rfind_lc = Find Last Char & Return Reference ]

inline bool vstr_cont_c(str string, char character); // Return true when @string contains @character

inline str vstr_rep_fc(str string, char old, char new); // Replace First Occurrence of @old with @new in @string [ fc = First Char ]
inline str vstr_rep_lc(str string, char old, char new); // Replace Last Occurrence of @old with @new in @string [ lc = Last Char ]
inline str vstr_repn_fc(str string, char old, char new); // Replace First Occurrence of @old with @new in @string & Return new String [ fc = First Char ]
inline str vstr_repn_lc(str string, char old, char new); // Replace Last Occurrence of @old with @new in @string & Return new String [ lc = Last Char ]

inline str vstr_rep_ac(str string, char old, char new); // Replace All Occurrences of @old with @new in @string [ ac = All Chars ]
inline str vstr_repn_ac(str string, char old, char new); // Replace All Occurrences of @old with @new in @string & Return new String [ ac = All Chars ]

// Erasing Strings, Characters & Indexes

inline str vstr_erase_fs(str* dest, cstr src); // Erase First Occurrence of @src in @dest [ fs = First String ]
inline str vstr_erase_ls(str* dest, cstr src); // Erase Last Occurrence of @src in @dest [ ls = Last String ]

inline str vstr_erase_fc(str* dest, char character); // Erase First Occurrence of @character in @dest [ fc = First Char ]
inline str vstr_erase_lc(str* dest, char character); // Erase Last Occurrence of @character in @dest [ lc = Last Char ]
inline str vstr_erase_ac(str* dest, char character); // Erase All Occurrences of @character in @dest [ ac = All Chars ]

inline str vstr_nerase_fs(str string, cstr src); // Erase First Occurrence of @src in @string & Return new String [ fs = First String ]
inline str vstr_nerase_ls(str string, cstr src); // Erase Last Occurrence of @src in @string & Return new String [ ls = Last String ]

inline str vstr_nerase_fc(str string, char character); // Erase First Occurrence of @character in @string & Return new String [ fc = First Char ]
inline str vstr_nerase_lc(str string, char character); // Erase Last Occurrence of @character in @string & Return new String [ lc = Last Char ]
inline str vstr_nerase_ac(str string, char character); // Erase All Occurrences of @character in @string & Return new String [ ac = All Chars ]

inline str vstr_erase_x(str* dest, u32 index); // Erase Character at @index in @dest
inline str vstr_erase_xx(str* dest, u32 start, u32 end); // Erase everything from @start to @end in @dest
inline str vstr_erase_xn(str* dest, u32 start, u32 length); // Erase everything from @start to @start + @length in @dest

inline str vstr_nerase_x(str string, u32 index); // Erase Character at @index in @string & Return new String
inline str vstr_nerase_xx(str string, u32 start, u32 end); // Erase everything from @start to @end in @string & Return new String
inline str vstr_nerase_xn(str string, u32 start, u32 length); // Erase everything from @start to @start + @length in @string & Return new String

// Trimming Strings

inline str vstr_trim(str* string); // Erase All Whitespaces at the beginning and end of @string
inline str vstr_trim_f(str* string); // Erase All Whitespaces at the beginning @string
inline str vstr_trim_b(str* string); // Erase All Whitespaces at the end of @string
inline str vstr_trim_a(str* string); // Erase All Whitespaces in @string

inline str vstr_ntrim(cstr string); // Erase All Whitespaces at the beginning and end of @string & Return new String
inline str vstr_ntrim_f(cstr string); // Erase All Whitespaces at the beginning @string & Return new String
inline str vstr_ntrim_b(cstr string); // Erase All Whitespaces at the end of @string & Return new String
inline str vstr_ntrim_a(cstr string); // Erase All Whitespaces in @string & Return new String

// Inserting Characters into Strings

inline str vstr_insert_xs(str* dest, u32 index, cstr src); // Insert @src into @dest at @index
inline str vstr_ninsert_xs(str string, u32 index, cstr src); // Insert @src into @string at @index & Return new String

inline str vstr_insert_xc(str* dest, u32 index, char character); // Insert @character into @dest at @index
inline str vstr_ninsert_xc(str dest, u32 index, char character); // Insert @character into @dest at @index & Return new String

// Uppercase / Lowercase

inline str vstr_upper(str string); // Make @string Uppercase
inline str vstr_upper_f(str string); // Capitalize each Character in @string prefixed by a Space
inline str vstr_nupper(str string); // Make @string Uppercase & Return new String
inline str vstr_nupper_f(str string); // Capitalize each Character in @string prefixed by a Space & Return new String

inline str vstr_lower(str string); // Make @string Lowercase
inline str vstr_nlower(str string); // Make @string Lowercase & Return new String

// Shortcuts to Last Element of String

inline char vstr_back(str string); // Returns the last Character of the String
inline str vstr_rback(str string); // Returns a Pointer to the Last Element of the String

// String to Number

inline bool vstr_to_bool(cstr string); // Parse @string to a Boolean Value

inline s8 vstr_to_s8(cstr string); // Parse @string to a Signed Char Value
inline u8 vstr_to_u8(cstr string); // Parse @string to an Unsigned Char Value
inline s16 vstr_to_s16(cstr string); // Parse @string to a Signed Short Value
inline u16 vstr_to_u16(cstr string); // Parse @string to an Unsigned Short Value
inline s32 vstr_to_s32(cstr string); // Parse @string to a Signed Integer Value
inline u32 vstr_to_u32(cstr string); // Parse @string to an Unsigned Integer Value
inline s64 vstr_to_s64(cstr string); // Parse @string to a Signed Long-Long Value
inline u64 vstr_to_u64(cstr string); // Parse @string to an Unsigned Long-Long Value

inline f32 vstr_to_f32(cstr string); // Parse @string to a Float Value
inline f64 vstr_to_f64(cstr string); // Parse @string to a Double Value

// Format Function

/*
 *
 * Format Specifiers:
 *
 *     %c - char                   [s8]
 *     %s - string                 [str]
 *     %i - signed int             [s32, s16, s8]
 *     %u - unsigned int           [u64, u32, u16, u8]
 *     %l - signed long long       [s64]
 *     %f - double                 [f64, f32]
 *     %d - double                 [f64, f32]
 *
 *     %p - pointer address
 *     %h - unsigned hex           [u32, u16, u8]
 *     %b - binary                 [8 bits]
 *
 *     %n - nothing (n or any other unused character)
 *     %% - % symbol
 *
 * Format Options (have to be used in the order below):
 *
 *     %+          - write both positive and negative numbers with their sign
 *     %#          - prefix %p, %b and %h with 0b or 0x
 *     %0          - fill blanks with 0's (default is ' ' space)
 *     %1-U32_MAX  - min-width (min-width = 0 is not valid and will result in an error)
 *     %.0-U32_MAX - max-width (for strings) / precision (for double/float)
 *     %*          - full-precision (does not remove the zeros after the decimal point, which are not necessary)
 *
 * Option Examples:
 *
 *     %1s   + "abc"      = "abc"
 *     %4s   + "abc"      = " abc"
 *     %.2s  + "abc"      = "ab"
 *     %s    + null       = "null"
 *
 *     %+i   + 72         = "+72"
 *     %+i   + -72        = "-72"
 *     %+4i  + -72        = " -72"
 *
 *     %3u   + 72         = " 72"
 *     %03u  + 72         = "072"
 *
 *     %d    + 0.1        = "0.1"
 *     %5d   + 0.1        = "  0.1"
 *
 *     %06h  + 92072      = "0167A8"
 *     %#h   + 92072      = "0x167A8"
 *     %#08h + 92072      = "0x000167A8"
 *
 *     %b    + 1          = "00000001"
 *     %b    + 0b11000101 = "11000101"
 *     %#b   + 0b11000101 = "0b11000101"
 * */

inline str vstr_from_format(cstr format, ...);

// Other Functions

inline str vstr_reverse(str string); // Reverse @string

inline u32 vstr_levenshtein(cstr string1, cstr string2); // Return Similarity of @string1 and @string2

inline void vstr_free(str string); // Free @string

// Dynamically Allocated String Function Defines

#define vstr_new()           vstr_alloc()
#define vstr_new_len()       vstr_alloc_len()
#define vstr_new_slen()      vstr_alloc_slen()
#define vstr_new_empty()     vstr_alloc_empty()
#define vstr_new_empty_len() vstr_alloc_empty_len()

#define vstr_length() vstr_len()

#define vstr_equals() vstr_equ()

#define vstr_append()     vstr_cat()
#define vstr_concat()     vstr_cat()
#define vstr_concat_new() vstr_catn()

#define vstr_set_char()  vstr_setc()
#define vstr_fill_char() vstr_setc()

#define vstr_push_front()  vstr_push_bc()
#define vstr_push_back()   vstr_push_bc()
#define vstr_pushn_front() vstr_pushn_bc()
#define vstr_pushn_back()  vstr_pushn_bc()

#define vstr_pop_front()  vstr_pop_bc()
#define vstr_pop_back()   vstr_pop_bc()
#define vstr_popn_front() vstr_popn_bc()
#define vstr_popn_back()  vstr_popn_bc()

#define vstr_substring() vstr_subxx()

#define vstr_contains() vstr_cont_s()
#define vstr_contains_s() vstr_cont_s()
#define vstr_contains_c() vstr_cont_c()

#define vstr_rep_char() vstr_rep_ac()

#define vstr_insert_string() vstr_insert_xs()
#define vstr_insert_char() vstr_insert_xc()
#define vstr_insert_s() vstr_insert_xs()
#define vstr_insert_c() vstr_insert_xc()

#define vstr_to_uppercase() vstr_upper()
#define vstr_to_lowercase() vstr_lower()
#define vstr_uppercase() vstr_upper()
#define vstr_lowercase() vstr_lower()

#define char_uppercase()    char_upper()
#define char_to_uppercase() char_upper()
#define char_lowercase()    char_lower()
#define char_to_lowercase() char_lower()

#define vstr_back_char() vstr_back()
#define vstr_ref_back() vstr_rback()
#define vstr_ref_back_char() vstr_rback()

#define vstr_rev() vstr_reverse()

#define vstr_comp_diff() vstr_levenshtein()
#define vstr_diff() vstr_levenshtein()

#define free_str() vstr_free()

// Char Functions [ return CHAR_NULL on fail ]

inline bool char_is_upper(char character);
inline bool char_is_lower(char character);
inline bool char_is_num(char character);

inline char char_upper(char character);
inline char char_lower(char character);

inline char char_to_num(char character);

// Char Function Defines

#define char_is_uppercase() char_is_upper()
#define char_is_lowercase() char_is_lower()
#define char_is_number()    char_is_num()

#define char_uppercase()    char_upper()
#define char_to_uppercase() char_upper()
#define char_lowercase()    char_lower()
#define char_to_lowercase() char_lower()

#define char_to_number() char_to_num()

// Mathematical Functions

static const u64 pow10s[] = {
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
        1000000000,
        10000000000,
        100000000000,
        1000000000000,
        10000000000000,
        100000000000000,
        1000000000000000
};

f32 f32_pow10(s32 exp) {
    f32 result = 1.0F;
    bool neg = false;

    if (exp < 0) {
        exp = -exp;
        neg = true;
    } else {
        neg = false;
    }

    while (exp > 15) {
        result *= (f32) pow10s[15];
        exp -= 15;
    }

    result *= (f32) pow10s[exp];

    return neg ? 1.0F / result : result;
}

f64 f64_pow10(s32 exp) {
    f64 result = 1.0;
    bool neg = false;

    if (exp < 0) {
        exp = -exp;
        neg = true;
    } else {
        neg = false;
    }

    while (exp > 15) {
        result *= (f64) pow10s[15];
        exp -= 15;
    }

    result *= (f64) pow10s[exp];

    return neg ? 1.0 / result : result;
}

// Dynamically Allocated String Functions

// Creating new Strings

inline str vstr_alloc(cstr string) {
    u32 length = vstr_len(string);
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    while ((*result++ = *string++) != '\0');

    return temp;
}

inline str vstr_alloc_len(cstr string, u32 length) {
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    u32 i = 0;
    while (i++ < length && (*result++ = *string++) != '\0');
    *result = '\0';

    return temp;
}

inline str vstr_alloc_slen(cstr string, u32 length) {
    u32 string_len = vstr_len(string);
    u32 result_len = min2(string_len, length);

    str result = malloc(sizeof(char) * (result_len + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    u32 i = 0;
    while (i++ < length && (*result++ = *string++) != '\0');
    *result = '\0';

    return temp;
}

inline str vstr_alloc_empty() {
    str result = malloc(sizeof(char) * 1);

    if (result == NULL) {
        return NULL;
    }

    *result = '\0';

    return result;
}

inline str vstr_alloc_empty_len(u32 length) {
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    result[length] = '\0';

    return result;
}

// Creating new Strings from Primitive Types

inline str vstr_from_bool(bool value) {
    str result = malloc(sizeof(char) * (value == true ? 5 : 6));

    if (result == NULL) {
        return NULL;
    }

    if (value == true) {
        result[0] = 't';
        result[1] = 'r';
        result[2] = 'u';
        result[3] = 'e';
        result[4] = '\0';
    } else {
        result[0] = 'f';
        result[1] = 'a';
        result[2] = 'l';
        result[3] = 's';
        result[4] = 'e';
        result[5] = '\0';
    }

    return result;
}

inline str vstr_from_s8(s8 num) {
    bool neg = false;
    bool min = false;

    if (num == S8_MIN) {
        min = true;
        num = S8_MIN + 1;
    }

    if (num < 0) {
        num = (s8) -num;
        neg = true;
    }

    u32 length = 1;
    s8 temp_num = num;

    while ((temp_num /= 10) > 0) length++;
    if (neg) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0 + (min ? 1 : 0));
        temp_result++;
        min = false;
    } while ((num /= 10) > 0);

    if (neg) {
        *temp_result = '-';
        temp_result++;
    }

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_u8(u8 num) {
    u32 length = 1;
    u8 temp_num = num;

    while ((temp_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0);
        temp_result++;
    } while ((num /= 10) > 0);

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_s16(s16 num) {
    bool neg = false;
    bool min = false;

    if (num == S16_MIN) {
        min = true;
        num = S16_MIN + 1;
    }

    if (num < 0) {
        num = (s16) -num;
        neg = true;
    }

    u32 length = 1;
    u32 temp_num = num;

    while ((temp_num /= 10) > 0) length++;
    if (neg) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0 + (min ? 1 : 0));
        temp_result++;
        min = false;
    } while ((num /= 10) > 0);

    if (neg) {
        *temp_result = '-';
        temp_result++;
    }

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_u16(u16 num) {
    u32 length = 1;
    u16 temp_num = num;

    while ((temp_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0);
        temp_result++;
    } while ((num /= 10) > 0);

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_s32(s32 num) {
    bool neg = false;
    bool min = false;

    if (num == S32_MIN) {
        min = true;
        num = S32_MIN + 1;
    }

    if (num < 0) {
        num = -num;
        neg = true;
    }

    u32 length = 1;
    u32 temp_num = num;

    while ((temp_num /= 10) > 0) length++;
    if (neg) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0 + (min ? 1 : 0));
        temp_result++;
        min = false;
    } while ((num /= 10) > 0);

    if (neg) {
        *temp_result = '-';
        temp_result++;
    }

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_u32(u32 num) {
    u32 length = 1;
    u32 temp_num = num;

    while ((temp_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0);
        temp_result++;
    } while ((num /= 10) > 0);

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_s64(s64 num) {
    bool neg = false;
    bool min = false;

    if (num == S64_MIN) {
        min = true;
        num = S64_MIN + 1;
    }

    if (num < 0) {
        num = -num;
        neg = true;
    }

    u32 length = 1;
    u64 temp_num = num;

    while ((temp_num /= 10) > 0) length++;
    if (neg) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0 + (min ? 1 : 0));
        temp_result++;
        min = false;
    } while ((num /= 10) > 0);

    if (neg) {
        *temp_result = '-';
        temp_result++;
    }

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_u64(u64 num) {
    u32 length = 1;
    u64 temp_num = num;

    while ((temp_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_result = result;

    do {
        *temp_result = (char) (num % 10 + CHAR_NUM_0);
        temp_result++;
    } while ((num /= 10) > 0);

    *temp_result = '\0';

    str end = temp_result - 1;
    char prev;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_f32(f32 num) {
    if (num != num) {
        str result = malloc(sizeof(char) * 4);

        if (result == NULL) {
            return NULL;
        }

        result[0] = 'N';
        result[1] = 'a';
        result[2] = 'N';
        result[3] = '\0';

        return result;
    } else if (num > F32_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '+';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    } else if (num < -F32_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '-';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    }

    bool neg;

    if (num < 0.0 && num != -0.0) {
        num = -num;
        neg = true;
    } else {
        neg = false;
    }

    u32 precision = FLOAT_PRECISION;

    u32 length = 1;
    u64 u64_num = (u64) num;

    while ((u64_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + precision + (neg ? 1 : 0) + (precision == 0 ? 0 : 1) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    f32 pow_prec = f32_pow10((s32) precision);

    u64 number = (u64) num;
    f32 temp_num = (num - (f32) number) * pow_prec;
    u64 fraction = (u64) temp_num;

    if ((temp_num - (f32) fraction) >= 0.5F) {
        fraction++;

        if ((f32) fraction >= pow_prec) {
            number++;
            fraction = 0;
        }
    }

    if (precision != 0) {
        while (precision--) {
            *result = (char) (CHAR_NUM_0 + fraction % 10);
            result++;
            fraction /= 10;
        }

        *result = '.';
        result++;
    }

    if (!number) {
        *result = CHAR_NUM_0;
        result++;
    }

    while (number) {
        *result = (char) (CHAR_NUM_0 + number % 10);
        result++;
        number /= 10;
    }

    if (neg) {
        *result = '-';
        result++;
    }

    *result = '\0';

    str end = result - 1;
    char prev;

    result = temp;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_f64(f64 num) {
    if (num != num) {
        str result = malloc(sizeof(char) * 4);

        if (result == NULL) {
            return NULL;
        }

        result[0] = 'N';
        result[1] = 'a';
        result[2] = 'N';
        result[3] = '\0';

        return result;
    } else if (num > F64_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '+';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    } else if (num < -F64_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '-';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    }

    bool neg;

    if (num < 0.0 && num != -0.0) {
        num = -num;
        neg = true;
    } else {
        neg = false;
    }

    u32 precision = DOUBLE_PRECISION;

    u32 length = 1;
    u64 u64_num = (u64) num;

    while ((u64_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + precision + (neg ? 1 : 0) + (precision == 0 ? 0 : 1) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    f64 pow_prec = f64_pow10((s32) precision);

    u64 number = (u64) num;
    f64 temp_num = (num - (f64) number) * pow_prec;
    u64 fraction = (u64) temp_num;

    if ((temp_num - (f64) fraction) >= 0.5) {
        fraction++;

        if ((f64) fraction >= pow_prec) {
            number++;
            fraction = 0;
        }
    }

    if (precision != 0) {
        while (precision--) {
            *result = (char) (CHAR_NUM_0 + fraction % 10);
            result++;
            fraction /= 10;
        }

        *result = '.';
        result++;
    }

    if (!number) {
        *result = CHAR_NUM_0;
        result++;
    }

    while (number) {
        *result = (char) (CHAR_NUM_0 + number % 10);
        result++;
        number /= 10;
    }

    if (neg) {
        *result = '-';
        result++;
    }

    *result = '\0';

    str end = result - 1;
    char prev;

    result = temp;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_f32_p(f32 num, u32 precision) {
    if (num != num) {
        str result = malloc(sizeof(char) * 4);

        if (result == NULL) {
            return NULL;
        }

        result[0] = 'N';
        result[1] = 'a';
        result[2] = 'N';
        result[3] = '\0';

        return result;
    } else if (num > F32_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '+';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    } else if (num < -F32_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '-';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    }

    bool neg;

    if (num < 0.0 && num != -0.0) {
        num = -num;
        neg = true;
    } else {
        neg = false;
    }

    if (precision > FLOAT_PRECISION_MAX) {
        precision = FLOAT_PRECISION_MAX;
    }

    u32 length = 1;
    u64 u64_num = (u64) num;

    while ((u64_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + precision + (neg ? 1 : 0) + (precision == 0 ? 0 : 1) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    f32 pow_prec = f32_pow10((s32) precision);

    u64 number = (u64) num;
    f32 temp_num = (num - (f32) number) * pow_prec;
    u64 fraction = (u64) temp_num;

    if ((temp_num - (f32) fraction) >= 0.5F) {
        fraction++;

        if ((f32) fraction >= pow_prec) {
            number++;
            fraction = 0;
        }
    }

    if (precision != 0) {
        while (precision--) {
            *result = (char) (CHAR_NUM_0 + fraction % 10);
            result++;
            fraction /= 10;
        }

        *result = '.';
        result++;
    }

    if (!number) {
        *result = CHAR_NUM_0;
        result++;
    }

    while (number) {
        *result = (char) (CHAR_NUM_0 + number % 10);
        result++;
        number /= 10;
    }

    if (neg) {
        *result = '-';
        result++;
    }

    *result = '\0';

    str end = result - 1;
    char prev;

    result = temp;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline str vstr_from_f64_p(f64 num, u32 precision) {
    if (num != num) {
        str result = malloc(sizeof(char) * 4);

        if (result == NULL) {
            return NULL;
        }

        result[0] = 'N';
        result[1] = 'a';
        result[2] = 'N';
        result[3] = '\0';

        return result;
    } else if (num > F64_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '+';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    } else if (num < -F64_MAX) {
        str result = malloc(sizeof(char) * 5);

        if (result == NULL) {
            return NULL;
        }

        result[0] = '-';
        result[1] = 'I';
        result[2] = 'N';
        result[3] = 'F';
        result[4] = '\0';

        return result;
    }

    bool neg;

    if (num < 0.0 && num != -0.0) {
        num = -num;
        neg = true;
    } else {
        neg = false;
    }

    if (precision > DOUBLE_PRECISION_MAX) {
        precision = DOUBLE_PRECISION_MAX;
    }

    u32 length = 1;
    u64 u64_num = (u64) num;

    while ((u64_num /= 10) > 0) length++;

    str result = malloc(sizeof(char) * (length + precision + (neg ? 1 : 0) + (precision == 0 ? 0 : 1) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    f64 pow_prec = f64_pow10((s32) precision);

    u64 number = (u64) num;
    f64 temp_num = (num - (f64) number) * pow_prec;
    u64 fraction = (u64) temp_num;

    if ((temp_num - (f64) fraction) >= 0.5) {
        fraction++;

        if ((f64) fraction >= pow_prec) {
            number++;
            fraction = 0;
        }
    }

    if (precision != 0) {
        while (precision--) {
            *result = (char) (CHAR_NUM_0 + fraction % 10);
            result++;
            fraction /= 10;
        }

        *result = '.';
        result++;
    }

    if (!number) {
        *result = CHAR_NUM_0;
        result++;
    }

    while (number) {
        *result = (char) (CHAR_NUM_0 + number % 10);
        result++;
        number /= 10;
    }

    if (neg) {
        *result = '-';
        result++;
    }

    *result = '\0';

    str end = result - 1;
    char prev;

    result = temp;

    while (result < end) {
        prev = *result;
        *result++ = *end;
        *end-- = prev;
    }

    return temp;
}

// Comparison & Length

inline u32 vstr_len(cstr string) {
    cstr org_string = string;
    for (; *string != '\0'; ++string);
    return (u32) (string - org_string) / sizeof(char);
}

/*
 * Similar Algorithms with same Outputs:
 *
 *     inline u32 vstr_len(cstr string) {
 *         u32 length = 0;
 *         for (; *string != '\0'; ++string, length++);
 *         return length;
 *     }
 *
 *     inline u32 vstr_len(cstr string) {
 *         u32 length = 0;
 *         while ((*string++) != '\0') length++;
 *         return length;
 *     }
 *
 * Second one increments the Pointer @string by 1 more
*/

/*
 * Another Approach with For-Loop:
 *
 *     inline u32 vstr_len(str string) {
 *         u32 length = 0;
 *         for (; *string++ != '\0'; length++);
 *         return length;
 *     }
 *
 * Same Functionality as the Method above
*/

inline u32 vstr_lenx(cstr string, u32 length) {
    u32 result = 0;
    for (; length > 0 && *string != '\0'; ++string, length--, result++);
    return result;
}

/*
 * Approach with While-Loop:
 *
 *     inline u32 vstr_lenx(cstr string, u32 length) {
 *         u32 result = 0;
 *         while (length-- > 0 && (*string++) != '\0') result++;
 *         return result;
 *     }
 *
 * Increments @string Pointer by one more than the Method above
 */

inline bool vstr_equ(cstr string1, cstr string2) {
    do {
        if (*string1 == '\0') {
            return *string2 == '\0';
        } else if (*string2 == '\0') {
            return *string1 == '\0';
        }
    } while (*string1++ == *string2++);

    return false;
}

inline bool vstr_is_empty(cstr string) {
    return *string == '\0';
}

inline bool vstr_starts_with(cstr string1, cstr string2) {
    while (*string1 == *string2) {
        if (*string2 == '\0') {
            return true;
        }

        string1++;
        string2++;
    }

    return *string2 == '\0';
}

inline bool vstr_starts_with_c(cstr string, char character) {
    return character == '\0' || *string != '\0' && *string == character;
}

inline bool vstr_ends_with(cstr string1, cstr string2) {
    for (; *string1 != '\0'; ++string1);

    string1 -= vstr_len(string2);

    while (*string1 == *string2) {
        if (*string2 == '\0') {
            return true;
        }

        string1++;
        string2++;
    }

    return *string2 == '\0';
}

inline bool vstr_ends_with_c(cstr string, char character) {
    if (character == '\0') return true;
    for (; *string != '\0'; ++string);
    return *(string - 1) == character;
}

// String Setter

inline str vstr_setc(str string, char character) {
    str temp = string;

    for (; *string != '\0'; ++string) {
        *string = character;
    }

    return temp;
}

inline str vstr_setcx(str string, char character, u32 length) {
    str temp = string;

    for (u32 i = 0; i++ < length && *string != '\0'; ++string) {
        *string = character;
    }

    return temp;
}

inline str vstr_clear(str* string) {
    str result = realloc(*string, sizeof(char) * 1);

    if (result == NULL) {
        return NULL;
    }

    *string = result;
    *result = '\0';

    return result;
}

inline str vstr_set(str dest, cstr src) {
    str temp = dest;
    for (; (*dest = *src) != '\0'; dest++, src++);
    return temp;
}

inline str vstr_sset(str* dest, cstr src) {
    str result = realloc(*dest, sizeof(char) * (vstr_len(src) + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    for (; (*result = *src) != '\0'; ++result, ++src);

    return temp;
}

inline str vstr_setx(str dest, cstr src, u32 length) {
    str temp = dest;
    for (u32 i = 0; i < length && (*dest = *src) != '\0'; ++dest, ++src, i++);
    return temp;
}

inline str vstr_ssetx(str* dest, cstr src, u32 length) {
    str result = *dest;

    result = realloc(*dest, sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    for (; length > 0 && *src != '\0'; ++result, ++src, length--) {
        *result = *src;
    }

    *result = '\0';

    return temp;
}

// Concatenation & Push / Pop Chars

inline str vstr_cat(str* dest, str src) {
    u32 dest_len = vstr_len(*dest);
    str result = realloc(*dest, sizeof(char) * (dest_len + vstr_len(src) + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    result += dest_len;
    for (; (*result = *src) != '\0'; ++result, ++src);

    return temp;
}

inline str vstr_catn(str dest, str src) {
    str result = malloc(sizeof(char) * (vstr_len(dest) + vstr_len(src) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; *dest != '\0'; ++result, ++dest) {
        *result = *dest;
    }

    for (; (*result = *src) != '\0'; ++result, ++src);

    return temp;
}

inline str vstr_push_fc(str* dest, char character) {
    u32 dest_len = vstr_len(*dest);
    str result = realloc(*dest, sizeof(char) * (dest_len + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    char last_char;
    char next_char = *result;

    result[dest_len + 1] = '\0';

    while (*result != '\0') {
        last_char = next_char;
        result++;
        next_char = *result;
        *result = last_char;
    }

    *temp = character;

    return temp;
}

inline str vstr_pushn_fc(str dest, char character) {
    u32 dest_len = vstr_len(dest);
    str result = malloc(sizeof(char) * (dest_len + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    *result = character;
    result++;

    while ((*result++ = *dest++) != '\0');

    return temp;
}

inline str vstr_push_bc(str* dest, char character) {
    u32 dest_len = vstr_len(*dest);
    str result = realloc(*dest, sizeof(char) * (dest_len + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    result += dest_len;
    *result = character;
    result++;
    *result = '\0';

    return temp;
}

inline str vstr_pushn_bc(str dest, char character) {
    str result = malloc(sizeof(char) * (vstr_len(dest) + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; (*result = *dest) != '\0'; ++result, ++dest);
    *result = character;
    result++;
    *result = '\0';

    return temp;
}

inline str vstr_pop_fc(str* string) {
    u32 string_len = vstr_len(*string);
    str result = realloc(*string, sizeof(char) * max2(string_len, 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    str ret = result;

    if (string_len > 0) {
        str temp = result;
        temp++;

        while (string_len-- > 0) {
            *result++ = *temp++;
        }

        result--;
    }

    *result = '\0';

    return ret;
}

inline str vstr_popn_fc(str string) {
    u32 string_len = vstr_len(string);
    str result = malloc(sizeof(char) * max2(string_len, 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    string++;

    if (string_len > 0) {
        for (; string_len > 0; ++result, ++string, string_len--) {
            *result = *string;
        }
    }

    result--;
    *result = '\0';

    return temp;
}

inline str vstr_pop_bc(str* string) {
    u32 string_len = vstr_len(*string);
    u32 result_len = max2(string_len, 1);
    str result = realloc(*string, sizeof(char) * result_len);

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    result[result_len - 1] = '\0';

    return result;
}

inline str vstr_popn_bc(str string) {
    u32 string_len = vstr_len(string);
    str result = malloc(sizeof(char) * max2(string_len, 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    if (string_len > 0) {
        for (; *string != '\0'; ++string, ++result) {
            *result = *string;
        }

        result--;
    }

    *result = '\0';

    return temp;
}

// Substring of Strings

inline str vstr_rsub(str string, u32 index) {
    for (; index > 0 && *string != '\0'; ++string, index--);
    return string;
}

inline str vstr_rssub(str string, u32 index) {
    if (*string == '\0') return string;
    for (; index > 0 && *string != '\0'; ++string, index--);
    return *string == '\0' ? --string : string;
}

inline str vstr_sub(str* string, u32 length) {
    u32 len = vstr_len(*string);

    if (length >= len) {
        return NULL;
    }

    str result = realloc(*string, sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    str temp = result;
    str temp_string = *string;

    for (; length > 0; ++result, ++temp_string, length--) {
        *result = *temp_string;
    }

    *result = '\0';

    return temp;
}

inline str vstr_subx(str* string, u32 start) {
    if (start == 0) {
        return *string;
    }

    u32 len = vstr_len(*string);

    if (start >= len) {
        return NULL;
    }

    str front = *string;
    str back = *string + start;

    for (; *back != '\0'; ++front, ++back) {
        *front = *back;
    }

    *front = '\0';

    str result = realloc(*string, sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_subxx(str* string, u32 start, u32 end) {
    u32 len = vstr_len(*string);

    if (start == 0 && end == len - 1) {
        return *string;
    }

    if (start > end || start >= len || end >= len) {
        return NULL;
    }

    str front = *string;
    str back = *string + start;

    for (u32 i = end - start + 1; i > 0; ++front, ++back, i--) {
        *front = *back;
    }

    *front = '\0';

    str result = realloc(*string, sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_subxn(str* string, u32 start, u32 length) {
    u32 len = vstr_len(*string);

    if (start == 0 && start + length == len - 1) {
        return *string;
    }

    if (start >= len || start + length >= len) {
        return NULL;
    }

    str front = *string;
    str back = *string + start;

    for (u32 i = length + 1; i > 0; ++front, ++back, i--) {
        *front = *back;
    }

    *front = '\0';

    str result = realloc(*string, sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_nsub(str string, u32 length) {
    u32 len = vstr_len(string);

    if (length > len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str temp_string = string;

    for (; length > 0; ++result, ++temp_string, length--) {
        *result = *temp_string;
    }

    *result = '\0';

    return temp;
}

inline str vstr_nsubx(str string, u32 start) {
    u32 len = vstr_len(string);

    if (start >= len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;
    str back = string + start;

    for (; *back != '\0'; ++back, ++front) {
        *front = *back;
    }

    *front = '\0';

    return result;
}

inline str vstr_nsubxx(str string, u32 start, u32 end) {
    u32 len = vstr_len(string);

    if (start > end || start >= len || end >= len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;
    str back = string + start;

    for (u32 i = end - start + 1; i > 0; ++front, ++back, i--) {
        *front = *back;
    }

    *front = '\0';

    return result;
}

inline str vstr_nsubxn(str string, u32 start, u32 length) {
    u32 len = vstr_len(string);

    if (start >= len || start + length >= len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (len - start + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;
    str back = string + start;

    for (u32 i = length + 1; i > 0; ++front, ++back, i--) {
        *front = *back;
    }

    *front = '\0';

    return result;
}

// String Resize

inline str vstr_resize(str* string, u32 length)  {
    str result = realloc(*string, sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;
    result[length] = '\0';

    return result;
}

inline str vstr_fit(str* string)  {
    str result = realloc(*string, sizeof(char) * (vstr_len(*string) + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_grow(str* string, u32 elements)  {
    u32 length = vstr_len(*string) + elements;
    str result = realloc(*string, sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    result[length] = '\0';

    return result;
}

inline str vstr_size(str* string, u32 length)  {
    u32 string_len = vstr_len(*string);
    str result = realloc(*string, sizeof(char) * (min2(string_len, length) + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    result[length] = '\0';

    return result;
}

// Finding & Replacing in Strings

inline u32 vstr_find_fs(cstr string1, cstr string2) {
    if (*string1 == '\0') {
        return U32_MAX;
    } else if (*string2 == '\0') {
        return 0;
    }

    cstr org1 = string1;

    cstr temp1;
    cstr temp2;

    for (; *string1 != '\0'; ++string1) {
        temp1 = string1;
        temp2 = string2;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                return (u32) (string1 - org1) / sizeof(char);
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            return (u32) (string1 - org1) / sizeof(char);
        }
    }

    return U32_MAX;
}

inline u32 vstr_find_ls(cstr string1, cstr string2) {
    if (*string1 == '\0') {
        return U32_MAX;
    } else if (*string2 == '\0') {
        return vstr_len(string1) - 1;
    }

    cstr org1 = string1;
    cstr last = NULL;

    cstr temp1;
    cstr temp2;

    for (; *string1 != '\0'; ++string1) {
        temp1 = string1;
        temp2 = string2;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                last = string1;
                break;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            last = string1;
        }
    }

    return last == NULL ? U32_MAX : (u32) (last - org1) / sizeof(char);
}


inline str vstr_rfind_fs(cstr string1, cstr string2) {
    if (*string1 == '\0') {
        return NULL;
    } else if (*string2 == '\0') {
        return (str) string1;
    }

    cstr org1 = string1;

    cstr temp1;
    cstr temp2;

    for (; *string1 != '\0'; ++string1) {
        temp1 = string1;
        temp2 = string2;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                return (str) string1;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            return (str) string1;
        }
    }

    return NULL;
}

inline str vstr_rfind_ls(cstr string1, cstr string2) {
    if (*string1 == '\0') {
        return NULL;
    } else if (*string2 == '\0') {
        while (*string1 != '\0') string1++;
        return (str) (--string1);
    }

    cstr org1 = string1;
    cstr last = NULL;

    cstr temp1;
    cstr temp2;

    for (; *string1 != '\0'; ++string1) {
        temp1 = string1;
        temp2 = string2;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                last = string1;
                break;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            last = string1;
        }
    }

    return (str) last;
}

inline bool vstr_cont_s(cstr string1, cstr string2) {
    if (*string1 == '\0') {
        return false;
    } else if (*string2 == '\0') {
        return true;
    }

    cstr temp1;
    cstr temp2;

    for (; *string1 != '\0'; ++string1) {
        temp1 = string1;
        temp2 = string2;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                return true;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            return true;
        }
    }

    return false;
}

inline str vstr_rep_fs(str* dest, cstr old, cstr new) {
    if (**dest == '\0' || *old == '\0') {
        return *dest;
    }

    str result = *dest;

    str res = result;

    cstr org_dest = *dest;

    str temp_dest = *dest;

    u32 dest_len = 0;
    u32 old_len = vstr_len(old);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        if (found == NULL) {
            temp1 = temp_dest;
            temp2 = old;

            while (*temp1 == *temp2) {
                if (*temp2 == '\0') {
                    found = temp_dest;
                    break;
                }

                temp1++;
                temp2++;
            }

            if (*temp2 == '\0') {
                found = temp_dest;
            }
        }
    }

    if (found == NULL) {
        return *dest;
    }

    result = found;

    u32 new_len = vstr_len(new);

    u32 result_len = dest_len - old_len + new_len;

    if (result_len < dest_len) {
        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        str front = result;
        str back = result + (old_len - new_len);

        for (; *back != '\0'; ++front, ++back) {
            *front = *back;
        }

        *front = '\0';

        res = realloc(*dest, sizeof(char) * (result_len + 1));

        if (res == NULL) {
            return NULL;
        }

        *dest = res;

        return res;
    } else {
        u32 found_index = (u32) (found - *dest) / sizeof(char);

        res = realloc(*dest, sizeof(char) * (result_len + 1));

        if (res == NULL) {
            return NULL;
        }

        *dest = res;
        result = res + found_index;

        str front = res + dest_len - 1;
        str back = res + result_len;

        *back = '\0';
        back--;

        for (u32 i = (dest_len - old_len + new_len) - (found_index + new_len - 1); i > 0; --front, --back, i--) {
            *back = *front;
        }

        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        return res;
    }
}

inline str vstr_rep_ls(str* dest, cstr old, cstr new) {
    if (**dest == '\0' || *old == '\0') {
        return *dest;
    }

    str result = *dest;

    str res = result;

    cstr org_dest = *dest;

    str temp_dest = *dest;

    u32 dest_len = 0;
    u32 old_len = vstr_len(old);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        temp1 = temp_dest;
        temp2 = old;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                found = temp_dest;
                break;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            found = temp_dest;
        }
    }

    if (found == NULL) {
        return *dest;
    }

    result = found;

    u32 new_len = vstr_len(new);

    u32 result_len = dest_len - old_len + new_len;

    if (result_len < dest_len) {
        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        str front = result;
        str back = result + (old_len - new_len);

        for (; *back != '\0'; ++front, ++back) {
            *front = *back;
        }

        *front = '\0';

        res = realloc(*dest, sizeof(char) * (result_len + 1));

        if (res == NULL) {
            return NULL;
        }

        *dest = res;

        return res;
    } else {
        u32 found_index = (u32) (found - *dest) / sizeof(char);

        res = realloc(*dest, sizeof(char) * (result_len + 1));

        if (res == NULL) {
            return NULL;
        }

        *dest = res;
        result = res + found_index;

        str front = res + dest_len - 1;
        str back = res + result_len;

        *back = '\0';
        back--;

        for (u32 i = (dest_len - old_len + new_len) - (found_index + new_len - 1); i > 0; --front, --back, i--) {
            *back = *front;
        }

        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        return res;
    }
}

inline str vstr_repn_fs(str string, cstr old, cstr new) {
    if (*string == '\0' || *old == '\0') {
        return vstr_alloc(string);
    }

    cstr org_dest = string;

    str temp_dest = string;

    u32 dest_len = 0;
    u32 old_len = vstr_len(old);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        if (found == NULL) {
            temp1 = temp_dest;
            temp2 = old;

            while (*temp1 == *temp2) {
                if (*temp2 == '\0') {
                    found = temp_dest;
                    break;
                }

                temp1++;
                temp2++;
            }

            if (*temp2 == '\0') {
                found = temp_dest;
            }
        }
    }

    if (found == NULL) {
        return vstr_alloc(string);
    }

    u32 found_index = (u32) (found - org_dest) / sizeof(char);

    u32 new_len = vstr_len(new);
    u32 result_len = dest_len - old_len + new_len;

    str result = malloc(sizeof(char) * (result_len + 1));

    str temp = result;

    if (result == NULL) {
        return NULL;
    }

    temp_dest = string;

    for (u32 i = found_index; i > 0; ++result, ++temp_dest, i--) {
        *result = *temp_dest;
    }

    if (result_len < dest_len) {
        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        str front = result;
        str back = string + found_index + old_len;

        for (; *back != '\0'; ++front, ++back) {
            *front = *back;
        }

        *front = '\0';
    } else {
        result = temp + found_index;

        str front = string + dest_len - 1;
        str back = temp + result_len;

        *back = '\0';
        back--;

        for (u32 i = (dest_len - old_len + new_len) - (found_index + new_len - 1); i > 0; --front, --back, i--) {
            *back = *front;
        }

        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }
    }

    return temp;
}

inline str vstr_repn_ls(str string, cstr old, cstr new) {
    if (*string == '\0' || *old == '\0') {
        return vstr_alloc(string);
    }

    cstr org_dest = string;

    str temp_dest = string;

    u32 dest_len = 0;
    u32 old_len = vstr_len(old);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        temp1 = temp_dest;
        temp2 = old;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                found = temp_dest;
                break;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            found = temp_dest;
        }
    }

    if (found == NULL) {
        return vstr_alloc(string);
    }

    u32 found_index = (u32) (found - org_dest) / sizeof(char);

    u32 new_len = vstr_len(new);
    u32 result_len = dest_len - old_len + new_len;

    str result = malloc(sizeof(char) * (result_len + 1));

    str temp = result;

    if (result == NULL) {
        return NULL;
    }

    temp_dest = string;

    for (u32 i = found_index; i > 0; ++result, ++temp_dest, i--) {
        *result = *temp_dest;
    }

    if (result_len < dest_len) {
        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }

        str front = result;
        str back = string + found_index + old_len;

        for (; *back != '\0'; ++front, ++back) {
            *front = *back;
        }

        *front = '\0';
    } else {
        result = temp + found_index;

        str front = string + dest_len - 1;
        str back = temp + result_len;

        *back = '\0';
        back--;

        for (u32 i = (dest_len - old_len + new_len) - (found_index + new_len - 1); i > 0; --front, --back, i--) {
            *back = *front;
        }

        for (; *new != '\0'; ++result, ++new) {
            *result = *new;
        }
    }

    return temp;
}

// Finding & Replacing Characters

inline u32 vstr_find_fc(cstr string, char character) {
    cstr org = string;

    for (; *string != '\0'; ++string) {
        if (*string == character) {
            return (u32) (string - org) / sizeof(char);
        }
    }

    return U32_MAX;
}

inline u32 vstr_find_lc(cstr string, char character) {
    cstr org = string;
    cstr last = NULL;

    for (; *string != '\0'; ++string) {
        if (*string == character) {
            last = string;
        }
    }

    return last == NULL ? U32_MAX : (u32) (last - org) / sizeof(char);
}

inline str vstr_rfind_fc(cstr string, char character) {
    for (; *string != character; ++string) {
        if (*string == '\0') {
            return NULL;
        }
    }

    return (str) string;
}

inline str vstr_rfind_lc(cstr string, char character) {
    cstr found = NULL;

    for (; *string != '\0'; ++string) {
        if (*string == character) {
            found = string;
        }
    }

    return (str) found;
}

inline bool vstr_cont_c(str string, char character) {
    for (; *string != '\0'; ++string) {
        if (*string == character) {
            return true;
        }
    }

    return false;
}

/*
 * Algorithm other way around:
 *
 *     inline bool vstr_cont_c(str string, char character) {
 *         for (; *string != character; ++string) {
 *             if (*string == '\0') {
 *                 return false;
 *             }
 *         }
 *
 *         return true;
 *     }
 *
 * Same Functionality as the Method above
*/

inline str vstr_rep_fc(str string, char old, char new) {
    str temp = string;

    for (; *string != '\0'; ++string) {
        if (*string == old) {
            *string = new;
            break;
        }
    }

    return temp;
}

inline str vstr_rep_lc(str string, char old, char new) {
    str temp = string;
    str found = NULL;

    for (; *string != '\0'; ++string) {
        if (*string == old) {
            found = string;
        }
    }

    if (found != NULL) {
        *found = new;
    }

    return temp;
}

inline str vstr_repn_fc(str string, char old, char new) {
    str result = malloc(sizeof(char) * (vstr_len(string) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str found = NULL;

    do {
        if (found == NULL && *string == old) {
            found = result;
        }
    } while ((*result++ = *string++) != '\0');

    if (found != NULL) {
        *found = new;
    }

    return temp;
}

inline str vstr_repn_lc(str string, char old, char new) {
    str result = malloc(sizeof(char) * (vstr_len(string) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str found = NULL;

    do {
        if (*string == old) {
            found = result;
        }
    } while ((*result++ = *string++) != '\0');

    if (found != NULL) {
        *found = new;
    }

    return temp;
}

inline str vstr_rep_ac(str string, char old, char new) {
    str temp = string;

    for (; *string != '\0'; ++string) {
        if (*string == old) {
            *string = new;
        }
    }

    return temp;
}

inline str vstr_repn_ac(str string, char old, char new) {
    str result = malloc(sizeof(char) * (vstr_len(string) + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; *string != '\0'; ++string) {
        if (*string == old) {
            *result = new;
        } else {
            *result = *string;
        }

        result++;
    }

    *result = '\0';

    return temp;
}

// Erasing Strings, Characters & Indexes

inline str vstr_erase_fs(str* dest, cstr src) {
    if (**dest == '\0' || *src == '\0') {
        return *dest;
    }

    str result = *dest;

    cstr org_dest = *dest;

    str temp_dest = *dest;

    u32 dest_len = 0;
    u32 src_len = vstr_len(src);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        if (found == NULL) {
            temp1 = temp_dest;
            temp2 = src;

            while (*temp1 == *temp2) {
                if (*temp2 == '\0') {
                    found = temp_dest;
                    break;
                }

                temp1++;
                temp2++;
            }

            if (*temp2 == '\0') {
                found = temp_dest;
            }
        }
    }

    if (found == NULL || src_len > dest_len) {
        return *dest;
    }

    result = found;

    str next = result + src_len;

    u32 result_len = dest_len + 1 - src_len;

    for (; *result != '\0'; ++result, ++next) {
        *result = *next;
    }

    result = realloc(*dest, sizeof(char) * result_len);

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return result;
}

inline str vstr_erase_ls(str* dest, cstr src) {
    if (**dest == '\0' || *src == '\0') {
        return *dest;
    }

    str result = *dest;

    cstr org_dest = *dest;

    str temp_dest = *dest;

    u32 dest_len = 0;
    u32 src_len = 0;
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        temp1 = temp_dest;
        temp2 = src;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                if (found == NULL) src_len--;
                found = temp_dest;
            }

            temp1++;
            temp2++;

            if (found == NULL) src_len++;
        }

        if (*temp2 == '\0') {
            found = temp_dest;
        }
    }

    if (found == NULL || src_len > dest_len) {
        return *dest;
    }

    result = found;
    str next = result + src_len;

    u32 result_len = dest_len + 1 - src_len;

    for (; *result != '\0'; ++result, ++next) {
        *result = *next;
    }

    result = realloc(*dest, sizeof(char) * result_len);

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return result;
}

inline str vstr_erase_fc(str* dest, char character) {
    str result = *dest;
    str next = result;
    u32 dest_len = 0;
    bool found = false;

    for (; *result != '\0'; ++result, ++next, dest_len++) {
        if (!found && *next == character) {
            next++;
            found = true;
            if (*next == '\0') break;
        }

        if (found) {
            *result = *next;
        }
    }

    *result = '\0';

    result = realloc(*dest, sizeof(char) * (dest_len + 1 - (found ? 1 : 0)));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return *dest;
}

inline str vstr_erase_lc(str* dest, char character) {
    str temp = *dest;
    u32 dest_len = 0;
    u32 found = U32_MAX;

    for (; *temp != '\0'; ++temp, dest_len++) {
        if (*temp == character) {
            found = dest_len;
        }
    }

    if (found == U32_MAX) {
        return *dest;
    } else if (*(--temp) == character) {
        str result = realloc(*dest, sizeof(char) * dest_len);

        if (result == NULL) {
            return NULL;
        }

        *dest = result;
        result[dest_len - 1] = '\0';
        return result;
    }

    str result = realloc(*dest, sizeof(char) * dest_len);

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    result[dest_len] = '\0';
    temp = result;
    result += found;

    str next = result + 1;

    for (; *result != '\0'; ++result, ++next) {
        *result = *next;
    }

    return temp;
}

inline str vstr_erase_ac(str* dest, char character) {
    str result = *dest;
    str next = result;

    u32 dest_len = 0;

    for (; *result != '\0'; ++result, ++next, dest_len++) {
        while (*next == character) {
            next++;
            if (*next == '\0') break;
        }

        *result = *next;

        if (*next == '\0') break;
    }

    *result = '\0';

    result = realloc(*dest, sizeof(char) * (dest_len + 1));

    str temp = result;

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return temp;
}

inline str vstr_nerase_fs(str string, cstr src) {
    if (*string == '\0' || *src == '\0') {
        return vstr_alloc(string);
    }

    cstr org_dest = string;

    str temp_dest = string;

    u32 dest_len = 0;
    u32 src_len = vstr_len(src);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        if (found == NULL) {
            temp1 = temp_dest;
            temp2 = src;

            while (*temp1 == *temp2) {
                if (*temp2 == '\0') {
                    found = temp_dest;
                    break;
                }

                temp1++;
                temp2++;
            }

            if (*temp2 == '\0') {
                found = temp_dest;
            }
        }
    }

    if (found == NULL || src_len > dest_len) {
        return vstr_alloc(string);
    }

    u32 found_index = (u32) (found - org_dest) / sizeof(char);
    u32 result_len = dest_len + 1 - src_len;

    str result = result = malloc(sizeof(char) * result_len);

    if (result == NULL) {
        return NULL;
    }

    if (result_len == 1) {
        *result = '\0';
        return result;
    }

    str temp = result;
    str next = string + found_index + src_len;

    for (; found_index > 0; ++result, ++string, found_index--) {
        *result = *string;
    }

    for (; *result != '\0'; ++result, ++next) {
        *result = *next;
    }

    return temp;
}

inline str vstr_nerase_ls(str string, cstr src) {
    if (*string == '\0' || *src == '\0') {
        return vstr_alloc(string);
    }

    cstr org_dest = string;

    str temp_dest = string;

    u32 dest_len = 0;
    u32 src_len = vstr_len(src);
    str found = NULL;

    cstr temp1;
    cstr temp2;

    for (; *temp_dest != '\0'; ++temp_dest, dest_len++) {
        temp1 = temp_dest;
        temp2 = src;

        while (*temp1 == *temp2) {
            if (*temp2 == '\0') {
                found = temp_dest;
                break;
            }

            temp1++;
            temp2++;
        }

        if (*temp2 == '\0') {
            found = temp_dest;
        }
    }

    if (found == NULL || src_len > dest_len) {
        return vstr_alloc(string);
    }

    u32 found_index = (u32) (found - org_dest) / sizeof(char);
    u32 result_len = dest_len + 1 - src_len;

    str result = result = malloc(sizeof(char) * result_len);

    if (result == NULL) {
        return NULL;
    }

    if (result_len == 1) {
        *result = '\0';
        return result;
    }

    str temp = result;
    str next = string + found_index + src_len;

    for (; found_index > 0; ++result, ++string, found_index--) {
        *result = *string;
    }

    for (; *result != '\0'; ++result, ++next) {
        *result = *next;
    }

    return temp;
}

inline str vstr_nerase_fc(str string, char character) {
    str result = string;

    str next = string;
    u32 dest_len = 0;
    bool found = false;

    for (; *result != '\0'; ++result, dest_len++) {
        if (!found && *result == character) {
            found = true;
        }
    }

    result = malloc(sizeof(char) * (dest_len + 1 - (found ? 1 : 0)));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    found = false;

    for (; *next != '\0'; ++result, ++next) {
        if (!found && *next == character) {
            next++;
            found = true;
            if (*next == '\0') break;
        }

        *result = *next;
    }

    *result = '\0';

    return temp;
}

inline str vstr_nerase_lc(str string, char character) {
    str result = string;

    str next = string;
    u32 dest_len = 0;

    str found = NULL;
    u32 found_index = U32_MAX;

    for (; *result != '\0'; ++result, dest_len++) {
        if (*result == character) {
            found = result;
        }
    }

    found_index = (u32) (found - string) / sizeof(char);

    result = malloc(sizeof(char) * (dest_len + 1 - (found != NULL ? 1 : 0)));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    if (found == NULL) {
        for (; *next != '\0'; ++result, ++next) {
            *result = *next;
        }
    } else {
        for (; found_index > 0; ++result, ++next, found_index--) {
            *result = *next;
        }

        for (; *next != '\0'; ++result, ++next) {
            if (*next == character) {
                next++;
                if (*next == '\0') break;
            }

            *result = *next;
        }
    }

    *result = '\0';

    return temp;
}

inline str vstr_nerase_ac(str string, char character) {
    str result = string;

    str next = string;
    u32 dest_len = 0;
    u32 found = 0;

    for (; *result != '\0'; ++result, dest_len++) {
        if (*result == character) {
            found++;
        }
    }

    result = malloc(sizeof(char) * (dest_len + 1 - found));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; *next != '\0'; ++result, ++next) {
        while (*next == character) {
            next++;
            if (*next == '\0') break;
        }

        *result = *next;
    }

    *result = '\0';

    return temp;
}

inline str vstr_erase_x(str* dest, u32 index) {
    if (index == 0) {
        return vstr_pop_fc(dest);
    }

    str result = *dest;
    str next = result;
    u32 dest_len = 0;

    for (u32 i = 0; *result != '\0'; ++result, ++next, dest_len++, i++) {
        if (i == index) {
            next++;
        }

        *result = *next;
    }

    if (index >= dest_len) {
        return NULL;
    }

    result = realloc(*dest, sizeof(char) * dest_len);

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return result;
}

inline str vstr_erase_xx(str* dest, u32 start, u32 end) {
    if (start == end) {
        return vstr_erase_x(dest, start);
    } else if (start > end) {
        return NULL;
    }

    str result = *dest;
    str next = result;
    u32 dest_len = 0;

    for (u32 i = 0; *result != '\0'; ++result, ++next, dest_len++, i++) {
        if (i == start) {
            next += end - start + 1;
        }

        *result = *next;
    }

    if (start >= dest_len || end >= dest_len) {
        return NULL;
    }

    result = realloc(*dest, sizeof(char) * (dest_len + 1 - (end - start)));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return result;
}

inline str vstr_erase_xn(str* dest, u32 start, u32 length) {
    if (length == 0) {
        return vstr_erase_x(dest, start);
    }

    str result = *dest;
    str next = result;
    u32 dest_len = 0;

    for (u32 i = 0; *result != '\0'; ++result, ++next, dest_len++, i++) {
        if (i == start) {
            next += length;
        }

        *result = *next;
    }

    if (start >= dest_len || start + length >= dest_len) {
        return NULL;
    }

    result = realloc(*dest, sizeof(char) * (dest_len + 1 - length));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    return result;
}

inline str vstr_nerase_x(str string, u32 index) {
    if (index == 0) {
        return vstr_popn_fc(string);
    }

    u32 dest_len = vstr_len(string);

    if (index >= dest_len) {
        return NULL;
    }

    str result = result = malloc(sizeof(char) * dest_len);

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str next = string;

    for (u32 i = 0; *result != '\0'; ++result, ++next, i++) {
        if (i == index) {
            next++;
        }

        *result = *next;
    }

    return temp;
}

inline str vstr_nerase_xx(str string, u32 start, u32 end) {
    if (start == end) {
        return vstr_nerase_x(string, start);
    } else if (start > end) {
        return NULL;
    }

    u32 dest_len = vstr_len(string);

    if (start >= dest_len || end >= dest_len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (dest_len + 1 - (end - start)));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str next = string;

    for (u32 i = 0; *next != '\0'; ++result, ++next, i++) {
        if (i == start) {
            next += end - start + 1;
        }

        *result = *next;
    }

    *result = '\0';

    return temp;
}

inline str vstr_nerase_xn(str string, u32 start, u32 length) {
    if (length == 0) {
        return vstr_nerase_x(string, start);
    }

    u32 dest_len = vstr_len(string);

    if (start >= dest_len || start + length >= dest_len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (dest_len + 1 - length));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    str next = string;

    for (u32 i = 0; *next != '\0'; ++result, ++next, i++) {
        if (i == start) {
            next += length;
        }

        *result = *next;
    }

    *result = '\0';

    return temp;
}

// Trimming Strings

inline str vstr_trim(str* string) {
    str result = *string;

    str front = result;
    str back = NULL;
    str start;

    for (; *result == CHAR_SPACE; ++result);

    start = result;

    for (; *result != '\0'; ++result) {
        if (*result != CHAR_SPACE) {
            back = result;
        }
    }

    if (back == NULL) {
        result = realloc(*string, sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *string = result;

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    result = realloc(*string, sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_trim_f(str* string) {
    str result = *string;

    str front = result;
    str back = NULL;
    str start;

    for (; *result == CHAR_SPACE; ++result);
    start = result;

    for (; *result != '\0'; ++result);
    back = result - 1;

    if (back == NULL) {
        result = realloc(*string, sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *string = result;

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    result = realloc(*string, sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_trim_b(str* string) {
    str result = *string;

    str front = result;
    str back = NULL;
    str start = result;

    for (; *result != '\0'; ++result) {
        if (*result != CHAR_SPACE) {
            back = result;
        }
    }

    if (back == NULL) {
        result = realloc(*string, sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *string = result;

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    result = realloc(*string, sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return result;
}

inline str vstr_trim_a(str* string) {
    str result = *string;
    str next = result;

    str temp = result;

    bool prev = true;

    for (; *result != '\0'; ++result, ++next) {
        if (*next == CHAR_SPACE && !prev) {
            *result = CHAR_SPACE;
            prev = true;
            continue;
        }

        while (*next == CHAR_SPACE) {
            next++;
            if (*next == '\0') break;
        }

        *result = *next;

        if (*next == '\0') break;

        prev = *result == CHAR_SPACE;
    }

    if (*(result - 1) == CHAR_SPACE) {
        result--;
        *result = '\0';
    }

    result = realloc(*string, sizeof(char) * ((u32) (result - *string) / sizeof(char) + 1));

    temp = result;

    if (result == NULL) {
        return NULL;
    }

    *string = result;

    return temp;
}

inline str vstr_ntrim(cstr string) {
    cstr back = NULL;
    cstr start;

    for (; *string == CHAR_SPACE; ++string);

    start = string;

    for (; *string != '\0'; ++string) {
        if (*string != CHAR_SPACE) {
            back = string;
        }
    }

    if (back == NULL) {
        str result = malloc(sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    str result = malloc(sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    return result;
}

inline str vstr_ntrim_f(cstr string) {
    cstr back = NULL;
    cstr start;

    for (; *string == CHAR_SPACE; ++string);
    start = string;

    for (; *string != '\0'; ++string);
    back = string - 1;

    if (back == NULL) {
        str result = malloc(sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    str result = malloc(sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    return result;
}

inline str vstr_ntrim_b(cstr string) {
    cstr back = NULL;
    cstr start = string;

    for (; *string != '\0'; ++string) {
        if (*string != CHAR_SPACE) {
            back = string;
        }
    }

    if (back == NULL) {
        str result = malloc(sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *result = '\0';

        return result;
    }

    u32 len = (u32) (back - start) / sizeof(char) + 1;

    str result = malloc(sizeof(char) * (len + 1));

    if (result == NULL) {
        return NULL;
    }

    str front = result;

    for (u32 temp_len = len; temp_len > 0; ++start, ++front, temp_len--) {
        *front = *start;
    }

    *front = '\0';

    return result;
}

inline str vstr_ntrim_a(cstr string) {
    str result = (str) string;

    cstr next = string;
    u32 length = 0;
    u32 found = 0;

    if (*result == CHAR_SPACE) {
        found++;
    }

    bool prev = false;

    for (; *result != '\0'; ++result, length++) {
        if (*result == CHAR_SPACE) {
            if (prev) {
                found++;
            }
        }

        prev = *result == CHAR_SPACE;
    }

    if (found == length) {
        result = malloc(sizeof(char) * 1);

        if (result == NULL) {
            return NULL;
        }

        *result = '\0';

        return result;
    }

    if (length > 1 && *(result - 1) == CHAR_SPACE) {
        found++;
    }

    result = malloc(sizeof(char) * (length + 1 - found));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;
    bool first = true;

    for (; *next != '\0'; ++result, ++next) {
        if (first || *next == CHAR_SPACE && *(next + 1) == CHAR_SPACE) {
            u32 spaces = 0;

            while (*next == CHAR_SPACE) {
                next++;
                spaces++;
                if (*next == '\0') { break; }
            }

            if (first) {
                first = false;
            } else if (spaces > 1) {
                next--;
            }
        }

        *result = *next;
    }

    if (*(result - 1) == CHAR_SPACE) {
        result--;
    }

    *result = '\0';

    return temp;
}

// Inserting Characters into Strings

inline str vstr_insert_xs(str* dest, u32 index, cstr src) {
    u32 dest_len = vstr_len(*dest);

    if (index > dest_len) {
        return NULL;
    }

    u32 src_len = vstr_len(src);

    str result = realloc(*dest, sizeof(char) * (dest_len + 1 + src_len));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    str front = result + dest_len;
    str back = result + dest_len + src_len;

    for (u32 i = dest_len + 1; i > index; --front, --back, i--) {
        *back = *front;
    }

    result += index;

    for (; *src != '\0'; ++result, ++src) {
        *result = *src;
    }

    return temp;
}

inline str vstr_ninsert_xs(str string, u32 index, cstr src) {
    u32 dest_len = vstr_len(string);

    if (index > dest_len) {
        return NULL;
    }

    u32 src_len = vstr_len(src);

    str result = malloc(sizeof(char) * (dest_len + 1 + src_len));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    str front = string + dest_len;
    str back = result + dest_len + src_len;

    for (u32 i = dest_len + 1; i > index; --front, --back, i--) {
        *back = *front;
    }

    for (u32 i = 0; i < index; ++result, ++string, i++) {
        *result = *string;
    }

    for (; *src != '\0'; ++result, ++src) {
        *result = *src;
    }

    return temp;
}

inline str vstr_insert_xc(str* dest, u32 index, char character) {
    if (index == 0) {
        return vstr_push_fc(dest, character);
    }

    u32 dest_len = vstr_len(*dest);

    if (index == dest_len) {
        str result = realloc(*dest, sizeof(char) * (dest_len + 1 + 1));

        if (result == NULL) {
            return NULL;
        }

        *dest = result;

        str temp = result;

        result += dest_len;
        *result = character;
        result++;
        *result = '\0';

        return temp;
    } else if (index > dest_len) {
        return NULL;
    }

    str result = realloc(*dest, sizeof(char) * (dest_len + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    *dest = result;

    str temp = result;

    str char_pos = NULL;

    result[dest_len + 1] = '\0';
    result += index;
    char_pos = result;

    char last_char;
    char next_char = *result;

    while (*result != '\0') {
        last_char = next_char;
        result++;
        next_char = *result;
        *result = last_char;
    }

    *char_pos = character;

    return temp;
}

inline str vstr_ninsert_xc(str dest, u32 index, char character) {
    if (index == 0) {
        return vstr_pushn_fc(dest, character);
    }

    u32 dest_len = vstr_len(dest);

    if (index == dest_len) {
        str result = malloc(sizeof(char) * (dest_len + 1 + 1));

        if (result == NULL) {
            return NULL;
        }

        str temp = result;

        while ((*result++ = *dest++) != '\0');
        *result = '\0';
        result--;
        *result = character;

        return temp;
    } else if (index > dest_len) {
        return NULL;
    }

    str result = malloc(sizeof(char) * (dest_len + 1 + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    str char_pos = NULL;
    u32 i = 0;

    while ((*result++ = *dest++) != '\0') {
        i++;

        if (i == index) {
            char_pos = result;
            result++;
        }
    }

    *char_pos = character;

    return temp;
}

// Uppercase / Lowercase

inline str vstr_upper(str string) {
    str temp = string;

    for (; *string != '\0'; ++string) {
        if (*string >= CHAR_LOWERCASE_A && *string <= CHAR_LOWERCASE_Z) {
            *string -= CHAR_CASE_DIFF;
        }
    }

    return temp;
}

inline str vstr_upper_f(str string) {
    str temp = string;
    bool prev_space = true;

    for (; *string != '\0'; ++string) {
        if (prev_space && *string >= CHAR_LOWERCASE_A && *string <= CHAR_LOWERCASE_Z) {
            *string -= CHAR_CASE_DIFF;
        }

        prev_space = *string == CHAR_SPACE;
    }

    return temp;
}

inline str vstr_nupper(str string) {
    u32 length = vstr_len(string);
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; *string != '\0'; ++string) {
        if (*string >= CHAR_LOWERCASE_A && *string <= CHAR_LOWERCASE_Z) {
            *temp = (char) (*string - CHAR_CASE_DIFF);
        } else {
            *temp = *string;
        }

        temp++;
    }

    *temp = '\0';

    return result;
}

inline str vstr_nupper_f(str string) {
    u32 length = vstr_len(string);
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    bool prev_space = true;

    for (; *string != '\0'; ++string) {
        if (prev_space && *string >= CHAR_LOWERCASE_A && *string <= CHAR_LOWERCASE_Z) {
            *temp = (char) (*string - CHAR_CASE_DIFF);
        } else {
            *temp = *string;
        }

        temp++;
        prev_space = *string == CHAR_SPACE;
    }

    *temp = '\0';

    return result;
}

inline str vstr_lower(str string) {
    str temp = string;

    for (; *string != '\0'; ++string) {
        if (*string >= CHAR_UPPERCASE_A && *string <= CHAR_UPPERCASE_Z) {
            *string += CHAR_CASE_DIFF;
        }
    }

    return temp;
}

inline str vstr_nlower(str string) {
    u32 length = vstr_len(string);
    str result = malloc(sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    str temp = result;

    for (; *string != '\0'; ++string) {
        if (*string >= CHAR_UPPERCASE_A && *string <= CHAR_UPPERCASE_Z) {
            *temp = (char) (*string + CHAR_CASE_DIFF);
        } else {
            *temp = *string;
        }

        temp++;
    }

    *temp = '\0';

    return result;
}

// Shortcuts to Last Element of String

inline char vstr_back(str string) {
    if (*string == '\0') return '\0';
    while (*string != '\0') string++;
    return *(string - 1);
}

inline str vstr_rback(str string) {
    if (*string == '\0') return NULL;
    while (*string != '\0') string++;
    return string - 1;
}

// String to Number

inline bool vstr_to_bool(cstr string) {
    return char_lower(string[0]) == 't' && char_lower(string[1]) == 'r' && char_lower(string[2]) == 'u' && char_lower(string[3]) == 'e';
}

inline s8 vstr_to_s8(cstr string) {
    s8 result = 0;
    bool neg = *string == '-';

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = (s8) (result * 10 + (s8) ((*string++) - CHAR_NUM_0));
    }

    return (s8) (neg ? -result : result);
}

inline u8 vstr_to_u8(cstr string) {
    u8 result = 0;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u8) ((*string++) - CHAR_NUM_0);
    }

    return result;
}

inline s16 vstr_to_s16(cstr string) {
    s16 result = 0;
    bool neg = *string == '-';

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = (s16) (result * 10 + (s16) ((*string++) - CHAR_NUM_0));
    }

    return (s16) (neg ? -result : result);
}

inline u16 vstr_to_u16(cstr string) {
    u16 result = 0;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u16) ((*string++) - CHAR_NUM_0);
    }

    return result;
}

inline s32 vstr_to_s32(cstr string) {
    s32 result = 0;
    bool neg = *string == '-';

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (s32) ((*string++) - CHAR_NUM_0);
    }

    return neg ? -result : result;
}

inline u32 vstr_to_u32(cstr string) {
    u32 result = 0;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u32) ((*string++) - CHAR_NUM_0);
    }

    return result;
}

inline s64 vstr_to_s64(cstr string) {
    s64 result = 0;
    bool neg = *string == '-';

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (s64) ((*string++) - CHAR_NUM_0);
    }

    return neg ? -result : result;
}

inline u64 vstr_to_u64(cstr string) {
    u64 result = 0;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u64) ((*string++) - CHAR_NUM_0);
    }

    return result;
}

inline f32 vstr_to_f32(cstr string) {
    u32 res = 0;
    u32 length = 4;

    cstr temp = string;

    for (; length > 0 && *temp != '\0'; ++temp, length--, res++);

    if (length == 1 && res == 3) {
        if (char_lower(string[0]) == 'i' && char_lower(string[1]) == 'n' && char_lower(string[2]) == 'f') {
            return INF;
        } else if (char_lower(string[0]) == 'n' && char_lower(string[1]) == 'a' && char_lower(string[2]) == 'n') {
            return NAN;
        }
    } else if (res >= 4 && char_lower(string[1]) == 'i' && char_lower(string[2]) == 'n' && char_lower(string[3]) == 'f') {
        if (char_lower(string[0]) == '+') {
            return INF;
        } else if (char_lower(string[0]) == '-') {
            return -INF;
        } else {
            return NAN;
        }
    }

    if (*string == '\0' || *string < CHAR_NUM_0 || *string > CHAR_NUM_9) {
        return NAN;
    }

    bool neg = *string == '-';

    u64 result = 0;
    f32 floating = 0.0F;

    s32 place = 1;

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u64) ((*string++) - CHAR_NUM_0);
    }

    string++;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9 && place < FLOAT_PRECISION_MAX) {
        floating += f32_pow10(-place) * (f32) ((*string++) - CHAR_NUM_0);
        place++;
    }

    floating = (f32) result + floating;

    return neg && floating != 0.0F ? -floating : floating;
}

inline f64 vstr_to_f64(cstr string) {
    u32 res = 0;
    u32 length = 4;

    cstr temp = string;

    for (; length > 0 && *temp != '\0'; ++temp, length--, res++);

    if (length == 1 && res == 3) {
        if (char_lower(string[0]) == 'i' && char_lower(string[1]) == 'n' && char_lower(string[2]) == 'f') {
            return INF;
        } else if (char_lower(string[0]) == 'n' && char_lower(string[1]) == 'a' && char_lower(string[2]) == 'n') {
            return NAN;
        }
    } else if (res >= 4 && char_lower(string[1]) == 'i' && char_lower(string[2]) == 'n' && char_lower(string[3]) == 'f') {
        if (char_lower(string[0]) == '+') {
            return INF;
        } else if (char_lower(string[0]) == '-') {
            return -INF;
        } else {
            return NAN;
        }
    }

    if (*string == '\0' || *string < CHAR_NUM_0 || *string > CHAR_NUM_9) {
        return NAN;
    }

    bool neg = *string == '-';

    u64 result = 0;
    f64 floating = 0.0;

    s32 place = 1;

    if (neg) {
        string++;
    }

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9) {
        result = result * 10 + (u64) ((*string++) - CHAR_NUM_0);
    }

    string++;

    while (*string >= CHAR_NUM_0 && *string <= CHAR_NUM_9 && place < DOUBLE_PRECISION_MAX) {
        floating += f64_pow10(-place) * (f64) ((*string++) - CHAR_NUM_0);
        place++;
    }

    floating = (f64) result + floating;

    return neg && floating != 0.0 ? -floating : floating;
}

// Format Function

inline str vstr_from_format(cstr format, ...);

// Other Functions

inline str vstr_reverse(str string) {
    if (*string == '\0') {
        return string;
    }

    str end = string;
    str temp = string;

    char prev;

    for (; *end != '\0'; ++end);
    end--;

    while (string < end) {
        prev = *string;
        *string++ = *end;
        *end-- = prev;
    }

    return temp;
}

inline u32 vstr_levenshtein(cstr string1, cstr string2) {
    if (vstr_equ(string1, string2)) {
        return 0;
    }

    u32 length1 = vstr_len(string1);
    u32 length2 = vstr_len(string2);

    if (length1 == 0) {
        return length2;
    } else if (length2 == 0) {
        return length1;
    }

    u32 *cache = calloc(length1, sizeof(u32));

    u32 i1 = 0;
    u32 i2 = 0;

    u32 dist1;
    u32 dist2;

    u32 result;

    while (i1 < length1) {
        cache[i1] = i1 + 1;
        i1++;
    }

    while (i2 < length2) {
        char character = string2[i2];
        result = dist1 = i2++;

        i1 = U32_MAX;

        while (++i1 < length1) {
            dist2 = character == string1[i1] ? dist1 : dist1 + 1;
            dist1 = cache[i1];

            result = dist1 > result ? (dist2 > result ? result + 1 : dist2) : (dist2 > dist1 ? dist1 + 1 : dist2);
            cache[i1] = result;
        }
    }

    free(cache);

    return result;
}

inline void vstr_free(str string) {
    free(string);
}

// Char Functions

inline bool char_is_upper(char character) {
    return character >= CHAR_UPPERCASE_A && character <= CHAR_UPPERCASE_Z;
}

inline bool char_is_lower(char character) {
    return character >= CHAR_LOWERCASE_A && character <= CHAR_LOWERCASE_Z;
}

inline bool char_is_num(char character) {
    return character >= CHAR_NUM_0 && character <= CHAR_NUM_9;
}

inline char char_upper(char character) {
    if (char_is_lower(character)) {
        return (char) (character - CHAR_CASE_DIFF);
    } else {
        return character;
    }
}

inline char char_lower(char character) {
    if (char_is_upper(character)) {
        return (char) (character + CHAR_CASE_DIFF);
    } else {
        return character;
    }
}

inline char char_to_num(char character) {
    if (char_is_num(character)) {
        return (char) (character - CHAR_NUM_0);
    } else {
        return CHAR_NULL;
    }
}

#endif