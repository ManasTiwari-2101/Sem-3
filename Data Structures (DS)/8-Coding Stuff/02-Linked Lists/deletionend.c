// Create The Logic For Deletion At The End Of A Linked List

#include <stdio.h>
#include <stdlib.h>

// Create A Linked List Node
struct Node
{
    int data;
    struct Node *next;
};

// Function To Print The Linked List
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Function To Delete The Last Node Of The Linked List
struct Node *deleteAtEnd(struct Node *head)
{
    // If The List Is Empty
    if (head == NULL)
    {
        printf("The List Is Empty, Nothing To Delete.\n");
        return head;
    }

    // If The List Contains Only One Node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    // Traverse To The Second Last Node
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Free The Last Node And Update The Second Last Node's Next Pointer
    free(temp->next);
    temp->next = NULL;

    return head;
}
