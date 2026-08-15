#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
// Insert a node
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}
// Delete a node
struct Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node has no left child
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Node has no right child
        if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
// Inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node* root = NULL;
    int n, value, deleteValue;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("BST after insertion (Inorder): ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);
    root = deleteNode(root, deleteValue);
    printf("BST after deletion (Inorder): ");
    inorder(root);
    printf("\n");
    return 0;
}