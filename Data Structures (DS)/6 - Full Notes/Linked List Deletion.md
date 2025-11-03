## Deletion of First Node

### Introduction to Linked Lists (for Beginners)
A **linked list** is a data structure where elements (called **nodes**) are connected in a sequence. Each node contains:
- **Data**: The value stored in the node (e.g., a number or character).
- **Link (or Pointer)**: A reference to the next node in the sequence.
The first node is called the **head** (or `start`), and the last node’s link points to `NULL`, indicating the end of the list.

**Deletion of the first node** means removing the head node and making the second node (if it exists) the new head.

### Runtime Complexity
- **Time Complexity**: O(1)
  - Deleting the first node is a constant-time operation because we directly access the head (`start`) and update it to point to the next node. No traversal is needed.
- **Space Complexity**: O(1)
  - We only use a single pointer (`p`) to store the address of the node to be deleted, so no extra space is required beyond a constant amount.

### Code
```c
struct node *p = start;    // Store the address of the first node
start = start->link;       // Update start to point to the next node
free(p);                   // Free the memory of the deleted node
```

### How Will You Read the Syntax?
Let’s break down the code step-by-step for clarity:
1. `struct node *p = start;`
   - `struct node`: Refers to the structure defining a node, which typically looks like:
     ```c
     struct node {
         int data;          // Data stored in the node
         struct node *link; // Pointer to the next node
     };
     ```
   - `*p`: Declares a pointer `p` that will point to a node.
   - `= start`: Assigns `p` the address of the first node (`start` is the head of the linked list).
   - **In simple terms**: `p` now points to the first node in the list.
1. `start = start->link;`
   - `start`: The pointer to the head of the linked list.
   - `->link`: Accesses the `link` field of the node that `start` points to (i.e., the address of the next node).
   - This line updates `start` to point to the second node (if it exists) or `NULL` (if the list has only one node).
   - **In simple terms**: The head now points to the next node, effectively removing the first node from the list.
1. `free(p);`
   - `free()`: A C function that deallocates memory previously allocated for the node.
   - `p`: Points to the original first node, which is no longer part of the list.
   - This line releases the memory of the deleted node to prevent memory leaks.
   - **In simple terms**: We delete the first node’s memory so it’s not left unused.

### Approach to the Solution
1. **Understand the goal**: We want to remove the first node and make the second node the new head.
2. **Steps**:
   - Save the address of the first node in a temporary pointer (`p`) so we can free it later.
   - Update the `start` pointer to point to the next node (`start->link`).
   - Free the memory of the original first node using `free(p)`.
3. **Edge Cases**:
   - **Empty List**: If `start == NULL`, there’s nothing to delete. You’d need to check this before running the code.
   - **Single Node**: If the list has only one node (`start->link == NULL`), `start` becomes `NULL` after deletion.
4. **Why it works**: Since we’re only manipulating the head pointer and freeing one node, the operation is quick and doesn’t require traversing the list.

### Visual Screenshots
![[Pasted image 20251014185212.png]]

---

## Deletion of the Last Node

### Introduction
Deleting the last node in a singly linked list means removing the final node in the sequence and setting the second-to-last node’s link to `NULL`. Since a singly linked list only has forward pointers, we need to traverse the list to find the last node and the node before it.

### Runtime Complexity
- **Time Complexity**: O(n)
  - We need to traverse the list to find the second-to-last node (where `p->link->link == NULL`). In the worst case, we traverse all `n` nodes.
- **Space Complexity**: O(1)
  - We use two pointers (`p` and `q`) regardless of the list’s size, so the space used is constant.

### Code
```c
struct node *p = start;           // Start at the head
while (p->link->link != NULL) {   // Traverse until p's next node is the last
    p = p->link;                  // Move to the next node
}
struct node *q = p->link;         // q points to the last node
p->link = NULL;                   // Set the second-to-last node's link to NULL
free(q);                          // Free the last node
```

### How Will You Read the Syntax?
1. `struct node *p = start;`
   - Initializes pointer `p` to the head of the list (`start`).
   - **In simple terms**: `p` points to the first node.
1. `while (p->link->link != NULL) { p = p->link; }`
   - `p->link`: The next node after `p`.
   - `p->link->link`: The node after the next node (two nodes ahead of `p`).
   - The condition checks if the node two steps ahead is `NULL`. If it’s not `NULL`, `p` moves to the next node (`p = p->link`).
   - This loop stops when `p` is the second-to-last node (i.e., `p->link` is the last node).
   - **In simple terms**: Move `p` until its next node is the last node.
