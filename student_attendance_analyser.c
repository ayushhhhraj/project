#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    int present;
    int total;
    float percentage;
};

void addStudents(struct Student s[50], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf("%29s", s[i].name);

        printf("Enter Total Classes: ");
        scanf("%d", &s[i].total);

        printf("Enter Classes Attended: ");
        scanf("%d", &s[i].present);

        if(s[i].total > 0 && s[i].present >= 0 &&
           s[i].present <= s[i].total)
        {
            s[i].percentage =
            (s[i].present * 100.0) / s[i].total;
        }
        else
        {
            printf("Invalid attendance data!\n");
            s[i].percentage = 0;
        }
    }
}

void displayStudents(struct Student s[], int n)
{
    int i;

    printf("\n------ ATTENDANCE REPORT ------\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nAttendance: %.2f%%", s[i].percentage);

        if(s[i].percentage >= 75)
        {
            printf("\nStatus: Eligible");
        }
        else
        {
            printf("\nStatus: Short Attendance");
        }

        printf("\n");
    }
}

void lowAttendance(struct Student s[], int n)
{
    int i;

    printf("\nStudents having attendance below 75%%:\n");

    for(i = 0; i < n; i++)
    {
        if(s[i].percentage < 75)
        {
            printf("%s - %.2f%%\n",
                   s[i].name, s[i].percentage);
        }
    }
}

void searchStudent(struct Student s[], int n)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            printf("\nStudent Found!");
            printf("\nName: %s", s[i].name);
            printf("\nAttendance: %.2f%%",
                   s[i].percentage);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!");
    }
}

int main()
{
    struct Student s[50];
    int n, choice;

    printf("Enter Number of Students: ");
    scanf("%d", &n);

    if(n < 1 || n > 50)
    {
        printf("Invalid number of students!");
        return 0;
    }

    addStudents(s, n);

    do
    {
        printf("\n\n===== ATTENDANCE ANALYSER =====");
        printf("\n1. Display All Students");
        printf("\n2. Show Low Attendance Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayStudents(s, n);
                break;

            case 2:
                lowAttendance(s, n);
                break;

            case 3:
                searchStudent(s, n);
                break;

            case 4:
                printf("\nThank You!");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while(choice != 4);

    return 0;
}
