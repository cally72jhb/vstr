# vstr - vector string
simple dynamic strings for c<br/>
The library can be used header-only by moving `vstr.h` to a directory in your program.<br/>
<br/>
vstr contains just about all the functions you'll need.<br/>
In total there are 128 functions ranging from searching algorithmns to advanced formatting<br/>
to number/float to string conversation.

# creating new string
<pre>
str string = vstr_alloc("abc"); // new string from const char*
str string = vstr_alloc_len("abc", 3); // new string from const char* with length 3
str string = vstr_alloc_empty(); // new empty string
</pre>

# concatenating strings
<pre>
str string1 = vstr_alloc("abc"); // new string with content "abc" and length 3
str string2 = vstr_alloc("def"); // new string with content "def" and length 3

vstr_cat(&string1, string2); // @string1 needs to be passed as reference here

printf("%s\n", string1); // prints: "abcdef"
</pre>

# utility functions
<pre>
vstr_len(string) - returns the length of @string
vstr_equ(string1, string2) - returns true if @string1 and @string2 are identical
vstr_cont_s(string1, string2) - returns true if @string1 contains @string2

vstr_find_fs(string1, string2) - returns the index of the first occurence of @string2 in @string1
vstr_find_ls(string1, string2) - returns the index of the last occurence of @string2 in @string1

vstr_upper(string) - makes @string uppercase
vstr_lower(string) - makes @string lowercase
</pre>