1. `struct node *q = p->link;`
   - `p->link` is the last node. Assign its address to pointer `q`.
   - **In simple terms**: `q` now points to the last node.
1. `p->link = NULL;`
   - Sets the link of the second-to-last node (`p`) to `NULL`, making it the new last node.
   - **In simple terms**: Cut off the last node from the list.
1. `free(q);`
   - Frees the memory of the last node (pointed to by `q`).
   - **In simple terms**: Delete the last node’s memory.

### Approach to the Solution
1. **Goal**: Remove the last node and update the second-to-last node’s link to `NULL`.
2. **Steps**:
   - Start with a pointer `p` at the head (`start`).
   - Traverse the list until `p->link` is the last node (i.e., `p->link->link == NULL`).
   - Save the last node’s address in `q`.
   - Set `p->link` to `NULL` to terminate the list.
   - Free the last node’s memory.
3. **Edge Cases**:
   - **Empty List**: If `start == NULL`, do nothing.
   - **Single Node**: If `start->link == NULL`, set `start = NULL` and free the node.
   - **Two Nodes**: The loop won’t run, and `p` stays at `start`.

### Visual Screenshots
![[Pasted image 20251014201127.png]]

---

## Deletion of the Last Node: Last Is Given

### Introduction
This case assumes you have a pointer (`last`) that already points to the last node. The task is to delete this node and update the second-to-last node’s link to `NULL`.

### Runtime Complexity
- **Time Complexity**: O(n)
  - We still need to traverse the list to find the second-to-last node (the node whose `link` points to `last`).
- **Space Complexity**: O(1)
  - We use two pointers (`p` and `q`) and a constant amount of memory.

### Code
```c
struct node *p = start;       // Start at the head
while (p->link != last) {     // Traverse until p's next node is last
    p = p->link;              // Move to the next node
}
struct node *q = last;        // q points to the last node
p->link = NULL;               // Set second-to-last node's link to NULL
free(q);                      // Free the last node
last = p;                     // Update last to point to the new last node
```

### How Will You Read the Syntax?
1. `struct node *p = start;`
   - `p` is initialized to point to the head of the list.
   - **In simple terms**: `p` starts at the first node.
1. `while (p->link != last) { p = p->link; }`
   - `p->link`: The next node after `p`.
   - The loop continues until `p->link` equals `last` (i.e., `p` is the node before `last`).
   - Inside the loop, `p = p->link` moves `p` to the next node.
   - **In simple terms**: Move `p` until its next node is the one we want to delete (`last`).
1. `struct node *q = last;`
   - Assigns the address of the last node to `q` for freeing later.
   - **In simple terms**: `q` points to the node we’re deleting.
1. `p->link = NULL;`
   - Sets the link of the second-to-last node (`p`) to `NULL`, making it the new last node.
   - **In simple terms**: End the list at `p`.
1. `free(q);`
   - Frees the memory of the last node.
   - **In simple terms**: Delete the last node’s memory.
1. `last = p;`
   - Updates the `last` pointer to point to the new last node (`p`).
   - **In simple terms**: Update the `last` pointer to the new end of the list.

### Approach to the Solution
1. **Goal**: Delete the node pointed to by `last` and update the list.
2. **Steps**:
   - Traverse the list with `p` until `p->link == last`.
   - Save `last` in `q` for freeing.
   - Set `p->link = NULL` to make `p` the new last node.
   - Free the memory of the old last node.
   - Update the `last` pointer to `p`.
3. **Edge Cases**:
   - **Single Node**: If `start == last`, set `start = NULL` and `last = NULL`.
   - **Empty List**: If `start == NULL`, do nothing.
   - **Last is Invalid**: Ensure `last` is part of the list (validation needed).

### Visual Screenshots
![[Pasted image 20251014230832.png]]

---

## Deletion of a Given Node

### Introduction
This operation deletes a specific node pointed to by a given pointer (`loc`). The node could be anywhere in the list (except possibly the first, depending on implementation).

### Runtime Complexity
- **Time Complexity**: O(n)
  - We need to traverse the list to find the node before `loc` (i.e., the node whose `link` points to `loc`).
- **Space Complexity**: O(1)
  - We use two pointers (`p` and `loc`) and no extra space.

