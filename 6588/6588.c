#include<stdio.h>
#include<stdbool.h>
#define MAX 1000001

bool is_prime[MAX] = {0};

void prime_check()
{
    for(int i = 2; i * 2 <= MAX; i++)
    {
        for(int j = 2; j * i <= MAX; j++)
        {
            is_prime[i * j] = 1;
        }
    }
    return ;
}


int main(void)
{
    int n, m;

    prime_check();
    while(scanf("%d", &n) == 1)
    {
        for(int i=3; i<=n; i+=2)
        {
            m = n - i;
            if(is_prime[i] == 0 && is_prime[m] == 0)
            {
                printf("%d = %d + %d\n", n, i, m);
                break;
            }
        }
    }
    return (0);
}
