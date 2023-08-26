#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    char section[50];
    struct Student *next;
};

struct Student *head = NULL;

void addStudent(int id, const char *name, const char *section)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->section, section);
    newStudent->next = head;
    head = newStudent;
}


void displayStudents()
{
    struct Student *current = head;
    if (current == NULL)
    {
        printf("No student records available.\n");
        return;
    }
    printf("Student Records:\n");
    while (current != NULL)
    {
        printf("ID: %d, Name: %s, section: %s\n", current->id, current->name, current->section);
        current = current->next;
    }
}

struct Student *searchStudent(int id)
{
    struct Student *current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void updateStudent(int id, const char *name, const char *section)
{
    struct Student *studentToUpdate = searchStudent(id);
    if (studentToUpdate == NULL)
    {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    strcpy(studentToUpdate->name, name);
    strcpy(studentToUpdate->section, section);
    printf("Student information updated successfully.\n");
}

void deleteStudent(int id)
{
    struct Student *current = head;
    struct Student *prev = NULL;

    while (current != NULL)
    {
        if (current->id == id)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Student with ID %d deleted.\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Student with ID %d not found.\n", id);
}

int main()
{
    int choice;
    int id;
    char name[50];
    char section[50];

    do
    {
        printf("\nStudent Registration System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            printf("Enter Student Name: ");
            scanf("%s", name);
            printf("Enter Student section: ");
            scanf("%s", section);
            addStudent(id, name, section);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter Student ID to search: ");
            scanf("%d", &id);
            struct Student *student = searchStudent(id);
            if (student != NULL)
            {
                printf("Student found - ID: %d, Name: %s, section: %s\n", student->id, student->name, student->section);
            }
            else
            {
                printf("Student not found.\n");
            }
            break;
        case 4:
            printf("Enter Student ID to update: ");
            scanf("%d", &id);
            printf("Enter Student Name: ");
            scanf("%s", name);
            printf("Enter Student section: ");
            scanf("%s", section);
            updateStudent(id, name, section);
            break;
        case 5:
            printf("Enter Student ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}