#ifndef VECTOR_STRING
#define VECTOR_STRING

// Includes

#include <stdarg.h>
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

#define min2(value1, value2) ((value1) < (value2) ? (value1) : (value2))
#define max2(value1, value2) ((value1) > (value2) ? (value1) : (value2))

#define min3(value1, value2, value3) min2(min2(value1, value2), value3)
#define max3(value1, value2, value3) max2(max2(value1, value2), value3)

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

#define F32_INF ((float) (HUGE_NUM * HUGE_NUM))
#define F64_INF ((double) (HUGE_NUM * HUGE_NUM))

#define F32_N_INF (-F32_INF)
#define F32_P_INF (+F32_INF)

#define F64_N_INF (-F64_INF)
#define F64_P_INF (+F64_INF)

// NAN (Not a Number)

#define F32_NAN (F32_INF * 0.0F)
#define F64_NAN (F64_INF * 0.0)

// User Defined Defines (you cannot change the length of the strings listed below)

#define FLOAT_PRECISION  (5) /* how many digits to print when printing floats */
#define DOUBLE_PRECISION (5) /* how many digits to print when printing doubles */

#define NEGATIVE_SIGN_CHARACTER ('-') /* the character that is placed in front of the "INF" when printing negative infinity */
#define POSITIVE_SIGN_CHARACTER ('+') /* the character that is placed in front of the "INF" when printing positive infinity */

#define NAN_NAME ("NaN") /* what to output when printing NAN (Not a Number) (string has to be 3 characters) */
#define INF_NAME ("INF") /* what to output when printing INF (Infinity +/-) (string has to be 3 characters) */

#define LOWERCASE_NAN_NAME ("nan") /* the lowercase of NAN_NAME (required to always be the same as NAN_NAME, but lowercase) */
#define LOWERCASE_INF_NAME ("inf") /* the lowercase of INF_NAME (required to always be the same as INF_NAME, but lowercase) */

#define INF_NAME_ALLOW_NO_SIGN 1 /* allows "INF" to be parsed as +INF (normally it would require "+INF") */
#define INF_NAME_INCLUDE_SIGN 1  /* writes +/- INF with their sign before the INF_NAME */

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

// Typedefs

typedef char* vstring;

typedef char* string;
typedef const char* cstring;

// Mathematical Functions

static const u64 vstring_pow10s[16]; // Powers of 10 (16 Elements)

f32 vstring_f32_pow10(s32 exp); // 10 to the Power of @exp & Return Result as f32
f64 vstring_f64_pow10(s32 exp); // 10 to the Power of @exp & Return Result as f64

// Dynamically Allocated String Functions [ return NULL/U32_MAX on fail/notfound ] ( in total 128 vstring_... functions )

// Allocating Strings

inline string vstring_alloc(cstring string); // Create new String with Unknown Length
inline string vstring_alloc_len(cstring string, u32 length); // Create new String with Length @length
inline string vstring_alloc_slen(cstring string, u32 length); // Create new String with Length of @string or @length depending on which of both is smaller
inline string vstring_alloc_empty(); // Create new Empty String with Length 0
inline string vstring_alloc_empty_len(u32 length); // Create new Empty String with Length @length

// Comparison & Length

inline u32 vstring_len(cstring string); // Return Length of @string
inline u32 vstring_lenx(cstring string, u32 length); // Return Length of @string or @length depending on what is smaller

inline bool vstring_equ(cstring string1, cstring string2); // Return true when both Strings are exactly equal [ string1 == string2 ]

inline bool vstring_is_empty(cstring string); // Return true when @string is empty

inline bool vstring_starts_with(cstring string1, cstring string2); // Return true when @string starts with @string2
inline bool vstring_starts_with_c(cstring string, char character); // Return true when @string starts with @character

inline bool vstring_ends_with(cstring string1, cstring string2); // Return true when @string ends with @string2
inline bool vstring_ends_with_c(cstring string, char character); // Return true when @string ends with @character

// String Setter

