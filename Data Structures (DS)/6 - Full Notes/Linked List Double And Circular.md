## Disadvantages of Singly List
- Link part of last node is not utilized - (Solution Circular Linked List) 
- address of predecessor is not known - (Solution Doubly Linked List)
- stepping backward is not possible - (Solution Doubly Linked List)

### Header List

- Contain Special First Node Called Header Node
- Header Node Contains some summery information 

Visual Reference:-
![[Pasted image 20251015144814.png]]

#### Grounded Header List

Last Node->link will be NULL


Visual Representation:-
![[Pasted image 20251015145010.png]]


#### Circular Header List


Last Node->link will have header node address

Visual Representation:-
![[Pasted image 20251015144911.png]]


### Traversing In Header List

Traversing In Grounded List
```c
struct node *p = list -> link
while(p!=NULL){
	process p->data;
	p = p -> link;
}
```


Traversing In Circular List
```c
struct node *p = list -> link
while(p!=list){
	process p->data;
	p = p -> link;
}
```

Visual Representation:-
![[Pasted image 20251015145910.png]]


# Doubly Linked List

Node Will have 3 sections now
- Data
- next
- prev

Code
```c
struct dnode{
	char data;
	struct dnode *next;
	struct dnode *prev;
};
```

Visual Reference:-
![[Pasted image 20251015150111.png]]
![[Pasted image 20251015150150.png]]


## Insertion At Start

code
```c

```

logic

visual reference:-
![[Pasted image 20251015150429.png]]

## Insertion After A Node

code
```c

```

logic

visual reference:-
![[Pasted image 20251015150608.png]]


## Insertion Before A Node

code
```c

```

logic

visual reference:-
![[Pasted image 20251015150807.png]]  

## Insertion At The End: Last Given

code
```c

```

logic

visual reference:-
![[Pasted image 20251015151042.png]]

## Insertion At The End: Last Not Given        

Visual Reference:-
![[Pasted image 20251015151237.png]]


## Deletion From Starting

logic

code
```c

```

Visual Reference:-
![[Pasted image 20251015151422.png]]

## Deletion Of A Given Node

logic

code
```c

```

Visual Reference:-
![[Pasted image 20251015151547.png]]

## Deletion At The End: Last Given

logic

code
```c

```

Visual Reference:-
![[Pasted image 20251015151640.png]]

## Deletion At The End: Last Not Given

logic

code
```c

```

Visual Reference:-
![[Pasted image 20251015151819.png]]

## Questions

1. What is the complexity to insert at starting of a circular singly linked list
	- O(1)
	- O(log n)
	- O(n)
	- O(n log n)
2. What is the complexity to remove a node from the last from a circular singly linked list ?
	Note: Address Of The Last Node Is Given
	- O(1)
	- O(log n)
	- O(n)
	- O(n log n)


---


## Disadvantages of Singly Linked List

A **singly linked list** is a data structure where each node contains data and a pointer (link) to the next node. While simple and memory-efficient, it has limitations that make certain operations inefficient or impossible. Let’s explore these disadvantages and their solutions.

### 1. Link Part of Last Node Is Not Utilized
- **Explanation for Beginners**: In a singly linked list, each node has a data part and a link (pointer) to the next node. The last node’s link points to **NULL**, indicating the end of the list. This means the last node’s link field is unused, which is a minor waste of memory and limits certain operations (e.g., looping back to the start).
- **Why It’s a Problem**: You cannot directly access the first node from the last node, making operations like circular traversal impossible without additional pointers.
- **Solution: Circular Linked List**
  - In a **circular linked list**, the last node’s link points back to the first node, forming a loop. This utilizes the last node’s link and allows continuous traversal (e.g., going from the last node to the first without restarting).
  - **Example**: Imagine a playlist on repeat; after the last song, it goes back to the first song.
  - **Advanced Note**: Circular linked lists are useful in applications like round-robin scheduling or cyclic buffers, where you need to cycle through elements repeatedly.
- **Visual Reference Description**: The visual likely shows a singly linked list with nodes (e.g., A → B → C → NULL), where the last node’s link is NULL, and contrasts it with a circular linked list (e.g., A → B → C → A), where the last node points back to the first.