### Code
```c
struct node *p = start;       // Start at the head
while (p->link != loc) {      // Traverse until p's next node is loc
    p = p->link;              // Move to the next node
}
p->link = loc->link;          // Connect p to the node after loc
free(loc);                    // Free the given node
```

### How Will You Read the Syntax?
1. `struct node *p = start;`
   - Initializes `p` to the head of the list.
   - **In simple terms**: `p` starts at the first node.
1. `while (p->link != loc) { p = p->link; }`
   - `p->link`: The next node after `p`.
   - The loop continues until `p->link` equals `loc` (i.e., `p` is the node before `loc`).
   - `p = p->link` moves `p` to the next node.
   - **In simple terms**: Move `p` until its next node is the one we want to delete.
1. `p->link = loc->link;`
   - `loc->link`: The node after the one to be deleted.
   - Sets `p->link` to skip `loc` and point to the node after it.
   - In simple terms: Bypass `loc` by linking `p` to the node after `loc`.
1. `free(loc);`
   - Frees the memory of the node pointed to by `loc`.
   - **In simple terms**: Delete `loc`’s memory.

### Approach to the Solution
1. **Goal**: Remove the node pointed to by `loc`.
2. **Steps**:
   - Traverse the list with `p` until `p->link == loc`.
   - Update `p->link` to point to `loc->link`, bypassing `loc`.
   - Free the memory of `loc`.
3. **Edge Cases**:
   - **loc is the first node**: This code doesn’t handle it (see “Deletion of First Node”).
   - **loc is the last node**: `loc->link` is `NULL`, so `p->link` becomes `NULL`.
   - **loc is invalid**: Ensure `loc` is in the list (validation needed).

### Visual Screenshots
![[Pasted image 20251014231105.png]]

---

## Deletion of a Given Node: Without Using Any Other Pointer

### Introduction
The note suggests there’s no valid way to delete a node without another pointer, but the provided code is identical to the previous section. This seems to be a misunderstanding. Typically, deleting a node requires the previous node’s pointer to update its `link`. However, I’ll explain the provided code and clarify the concept.

### Runtime Complexity
- **Time Complexity**: O(n)
  - Same as above, since we traverse to find the node before `loc`.
- **Space Complexity**: O(1)
  - Uses only `p` and `loc`.

### Code
```c
struct node *p = start;       // Start at the head
while (p->link != loc) {      // Traverse until p's next node is loc
    p = p->link;              // Move to the next node
}
p->link = loc->link;          // Connect p to the node after loc
free(loc);                    // Free the given node
```

### How Will You Read the Syntax?
(Same as the previous section; see above.)

### Approach to the Solution
- The provided code uses `p`, so it doesn’t truly avoid using another pointer.
- **Clarification**: Deleting a node in a singly linked list without another pointer is generally not possible because we need to update the previous node’s `link`. The note’s claim (“You Don’t Have Any Valid Way LOL, then u just put start = loc->link;”) seems to refer to the special case where `loc` is the first node, but this isn’t clear in the code.
- **Correct Approach**:
  - Use `p` to find the node before `loc`.
  - Update `p->link` to skip `loc`.
  - Free `loc`.
- **Edge Case (First Node)**: If `loc == start`, then `start = loc->link` works, but this isn’t “without another pointer.”

### Visual Screenshots
![[Pasted image 20251014231343.png]]

---

## Deletion of a Given Node: Without Using Any Other Pointer When Even start Is Also Not Given

### Introduction
This method deletes a node (`loc`) by copying the data from the next node into `loc` and then deleting the next node. This avoids needing the previous node’s pointer or `start`. However, it only works if `loc` is not the last node.

### Runtime Complexity
- **Time Complexity**: O(1)
  - No traversal is needed; we directly manipulate `loc` and its next node.
- **Space Complexity**: O(1)
  - No extra pointers are used.

### Code
```c
loc->data = loc->link->data;    // Copy next node's data to loc
loc->link = loc->link->link;    // Bypass the next node
free(loc->link);                // Free the next node (corrected from original)
```

### How Will You Read the Syntax?
1. `loc->data = loc->link->data;`
   - `loc->link`: The node after `loc`.
   - `loc->link->data`: The data in the next node.
   - Copies the next node’s data into `loc`’s data field.
   - **In simple terms**: Replace `loc`’s data with the next node’s data.
1. `loc->link = loc->link->link;`
   - `loc->link->link`: The node after the next node.
   - Updates `loc`’s link to skip the next node and point to the node after it.
   - **In simple terms**: Bypass the next node in the list.
