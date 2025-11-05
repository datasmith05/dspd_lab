#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    int age;
    float avgMarks;
};

void sorted(struct Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].avgMarks < arr[j + 1].avgMarks)
            {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter no. of students: ");
    scanf("%d", &n);

    struct Student students[n];

    
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d student details :\n",i+1);
        printf("Roll Name Age AvgMarks\n");
        scanf("%d %s %d %f", &students[i].roll, students[i].name, &students[i].age, &students[i].avgMarks);
    }

    sorted(students, n);

    printf("\nStudents sorted by average marks:\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("Roll\tName\tAge\tAvg Marks\n");
        printf("%d\t%s\t%d\t%.2f\n", students[i].roll, students[i].name, students[i].age, students[i].avgMarks);
    }

    return 0;
}