### 2. Address of Predecessor Is Not Known
- **Explanation for Beginners**: In a singly linked list, each node only knows the address of the **next** node, not the **previous** one. If you’re at a node (say, Node B), you cannot find the node before it (Node A) without traversing the list from the start.
- **Why It’s a Problem**: Operations like deleting a node or inserting before a given node require knowing the predecessor. To find it, you must traverse the list from the head, which takes O(n) time, making these operations slow.
- **Solution: Doubly Linked List**
  - A **doubly linked list** has nodes with pointers to both the next and previous nodes. This allows direct access to the predecessor, making operations like deletion or insertion before a node more efficient (O(1) if the node is given).
  - **Example**: Think of a browser’s back and forward buttons; you can move in both directions because each page knows the previous and next pages.
  - **Advanced Note**: The trade-off is increased memory usage (two pointers per node instead of one) and more complex pointer updates during insertions/deletions.
- **Visual Reference Description**: The visual likely shows a singly linked list (A → B → C) where each node has only a next pointer, and a doubly linked list (A ↔ B ↔ C) where each node has both next and prev pointers.

### 3. Stepping Backward Is Not Possible
- **Explanation for Beginners**: Since a singly linked list only has forward links, you can’t move backward (e.g., from Node B to Node A). To access a previous node, you’d need to start from the head and traverse again, which is time-consuming.
- **Why It’s a Problem**: Operations requiring backward movement (e.g., reversing the list or accessing the previous node) are inefficient, requiring O(n) time to restart from the head.
- **Solution: Doubly Linked List**
  - As mentioned, a doubly linked list allows backward traversal using the **prev** pointer, enabling operations like moving backward or reversing the list in O(1) per step.
  - **Example**: Like a two-way street, you can travel forward or backward, unlike a one-way street (singly linked list).
  - **Advanced Note**: Backward traversal is useful in applications like undo/redo functionality or navigating a playlist in both directions.
- **Visual Reference Description**: Similar to the previous visual, it likely contrasts the one-way arrows of a singly linked list with the two-way arrows of a doubly linked list.

---

## Header List

A **header list** is a variation of a linked list that includes a special first node called the **header node**. This node doesn’t store actual data but holds metadata or serves as a placeholder to simplify list operations.

### Contain Special First Node Called Header Node
- **Explanation for Beginners**: A header list starts with a **header node**, which is like a title page in a book. It doesn’t hold the main content (data) but provides information about the list, such as the number of nodes, or acts as a starting point for traversal.
- **Purpose**: The header node simplifies operations like insertion at the start or traversal by providing a fixed starting point. It avoids special cases (e.g., handling an empty list differently).
- **Example**: Think of a table of contents in a book; it’s not a chapter but helps you navigate the chapters.
- **Advanced Note**: The header node can store metadata (e.g., list size, type of data) or be empty (just a placeholder). It’s especially useful in algorithms where the first node needs consistent handling.

### Header Node Contains Some Summary Information
- **Explanation for Beginners**: The header node might store information like the total number of nodes, the type of data in the list, or a pointer to the first actual data node. This makes it easier to manage the list.
- **Example**: In a music playlist, the header node might store the playlist name or the number of songs, while the actual nodes store song details.
- **Advanced Note**: The summary information can be customized based on the application (e.g., maximum value in the list, sum of elements). This reduces the need to traverse the list for such information, improving efficiency.
- **Visual Reference Description**: The visual likely shows a list starting with a header node (e.g., labeled “Header”) followed by data nodes (e.g., Header → A → B → C). The header node may have fields like “count” or “type” to indicate summary information.

#### Grounded Header List
- **Explanation for Beginners**: A **grounded header list** is a header list where the last node’s link points to **NULL**, just like a regular singly linked list. The header node is just a starting point, and the list has a definite end.
- **Key Feature**: The header node simplifies operations, but the list behaves like a standard singly linked list after the header.
- **Example**: Imagine a train with a locomotive (header node) that doesn’t carry passengers but leads to passenger cars (data nodes), and the last car has no connection forward (NULL).
- **Advanced Note**: Grounded header lists are simpler to implement than circular ones and are used when a linear structure is sufficient.
- **Visual Reference Description**: The visual likely shows a list like Header → A → B → C → NULL, where the header node points to the first data node, and the last node’s link is NULL.

