# Write a C program to find all pairs of elements in an array whose sum is equal to a given target
value. Each pair should be displayed only once.
Array: 2 7 4 5 1 3 Target: 6
Output: (2, 4), (5, 1)

  #include <stdio.h>

int main() {
    int n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("Pairs whose sum is %d:\n", target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }

    return 0;
}
