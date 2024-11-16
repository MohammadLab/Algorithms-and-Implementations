#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int item)
{
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (node->key == key)
        return node;

    if (node->key < key)
        node->right = insert(node->right, key);

    else
        node->left = insert(node->left, key);

    return node;
}

struct Node *getSuccessor(struct Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct Node *delNode(struct Node *root, int x)
{

    // Base case
    if (root == NULL)
        return root;

    if (root->key > x)
        root->left = delNode(root->left, x);
    else if (root->key < x)
        root->right = delNode(root->right, x);
    else
    {

        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }
    return root;
}

struct Node *createNode(int key)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *search(struct Node *root, int key)
{

    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void treeprint(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < level; i++)
    {
        printf(i == level - 1 ? " |_" : "  ");
    }
    printf("%d\n", root->key);
    treeprint(root->right, level + 1);
    treeprint(root->left, level + 1);
}
/*
void print2DUtil(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->left, space);
}
*/

int main()
{
    struct Node *root = newNode(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 15);

    inorder(root);
    printf("\nTime for root 1: \n");

    clock_t start = clock();
    for (int i = 0; i < 100000; i++)
    {
        search(root, 1);
    }
    clock_t end = clock();
    double time_taken_1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("search(1) 100,000 times: %f seconds\n", time_taken_1); // using a c compiler I get 0.001126 seconds

    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        search(root, 1);
    }

    end = clock();
    double time_taken_15 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("search(15) 100,000 times: %f seconds\n", time_taken_15); // using a c compiler I get 0.000821 seconds
    printf("\n");

    struct Node *root2 = newNode(8);
    root2 = insert(root2, 4);
    root2 = insert(root2, 12);
    root2 = insert(root2, 2);
    root2 = insert(root2, 6);
    root2 = insert(root2, 10);
    root2 = insert(root2, 14);
    root2 = insert(root2, 1);
    root2 = insert(root2, 3);
    root2 = insert(root2, 5);
    root2 = insert(root2, 7);
    root2 = insert(root2, 9);
    root2 = insert(root2, 11);
    root2 = insert(root2, 13);
    root2 = insert(root2, 15);

    inorder(root2);
    printf("\nTime for root2: \n");

    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        search(root2, 1);
    }
    end = clock();
    double time_taken_1b = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("search(1) 100,000 times: %f seconds\n", time_taken_1); // using a c compiler I get 0.001302 seconds

    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        search(root2, 15);
    }

    end = clock();
    double time_taken_15b = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("search(15) 100,000 times: %f seconds\n", time_taken_15); // using a c compiler I get 0.001197 seconds
    printf("\n");

    delNode(root2, 8);
    inorder(root2);
    printf("\n\n");

    // print2DUtil(root2, 0);
    treeprint(root2, 0);

    return 0;
}

/*
Output via online c compiler
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Time for root 1:
search(1) 100,000 times: 0.000225 seconds
search(15) 100,000 times: 0.000313 seconds

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Time for root2:
search(1) 100,000 times: 0.000225 seconds
search(15) 100,000 times: 0.000313 seconds

*/