#include <stdio.h>

int main() {
    int numberOfDay = 1;

    for (int x = 1; x <= 31; x++) {
        printf("Number %d ", x);

        switch (numberOfDay) {
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
            case 0:
                printf("Sunday\n");
                break;
        }

        numberOfDay = (numberOfDay % 7) + 1;  
    }

    return 0;
}
