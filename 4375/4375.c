#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;

        long long number = 1;
        int digitCount = 1;
        while (number % n != 0) {
            number = number * 10 + 1;
            digitCount++;
            number = number % n; 
        }

        printf("%d\n", digitCount);
    }
    return 0;
}