1. `free(loc->link);` (Corrected from original)
   - The original code (`loc->link = loc->link->link`) doesn’t free the next node, causing a memory leak. We need to free the bypassed node.
   - **In simple terms**: Delete the next node’s memory.

### Approach to the Solution
1. **Goal**: Delete the node at `loc` without traversing or using `start`.
2. **Steps**:
   - Copy the data from the next node (`loc->link`) into `loc`.
   - Update `loc->link` to point to the node after the next node, bypassing it.
   - Free the next node’s memory.
3. **Why it works**: Instead of deleting `loc`, we make `loc` mimic the next node and delete the next node instead.
4. **Edge Cases**:
   - **loc is the last node**: This method fails because `loc->link` is `NULL`. You’d need to handle this separately.
   - **Single node**: Not applicable since `loc` must have a next node.

### Visual Screenshots
![[Pasted image 20251014231720.png]]

---

## Deletion After a Given Node

### Introduction
This operation deletes the node immediately following the node pointed to by `loc`.

### Runtime Complexity
- **Time Complexity**: O(1)
  - We directly access `loc->link` and update it, with no traversal.
- **Space Complexity**: O(1)
  - No extra pointers are needed.

### Code
```c
struct node *temp = loc->link;     // Save the node to delete
loc->link = loc->link->link;       // Bypass the next node
free(temp);                        // Free the deleted node
```

### How Will You Read the Syntax?
1. `struct node *temp = loc->link;`
   - `loc->link`: The node after `loc`.
   - Saves its address in `temp` for freeing later.
   - **In simple terms**: `temp` points to the node we want to delete.
1. `loc->link = loc->link->link;`
   - `loc->link->link`: The node after the one to be deleted.
   - Updates `loc`’s link to skip the next node.
   - **In simple terms**: Bypass the node after `loc`.
1. `free(temp);`
   - Frees the memory of the node after `loc`.
   - **In simple terms**: Delete the bypassed node’s memory.

### Approach to the Solution
1. **Goal**: Delete the node after `loc`.
2. **Steps**:
   - Save the address of the node after `loc` in `temp`.
   - Update `loc->link` to point to the node after the next node.
   - Free the node stored in `temp`.
3. **Edge Cases**:
   - **loc is the last node**: `loc->link` is `NULL`, so check before deletion.
   - **Empty list or invalid loc**: Ensure `loc` is valid and has a next node.

### Visual Screenshots
![[Pasted image 20251014232044.png]]

---

## Deletion Before a Given Node

### Introduction
This operation deletes the node immediately before the node pointed to by `loc`. Since it’s a singly linked list, we need to find the node whose `link` points to the node before `loc`.

### Runtime Complexity
- **Time Complexity**: O(n)
  - We need to traverse to find the node before the one before `loc`.
- **Space Complexity**: O(1)
  - Uses only one pointer (`p`).

### Code (Corrected)
The provided code has an error (`p->loc = loc`). Here’s the corrected version:
```c
struct node *p = start;       // Start at the head
while (p->link->link != loc) { // Traverse until p's next node is the one before loc
    p = p->link;              // Move to the next node
}
struct node *temp = p->link;  // Save the node to delete
p->link = loc;                // Bypass the node before loc
free(temp);                   // Free the deleted node
```

### How Will You Read the Syntax?
1. `struct node *p = start;`
   - Initializes `p` to the head of the list.
   - **In simple terms**: `p` starts at the first node.
1. `while (p->link->link != loc) { p = p->link; }`
   - `p->link->link`: The node two steps ahead of `p`.
   - The loop continues until `p->link->link == loc`, meaning `p->link` is the node before `loc`.
   - `p = p->link` moves `p` to the next node.
   - **In simple terms**: Move `p` until its next node is the one before `loc`.
1. `struct node *temp = p->link;`
   - Saves the node before `loc` (the one to delete) in `temp`.
   - **In simple terms**: `temp` points to the node we’re deleting.
1. `p->link = loc;`
   - Updates `p`’s link to point to `loc`, bypassing the node before `loc`.
   - **In simple terms**: Skip the node before `loc`.
1. `free(temp);`
   - Frees the memory of the node before `loc`.
   - **In simple terms**: Delete the bypassed node’s memory.

### Approach to the Solution
1. **Goal**: Delete the node before `loc`.
2. **Steps**:
   - Traverse with `p` until `p->link->link == loc`.
   - Save the node to delete (`p->link`) in `temp`.
   - Update `p->link` to point to `loc`.
   - Free the node in `temp`.
