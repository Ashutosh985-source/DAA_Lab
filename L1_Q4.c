#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, j, palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        // Ignore spaces
        if (str[i] == ' ') {
            i++;
        }
        else if (str[j] == ' ' || str[j] == '\n') {
            j--;
        }
        else {
            if (tolower(str[i]) != tolower(str[j])) {
                palindrome = 0;
                break;
            }
            i++;
            j--;
        }
    }

    if (palindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}