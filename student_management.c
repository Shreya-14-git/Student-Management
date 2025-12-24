#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    char branch[50];
    float marks;
    struct student *next;
};

struct student *start = NULL;

/* Add Student */
void addStudent() {
    struct student *ptr, *temp;

    ptr = (struct student *)malloc(sizeof(struct student));

    printf("Enter Roll Number: ");
    scanf("%d", &ptr->roll);

    printf("Enter Name: ");
    scanf("%s", ptr->name);

    printf("Enter Branch: ");
    scanf("%s", ptr->branch);

    printf("Enter Marks: ");
    scanf("%f", &ptr->marks);

    ptr->next = NULL;

    if (start == NULL) {
        start = ptr;
    } else {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }

    printf("Student added successfully!\n");
}

/* Display Students */
void displayStudents() {
    struct student *temp = start;

    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Roll: %d | Name: %s | Branch: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->branch, temp->marks);
        temp = temp->next;
    }
}

/* Search Student */
void searchStudent() {
    int roll, found = 0;
    struct student *temp = start;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Student Found:\n");
            printf("Roll: %d | Name: %s | Branch: %s | Marks: %.2f\n",
                   temp->roll, temp->name, temp->branch, temp->marks);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Student not found!\n");
}

/* Update Student */
void updateStudent() {
    int roll, found = 0;
    struct student *temp = start;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Enter New Name: ");
            scanf("%s", temp->name);

            printf("Enter New Branch: ");
            scanf("%s", temp->branch);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Student record updated successfully!\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Student not found!\n");
}

/* Delete Student */
void deleteStudent() {
    int roll;
    struct student *temp = start, *prev = NULL;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            if (prev == NULL) {
                start = temp->next;   // delete first node
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Student record deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Student not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System (Linked List) ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