3. **Edge Cases**:
   - **loc is the first or second node**: There’s no node before `loc` or it’s the head, which needs special handling.
   - **Empty list or invalid loc**: Validate `loc` and ensure the list has at least two nodes before `loc`.

### Visual Screenshots
![[Pasted image 20251014232353.png]]

---

### Summary for Beginners
- **Linked List Basics**: Think of a linked list as a chain of nodes, each pointing to the next. Deleting a node means breaking and reconnecting the chain.
- **Key Operations**:
  - **First Node**: Easy because we just update `start`.
  - **Last Node**: Requires traversal to find the second-to-last node.
  - **Given Node**: Usually needs the previous node, but we can use tricks like copying data for special cases.
  - **Before/After Node**: Requires careful pointer manipulation to bypass the target node.
- **Memory Management**: Always use `free()` to avoid memory leaks.
- **Edge Cases**: Always check for empty lists, single nodes, or invalid pointers.

### Advanced Notes
- **Optimizations**: For frequently deleting the last node, consider a doubly linked list to avoid O(n) traversal.
- **Error Handling**: Always validate pointers (`start`, `loc`, `last`) to prevent crashes.
- **Memory Leaks**: Ensure every deleted node is freed.
- **Special Cases**: The “no extra pointer” method for deleting a given node is a clever trick but limited to non-last nodes.
# Application of Linked Lists

## Introduction to Linked Lists and Polynomials
A **linked list** is a data structure where elements (nodes) are connected sequentially, with each node containing data and a pointer to the next node. Linked lists are ideal for applications like storing polynomials because:
- Polynomials have terms that may vary in number (dynamic size).
- Terms can be easily inserted, deleted, or modified without shifting elements (unlike arrays).
- Each term in a polynomial can be represented as a node with relevant data (e.g., coefficient, exponents).

A **polynomial** is a mathematical expression consisting of terms, where each term has a **coefficient** (a number) and **exponents** for variables (e.g., \(x\), \(y\)). For example:
- **Univariate Polynomial**: Involves one variable (e.g., \(3x^3 - 6x^2 + 4x - 7\)).
- **Bivariate Polynomial**: Involves two variables (e.g., \(6x^2y - 4xy^2 + 3xy - 7x + 9y - 1\)).

Linked lists are used to store each term as a node, allowing efficient manipulation (e.g., addition, subtraction, or evaluation of polynomials).

---

## Univariate Polynomial (Single Variable)

### Introduction
A **univariate polynomial** has one variable (e.g., \(x\)). Each term consists of a **coefficient** (the number multiplying the variable) and an **exponent** (the power of the variable). For example, in \(3x^3 - 6x^2 + 4x - 7\):
- \(3x^3\): Coefficient = 3, Exponent = 3
- \(-6x^2\): Coefficient = -6, Exponent = 2
- \(4x\): Coefficient = 4, Exponent = 1
- \(-7\): Coefficient = -7, Exponent = 0 (constant term)

We represent each term as a node in a linked list, where the node contains:
- **Coefficient**: The numerical multiplier.
- **Exponent**: The power of \(x\).
- **Link**: A pointer to the next term (node).

The linked list is typically sorted by descending exponents for easier operations (e.g., addition of polynomials).

### Runtime Complexity
- **Creation/Insertion**:
  - **O(n)**: Inserting a term in a sorted linked list (by exponent) requires traversing up to \(n\) nodes to find the correct position.
- **Deletion**:
  - **O(n)**: Deleting a term (e.g., a specific exponent) requires traversing to find the node or the node before it.
- **Traversal/Evaluation**:
  - **O(n)**: To evaluate the polynomial for a given \(x\), traverse all \(n\) terms and compute each term’s value.
- **Addition of Two Polynomials**:
  - **O(n + m)**: Where \(n\) and \(m\) are the number of terms in the two polynomials. Traverse both lists, compare exponents, and combine terms.
- **Space Complexity**:
  - **O(n)**: Each term requires a node, so the space grows linearly with the number of terms.

### Code
Here’s a sample C code to represent and create a univariate polynomial linked list:

