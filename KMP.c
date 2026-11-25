#include <stdio.h>
#include <string.h>

// Create LPS array
void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
void KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0)
    {
        printf("Pattern is empty.\n");
        return;
    }

    int lps[m];

    // Step 1: Create LPS array
    computeLPS(pattern, m, lps);

    int i = 0;  // text index
    int j = 0;  // pattern index

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        // Complete pattern matched
        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);

            // Continue searching
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMP(text, pattern);

    return 0;
}
