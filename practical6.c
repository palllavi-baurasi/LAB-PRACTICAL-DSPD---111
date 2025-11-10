// Implement BST with following Menu operations :
// 1 . search an element in BST
// 2 . Insert an element in BST 
// 3 . Delete leaf elements in BST
// 4 . EXIT

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an element in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search an element in BST
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (root->data == key) {
        printf("Found\n");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to check if node is a leaf
int isLeaf(struct Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Function to delete a leaf node
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (isLeaf(root)) {
            printf("Leaf node %d deleted successfully.\n", root->data);
            free(root);
            return NULL;
        } else {
            printf("%d is not a leaf node. Cannot delete.\n", root->data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;

    do {
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                printf("Search result: ");
                search(root, key);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element inserted successfully!\n");
                break;

            case 3:
                printf("Enter leaf node to delete: ");
                scanf("%d", &key);
                root = deleteLeaf(root, key);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

// Output:
// --- Binary Search Tree Menu ---
// 1. Search an element in BST
// 2. Insert an element in BST
// 3. Delete leaf element in BST
// 4. Exit
// Enter your choice: 2
// Enter element to insert: 25
// Element inserted successfully!


// --- Binary Search Tree Menu ---
// 1. Search an element in BST
// 2. Insert an element in BST
// 3. Delete leaf element in BST
// 4. Exit
// Enter your choice: 2
// Enter element to insert: 36
// Element inserted successfully!


// --- Binary Search Tree Menu ---
// 1. Search an element in BST
// 2. Insert an element in BST
// 3. Delete leaf element in BST
// 4. Exit
// Enter your choice: 2
// Enter element to insert: 78
// Element inserted successfully!


// --- Binary Search Tree Menu ---
// 1. Search an element in BST
// 2. Insert an element in BST
// 3. Delete leaf element in BST
// 4. Exit
// Enter your choice: 1
// Enter element to search: 78
// Search result: Found


// --- Binary Search Tree Menu ---
// 1. Search an element in BST
// 2. Insert an element in BST
// 3. Delete leaf element in BST
// 4. Exit
// Enter your choice: 4
// Exiting program... 