#### Circular Header List
- **Explanation for Beginners**: In a **circular header list**, the last node’s link points back to the **header node**, forming a loop. This means you can keep traversing the list forever, starting from the header.
- **Key Feature**: The header node is part of the loop, making it easy to return to the start without resetting the pointer.
- **Example**: Like a merry-go-round, you can keep going around, and the header node is like the operator’s booth you pass each time.
- **Advanced Note**: Circular header lists are useful for applications requiring cyclic access, like scheduling tasks or buffering data. The header node simplifies loop management.
- **Visual Reference Description**: The visual likely shows a list like Header → A → B → C → Header, where the last node’s link points back to the header node, forming a closed loop.

---

### Traversing in Header List

**Traversal** means visiting each node in the list to process its data (e.g., print it, sum it, etc.). The traversal method differs slightly for grounded and circular header lists due to their structure.

#### Traversing in Grounded List
- **Explanation for Beginners**: In a grounded header list, you start from the node after the header (since the header doesn’t hold data) and move forward until you reach NULL.
- **Logic**:
  1. Start with a pointer `p` at the header’s link (first data node).
  2. While `p` is not NULL, process the data at `p` and move to the next node (`p = p->link`).
  3. Stop when `p` becomes NULL (end of the list).
- **Code**:
  ```c
  struct node *p = list->link; // Start from first data node
  while (p != NULL) {
      process(p->data); // Process current node's data (e.g., print)
      p = p->link;      // Move to next node
  }
  ```
- **Example**: If the list is Header → 1 → 2 → 3 → NULL, traversal prints 1, 2, 3.
- **Advanced Note**: The header node simplifies traversal by providing a consistent starting point. The time complexity is O(n), where n is the number of data nodes.
- **Visual Reference Description**: The visual likely shows a grounded header list with arrows from the header to data nodes, ending at NULL, and a pointer moving from node to node during traversal.

#### Traversing in Circular List
- **Explanation for Beginners**: In a circular header list, you start from the node after the header and move forward until you reach the header node again (since the last node points back to the header).
- **Logic**:
  1. Start with a pointer `p` at the header’s link (first data node).
  2. While `p` is not back at the header node (`list`), process the data at `p` and move to the next node (`p = p->link`).
  3. Stop when `p` equals the header node (loop complete).
- **Code**:
  ```c
  struct node *p = list->link; // Start from first data node
  while (p != list) {
      process(p->data); // Process current node's data
      p = p->link;      // Move to next node
  }
  ```
- **Example**: If the list is Header → 1 → 2 → 3 → Header, traversal prints 1, 2, 3.
- **Advanced Note**: The circular structure avoids the need for a NULL check, but you must check for the header node to avoid an infinite loop. Time complexity is O(n).
- **Visual Reference Description**: The visual likely shows a circular header list with arrows forming a loop, and a pointer moving from node to node until it reaches the header again.

---

# Doubly Linked List

A **doubly linked list** is a data structure where each node contains three parts: data, a pointer to the next node, and a pointer to the previous node. This allows traversal in both directions, overcoming limitations of singly linked lists.

### Node Structure
- **Explanation for Beginners**: Each node in a doubly linked list is like a person holding hands with the person in front (next) and behind (prev). The node stores:
  - **Data**: The actual information (e.g., a number, character).
  - **Next**: A pointer to the next node.
  - **Prev**: A pointer to the previous node.
- **Code**:
  ```c
  struct dnode {
      char data;          // Data part (can be any type)
      struct dnode *next; // Pointer to next node
      struct dnode *prev; // Pointer to previous node
  };
  ```
