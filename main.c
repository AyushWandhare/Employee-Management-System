#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initilizing global variables
int b = 1;
int k, n = 0, eid = 0, ch = 0, cmp = 1;
char newName[20];
int id[20];

// structure Employee
struct emp
{
    int id;
    char name[20];
    char dprt[20];
    float sal;
};

// functions
int menu()
{
    int c;
    printf("\n");
    printf("::menu::\n");
    printf("0. Exit Menu\n");
    printf("1. Add Employee\n");
    printf("2. Show Employee Records\n");
    printf("3. Update Employee's Data\n");
    printf("4. Delete Employee's Records\n");

    printf("Enter Your Choice:  ");
    scanf("%d", &c);
    return c;
}
void add(struct emp e[50])
{
    printf("Enter Number Of Employee : ");
    scanf("%d", &n);
    for (k = 1; k <= n; k++)
    {
        printf("\n");
        printf("Emp        : %d \n", k);
        printf("Emp Id     : ");
        scanf("%d", &e[k].id);
        printf("Name       : ");
        scanf("%s", &e[k].name);
        printf("Department : ");
        scanf("%s", &e[k].dprt);
        printf("Salary     : ");
        scanf("%f", &e[k].sal);
    }
}

void show(struct emp e[50])
{
    printf("\t\n || All Employee Records ||\n\n");

    printf("EmpId\t|\tName\t\t|\tDepartment\t|\tSalary\n");
    printf("-----------------------------------------------------------------------\n");

    for (k = 1; k <= n; k++)
    {
        if (e[k].id != 0)
            printf("%d\t|\t%s\t\t|\t%s\t\t| \t%f\n", e[k].id, e[k].name, e[k].dprt, e[k].sal);
    }
}

void update(struct emp e[50])
{
    printf("\nEnter your Employee Id: ");
    scanf("%d", &eid);
    for (k = 1; k <= n; k++)
    {
        if (eid == e[k].id)
        {
            printf("Do You Want To Update Your Name?\n");
            printf("Your Old Name Is %s\n", e[k].name);
            printf("What  Is Your Correct Name?\n");
            printf(">> \n");
            scanf("%s",&newName);
            printf("OK..\n");
            printf("your old name is %s & Your new name is %s.\n", e[k].name, newName);
            printf("Do You Want To Confirm Your Changes?\n");
            printf("1.Yes  2.No\n");
            printf("Select Yes or No: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                strcpy(e[k].name, newName);
                printf("Employee Data Updated Successfully\n");
                printf("\n%d\t%s\t%s\t\t%f\n", e[k].id, e[k].name, e[k].dprt, e[k].sal);
                break;
            case 2:
                printf("Employee Data Updation Discarded.\n");
                break;
            default:
                printf("wrong Choice Selected\n");
                break;
            }
        }
    }
}

void del(struct emp e[50])
{
    printf("\nEnter your Employee Id: ");
    scanf("%d", &eid);
    printf("OK..\n");
    printf("Employee Data Record Deleted Successfully.\n");
    for (k = 1; k <= n; k++)
    {
        if (eid == e[k].id)
        {
            e[k].id = 0;
            strcpy(e[k].name, "");
            strcpy(e[k].dprt, "");
            e[k].sal = 0.0;
        }
    }
}

void func(struct emp e[50])
{
    switch (menu())
    {
    case 1:
        add(e);
        break;
    case 2:
        show(e);
        break;
    case 3:
        update(e);
        break;
    case 4:
        del(e);
        break;
    case 0:
        b = 0;
        break;
    default:
        printf("Wrong Option Selected\n");
        break;
    }
}

void choice(struct emp e[50])
{

    {
        func(e);
    }
}

// main function
void main()
{
    printf("::Welcome To Employee Management System::\n");
    struct emp e[50];
    while (b)
    {
        choice(e);
    }
   
}