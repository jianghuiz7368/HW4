//Name: Jiang Hui Zheng
//ID: 116588223
#include <criterion/criterion.h>
#include "../strgPtr.h"

Test(strgLen, basic) {
    cr_expect_eq(strgLen("Stony Brook"), 11);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, test1) {
    cr_expect_eq(strgLen("abc 123"), 7);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, test_space) {
    cr_expect_eq(strgLen("Stony Brook"), 11);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, one_char) {
    cr_expect_eq(strgLen("a"), 1);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, one_num) {
    cr_expect_eq(strgLen("6"), 1);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, empty_string) {
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, null_string) {
    cr_expect_eq(strgLen(NULL), -1);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, long_string) {
    cr_expect_eq(strgLen("abcdefghijklmnopqrstuvwxyz"), 26);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, spaces_only) {
    cr_expect_eq(strgLen("      "), 6);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, special_characters) {
    cr_expect_eq(strgLen("!@#$)^&*()"), 10);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, mixed) {
    cr_expect_eq(strgLen("1ab&8"), 5);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}

Test(strgCopy, truncation) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_expect_str_eq(d, "Comp");
}
Test(strgCopy, test1) {
    char d[5];
    strgCopy("hi", d, 5);
    cr_expect_str_eq(d, "hi");
}
Test(strgCopy, empty_source) {
    char d[5];
    strgCopy("", d, 5);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, size_zero) {
    char d[5];
    strgCopy("Computer Science", d, 0);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, size_one) {
    char d[5];
    strgCopy("Computer Science", d, 1);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, number) {
    char d[5];
    strgCopy("1234567890", d, 5);
    cr_expect_str_eq(d, "1234");
}
Test(strgCopy, special_characters) {
    char d[10];
    strgCopy("!!!@@@^", d, 8);
    cr_expect_str_eq(d, "!!!@@@^");
}
Test(strgCopy, mixed) {
    char d[10];
    strgCopy("a1b2c3d4e5", d, 10);
    cr_expect_str_eq(d, "a1b2c3d4e");
} 
Test(strgCopy, long_string) {
    char d[26];
    strgCopy("abcdefghijklmnopqrstuvwxyz", d, 27);
    cr_expect_str_eq(d, "abcdefghijklmnopqrstuvwxyz");
} 
Test(strgCopy, different_size) {
    char d[10];
    strgCopy("Hello, World!", d, 10);
    cr_expect_str_eq(d, "Hello, Wo");
} 
Test(strgCopy, exact_size) {
    char d[14];
    strgCopy("Hello, World!", d, 14);
    cr_expect_str_eq(d, "Hello, World!");
    
} 



Test(strgChangeCase, adjacency) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s, "sTONY bROOK");
}
Test(strgChangeCase, test1) {
    char s[] = "a1B2c3D4";
    strgChangeCase(s);
    cr_expect_str_eq(s, "A1b2C3d4");
}
Test(strgChangeCase, empty) {
    char s[] = "";
    strgChangeCase(s);
    cr_expect_str_eq(s, "");
}
Test(strgChangeCase, no_letters) {
    char s[] = "1234!@#$";
    strgChangeCase(s);
    cr_expect_str_eq(s, "1234!@#$");
}
Test(strgChangeCase, all_upper) {
    char s[] = "HELLO";
    strgChangeCase(s);
    cr_expect_str_eq(s, "hello");
}
Test(strgChangeCase, all_lower) {
    char s[] = "eeeee";
    strgChangeCase(s);
    cr_expect_str_eq(s, "EEEEE");
}
Test(strgChangeCase, mixed) {
    char s[] = "@@#$abC123";
    strgChangeCase(s);
    cr_expect_str_eq(s, "@@#$ABc123");
    
}
Test(strgChangeCase, letters_only) {
    char s[] = "AbCdEfG";
    strgChangeCase(s);
    cr_expect_str_eq(s, "aBcDeFg");
}
Test(strgChangeCase, Null) {
    strgChangeCase(NULL);
    cr_expect(1);
}
Test(strgChangeCase, spaces) {
    char s[] = "   a b c   ";
    strgChangeCase(s);
    cr_expect_str_eq(s, "   A B C   ");
}
Test(strgChangeCase, characters_only) {
    char s[] = "$$$$$$!!";
    strgChangeCase(s);
    cr_expect_str_eq(s, "$$$$$$!!");
}



