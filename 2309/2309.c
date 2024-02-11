#include<stdio.h>
#define DWARF_NUM 9 

int	main(void)
{
	int	height[100];
	int sum;

	sum = 0;
	for (int i = 0; i < DWARF_NUM; i++)
	{
		scanf("%d", &height[i]);
		sum += height[i];
	}

	for (int i = 0; i < DWARF_NUM; i++)
	{
		for (int j = i + 1; j < DWARF_NUM; j++)
		{
			if ((sum - height[i] - height[j]) == 100)
			{
				height[i] = height[j] = -1;
			}
		}
	}
	for (int i = 0; i < DWARF_NUM; i++)
	{
		for (int j = i + 1; j < DWARF_NUM; j++)
		{
			if (height[i] > height[j])
			{
				int tmp = height[i];
				height[i] = height[j];
				height[j] = tmp;
			}
		}
	}

	for (int i = 0; i < DWARF_NUM; i++)
	{
		if(height[i] != -1)
			printf("%d\n", height[i]);
	}
	return (0);
}