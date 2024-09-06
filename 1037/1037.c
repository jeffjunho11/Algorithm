#include <stdio.h>
#include <stdlib.h>

int compare_ascending(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void)
{
	int n;
	int target;
	int divisor[55];

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &divisor[i]);
	}
	if(n == 1)
	{
		printf("%d\n", divisor[0] * divisor[0]);
		return (0);
	}
	else 
		qsort(divisor, n, sizeof(int), compare_ascending);
	printf("%d\n", divisor[1] * divisor[n - 2]);
    return (0);
}