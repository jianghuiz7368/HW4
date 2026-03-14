//Name: Jiang Hui Zheng
//ID: 116588223
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int strgLen(const char *s) {
    (void)s;
    
    /* TODO */
    if(s == NULL) return -1;
    const char *p = s;

    while(*p != '\0'){
        p++;
    }
    return (p - s);
    
    
    
}

void strgCopy(const char *source, char *destination, size_t size) {
    (void)source;
    (void)destination;
    (void)size;
    /* TODO */
    if(size == 0){
        return;
    }
    size_t count = 0;
    while(source[count] != '\0' && count < (size-1)){
        destination[count] = source[count];
        count++;
    }
    destination[count] = '\0';
    


}

void strgChangeCase(char *s) {
    (void)s;
    /* TODO */

    if(s == NULL) {
        return;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            int digitNeighbor = 0;

            if (digitNeighbor == 0) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - 32; 
                } else if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] + 32; 
                }
            }
        }
    }
}


int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;
    /* TODO */

    if(s1 == NULL || s2 == NULL) {
        return -1;
    }

    int i = 0;
    while(s1[i] == s2[i]){
        if(s1[i] == '\0'){
            return -1;

        }
        i++;
    }
    return i;
}

void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
    /* TODO */


    int length1 = strgLen(s1);
    int length2 = strgLen(s2);
    size_t index = 0;

    for(int i = 0; i < length1 || i < length2; i++){
        if(i < length1 && index < size - 1){
            d[index++] = s1[i];
        }
        if(i < length2 && index < size - 1){
            d[index++] = s2[i];
        }
    }
    
    d[index] = '\0';
}

void strgReverseLetters(char *s) {
    (void)s;
    /* TODO */
    if(s == NULL) return;
    
    int left = 0;
    int right = 0;

    while(s[right] != '\0'){
        right++;
    }
    right--;
    
    while(left < right){
        int leftIsLetter = 0;
        int rightIsLetter = 0;

        if(s[left] >= 'A' && s[left] <= 'Z'){
            leftIsLetter = 1;
        }
        else if(s[left] >= 'a' && s[left] <= 'z'){
            leftIsLetter = 1;
        }
        if(s[right] >= 'A' && s[right] <= 'Z'){
            rightIsLetter = 1;
        }
        else if(s[right] >= 'a' && s[right] <= 'z'){
            rightIsLetter = 1;
        }

        if(leftIsLetter == 0) {
            left++;
        }
        else if(rightIsLetter == 0){
            right--;
        }
        else{
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }

    }
}