Test(strgDiff, identical) {
    cr_expect_eq(strgDiff("yo", "yo"), -1);
}
Test(strgDiff, first_char_diff) {
    cr_expect_eq(strgDiff("66abc", "76abc"), 0);
}
Test(strgDiff, last_char_diff) {
    cr_expect_eq(strgDiff("yes", "yez"), 2);
}
Test(strgDiff, case_sensitive) {
    cr_expect_eq(strgDiff("Jack", "jack"), 0);
}
Test(strgDiff, s1_shorter) {
    cr_expect_eq(strgDiff("cat", "cats"), 3);
}
Test(strgDiff, s2_shorter) {
    cr_expect_eq(strgDiff("stones", "stone"), 5);
}
Test(strgDiff, empty_strings) {
    cr_expect_eq(strgDiff("", ""), -1);
}
Test(strgDiff, one_empty) {
    cr_expect_eq(strgDiff("", "nonempty"), 0);
    cr_expect_eq(strgDiff("nonempty", ""), 0);
}
Test(strgDiff, null_strings) {
    cr_expect_eq(strgDiff(NULL, NULL), -1);
}
Test(strgDiff, one_null) {
    cr_expect_eq(strgDiff(NULL, "nonempty"), -1);
}
Test(strgDiff, different_lengths) {
    cr_expect_eq(strgDiff("abc", "abcd"), 3);
}




Test(strgInterleave, priority) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}
Test(strgInterleave, test1) {
    char d[10];
    strgInterleave("heyyo", "hello", d, 10);
    cr_expect_str_eq(d, "hheeylylo");
}
Test(strgInterleave, empty_s1) {
    char d[10];
    strgInterleave("", "br", d, 10);
    cr_expect_str_eq(d, "br");
}
Test(strgInterleave, empty_s2) {
    char d[10];
    strgInterleave("yo", "", d, 10);
    cr_expect_str_eq(d, "yo");
}
Test(strgInterleave, both_empty) {
    char d[10];
    strgInterleave("", "", d, 10);
    cr_expect_str_eq(d, "");
}
Test(strgInterleave, size_one) {
    char d[10];
    strgInterleave("abc", "def", d, 1);
    cr_expect_str_eq(d, "");
}
Test(strgInterleave, one_empty) {
    char d[10];
    strgInterleave("abc", "", d, 10);
    cr_expect_str_eq(d, "abc");
}
Test(strgInterleave, mixed) {
    char d[20];
    strgInterleave("12345", "abcde", d, 20);
    cr_expect_str_eq(d, "1a2b3c4d5e");
}
Test(strgInterleave, exact_size) {
    char d[11];
    strgInterleave("abcde", "12345", d, 11);
    cr_expect_str_eq(d, "a1b2c3d4e5");
}
Test(strgInterleave, different_size) {
    char d[6];
    strgInterleave("abcdef", "123456", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}
Test(strgInterleave, numbera) {
    char d[10];
    strgInterleave("123", "456", d, 10);
    cr_expect_str_eq(d, "142536");
}


Test(strgReverseLetters, reverse){
    char s1[] = "yo";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "oy");
}
Test(strgReverseLetters, characters){
    char s1[] = "ee-cd";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "dc-ee");
}
Test(strgReverseLetters, numbers){
    char s1[] = "12abc";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "12cba");
}
Test(strgReverseLetters, empty){
    char s1[] = "";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "");
}
Test(strgReverseLetters, no_letters){
    char s1[] = "1234!!!@";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "1234!!!@");
}
Test(strgReverseLetters, all_letters){
    char s1[] = "abcdef";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "fedcba");
}
Test(strgReverseLetters, mixed){
    char s1[] = "1e2c4b3a5";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "1a2b4c3e5");
}
Test(strgReverseLetters, spaces){
    char s1[] = "a b c d e";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "e d c b a");
}
Test(strgReverseLetters, null){
    strgReverseLetters(NULL);
    cr_expect(1);
}
Test(strgReverseLetters, special_characters){
    char s1[] = "$$$###";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "$$$###");
}
Test(strgReverseLetters, one_letter){
    char s1[] = "a";
    strgReverseLetters(s1);
    cr_expect_str_eq(s1, "a");
}



