//Name: Jiang Hui Zheng
//ID: 116588223
#include <criterion/criterion.h>
#include "../cse_caesar.h"

Test(encryptCaesar, basic) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("abc", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "ceg__EOM__");
}
Test(encryptCaesar, digit_shift) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("12", buf, 2);
    cr_expect_eq(r, 2);
    cr_expect_str_eq(buf, "36__EOM__");
}
Test(encryptCaesar, null_pointers) {
    int r = encryptCaesar(NULL, NULL, 5);
    cr_expect_eq(r, -2);
}
Test(encryptCaesar, small_buffer) {
    char buf[10] = "abc";
    int r = encryptCaesar("Hi", buf, 1);
    cr_expect_eq(r, -1);
}
Test(encryptCaesar, digit_math) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    encryptCaesar("9", buf, 3);
    cr_expect_str_eq(buf, "2__EOM__");
}
Test(encryptCaesar, mixed) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("Cse220", buf, 1);
    cr_expect_eq(r,6);
    cr_expect_str_eq(buf, "Duh911__EOM__");
}




Test(decryptCaesar, basic) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("ceg__EOM__", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "abc");
}
Test(decryptCaesar, test_null) {
    int r = decryptCaesar(NULL, NULL, 0);
    cr_expect_eq(r, -2);
    
}
Test(decryptCaesar, empty) {
    char buf[32] = "";
    int r = decryptCaesar("__EOM__", buf, 1);
    cr_expect_eq(r, 0);
}
Test(decryptCaesar, missing_eom) {
    char buf[10] = "123";
    int r = decryptCaesar("Input", buf, 1);
    cr_expect_eq(r, -1);
    cr_expect_str_eq(buf, "123");
}
Test(decryptCaesar, only_eom) {
    char buf[32] = "xxxxxxxx";
    decryptCaesar("B__EOM__", buf, 2);
    cr_expect_str_eq(buf, "Z");
}
Test(decryptCaesar, mixed) {
    char buf[32] = "";
    int r = decryptCaesar("Duh911__EOM__", buf, 1);
    cr_expect_eq(r,6);
    cr_expect_str_eq(buf, "Cse220");
}