- **Example**: In a list A ↔ B ↔ C, node B’s `next` points to C, and `prev` points to A.
- **Advanced Note**: The prev pointer enables O(1) access to the predecessor, making operations like deletion or insertion before a node efficient. However, each node uses more memory (two pointers instead of one).
- **Visual Reference Description**: The visuals likely show nodes with three fields (data, next, prev) and arrows showing bidirectional links (e.g., A ↔ B ↔ C). One visual may show a single node’s structure, another the entire list.

---

## Insertion at Start

Inserting a node at the beginning of a doubly linked list involves creating a new node and adjusting the pointers to make it the new first node.

- **Logic**:
  1. Create a new node with the given data.
  2. Set the new node’s `prev` to NULL (since it’s the first node).
  3. Set the new node’s `next` to the current head (if the list is not empty).
  4. If the list is not empty, update the current head’s `prev` to point to the new node.
  5. Update the head pointer to the new node.
- **Code**:
  ```c
  struct dnode* insert_at_start(struct dnode *head, char data) {
      struct dnode *new_node = (struct dnode*)malloc(sizeof(struct dnode));
      new_node->data = data;
      new_node->prev = NULL;
      new_node->next = head;
      if (head != NULL) {
          head->prev = new_node;
      }
      return new_node; // New head
  }
  ```
- **Example**: Inserting ‘X’ into A ↔ B results in X ↔ A ↔ B.
- **Advanced Note**: Time complexity is O(1) since no traversal is needed. This is more efficient than a singly linked list, where insertion at the start is also O(1) but lacks backward links.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) and a new node X being added at the start, with arrows updated to show X ↔ A ↔ B.

---

## Insertion After a Node

Inserting a node after a given node in a doubly linked list involves placing the new node between the given node and its next node.

- **Logic**:
  1. Create a new node with the given data.
  2. Set the new node’s `next` to the given node’s `next`.
  3. Set the new node’s `prev` to the given node.
  4. If the given node’s `next` is not NULL, update its `prev` to the new node.
  5. Update the given node’s `next` to the new node.
- **Code**:
  ```c
  void insert_after(struct dnode *node, char data) {
      if (node == NULL) return;
      struct dnode *new_node = (struct dnode*)malloc(sizeof(struct dnode));
      new_node->data = data;
      new_node->next = node->next;
      new_node->prev = node;
      if (node->next != NULL) {
          node->next->prev = new_node;
      }
      node->next = new_node;
  }
  ```
- **Example**: Inserting ‘X’ after node A in A ↔ B results in A ↔ X ↔ B.
- **Advanced Note**: Time complexity is O(1) if the node is given, as only pointer updates are needed. In a singly linked list, finding the predecessor would take O(n).
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) with a new node X inserted after A, updating arrows to show A ↔ X ↔ B.

---

## Insertion Before a Node

Inserting a node before a given node in a doubly linked list is efficient because the `prev` pointer provides direct access to the predecessor.

- **Logic**:
  1. Create a new node with the given data.
  2. Set the new node’s `prev` to the given node’s `prev`.
  3. Set the new node’s `next` to the given node.
  4. Update the given node’s `prev` to the new node.
  5. If the new node’s `prev` is not NULL, update its `next` to the new node.
  6. If the given node was the head, update the head to the new node.
- **Code**:
  ```c
  struct dnode* insert_before(struct dnode *head, struct dnode *node, char data) {
      if (node == NULL) return head;
      struct dnode *new_node = (struct dnode*)malloc(sizeof(struct dnode));
      new_node->data = data;
      new_node->next = node;
      new_node->prev = node->prev;
      node->prev = new_node;
      if (new_node->prev != NULL) {
          new_node->prev->next = new_node;
      }
      if (node == head) {
          head = new_node;
      }
      return head;
  }
  ```
- **Example**: Inserting ‘X’ before node B in A ↔ B results in A ↔ X ↔ B.
- **Advanced Note**: Time complexity is O(1) if the node is given, thanks to the `prev` pointer. In a singly linked list, this would require O(n) to find the predecessor.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) with a new node X inserted before B, updating arrows to show A ↔ X ↔ B.

---

## Insertion at the End: Last Node Given

Inserting a node at the end of a doubly linked list is efficient if the last node is given, as no traversal is needed.

