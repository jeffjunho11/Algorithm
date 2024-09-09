#include<stdio.h>
#define E 15
#define S 28
#define M 19

int main(void)
{
    int e, s, m;
    int i = 0;
    int n = 100;
    scanf("%d %d %d", &e, &s, &m);
    while(1)
    {
        for(int j=0; (E * j + e)<= (S * i + s); j++)
        {
            if((S * i + s) == (E * j + e))
            {
                for(int k=0; (M * k + m) <= (E * j + e); k++)
                {
                    if(S * i + s  == M * k + m)
                    {
                        int res = S * i + s;
                        printf("%d\n", res);
                        return (0);
                    }
                }
            }
        }
        i++;
    }
    return (0);
}