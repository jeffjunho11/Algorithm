#include<stdio.h>
#include<stdbool.h>
#define MAX 1000001

bool is_prime[MAX] = {0};

void prime_check()
{
    is_prime[1] = true;
    for(int i=2; i * 2 < MAX; i++)
    {
        for(int j=2; j * i < MAX; j++)
        {
            is_prime[i * j] = true;
        }
    }
}

int main(void)
{
    int flag;
    int m, n;
    scanf("%d %d", &m, &n);

    prime_check();
    for(int i=m; i<=n; i++)
    {
        if(is_prime[i] == false)
        {
            printf("%d\n", i);
        }
    }
    return (0);
}