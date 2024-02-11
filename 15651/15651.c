#include<stdio.h>

void	recursive(int n, int m, int curr)
{
	if(m <= 1)
	{
		printf("\n");
		return ;
	}
	if(curr > n)
	{
		return ;
	}
	printf("%d ", n);
	recursive(n, m - 1, curr);
	recursive(n, m - 1, curr + 1);
	recursive(n, m, curr + 1);
}

int	main(void)
{
	int	n;
	int	m;

	scanf("%d %d", &n, &m);

	recursive(n, m, 1);
	return (0);
}