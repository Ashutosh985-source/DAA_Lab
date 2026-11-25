#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
    int id;
};

// Sort activities according to start time
int compare(const void *a, const void *b)
{
    struct Activity *x = (struct Activity *)a;
    struct Activity *y = (struct Activity *)b;

    return x->start - y->start;
}

void intervalPartition(struct Activity activities[], int n)
{
    // Sort according to start time
    qsort(activities, n, sizeof(struct Activity), compare);

    // finishTime[i] stores finish time of last
    // activity assigned to room i
    int finishTime[n];

    int roomCount = 0;

    printf("Activity\tStart\tFinish\tRoom\n");

    for (int i = 0; i < n; i++)
    {
        int assigned = 0;

        // Try to find an available room
        for (int j = 0; j < roomCount; j++)
        {
            if (activities[i].start >= finishTime[j])
            {
                finishTime[j] = activities[i].finish;

                printf("A%d\t\t%d\t%d\t%d\n",
                       activities[i].id,
                       activities[i].start,
                       activities[i].finish,
                       j + 1);

                assigned = 1;
                break;
            }
        }

        // No existing room is available
        if (!assigned)
        {
            finishTime[roomCount] = activities[i].finish;

            printf("A%d\t\t%d\t%d\t%d\n",
                   activities[i].id,
                   activities[i].start,
                   activities[i].finish,
                   roomCount + 1);

            roomCount++;
        }
    }

    printf("\nMinimum number of rooms = %d\n", roomCount);
}

int main()
{
    struct Activity activities[] = {
        {1, 4, 1},
        {2, 5, 2},
        {4, 7, 3},
        {6, 8, 4},
        {7, 9, 5}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    intervalPartition(activities, n);

    return 0;
}