```c
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a univariate polynomial
struct node {
    int coeff;        // Coefficient of the term
    int exp;          // Exponent of x
    struct node *link; // Pointer to the next term
};

// Function to insert a term in a sorted linked list (by descending exponent)
struct node* insert_term(struct node *start, int coeff, int exp) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->link = NULL;

    // If list is empty or new term has highest exponent
    if (start == NULL || start->exp < exp) {
        new_node->link = start;
        return new_node;
    }

    // Traverse to find the correct position
    struct node *p = start;
    while (p->link != NULL && p->link->exp > exp) {
        p = p->link;
    }

    // Insert the new node
    new_node->link = p->link;
    p->link = new_node;
    return start;
}

// Function to print the polynomial
void print_polynomial(struct node *start) {
    struct node *p = start;
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%d x^%d", p->coeff, p->exp);
        p = p->link;
        if (p != NULL) printf(" + ");
    }
    printf("\n");
}

// Example usage
int main() {
    struct node *poly = NULL;
    // Create polynomial: 3x^3 - 6x^2 + 4x - 7
    poly = insert_term(poly, 3, 3);   // 3x^3
    poly = insert_term(poly, -6, 2);  // -6x^2
    poly = insert_term(poly, 4, 1);   // 4x
    poly = insert_term(poly, -7, 0);  // -7
    print_polynomial(poly);           // Output: 3 x^3 + -6 x^2 + 4 x^1 + -7 x^0
    return 0;
}
```

### How Will You Read the Syntax?
1. **Node Structure**:
   ```c
   struct node {
       int coeff;        // Stores the coefficient (e.g., 3 in 3x^3)
       int exp;          // Stores the exponent (e.g., 3 in x^3)
       struct node *link; // Points to the next term (node)
   };
   ```
   - **In simple terms**: Each node represents one term of the polynomial, with its coefficient, exponent, and a pointer to the next term.
2. **Insert Function**:
   - `struct node* insert_term(struct node *start, int coeff, int exp)`:
     - Takes the current list (`start`), coefficient, and exponent as input.
     - Creates a new node with `coeff` and `exp`.
     - Inserts the node in the correct position (sorted by descending exponent).
   - **Allocation**: `struct node *new_node = (struct node*)malloc(sizeof(struct node));`
     - Allocates memory for the new node.
     - **In simple terms**: Reserve space for a new term.
   - **Case 1**: If the list is empty (`start == NULL`) or the new term’s exponent is higher than the head’s, insert at the start.
   - **Case 2**: Traverse with pointer `p` until the correct position is found (where `p->link->exp <= exp`).
   - **Insertion**: Link the new node between `p` and `p->link`.
   - **In simple terms**: Add the term in the right spot so exponents stay sorted.
3. **Print Function**:
   - Traverses the list and prints each term in the format `coeff x^exp`.
   - Adds a `+` between terms unless it’s the last term.
   - **In simple terms**: Display the polynomial in a readable way.

### Visual Representation
![[Pasted image 20251014235850.png]]

### Approach to the Solution
1. **Goal**: Represent a polynomial like \(3x^3 - 6x^2 + 4x - 7\) as a linked list.
2. **Steps**:
   - Define a node structure with `coeff`, `exp`, and `link`.
   - Create a function to insert terms in sorted order (by exponent).
   - For each term (e.g., \(3x^3\)), create a node and insert it.
   - Print the list to verify the polynomial.
3. **Why Linked Lists?**:
   - Dynamic size: Easily add or remove terms.
   - Sorted order: Simplifies operations like polynomial addition.
4. **Edge Cases**:
   - **Empty Polynomial**: Handle `start == NULL`.
   - **Duplicate Exponents**: Combine coefficients (e.g., \(3x^2 + 4x^2 = 7x^2\)).
   - **Zero Coefficient**: Skip or remove terms with zero coefficients.

---

## Bivariate Polynomial (Two Variables)

### Introduction
A **bivariate polynomial** involves two variables (e.g., ($x$) and ($y$)).
Each term has a **coefficient** and **exponents** for both variables. 
For example, in ($6x^{2}y - 4xy^{2} + 3xy - 7x + 9y - 1$):- ($6x^2y$): Coefficient = 6, Exponent of ($x$) = 2, Exponent of ($y$) = 1
- ($-4xy^2$): Coefficient = -4, Exponent of ($x$) = 1, Exponent of ($y$) = 2
- ($3xy$): Coefficient = 3, Exponent of ($x$) = 1, Exponent of ($y$) = 1
- ($-7x$): Coefficient = -7, Exponent of ($x$) = 1, Exponent of ($y$) = 0
- ($9y$): Coefficient = 9, Exponent of ($x$) = 0, Exponent of ($y$) = 1
- ($-1$): Coefficient = -1, Exponent of ($x$) = 0, Exponent of ($y$) = 0

