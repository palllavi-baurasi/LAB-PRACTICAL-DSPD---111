/*
 Write a program which creates a structure Student which must have the attribute 
 Avg Marks with 3 more attributes sort the list of the student in descending 
 order using Bubble sort
*/

#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    // Bubble Sort in descending order of avgMarks
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                // Swap
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Display sorted list
    printf("\n--- Students sorted in descending order of Average Marks ---\n");
    printf("%-10s %-15s %-10s %-15s\n", "RollNo", "Name", "Age", "AverageMarks");
    printf("-----------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-10d %-15.2f\n", s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}

/*
 Output:
  Enter number of students: 3

 Enter details for Student 1:
 Roll Number: 3
 Name: jaideep
 Age: 19
 Average Marks: 92

 Enter details for Student 2:
 Roll Number: 4
 Name: jayash
 Age: 20
 Average Marks: 90

 Enter details for Student 3:
 Roll Number: 5
 Name: khushwant
 Age: 20
 Average Marks: 85

 --- Students sorted in descending order of Average Marks ---
 RollNo     Name            Age        AverageMarks
 -----------------------------------------
 3          jaideep         19         92.00
 4          jayash          20         90.00
 5          khushwant       20         85.00
*/