inline string vstring_setc(string string, char character); // Set all Characters of @string to @character
inline string vstring_setcx(string string, char character, u32 length); // Set all Characters from 0 to @length of @string to @character

inline string vstring_clear(string* string); // Clears @string [ returns string with length 0 || however result is already assigned to @string ]

inline string vstring_set(string dest, cstring src); // Set @dest to @src [assuming both strings are equal length]
inline string vstring_sset(string* dest, cstring src); // Set @dest to @src & Return new String Length
inline string vstring_setx(string dest, cstring src, u32 length); // Set @dest to the first @length characters of @src [assuming both strings are equal length or src is smaller]
inline string vstring_ssetx(string* dest, cstring src, u32 length); // Set @dest to the first @length characters of @src

// Concatenation & Push / Pop Chars

inline string vstring_cat(string* dest, string src); // Concat @dest with @src [ @dest + @src ]
inline string vstring_catn(string dest, string src); // Concat @dest with @src & Return new String [ @dest + @src ] [ catn = Concat String & Return new String ]

inline string vstring_push_fc(string* dest, char character); // Concat @src with @dest
inline string vstring_pushn_fc(string dest, char character); // Concat @src with @dest & Return new String
inline string vstring_push_bc(string* dest, char character); // Concat @dest with @src
inline string vstring_pushn_bc(string dest, char character); // Concat @dest with @src & Return new String

inline string vstring_pop_fc(string* string); // Remove First Char of @string [ pop_fc = Pop First Char ]
inline string vstring_popn_fc(string string); // Remove First Char of @string & Return new String [ popn_fc = Pop First Char & Return new String ]
inline string vstring_pop_bc(string* string); // Remove Last Char of @string [ pop_bc = Pop Back ]
inline string vstring_popn_bc(string string); // Remove Last Char of @string & Return new String [ popn_bc = Pop Back & Return new String ]

// Substring of Strings

inline string vstring_rsub(string string, u32 index); // Returns a Reference to the Element at @index of @string
inline string vstring_rssub(string string, u32 index); // Returns a Reference to the Element at @index of @string [ if @index > length of @string it will return the last element of @string ]

inline string vstring_sub(string* string, u32 length); // Substring of @string from 0 to @length
inline string vstring_subx(string* string, u32 start); // Substring of @string from @start to end of @string
inline string vstring_subxx(string* string, u32 start, u32 end); // Substring of @string from @start to @end
inline string vstring_subxn(string* string, u32 start, u32 length); // Substring of @string from @start to @start + @length

inline string vstring_nsub(string string, u32 length); // Substring of @string from 0 to @length & Return new String
inline string vstring_nsubx(string string, u32 start); // Substring of @string from @start to end of @string & Return new String
inline string vstring_nsubxx(string string, u32 start, u32 end); // Substring of @string from @start to @end & Return new String
inline string vstring_nsubxn(string string, u32 start, u32 length); // Substring of @string from @start to @start + @length & Return new String

// String Resize

inline string vstring_resize(string* string, u32 length); // Resize @string to @length
inline string vstring_fit(string* string); // Reallocate @string with its String Length
inline string vstring_grow(string* string, u32 elements); // Grow @string by @elements
inline string vstring_size(string* string, u32 length); // Reallocate @string to be @length long or its Original Length

// Finding & Replacing in Strings

inline u32 vstring_find_fs(cstring string1, cstring string2); // Find First Occurrence of @string2 in @string1 [ bfind_fs = Bruteforce Search Find First String ]
inline u32 vstring_find_ls(cstring string1, cstring string2); // Find Last Occurrence of @string2 in @string1 [ bfind_ls = Bruteforce Search Find Last String ]

inline string vstring_rfind_fs(cstring string1, cstring string2); // Find First Occurrence of @string2 in @string1 & Return Reference [ rfind_fs = Find First String & Return Reference ]
inline string vstring_rfind_ls(cstring string1, cstring string2); // Find Last Occurrence of @string2 in @string1 & Return Reference [ rfind_ls = Find Last String & Return Reference ]

