

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
#define STND_CH 100

int func(int a, int b)
{
    if(b <= 0)
        return (1);
    return a * func(a, b - 1);
}

int main(void)
{
    int n, m;
    int min;
    int temp, cnt = 0;
    bool button[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    scanf("%d %d", &n, &m);
    if(m == 10)
    {
        printf("%d\n", abs(m - STND_CH));
        return(0);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", &temp);
        button[temp] = false;
    }
    min = abs(STND_CH - n);
    cnt = 0;
    int digit = 0;
    
    while(1)
    {
        temp = n % 10;
        if(n >= 10)
            n = n / 10;
        if(button[temp] == true)
            cnt++;
        else
        {
            for(int i = 1; i < MAX ; i++)
            {
                if(button[temp + i] == true && temp + i < MAX)
                {
                    cnt += (i * func(10, digit)) + 1;
                    break;
                }
                if(button[temp - i] == true && temp - i >= 0)
                {
                    cnt += (i * func(10, digit)) + 1;
                    break;
                }
            }
        }
        digit++;
        if(n < 10)
            break;
    }
    if(cnt < min)
        min = cnt;
    printf("%d\n", min);
    return (0);
}