Each term is stored as a node with:
- **Coefficient**: The numerical multiplier.
- **Exponent of \(x\)**: Power of \(x\).
- **Exponent of \(y\)**: Power of \(y\).
- **Link**: Pointer to the next term.

The list is typically sorted by the total degree (sum of \(x\) and \(y\) exponents) or by \(x\)’s exponent first, then \(y\)’s.

### Runtime Complexity
- **Creation/Insertion**:
  - **O(n)**: Inserting a term requires traversing up to \(n\) nodes to maintain sorted order (e.g., by total degree or \(x\)-exponent).
- **Deletion**:
  - **O(n)**: Deleting a term requires traversing to find it.
- **Traversal/Evaluation**:
  - **O(n)**: Evaluating for given \(x\) and \(y\) values requires computing each term.
- **Addition of Two Polynomials**:
  - **O(n + m)**: Combine terms from two polynomials by comparing exponents of \(x\) and \(y\).
- **Space Complexity**:
  - **O(n)**: Proportional to the number of terms.

### Code
Here’s a sample C code for a bivariate polynomial:

```c
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a bivariate polynomial
struct node {
    int coeff;        // Coefficient of the term
    int exp_x;        // Exponent of x
    int exp_y;        // Exponent of y
    struct node *link; // Pointer to the next term
};

// Function to insert a term in sorted order (by total degree: exp_x + exp_y)
struct node* insert_term(struct node *start, int coeff, int exp_x, int exp_y) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp_x = exp_x;
    new_node->exp_y = exp_y;
    new_node->link = NULL;

    // If list is empty or new term has higher total degree
    if (start == NULL || (start->exp_x + start->exp_y) < (exp_x + exp_y)) {
        new_node->link = start;
        return new_node;
    }

    // Traverse to find the correct position
    struct node *p = start;
    while (p->link != NULL && (p->link->exp_x + p->link->exp_y) > (exp_x + exp_y)) {
        p = p->link;
    }

    // Insert the new node
    new_node->link = p->link;
    p->link = new_node;
    return start;
}

// Function to print the polynomial
void print_polynomial(struct node *start) {
    struct node *p = start;
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%d x^%d y^%d", p->coeff, p->exp_x, p->exp_y);
        p = p->link;
        if (p != NULL) printf(" + ");
    }
    printf("\n");
}

// Example usage
int main() {
    struct node *poly = NULL;
    // Create polynomial: 6x^2y - 4xy^2 + 3xy - 7x + 9y - 1
    poly = insert_term(poly, 6, 2, 1);   // 6x^2y
    poly = insert_term(poly, -4, 1, 2);  // -4xy^2
    poly = insert_term(poly, 3, 1, 1);   // 3xy
    poly = insert_term(poly, -7, 1, 0);  // -7x
    poly = insert_term(poly, 9, 0, 1);   // 9y
    poly = insert_term(poly, -1, 0, 0);  // -1
    print_polynomial(poly);              // Output: 6 x^2 y^1 + -4 x^1 y^2 + 3 x^1 y^1 + -7 x^1 y^0 + 9 x^0 y^1 + -1 x^0 y^0
    return 0;
}
```

### How Will You Read the Syntax?
1. **Node Structure**:
   ```c
   struct node {
       int coeff;        // Coefficient (e.g., 6 in 6x^2y)
       int exp_x;        // Exponent of x (e.g., 2 in x^2)
       int exp_y;        // Exponent of y (e.g., 1 in y^1)
       struct node *link; // Pointer to the next term
   };
   ```
   - **In simple terms**: Each node stores one term with its coefficient and exponents for \(x\) and \(y\).
2. **Insert Function**:
   - `struct node* insert_term(struct node *start, int coeff, int exp_x, int exp_y)`:
     - Takes the list, coefficient, and exponents for \(x\) and \(y\).
     - Creates a new node and inserts it in sorted order (by total degree: `exp_x + exp_y`).
   - **Allocation**: Allocates memory for the new node.
   - **Case 1**: If the list is empty or the new term’s total degree is higher, insert at the start.
   - **Case 2**: Traverse until the correct position is found (based on total degree).
   - **Insertion**: Link the new node in the correct position.
   - **In simple terms**: Add the term so the list stays sorted by total degree.
3. **Print Function**:
   - Prints each term as `coeff x^exp_x y^exp_y`.
   - Adds a `+` between terms.
   - **In simple terms**: Show the polynomial in a readable format.