- **Logic**:
  1. Create a new node with the given data.
  2. Set the new node’s `next` to NULL (it’s the new last node).
  3. Set the new node’s `prev` to the last node.
  4. Update the last node’s `next` to the new node.
- **Code**:
  ```c
  void insert_at_end_given_last(struct dnode *last, char data) {
      if (last == NULL) return;
      struct dnode *new_node = (struct dnode*)malloc(sizeof(struct dnode));
      new_node->data = data;
      new_node->next = NULL;
      new_node->prev = last;
      last->next = new_node;
  }
  ```
- **Example**: Inserting ‘X’ after last node B in A ↔ B results in A ↔ B ↔ X.
- **Advanced Note**: Time complexity is O(1) since the last node is given. In a singly linked list, this would be O(1) too, but the doubly linked list also updates the `prev` pointer.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) with a new node X added after B, updating arrows to show A ↔ B ↔ X, with X’s `next` as NULL.

---

## Insertion at the End: Last Node Not Given

If the last node is not given, you must traverse the list to find it before inserting.

- **Logic**:
  1. Create a new node with the given data.
  2. If the list is empty, make the new node the head (with `next` and `prev` as NULL).
  3. Otherwise, traverse to the last node (where `next` is NULL).
  4. Set the new node’s `next` to NULL and `prev` to the last node.
  5. Update the last node’s `next` to the new node.
- **Code**:
  ```c
  struct dnode* insert_at_end(struct dnode *head, char data) {
      struct dnode *new_node = (struct dnode*)malloc(sizeof(struct dnode));
      new_node->data = data;
      new_node->next = NULL;
      if (head == NULL) {
          new_node->prev = NULL;
          return new_node;
      }
      struct dnode *p = head;
      while (p->next != NULL) {
          p = p->next;
      }
      p->next = new_node;
      new_node->prev = p;
      return head;
  }
  ```
- **Example**: Inserting ‘X’ into A ↔ B results in A ↔ B ↔ X.
- **Advanced Note**: Time complexity is O(n) due to traversal to find the last node. Maintaining a tail pointer (pointing to the last node) can reduce this to O(1).
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) with a new node X added at the end, updating arrows to show A ↔ B ↔ X.

---

## Deletion from Starting

Deleting the first node in a doubly linked list involves updating the head and the `prev` pointer of the new first node.

- **Logic**:
  1. If the list is empty, do nothing.
  2. Store the current head in a temporary pointer.
  3. Update the head to the next node.
  4. If the new head is not NULL, set its `prev` to NULL.
  5. Free the temporary node.
- **Code**:
  ```c
  struct dnode* delete_from_start(struct dnode *head) {
      if (head == NULL) return NULL;
      struct dnode *temp = head;
      head = head->next;
      if (head != NULL) {
          head->prev = NULL;
      }
      free(temp);
      return head;
  }
  ```
- **Example**: Deleting A from A ↔ B results in B (with `prev` as NULL).
- **Advanced Note**: Time complexity is O(1). In a singly linked list, this is also O(1), but the doubly linked list requires updating the `prev` pointer.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B) with A removed, resulting in B as the new head with `prev` as NULL.

---

## Deletion of a Given Node

Deleting a specific node (given its address) involves adjusting the pointers of its neighbors.

- **Logic**:
  1. If the node is NULL or the list is empty, do nothing.
  2. If the node is the head, use deletion from start logic.
  3. Otherwise, set the `next` of the node’s `prev` to the node’s `next`.
  4. Set the `prev` of the node’s `next` (if not NULL) to the node’s `prev`.
  5. Free the node.
- **Code**:
  ```c
  struct dnode* delete_node(struct dnode *head, struct dnode *node) {
      if (head == NULL || node == NULL) return head;
      if (node == head) {
          head = head->next;
          if (head != NULL) head->prev = NULL;
          free(node);
          return head;
      }
      if (node->prev != NULL) {
          node->prev->next = node->next;
      }
      if (node->next != NULL) {
          node->next->prev = node->prev;
      }
      free(node);
      return head;
  }
  ```
