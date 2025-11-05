#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Element %d inserted successfully\n", value);
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Element %d already exists \n", value);
    }
    return root;
}

int search(struct Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == value)
    {
        return 1;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}
int isLeaf(struct Node *node)
{
    return (node->left == NULL && node->right == NULL);
}

struct Node *delete(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        if (isLeaf(root))
        {
            printf("Leaf node %d deleted successfully\n", value);
            free(root);
            return NULL;
        }
        else
        {
            printf("Element %d is cannot delete\n", value);
        }
    }
    return root;
}

void display(struct Node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nBST OPERATIONS MENU \n");
        printf("1. Search \n");
        printf("2. Insert \n");
        printf("3. Delete  \n");
        printf("4. Display Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
            {
                printf("Found\n");
            }
            else
            {
                printf("NULL\n");
            }
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &value);
            root = delete(root, value);
            break;

        case 4:
            printf("binary search tree: ");
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                display(root);
                printf("\n");
            }
            break;

        case 5:
            printf("Exit\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
