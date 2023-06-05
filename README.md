# vstr/vstring - vector string
simple dynamic strings for c<br/>
The library can be used header-only by moving `vstr.h` to a directory in your program.<br/>
<br/>
vstr contains just about all the functions you'll need.<br/>
In total there are 128 functions ranging from searching algorithms to advanced formatting<br/>
to number/float to string conversation.

## what is the difference between vstr and vstring?

vstr and vstring are separated by different files, but can be used together in one project.<br/>
vstr is designed like `c-strings` and is compatible with them. It does not store the length of the string and must<br/>
go through the entire string to determine it's length.<br/>
<br/>
```
+-------------------------------+------------------+
| String Data (built like vstr) | Null Termination |
+-------------------------------+------------------+
```

<br/>
vstring is a string of known length. The length is stored in the 4 bytes `int` before<br/>
the pointer that is returned to the user.<br/>
Since the length of the string is always known, vstring is faster than vstr, but requires more memory.<br/><br/>

```
+---------------+----------------------------------+------------------+
| String Length | String Data (designed like vstr) | Null Termination |
+---------------+----------------------------------+------------------+
                |
             pointer
```

## how to decide between vstr and vstring
To decide between vstr and vstring some things have to be considered:

| vstr                                                    | vstring                                                   |
|:--------------------------------------------------------|:----------------------------------------------------------|
| requires less memory                                    | requires more memory than vstr                            |
| has to query the whole string<br/>to obtain it's length | length is always known and can<br/> be accessed very fast |
| fast implementation                                     | takes time to implement                                   |
| made for small strings and few memory                   | made for big applications with long strings               |
<br/>
For fast implementation it's better to use vstr. For projects that work<br/>
with long strings, the speed of the application is better with vstring.

## creating new string
<pre>
str string = vstr_alloc("abc"); // new string from const char*
str string = vstr_alloc_len("abc", 3); // new string from const char* with length 3
str string = vstr_alloc_empty(); // new empty string
</pre>

## concatenating strings
<pre>
str string1 = vstr_alloc("abc"); // new string with content "abc" and length 3
str string2 = vstr_alloc("def"); // new string with content "def" and length 3

vstr_cat(&string1, string2); // @string1 needs to be passed as reference here

printf("%s\n", string1); // prints: "abcdef"
</pre>

## utility functions
<pre>
vstr_len(string) - returns the length of @string
vstr_equ(string1, string2) - returns true if @string1 and @string2 are identical
vstr_cont_s(string1, string2) - returns true if @string1 contains @string2

vstr_find_fs(string1, string2) - returns the index of the first occurence of @string2 in @string1
vstr_find_ls(string1, string2) - returns the index of the last occurence of @string2 in @string1

vstr_upper(string) - makes @string uppercase
vstr_lower(string) - makes @string lowercase
</pre>