inline bool vstring_cont_s(cstring string1, cstring string2); // Return true when @string1 contains @string2 [ bcont = Bruteforce Search Contains ]

inline string vstring_rep_fs(string* dest, cstring old, cstring new); // Replace First Occurrence of @old with @new in @dest [ fs = First String ]
inline string vstring_rep_ls(string* dest, cstring old, cstring new); // Replace Last Occurrence of @old with @new in @dest [ ls = Last String ]
inline string vstring_repn_fs(string string, cstring old, cstring new); // Replace First Occurrence of @old with @new in @string & Return new String [ fs = First String ]
inline string vstring_repn_ls(string string, cstring old, cstring new); // Replace Last Occurrence of @old with @new in @string & Return new String [ ls = Last String ]

// Finding & Replacing Characters

inline u32 vstring_find_fc(cstring string, char character); // Find First Occurrence of @character in @string [ fc = First Char ]
inline u32 vstring_find_lc(cstring string, char character); // Find Last Occurrence of @character in @string [ lc = Last Char ]

inline string vstring_rfind_fc(cstring string, char character); // Find First Occurrence of @character in @string & Return Reference [ rfind_fc = Find First Char & Return Reference ]
inline string vstring_rfind_lc(cstring string, char character); // Find Last Occurrence of @character in @string & Return Reference [ rfind_lc = Find Last Char & Return Reference ]

inline bool vstring_cont_c(string string, char character); // Return true when @string contains @character

inline string vstring_rep_fc(string string, char old, char new); // Replace First Occurrence of @old with @new in @string [ fc = First Char ]
inline string vstring_rep_lc(string string, char old, char new); // Replace Last Occurrence of @old with @new in @string [ lc = Last Char ]
inline string vstring_repn_fc(string string, char old, char new); // Replace First Occurrence of @old with @new in @string & Return new String [ fc = First Char ]
inline string vstring_repn_lc(string string, char old, char new); // Replace Last Occurrence of @old with @new in @string & Return new String [ lc = Last Char ]

inline string vstring_rep_ac(string string, char old, char new); // Replace All Occurrences of @old with @new in @string [ ac = All Chars ]
inline string vstring_repn_ac(string string, char old, char new); // Replace All Occurrences of @old with @new in @string & Return new String [ ac = All Chars ]

// Erasing Strings, Characters & Indexes

inline string vstring_erase_fs(string* dest, cstring src); // Erase First Occurrence of @src in @dest [ fs = First String ]
inline string vstring_erase_ls(string* dest, cstring src); // Erase Last Occurrence of @src in @dest [ ls = Last String ]

inline string vstring_erase_fc(string* dest, char character); // Erase First Occurrence of @character in @dest [ fc = First Char ]
inline string vstring_erase_lc(string* dest, char character); // Erase Last Occurrence of @character in @dest [ lc = Last Char ]
inline string vstring_erase_ac(string* dest, char character); // Erase All Occurrences of @character in @dest [ ac = All Chars ]

inline string vstring_nerase_fs(string string, cstring src); // Erase First Occurrence of @src in @string & Return new String [ fs = First String ]
inline string vstring_nerase_ls(string string, cstring src); // Erase Last Occurrence of @src in @string & Return new String [ ls = Last String ]

inline string vstring_nerase_fc(string string, char character); // Erase First Occurrence of @character in @string & Return new String [ fc = First Char ]
inline string vstring_nerase_lc(string string, char character); // Erase Last Occurrence of @character in @string & Return new String [ lc = Last Char ]
inline string vstring_nerase_ac(string string, char character); // Erase All Occurrences of @character in @string & Return new String [ ac = All Chars ]

inline string vstring_erase_x(string* dest, u32 index); // Erase Character at @index in @dest
inline string vstring_erase_xx(string* dest, u32 start, u32 end); // Erase everything from @start to @end in @dest
inline string vstring_erase_xn(string* dest, u32 start, u32 length); // Erase everything from @start to @start + @length in @dest

