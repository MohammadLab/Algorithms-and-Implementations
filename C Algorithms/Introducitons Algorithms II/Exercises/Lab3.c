#include <stdio.h>

// char_caesar(*c, n) modifies the character pointed to by c by shifting it by a 
// given amount using the Caesar cipher technique.
// requires: *c is a letter (lowercase or uppercase), n is in the range of 0 to 25.
void char_caesar(char *c, int n) {
    if (*c >= 'A' && *c <= 'Z') {
        *c = ((*c - 'A' + n) % 26) + 'A';
    } else if (*c >= 'a' && *c <= 'z') {
        *c = ((*c - 'a' + n) % 26) + 'a'; 
    }
}

int main() {
    char c;
    int n;
    scanf("%c %d", &c, &n); 
    char_caesar(&c, n); 
    printf("%c\n", c); 
    return 0;
}