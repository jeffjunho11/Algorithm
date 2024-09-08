
#include<stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b)
{
    if(a > b) 
        return (a);
    return (b);
}

int check_max_candies(int n, char map[51][51])
{
    int cnt = 1;
    int max = 1;
    for(int i=0; i<n; i++)
    {
        cnt = 1;
        for(int j=1; j<n; j++)
        {
            if(map[i][j] == map[i][j - 1])
            {
                cnt++;
                if(max < cnt)
                    max = cnt;
            }
            else
            {
                cnt = 1;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cnt = 1;
        for(int j=1; j < n; j++)
        {
            if(map[j][i] == map[j - 1][i])
            {
                cnt++;
                if(max < cnt)
                    max = cnt;
            }
            else
            {
                cnt = 1;
            }
        }
    }
    return (max);
}

int change_candies(int n, char map[51][51])
{
    int maxCount = 0;
    for(int i=0; i<n; i++) // 가로
    {
        for(int j=0; j<n; j++)
        {
            if(j + 1 < n && map[i][j] != map[i][j + 1])
            {
                swap(&map[i][j], &map[i][j + 1]);
                maxCount = max(maxCount, check_max_candies(n, map));
                swap(&map[i][j + 1], &map[i][j]);
            }
            if(i + 1 < n && map[i][j] != map[i + 1][j])
            {
                swap(&map[i][j], &map[i + 1][j]);
                maxCount = max(maxCount, check_max_candies(n, map));
                swap(&map[i + 1][j], &map[i][j]);
            }
        }
    }
    return (maxCount);
}

int main(void)
{
    int n;
    char map[51][51];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }
    printf("%d\n", change_candies(n, map));
    return (0);
}



/*
#include<stdio.h>

void parseMap(int n, char map[51][51])
{
    for(int i=0; i<n; i++)
    {
        scanf("%s", map[i]);
    }
}

int dfs(int n, char map[51][51])
{
    int max = 0;
    int cnt = 1;
    int cnt2 = 1;
    int flag = 0;
    int flag2 = 0;
    for(int i = 0; i < n; i++)
    {
        cnt = 1;
        cnt2 = 1;
        flag = 0;
        flag2 = 0;
        for(int j = 1; j < n; j++)
        {
            if(map[j - 1][i] == map[j][i])
            {
                cnt2++;
                if(max < cnt2)
                    max = cnt2;
            }
            else
            {
                if(map[j - 1][i] == map[j][i + 1] || map[j - 1][i] == map[j][i - 1])
                {
                    cnt2++;
                    if(max < cnt2)
                    {
                        max = cnt2;
                    }
                    if(flag2 != 0)
                    {
                        cnt2 -= flag2;
                    }
                    flag2 = cnt2;
                }
                else
                    cnt2 = 1;
            }
            if(map[i][j - 1] == map[i][j])
            {
                cnt++;
                if(max < cnt)
                {
                    max = cnt;
                }
            }
            else
            {
                if(map[i+1][j] == map[i][j - 1] || map[i - 1][j] == map[i][j - 1])
                {
                    cnt++;
                    if(max < cnt)
                    {
                        max = cnt;
                    }
                    if(flag != 0)
                    {
                        cnt -= flag;
                    }
                    flag = cnt;
                }
                else
                    cnt = 1;
            }
        }
    }
    return (max);
}

int main(void)
{
    int n;
    int max;
    char map[51][51];

    scanf("%d", &n);
    parseMap(n, map);
    
    max = dfs(n, map);
    printf("%d\n", max);
    return (0);
}
*/






/*
#include<stdio.h>

int parseMap(int n, char map[51][51])
{
    for(int i=0; i<n; i++)
    {
        scanf("%s", map[i]);
    }
}

int dfs_row(int n, char map[51][51])
{
    int max = 0;
    int cnt = 1;
    int flag = 0;

    for(int i = 0; i < n; i++)
    {
        cnt = 1;
        flag = 0;
        for(int j = 1; j < n; j++)
        {
            if(map[i][j - 1] == map[i][j])
            {
                cnt++;
                if(max < cnt)
                {
                    max = cnt;
                }
            }
            else
            {
                if(map[i+1][j] == map[i][j - 1] || map[i - 1][j] == map[i][j - 1])
                {
                    cnt++;
                    if(max < cnt)
                    {
                        max = cnt;
                    }
                    if(flag != 0)
                    {
                        cnt -= flag;
                    }
                    flag = cnt;
                }
                else
                    cnt = 1;
            }
        }
    }
    return (max);
}

int dfs_column(int n, char map[51][51])
{
    int max = 0;
    int cnt = 1;
    int flag = 0;

    for(int i = 0; i < n; i++)
    {
        cnt = 1;
        flag = 0;
        for(int j = 1; j < n; j++)
        {
            if(map[j - 1][i] == map[j][i])
            {
                cnt++;
                if(max < cnt)
                    max = cnt;
            }
            else
            {
                if(map[j - 1][i] == map[j][i + 1] || map[j - 1][i] == map[j][i - 1])
                {
                    cnt++;
                    if(max < cnt)
                    {
                        max = cnt;
                    }
                    if(flag != 0)
                    {
                        cnt -= flag;
                    }
                    flag = cnt;
                }
                else
                    cnt = 1;
            }
        }
    }
    return (max);
}

int main(void)
{
    int n;
    int max_c;
    int max_r;
    char map[51][51];

    scanf("%d", &n);
    parseMap(n, map);
    
    max_r = dfs_row(n, map);
    max_c = dfs_column(n, map);
    if(max_c > max_r)
        printf("%d\n", max_c);
    else
        printf("%d\n", max_r);
    return (0);
}
*/