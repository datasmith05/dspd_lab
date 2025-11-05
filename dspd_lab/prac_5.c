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

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
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

int main()
{
    struct Node *root = NULL;
    int choice, value, n, i;

    while (1)
    {
        printf("\n BINARY TREE \n");
        printf("1. Insert \n");
        printf("2.Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Search \n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter %d values:\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &value);
                root = insert(root, value);
            }
            printf("Nodes inserted \n");
            break;
        case 2:
            printf("Inorder Traversal: ");
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                inorder(root);
                printf("\n");
            }
            break;

        case 3:
            printf("Preorder Traversal: ");
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                preorder(root);
                printf("\n");
            }
            break;

        case 4:
            printf("Postorder Traversal: ");
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                postorder(root);
                printf("\n");
            }
            break;

        case 5:
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

        case 6:
            printf("Exit\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
