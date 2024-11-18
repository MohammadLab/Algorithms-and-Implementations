#include <stdio.h>

int shift_digits(int n) {
    
    if (n == 0) {
        return 1;
    } else {
        int digit = (n % 10 + 1) % 10;
        if (digit == 0){
            if (n/10 == 0){
                return 9;
            }
            return shift_digits(n / 10) * 10 + 9;
        }else if (n / 10 == 0) {
            return digit;  
        } else {
            return shift_digits(n / 10) * 10 + digit;
        }
    }
}

int main(void) {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", shift_digits(n));
}