/*######################################
# University of Information Technology #
# IT007 Operating System #
# Nguyen Khai Dang, 19521317 #
# File: baitap2.c #
######################################*/
#include <stdio.h>
void main()
{
    int pn[10];
    int arr[10], bur[10], star[10], res[10], x[10], finish[10], tat[10], wt[10];
    int totwt = 0, tottat = 0, waitting[10], turnaround[10];
    int i, n, flag[10], time, count = 0, smallest;
    double avg = 0, tt = 0, end;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time: ");
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time: ");
        scanf("%d", &bur[i]);
        flag[i] = 0;
    }
    for (int i = 0; i < n; i++)
        x[i] = bur[i];
    bur[9] = 9999;

    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (arr[i] <= time && bur[i] < bur[smallest] && bur[i] > 0)
                smallest = i;
        }
        bur[smallest]--;
        if (flag[smallest] == 0)
        {
            res[smallest] = time - arr[smallest];
            flag[smallest] = 1;
        }
        if (bur[smallest] == 0)
        {
            count++;
            end = time + 1;
            finish[smallest] = end;
            waitting[smallest] = end - arr[smallest] - x[smallest];
            turnaround[smallest] = end - arr[smallest];
        }
    }
    printf("\nPName Bur Arrival Waitting Res Turnaround Finish");
    for (i = 0; i < n; i++)
    {
        printf("\n%6d\t%6d\t\t%6d\t%6d\t%6d\t%6d\t%6d", i + 1, x[i], arr[i], waitting[i], res[i], turnaround[i], finish[i]);
        avg = avg + waitting[i];
        tt = tt + turnaround[i];
    }
    printf("\nAWT = %lf\n", avg);
    printf("\nAT = %lf\n", tt);
}
