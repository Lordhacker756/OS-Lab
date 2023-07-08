#include <stdio.h>

int main() {
    int st[10], bt[10], wt[10], tat[10], n, tq;
    int i, count = 0, swt = 0, stat = 0, temp, sq = 0, total_bt = 0;
    float awt, atat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        st[i] = bt[i];
        total_bt += bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            temp = tq;
            if (st[i] == 0) {
                count++;
                continue;
            }
            if (st[i] > tq) {
                st[i] = st[i] - tq;
            } else {
                temp = st[i];
                st[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (count == n) {
            break;
        }
        if (sq >= total_bt) {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        swt += wt[i];
        stat += tat[i];
    }

    awt = (float) swt / n;
    atat = (float) stat / n;

    printf("Process No. \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("p%d\t\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time: %f\n", awt);
    printf("Average turnaround time: %f\n", atat);

    return 0;
}
