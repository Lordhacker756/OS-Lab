#include <stdio.h>

int main()
{
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
	float avg_wt, avg_tat;

	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("\nEnter burst time: \n");
	for (i = 0; i < n; i++)
	{
		printf("p%d: ", i);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	wt[0] = 0;

	// Calculating wait time
	for (i = 1; i < n; i++)
	{
		wt[i] = 0;
		for (j = 0; j < i; j++)
		{
			wt[i] += bt[j];
			total += wt[i];
		}
	}
	printf("\nProcess \tBurst Time \tWaiting Time \tTurnaround Time");

	for (i = 0; i < n; i++)
	{
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("\nP%d \t\t %d\t\t %d\t\t %d", p[i], bt[i], wt[i], tat[i]);
	}

	avg_tat = (float)total / n;
	printf("\n\nAverage Waiting Time = %f\n", avg_wt);
	printf("\nAverage Turnaround Time=%f\n", avg_tat);
	return 0;
}