inline string vstring_nerase_x(string string, u32 index); // Erase Character at @index in @string & Return new String
inline string vstring_nerase_xx(string string, u32 start, u32 end); // Erase everything from @start to @end in @string & Return new String
inline string vstring_nerase_xn(string string, u32 start, u32 length); // Erase everything from @start to @start + @length in @string & Return new String

// Trimming Strings

inline string vstring_trim(string* string); // Erase All Whitespaces at the beginning and end of @string
inline string vstring_trim_f(string* string); // Erase All Whitespaces at the beginning @string
inline string vstring_trim_b(string* string); // Erase All Whitespaces at the end of @string
inline string vstring_trim_a(string* string); // Erase All Whitespaces in @string

inline string vstring_ntrim(cstring string); // Erase All Whitespaces at the beginning and end of @string & Return new String
inline string vstring_ntrim_f(cstring string); // Erase All Whitespaces at the beginning @string & Return new String
inline string vstring_ntrim_b(cstring string); // Erase All Whitespaces at the end of @string & Return new String
inline string vstring_ntrim_a(cstring string); // Erase All Whitespaces in @string & Return new String

// Inserting Characters into Strings

inline string vstring_insert_xs(string* dest, u32 index, cstring src); // Insert @src into @dest at @index
inline string vstring_ninsert_xs(string string, u32 index, cstring src); // Insert @src into @string at @index & Return new String

inline string vstring_insert_xc(string* dest, u32 index, char character); // Insert @character into @dest at @index
inline string vstring_ninsert_xc(string dest, u32 index, char character); // Insert @character into @dest at @index & Return new String

// Uppercase / Lowercase

inline string vstring_upper(string string); // Make @string Uppercase
inline string vstring_upper_f(string string); // Capitalize each Character in @string prefixed by a Space
inline string vstring_nupper(string string); // Make @string Uppercase & Return new String
inline string vstring_nupper_f(string string); // Capitalize each Character in @string prefixed by a Space & Return new String

inline string vstring_lower(string string); // Make @string Lowercase
inline string vstring_nlower(string string); // Make @string Lowercase & Return new String

// Shortcuts to Last Element of String

inline char vstring_back(string string); // Returns the last Character of the String
inline string vstring_rback(string string); // Returns a Pointer to the Last Element of the String

// String to Number

inline bool vstring_to_bool(cstring string); // Parse @string to a Boolean Value

inline s8 vstring_to_s8(cstring string); // Parse @string to a Signed Char Value
inline u8 vstring_to_u8(cstring string); // Parse @string to an Unsigned Char Value
inline s16 vstring_to_s16(cstring string); // Parse @string to a Signed Short Value
inline u16 vstring_to_u16(cstring string); // Parse @string to an Unsigned Short Value
inline s32 vstring_to_s32(cstring string); // Parse @string to a Signed Integer Value
inline u32 vstring_to_u32(cstring string); // Parse @string to an Unsigned Integer Value
inline s64 vstring_to_s64(cstring string); // Parse @string to a Signed Long-Long Value
inline u64 vstring_to_u64(cstring string); // Parse @string to an Unsigned Long-Long Value

inline f32 vstring_to_f32(cstring string); // Parse @string to a Float Value
inline f64 vstring_to_f64(cstring string); // Parse @string to a Double Value

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
 *     %05d  + 72.1       = "072.1"
 *     %.3d  + 72.1       = "72.1"
 *     %.3*d + 72.1       = "72.100"
 *
 *     %06h  + 92072      = "0167A8"
 *     %#h   + 92072      = "0x167A8"
 *     %#08h + 92072      = "0x000167A8"
 *
 *     %p    + null       = "null"
 *     %#p   + pointer    = "0x239DB326" (example address)
 *
 *     %b    + 1          = "00000001"
 *     %b    + 0b11000101 = "11000101"
 *     %#b   + 0b11000101 = "0b11000101"
 *     %#10b + 0b11000101 = "  0b11000101"
 * */

string vstring_from_format(cstring format, ...);

// Other Functions

inline string vstring_reverse(string string); // Reverse @string

