#include <stdio.h>

int main() {
    int n, i;
    int a[100];
    int largest, second;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = a[0];
    second = -9999;

    for(i = 1; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Second largest = %d", second);

    return 0;
}