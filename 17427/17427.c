#include<stdio.h>

int main(void)
{
    long long n;
    long long sum = 0;

    scanf("%llu", &n);
    for(long long i = 1; i <= n; i++) 
    {
        sum += (n / i) * i; 
    }

    printf("%llu\n", sum);
    return 0;
}
