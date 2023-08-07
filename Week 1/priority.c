#include <stdio.h>

int main()
{
    int burst_times[10], waiting_times[10], turnaround_times[10], priorities[10], num_processes;
    int i, j, temp, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter burst time and priority of each process:\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst_times[i]);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &priorities[i]);
    }

    // Sort the processes based on priority using Bubble Sort
    for (i = 0; i < num_processes - 1; i++)
    {
        for (j = 0; j < num_processes - i - 1; j++)
        {
            if (priorities[j] > priorities[j + 1])
            {
                // Swap priorities
                temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;

                // Swap burst times
                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;
            }
        }
    }

    waiting_times[0] = 0;                 // First process has no waiting time
    turnaround_times[0] = burst_times[0]; // First process turnaround time is its burst time

    // Calculate waiting times and turnaround times
    for (i = 1; i < num_processes; i++)
    {
        waiting_times[i] = waiting_times[i - 1] + burst_times[i - 1];
        turnaround_times[i] = waiting_times[i] + burst_times[i];
    }

    // Calculate total waiting and turnaround times
    for (i = 0; i < num_processes; i++)
    {
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    avg_waiting_time = (float)total_waiting_time / num_processes;
    avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("Process No. \t Burst Time \t Priority \t Waiting Time \t Turnaround Time\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, burst_times[i], priorities[i], waiting_times[i], turnaround_times[i]);
    }

    printf("Average waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    return 0;
}
