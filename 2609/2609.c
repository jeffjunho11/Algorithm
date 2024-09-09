#include <stdio.h>

void    gcd(int n, int m)
{
    while(n != m)
    {
        if(n > m)
        {
            n = n - m;
        }
        else
        {
            m = m - n;
        }
    }
    printf("%d\n", n);
    return ;
}

void    lcd(int n, int m)
{
    if(n < m)
    {
        for(int i=1; i<=n; i++)
        {
            if(m * i % n == 0)
            {
                printf("%d\n", m * i);
                return ;
            }
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(n * i % m == 0)
            {
                printf("%d\n", n * i);
                return ;
            }
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    gcd(n,m);
    lcd(n,m);
    return (0);
}