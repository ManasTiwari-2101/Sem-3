// Create a double linked list and perform basic operations
#include <stdio.h>
#include <stdlib.h>

// Create A Struct For Double Linked List Node
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Write A Function To Create Node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Write A Function To Print The List
void printList(Node * head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Write A Function To Insert At The Beginning
Node *insertAtBeginning(Node * head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Write A Function To Insert At The End
Node *insertAtEnd(Node * head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}



int main()
{
    // Write A Loop To Use The Above Functions Making The Program Dynamic
    Node *head = NULL;
    int choice, data;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}