inline u32 vstring_levenshtein(cstring string1, cstring string2); // Return Similarity of @string1 and @string2

inline void vstring_free(string string); // Free @string

// Dynamically Allocated String Function Defines

#define vstring_new()           vstring_alloc()
#define vstring_new_len()       vstring_alloc_len()
#define vstring_new_slen()      vstring_alloc_slen()
#define vstring_new_empty()     vstring_alloc_empty()
#define vstring_new_empty_len() vstring_alloc_empty_len()

#define vstring_length() vstring_len()

#define vstring_equals() vstring_equ()

#define vstring_append()     vstring_cat()
#define vstring_concat()     vstring_cat()
#define vstring_concat_new() vstring_catn()

#define vstring_set_char()  vstring_setc()
#define vstring_fill_char() vstring_setc()

#define vstring_push_front()  vstring_push_bc()
#define vstring_push_back()   vstring_push_bc()
#define vstring_pushn_front() vstring_pushn_bc()
#define vstring_pushn_back()  vstring_pushn_bc()

#define vstring_pop_front()  vstring_pop_bc()
#define vstring_pop_back()   vstring_pop_bc()
#define vstring_popn_front() vstring_popn_bc()
#define vstring_popn_back()  vstring_popn_bc()

#define vstring_substring() vstring_subxx()

#define vstring_contains() vstring_cont_s()
#define vstring_contains_s() vstring_cont_s()
#define vstring_contains_c() vstring_cont_c()

#define vstring_rep_char() vstring_rep_ac()

#define vstring_insert_string() vstring_insert_xs()
#define vstring_insert_char() vstring_insert_xc()
#define vstring_insert_s() vstring_insert_xs()
#define vstring_insert_c() vstring_insert_xc()

#define vstring_to_uppercase() vstring_upper()
#define vstring_to_lowercase() vstring_lower()
#define vstring_uppercase() vstring_upper()
#define vstring_lowercase() vstring_lower()

#define vstring_back_char() vstring_back()
#define vstring_ref_back() vstring_rback()
#define vstring_ref_back_char() vstring_rback()

#define vstring_format(format, ...) vstring_from_format(format, __VA_ARGS__)
#define vstring_frmt(format, ...) vstring_from_format(format, __VA_ARGS__)

#define vstring_rev() vstring_reverse()

#define vstring_comp_diff() vstring_levenshtein()
#define vstring_diff() vstring_levenshtein()
#define vstring_diff() vstring_levenshtein()

#define free_str() vstring_free()
#define free_string() vstring_free()

// Mathematical Functions

