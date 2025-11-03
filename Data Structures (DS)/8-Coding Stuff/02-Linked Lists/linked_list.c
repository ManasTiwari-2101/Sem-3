/*
 A simple singly linked list program with an interactive menu.
 Features:
 - Create list
 - Create node (factory function)
 - Insert node: at beginning, at end, at position
 - Delete node: from beginning, from end, at position, by value
 - Display list
 - Free entire list on exit

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create a new node with given value (beginner-friendly name)
struct Node *CreateNode(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (!n)
    {
        printf("Memory error: could not create node.\n");
        return NULL; // caller should handle NULL
    }
    n->data = value;
    n->next = NULL;
    return n;
}

// Display the linked list
void PrintList(struct Node *head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *cur = head;
    printf("List: ");
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// Insert at beginning
struct Node *InsertAtStart(struct Node *head, int value)
{
    struct Node *n = CreateNode(value);
    if (!n)
        return head; // failed to create node
    n->next = head;
    return n;
}

// Insert at end
struct Node *InsertAtEnd(struct Node *head, int value)
{
    struct Node *n = CreateNode(value);
    if (!n)
        return head;
    if (!head)
        return n;
    struct Node *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    return head;
}

// Insert at position (1-based). If pos <= 1, insert at beginning. If pos > length, insert at end.
struct Node *InsertAtPos(struct Node *head, int value, int pos)
{
    if (pos <= 1 || !head)
        return InsertAtStart(head, value);
    struct Node *cur = head;
    int i = 1;
    while (cur->next && i < pos - 1)
    {
        cur = cur->next;
        i++;
    }
    struct Node *n = CreateNode(value);
    if (!n)
        return head;
    n->next = cur->next;
    cur->next = n;
    return head;
}

// Delete from beginning
struct Node *DeleteFromStart(struct Node *head)
{
    if (!head)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    struct Node *next = head->next;
    free(head);
    return next;
}

// Delete from end
struct Node *DeleteFromEnd(struct Node *head)
{
    if (!head)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (!head->next)
    {
        free(head);
        return NULL;
    }
    struct Node *cur = head;
    while (cur->next->next)
        cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    return head;
}

// Delete at position (1-based)
struct Node *DeleteAtPos(struct Node *head, int pos)
{
    if (!head)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (pos <= 1)
        return DeleteFromStart(head);
    struct Node *cur = head;
    int i = 1;
    while (cur->next && i < pos - 1)
    {
        cur = cur->next;
        i++;
    }
    if (!cur->next)
    {
        printf("Position %d out of range. No deletion performed.\n", pos);
        return head;
    }
    struct Node *to_delete = cur->next;
    cur->next = to_delete->next;
    free(to_delete);
    return head;
}

// Delete by value (first occurrence)
struct Node *DeleteByValue(struct Node *head, int value)
{
    if (!head)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (head->data == value)
        return DeleteFromStart(head);
    struct Node *cur = head;
    while (cur->next && cur->next->data != value)
        cur = cur->next;
    if (!cur->next)
    {
        printf("Value %d not found in list.\n", value);
        return head;
    }
    struct Node *to_delete = cur->next;
    cur->next = to_delete->next;
    free(to_delete);
    return head;
}

// Free whole list
void FreeList(struct Node *head)
{
    struct Node *cur = head;
    while (cur)
    {
        struct Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

// Create list by reading n values
struct Node *CreateList(int n)
{
    struct Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int val;
        printf("Enter value for node %d: ", i + 1);
        if (scanf("%d", &val) != 1)
        {
            printf("Invalid input. Stopping creation.\n");
            // clear invalid input
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            break;
        }
        head = InsertAtEnd(head, val);
    }
    return head;
}

void print_menu(void)
{
    printf("\n--- Linked List Menu ---\n");
    printf("1. Create list\n");
    printf("2. Insert node\n");
    printf("3. Delete node\n");
    printf("4. Display list\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main(void)
{
    struct Node *head = NULL;
    int choice;
    while (1)
    {
        print_menu();
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            continue;
        }
        if (choice == 1)
        {
            int n;
            printf("How many nodes to create? ");
            if (scanf("%d", &n) != 1 || n < 0)
            {
                printf("Invalid number.\n");
                continue;
            }
            FreeList(head);
            head = NULL;
            head = CreateList(n);
        }
        else if (choice == 2)
        {
            printf("Insert: 1-Beginning 2-End 3-Position. Choose: ");
            int ins;
            if (scanf("%d", &ins) != 1)
            {
                printf("Invalid input.\n");
                continue;
            }
            int val;
            printf("Enter value: ");
            if (scanf("%d", &val) != 1)
            {
                printf("Invalid input.\n");
                continue;
            }
            if (ins == 1)
                head = InsertAtStart(head, val);
            else if (ins == 2)
                head = InsertAtEnd(head, val);
            else if (ins == 3)
            {
                int pos;
                printf("Enter position (1-based): ");
                if (scanf("%d", &pos) != 1)
                {
                    printf("Invalid input.\n");
                    continue;
                }
                head = InsertAtPos(head, val, pos);
            }
            else
            {
                printf("Unknown insert choice.\n");
            }
        }
        else if (choice == 3)
        {
            printf("Delete: 1-Beginning 2-End 3-Position 4-By value. Choose: ");
            int del;
            if (scanf("%d", &del) != 1)
            {
                printf("Invalid input.\n");
                continue;
            }
            if (del == 1)
                head = DeleteFromStart(head);
            else if (del == 2)
                head = DeleteFromEnd(head);
            else if (del == 3)
            {
                int pos;
                printf("Enter position (1-based): ");
                if (scanf("%d", &pos) != 1)
                {
                    printf("Invalid input.\n");
                    continue;
                }
                head = DeleteAtPos(head, pos);
            }
            else if (del == 4)
            {
                int val;
                printf("Enter value to delete: ");
                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input.\n");
                    continue;
                }
                head = DeleteByValue(head, val);
            }
            else
            {
                printf("Unknown delete choice.\n");
            }
        }
        else if (choice == 4)
        {
            PrintList(head);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Unknown option.\n");
        }
    }

    FreeList(head);
    printf("Exiting.\n");
    return 0;
}
