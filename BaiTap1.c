/*######################################
# University of Information Technology #
# IT007 Operating System #
# Nguyen Khai Dang, 19521317 #
# File: baitap1.c #
######################################*/
#include <stdio.h>
void main()
{
    int pn[10];
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, n;
    int totwt = 0, tottat = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%d%d%d", &pn[i], &arr[i], &bur[i]);
    }
    int temp;
    for (int m = 0; m < n; m++)
        for (int l = m + 1; l < n; l++)
            if (arr[m] > arr[l])
            {
                temp = arr[m];
                arr[m] = arr[l];
                arr[l] = temp;

                temp = pn[m];
                pn[m] = pn[l];
                pn[l] = temp;

                temp = bur[m];
                bur[m] = bur[l];
                bur[l] = temp;
            }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            star[i] = arr[i];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
        else
        {
            for (int j = i + 1; j < n; j++)
                if ((bur[i] > bur[j]) && (arr[j] <= finish[i - 1]))
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    temp = pn[i];
                    pn[i] = pn[j];
                    pn[j] = temp;

                    temp = bur[i];
                    bur[i] = bur[j];
                    bur[i] = temp;
                }

            if (arr[i] <= finish[i - 1])
            {
                star[i] = finish[i - 1];
                wt[i] = star[i] - arr[i];
                finish[i] = star[i] + bur[i];
                tat[i] = finish[i] - arr[i];
            }
            else
            {
                star[i] = arr[i];
                wt[i] = star[i] - arr[i];
                finish[i] = star[i] + bur[i];
                tat[i] = finish[i] - arr[i];
            }
        }
    }
    float waiting_time = 0, turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        waiting_time += star[i] - arr[i];
        turnaround_time += tat[i];
    }

    printf("\nPName Arrtime Burtime Start TAT Finish");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d", pn[i], arr[i], bur[i], star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    float AWT = (float)totwt / n;
    printf("\nAWT = %f\n", AWT);
    float AT = (float)tottat / n;
    printf("\nAT = %f\n", AT);
}