static const u64 vstring_pow10s[] = {
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

f32 vstring_f32_pow10(s32 exp) {
    f32 result = 1.0F;
    bool neg = false;

    if (exp < 0) {
        exp = -exp;
        neg = true;
    } else {
        neg = false;
    }

    while (exp > 15) {
        result *= (f32) vstring_pow10s[15];
        exp -= 15;
    }

    result *= (f32) vstring_pow10s[exp];

    return neg ? 1.0F / result : result;
}

f64 vstring_f64_pow10(s32 exp) {
    f64 result = 1.0;
    bool neg = false;

    if (exp < 0) {
        exp = -exp;
        neg = true;
    } else {
        neg = false;
    }

    while (exp > 15) {
        result *= (f64) vstring_pow10s[15];
        exp -= 15;
    }

    result *= (f64) vstring_pow10s[exp];

    return neg ? 1.0 / result : result;
}

// Dynamically Allocated String Functions

// Creating new Strings

inline string vstring_alloc(cstring string) {
    cstring org_string = string;
    cstring temp_string = string;

    for (; *temp_string != '\0'; ++temp_string);
    u32 length = (u32) (temp_string - org_string) / sizeof(char);

    vstring result = malloc(sizeof(u32) + sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = length;

    vstring string_start = (vstring) (result + sizeof(u32));
    vstring temp = string_start;

    while ((*string_start++ = *string++) != '\0');

    return temp;
}

inline string vstring_alloc_len(cstring string, u32 length) {
    vstring result = malloc(sizeof(u32) + sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = length;

    vstring string_start = (vstring) (result + sizeof(u32));
    vstring temp = string_start;

    u32 i = 0;
    while (i++ < length && (*string_start++ = *string++) != '\0');
    *string_start = '\0';

    return temp;
}

inline string vstring_alloc_slen(cstring string, u32 length) {
    cstring org_string = string;
    cstring temp_string = string;

    for (; *temp_string != '\0'; ++temp_string);
    u32 string_length = (u32) (temp_string - org_string) / sizeof(char);
    u32 result_len = min2(string_length, length);

    vstring result = malloc(sizeof(u32) + sizeof(char) * (result_len + 1));

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = result_len;

    vstring string_start = (vstring) (result + sizeof(u32));
    vstring temp = string_start;

    u32 i = 0;
    while (i++ < result_len && (*string_start++ = *string++) != '\0');
    *string_start = '\0';

    return temp;
}

inline string vstring_alloc_empty() {
    vstring result = malloc(sizeof(u32) + sizeof(char) * 1);

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = 0;

    vstring string_start = (vstring) (result + sizeof(u32));

    *string_start = '\0';

    return string_start;
}

inline string vstring_alloc_empty_len(u32 length) {
    vstring result = malloc(sizeof(u32) + sizeof(char) * (length + 1));

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = length;

    vstring string_start = (vstring) (result + sizeof(u32));

    string_start[length] = '\0';

    return string_start;
}

// Comparison & Length

inline u32 vstring_len(cstring string) {
    return *((u32*) (string - sizeof(u32)));
}

inline u32 vstring_lenx(cstring string, u32 length) {
    u32 string_length = *((u32*) (string - sizeof(u32)));
    return min2(string_length, length);
}

inline bool vstring_equ(cstring string1, cstring string2) {
    if (vstring_len(string1) != vstring_len(string2)) {
        return false;
    }

    do {
        if (*string1 == '\0') {
            return *string2 == '\0';
        } else if (*string2 == '\0') {
            return *string1 == '\0';
        }
    } while (*string1++ == *string2++);

    return false;
}

inline bool vstring_is_empty(cstring string) {
    return vstring_len(string) == 0;
}

inline bool vstring_starts_with(cstring string1, cstring string2) {
    if (vstring_len(string1) < vstring_len(string2)) {
        return false;
    }

    while (*string1 == *string2) {
        if (*string2 == '\0') {
            return true;
        }

        string1++;
        string2++;
    }

    return *string2 == '\0';
}

inline bool vstring_starts_with_c(cstring string, char character) {
    return character == '\0' || *string != '\0' && *string == character;
}

inline bool vstring_ends_with(cstring string1, cstring string2) {
    u32 len1 = vstring_len(string1);
    u32 len2 = vstring_len(string2);

    if (len1 < len2) {
        return false;
    }

    string1 += len1 - len2;

    while (*string1 == *string2) {
        if (*string2 == '\0') {
            return true;
        }

        string1++;
        string2++;
    }

    return *string2 == '\0';
}

inline bool vstring_ends_with_c(cstring string, char character) {
    u32 length = vstring_len(string);
    return character == '\0' || *(string + length - 1) == character;
}

// String Setter

inline vstring vstring_setc(vstring string, char character) {
    vstring temp = string;

    for (; *string != '\0'; ++string) {
        *string = character;
    }

    return temp;
}

inline vstring vstring_setcx(vstring string, char character, u32 length) {
    vstring temp = string;

    for (u32 i = 0; i++ < length && *string != '\0'; ++string) {
        *string = character;
    }

    return temp;
}

inline vstring vstring_clear(vstring* string) {
    vstring result = realloc((vstring) (*string - sizeof(u32)), sizeof(u32) + sizeof(char) * 1);

    if (result == NULL) {
        return NULL;
    }

    *((u32*) result) = 0;

    vstring string_start = (vstring) (result + sizeof(u32));

    *string = string_start;

    *string_start = '\0';

    return result;
}

#endif