### Visual Representation
![[Pasted image 20251015123310.png]]

### Approach to the Solution
1. **Goal**: Represent a polynomial like \(6x^2y - 4xy^2 + 3xy - 7x + 9y - 1\).
2. **Steps**:
   - Define a node with `coeff`, `exp_x`, `exp_y`, and `link`.
   - Insert terms in sorted order (e.g., by total degree or \(x\)-exponent then \(y\)-exponent).
   - For each term, create a node and insert it.
   - Print the list to verify.
3. **Why Linked Lists?**:
   - Flexible for adding/removing terms.
   - Sorted order simplifies polynomial operations.
4. **Edge Cases**:
   - **Empty Polynomial**: Handle `start == NULL`.
   - **Duplicate Terms**: Combine coefficients for terms with the same \(x\) and \(y\) exponents.
   - **Zero Coefficient**: Skip or remove terms with zero coefficients.

---

## Questions

### 1. What is the complexity to delete a given key value node from a sorted linked list?
- **Options**: O(1), O(log n), O(n), O(n log n)
- **Answer**: **O(n)**
- **Reasoning**:
  - In a **sorted singly linked list**, nodes are ordered by a key (e.g., value or exponent). To delete a node with a given key:
    - Traverse the list to find the node with the key or the node before it (since we need to update the previous node’s `link`).
    - In the worst case, the key is at the end or not present, requiring traversal of all \(n\) nodes.
  - **Why not O(1)?**: We can’t access the node directly without traversal (unlike an array with indexing).
  - **Why not O(log n)?**: Linked lists don’t support binary search due to sequential access.
  - **Why not O(n log n)?**: No sorting is needed; the list is already sorted.
  - **Steps**:
    - Traverse with a pointer until the node with the key is found or the previous node is identified.
    - Update the previous node’s `link` to skip the target node.
    - Free the target node.
  - **Time Complexity**: O(n) for traversal and deletion.

### 2. What is the complexity to remove a node from last and to insert it at the starting of a singly linked list?
- **Options**: O(1), O(log n), O(n), O(n log n)
- **Answer**: **O(n)**
- **Reasoning**:
  - **Removing the Last Node**:
    - In a singly linked list, we need to traverse to the second-to-last node to set its `link` to `NULL`.
    - This requires visiting up to \(n-1\) nodes, so it’s O(n).
  - **Inserting at the Start**:
    - Inserting at the start (updating `start` to point to the new node) is O(1).
  - **Overall Complexity**:
    - The operation involves:
      1. Traversing to the last node: O(n).
      2. Removing it by updating the second-to-last node’s `link`: O(1).
      3. Inserting the removed node at the start: O(1).
    - The dominant step is the traversal, so the total complexity is O(n).
  - **Why not O(1)?**: Removing the last node requires traversal.
  - **Why not O(log n) or O(n log n)?**: No logarithmic or sorting operations are involved.
  - **Edge Cases**:
    - **Single Node**: Remove and insert in O(1).
    - **Empty List**: Handle appropriately (no operation).

---

### Summary for Beginners
- **Linked Lists for Polynomials**:
  - Each term is a node with coefficient and exponent(s).
  - Linked lists allow dynamic addition/removal of terms.
  - Sorted order (by exponent or total degree) simplifies operations.
- **Univariate Polynomial**: One variable (\(x\)), node stores `coeff`, `exp`, and `link`.
- **Bivariate Polynomial**: Two variables (\(x\), \(y\)), node stores `coeff`, `exp_x`, `exp_y`, and `link`.
- **Key Operations**:
  - Insertion: O(n) to maintain sorted order.
  - Deletion: O(n) to find the term.
  - Printing/Evaluation: O(n) to process all terms.

### Advanced Notes
- **Optimizations**:
  - Use a **doubly linked list** to reduce deletion complexity in some cases.
  - Store terms in a hash table for O(1) lookup (but lose order).
- **Sorting Criteria**:
  - Univariate: Sort by exponent of \(x\).
  - Bivariate: Sort by total degree (\(exp_x + exp_y\)) or lexicographically (\(x\) then \(y\)).
- **Applications**:
  - Polynomial arithmetic (addition, multiplication).
  - Symbolic computation in tools like Mathematica or MATLAB.
- **Error Handling**:
  - Validate inputs (non-negative exponents, non-zero coefficients).
  - Handle duplicate terms by combining coefficients.
