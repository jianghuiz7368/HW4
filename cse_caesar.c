//Name: Jiang Hui Zheng
//ID: 116588223
#include "cse_caesar.h"
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    
    /* TODO */
    if(plaintext == NULL || ciphertext == NULL) return -2;

    int pLength = strgLen(plaintext);
    int cipherCapacity = strgLen(ciphertext);

    if(cipherCapacity < (pLength + 7)){
        return -1;
    }
    int i = 0;
    int count = 0;

    while(plaintext[i] != '\0'){
        char c = plaintext[i];
        

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            int s = ((key + i)%26 + 26) %26;

            if(c >= 'A' && c <= 'Z'){
                ciphertext[i] = ((c - 'A' + s)%26) + 'A';
            }
            else{
                ciphertext[i] = ((c - 'a' + s)%26) + 'a';
            }
            count++;
        }
            
        else if (c >= '0' && c <= '9'){
           int digit_s = ((key + 2 * i)% 10 + 10) %10;
           ciphertext[i] = ((c - '0' + digit_s) % 10) + '0';
           count++;
        }
        else{
            ciphertext[i] = c;
        }
        i++;
    }
    ciphertext[i++] = '_';
    ciphertext[i++] = '_';
    ciphertext[i++] = 'E';
    ciphertext[i++] = 'O';
    ciphertext[i++] = 'M';
    ciphertext[i++] = '_';
    ciphertext[i++] = '_';
    ciphertext[i++] = '\0';
    
    return count;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    
    /* TODO */


    if(ciphertext == NULL || plaintext == NULL) {
        return -2;
    }

    

    
    int indexEOM = -1;
    for(int i = 0; ciphertext[i] != '\0'; i++) {
        if(ciphertext[i] == '_' && ciphertext[i+1] == '_' 
            && ciphertext[i+2] == 'E' && ciphertext[i+3] == 'O' && 
            ciphertext[i+4] == 'M' && ciphertext[i+5] == '_' && 
            ciphertext[i+6] == '_')
            {
                indexEOM = i;
                break;
            }
    }
    if(indexEOM == -1){
        return -1;
    }

    int i = 0;
    int count = 0;
    // int plainCap = strgLen(plaintext);

    while (i < indexEOM){
        char c = ciphertext[i];

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            int s = ((key + i) % 26 + 26) %26;

            if(c >= 'A' && c <= 'Z'){
                plaintext[i] = ((c - 'A' - s) % 26 + 26) % 26 + 'A';
            }
            else{
                plaintext[i] = ((c - 'a' - s) %26 + 26) %26 + 'a';
            }
            count++;
        }
        else if(c >= '0' && c <= '9'){
            int digit_s = ((key + 2 * i) %10 + 10)%10;
            plaintext[i] = ((c - '0' - digit_s) % 10 + 10) % 10 + '0';
            count++;
        }
        else{
            plaintext[i] = c;
        }
        i++;
    }
    plaintext[i] = '\0';
    return count;
}
