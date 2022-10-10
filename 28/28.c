#include <sched.h>
#include <stdio.h>

int main()
{
    int max_pri, min_pri;

    max_pri = sched_get_priority_max(SCHED_RR);
    if (max_pri == -1)
        perror("Not able to get max priority, error occured!\n");
    else
        printf("The max priority with RR Scheduling Policy is : %d\n", max_pri);

    min_pri = sched_get_priority_min(SCHED_RR);
    if (min_pri == -1)
        perror("Not able to get min priority, error occured!\n");
    else
        printf("The min priority with RR Scheduling Policy is : %d\n", min_pri);
    return 0;
}