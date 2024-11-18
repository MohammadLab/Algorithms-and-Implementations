#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN_POWER 3
#define MAX_POWER 20

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int getBSTHeight(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getBSTHeight(root->left), getBSTHeight(root->right));
}

void freeBST(struct Node *root)
{
    if (root != NULL)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int height(struct AVLNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct AVLNode *newAVLNode(int key)
{
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    if (node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode *rightRotate(struct AVLNode *y)
{
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct AVLNode *leftRotate(struct AVLNode *x)
{
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct AVLNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct AVLNode *insertAVL(struct AVLNode *node, int key)
{
    if (node == NULL)
        return newAVLNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void freeAVL(struct AVLNode *root)
{
    if (root != NULL)
    {
        freeAVL(root->left);
        freeAVL(root->right);
        free(root);
    }
}

int *generateRandomArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int *getSortedArray(int *arr, int size)
{
    int *sorted = (int *)malloc(size * sizeof(int));
    if (sorted == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        sorted[i] = arr[i];
    }
    quickSort(sorted, 0, size - 1);
    return sorted;
}

int main()
{
    srand(time(NULL));

    printf("Tree Height Comparison (Random vs Sorted Arrays)\n");
    printf("================================================\n");
    printf("Size\t\tRandom Array\t\tSorted Array\n");
    printf("\t\tAVL\tBST\t\tAVL\tBST\n");
    printf("------------------------------------------------\n");

    for (int power = MIN_POWER; power <= MAX_POWER; power++)
    {
        int size = pow(2, power);

        int *randomArr = generateRandomArray(size);
        int *sortedArr = getSortedArray(randomArr, size);

        struct Node *bstRandom = NULL;
        struct AVLNode *avlRandom = NULL;
        clock_t startRandom = clock();

        for (int i = 0; i < size; i++)
        {
            bstRandom = insert(bstRandom, randomArr[i]);
            avlRandom = insertAVL(avlRandom, randomArr[i]);
        }

        clock_t endRandom = clock();
        double timeRandom = ((double)(endRandom - startRandom)) / CLOCKS_PER_SEC;

        struct Node *bstSorted = NULL;
        struct AVLNode *avlSorted = NULL;
        clock_t startSorted = clock();

        for (int i = 0; i < size; i++)
        {
            bstSorted = insert(bstSorted, sortedArr[i]);
            avlSorted = insertAVL(avlSorted, sortedArr[i]);
        }

        clock_t endSorted = clock();
        double timeSorted = ((double)(endSorted - startSorted)) / CLOCKS_PER_SEC;

        printf("2^%d\t\t%d\t%d\t\t%d\t%d\n", power, height(avlRandom), getBSTHeight(bstRandom), height(avlSorted), getBSTHeight(bstSorted));

        freeBST(bstRandom);
        freeAVL(avlRandom);
        freeBST(bstSorted);
        freeAVL(avlSorted);
        free(randomArr);
        free(sortedArr);
    }

    return 0;
}