- **Example**: Deleting B from A ↔ B ↔ C results in A ↔ C.
- **Advanced Note**: Time complexity is O(1) if the node is given, thanks to the `prev` pointer. In a singly linked list, this would be O(n) to find the predecessor.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B ↔ C) with B removed, updating arrows to show A ↔ C.

---

## Deletion at the End: Last Node Given

Deleting the last node when its address is given is efficient due to direct access.

- **Logic**:
  1. If the list is empty or the node is NULL, do nothing.
  2. If the node is the only node, set head to NULL and free the node.
  3. Otherwise, set the `next` of the node’s `prev` to NULL.
  4. Free the node.
- **Code**:
  ```c
  struct dnode* delete_last_given(struct dnode *head, struct dnode *last) {
      if (head == NULL || last == NULL) return head;
      if (head == last) {
          free(last);
          return NULL;
      }
      last->prev->next = NULL;
      free(last);
      return head;
  }
  ```
- **Example**: Deleting C from A ↔ B ↔ C results in A ↔ B.
- **Advanced Note**: Time complexity is O(1). Maintaining a tail pointer can make this operation straightforward in practice.
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B ↔ C) with C removed, updating arrows to show A ↔ B with B’s `next` as NULL.

---

## Deletion at the End: Last Node Not Given

If the last node is not given, you must traverse to find it.

- **Logic**:
  1. If the list is empty, do nothing.
  2. If there’s only one node, free it and set head to NULL.
  3. Traverse to the last node (where `next` is NULL).
  4. Set the `next` of the last node’s `prev` to NULL.
  5. Free the last node.
- **Code**:
  ```c
  struct dnode* delete_last(struct dnode *head) {
      if (head == NULL) return NULL;
      if (head->next == NULL) {
          free(head);
          return NULL;
      }
      struct dnode *p = head;
      while (p->next != NULL) {
          p = p->next;
      }
      p->prev->next = NULL;
      free(p);
      return head;
  }
  ```
- **Example**: Deleting C from A ↔ B ↔ C results in A ↔ B.
- **Advanced Note**: Time complexity is O(n) due to traversal. A tail pointer would reduce this to O(1).
- **Visual Reference Description**: The visual likely shows a list (e.g., A ↔ B ↔ C) with C removed after traversal, updating arrows to show A ↔ B.

---

## Questions

### 1. What is the complexity to insert at the starting of a circular singly linked list?
- **Answer**: O(1)
- **Explanation**:
  - In a circular singly linked list, insertion at the start involves creating a new node and updating pointers:
    1. Set the new node’s `link` to the current head.
    2. Update the last node’s `link` to point to the new node (if the list is not empty).
    3. Update the head to the new node.
  - If a tail pointer (pointing to the last node) is maintained, updating the last node’s `link` is O(1).
  - Even without a tail pointer, in some implementations, the head’s `link` can be adjusted directly, keeping it O(1).
  - **Why not O(n)?** Unlike insertion at the end (which may require traversal to find the last node), insertion at the start only involves the head and possibly the last node (accessible via a tail pointer or head’s link in a circular list).

### 2. What is the complexity to remove a node from the last from a circular singly linked list? (Note: Address of the last node is given)
- **Answer**: O(1)
- **Explanation**:
  - If the last node’s address is given, deletion involves:
    1. Updating the second-to-last node’s `link` to point to the head (maintaining the circular structure).
    2. Freeing the last node.
  - Since the last node is given, no traversal is needed to find it or its predecessor (the predecessor’s `link` points to the last node).
  - The head pointer may need updating if the list becomes empty, but this is a constant-time operation.
  - **Why not O(n)?** In a singly linked list, finding the predecessor of the last node requires O(n) traversal, but in a circular list with the last node given, the predecessor’s `link` can be updated directly in O(1).

---

These notes provide a comprehensive understanding of singly linked lists, header lists, and doubly linked lists, including their operations, advantages, disadvantages, and complexities. Each section starts with beginner-friendly explanations and progresses to advanced insights, ensuring clarity for all levels of learners. Let me know if you need further clarification or additional details!