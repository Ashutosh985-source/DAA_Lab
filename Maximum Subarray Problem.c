#include <stdio.h>

void maxSubarray(int arr[], int n)
{
    int currentSum = arr[0];
    int maxSum = arr[0];

    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 1; i < n; i++)
    {
        // Decide whether to start a new subarray
        // or continue the existing one
        if (arr[i] > currentSum + arr[i])
        {
            currentSum = arr[i];
            tempStart = i;
        }
        else
        {
            currentSum = currentSum + arr[i];
        }

        // Update maximum sum
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    printf("Maximum Subarray: ");

    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMaximum Sum = %d\n", maxSum);
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    maxSubarray(arr, n);

    return 0;
}
