#include <stdio.h>

int main()
{
    int burst_times[10], waiting_times[10], turnaround_times[10], num_processes, time_quantum;
    int i, completed_processes = 0, total_waiting_time = 0, total_turnaround_time = 0, temp, current_time = 0, total_burst_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter burst time of each process:\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_times[i]);
        waiting_times[i] = burst_times[i];
        total_burst_time += burst_times[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    while (1)
    {
        for (i = 0, completed_processes = 0; i < num_processes; i++)
        {
            temp = time_quantum;
            if (waiting_times[i] == 0)
            {
                completed_processes++;
                continue;
            }
            if (waiting_times[i] > time_quantum)
            {
                waiting_times[i] = waiting_times[i] - time_quantum;
            }
            else
            {
                temp = waiting_times[i];
                waiting_times[i] = 0;
            }
            current_time = current_time + temp;
            turnaround_times[i] = current_time;
        }
        if (completed_processes == num_processes)
        {
            break;
        }
        if (current_time >= total_burst_time)
        {
            break;
        }
    }

    for (i = 0; i < num_processes; i++)
    {
        waiting_times[i] = turnaround_times[i] - burst_times[i];
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    avg_waiting_time = (float)total_waiting_time / num_processes;
    avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("Process No. \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d\t\t %d\t\t %d\t\t %d\n", i + 1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }

    printf("Average waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    return 0;
}
