# Student Result Analysis
• Store the roll number, name, and marks in five subjects for N students using structures.
• Calculate the total, percentage, and grade of each student.
• Display the class topper, students who failed in one or more subjects, and the class average.

#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
    int failed;
};

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of Student %d:\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        s[i].failed = 0;

        printf("Enter marks in 5 subjects:\n");

        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);

            s[i].total += s[i].marks[j];

            // Assuming below 33 is fail
            if (s[i].marks[j] < 33) {
                s[i].failed = 1;
            }
        }

        s[i].percentage = s[i].total / 5;

        // Calculate grade
        if (s[i].failed) {
            s[i].grade = 'F';
        }
        else if (s[i].percentage >= 90) {
            s[i].grade = 'A';
        }
        else if (s[i].percentage >= 80) {
            s[i].grade = 'B';
        }
        else if (s[i].percentage >= 70) {
            s[i].grade = 'C';
        }
        else if (s[i].percentage >= 60) {
            s[i].grade = 'D';
        }
        else if (s[i].percentage >= 50) {
            s[i].grade = 'E';
        }
        else {
            s[i].grade = 'F';
        }
    }

    // Find topper
    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].total > s[topper].total) {
            topper = i;
        }
    }

    // Calculate class average
    float classTotal = 0;

    for (int i = 0; i < n; i++) {
        classTotal += s[i].percentage;
    }

    float classAverage = classTotal / n;

    // Display results
    printf("\n========== STUDENT RESULTS ==========\n");

    for (int i = 0; i < n; i++) {
        printf("\nRoll Number : %d", s[i].roll);
        printf("\nName        : %s", s[i].name);
        printf("\nTotal       : %.2f", s[i].total);
        printf("\nPercentage  : %.2f%%", s[i].percentage);
        printf("\nGrade       : %c\n", s[i].grade);
    }

    // Display topper
    printf("\n========== CLASS TOPPER ==========\n");
    printf("Roll Number : %d\n", s[topper].roll);
    printf("Name        : %s\n", s[topper].name);
    printf("Total       : %.2f\n", s[topper].total);
    printf("Percentage  : %.2f%%\n", s[topper].percentage);

    // Display failed students
    printf("\n========== FAILED STUDENTS ==========\n");

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (s[i].failed) {
            printf("Roll Number: %d, Name: %s\n",
                   s[i].roll, s[i].name);
            found = 1;
        }
    }

    if (!found) {
        printf("No student failed.\n");
    }

    // Display class average
    printf("\n========== CLASS AVERAGE ==========\n");
    printf("Class Average = %.2f%%\n", classAverage);

    return 0;
}
