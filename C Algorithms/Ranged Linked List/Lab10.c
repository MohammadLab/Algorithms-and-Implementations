#include <stdio.h>
#include <stdlib.h>

struct llnode
{
    int item;
    struct llnode *next;
};

struct llist
{
    struct llnode *front;
};

// list_range(n, m) returns a new list containing the integers between
//   n and m (inclusive) in ascending order
// requires: n <= m
// note: caller must free allocated memory
struct llist *list_range(const int n, const int m)
{
    struct llist *lst = malloc(sizeof(struct llist));
    struct llnode *old = NULL;
    lst->front = NULL;

    for (int i = n; i <= m; i++)
    {
        struct llnode *node = malloc(sizeof(struct llnode));

        node->item = i;
        node->next = NULL;

        if (old == NULL)
        {
            lst->front = node;
        }
        else
        {
            old->next = node;
        }
        old = node;
    }

    return lst;
}

void free_list(struct llist *lst)
{
    struct llnode *current = lst->front;
    while (current != NULL)
    {
        struct llnode *temp = current;
        current = current->next;
        free(temp);
    }
    free(lst);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct llist *list = list_range(n, m);
    struct llnode *current = list->front;
    if (current != NULL)
    {
        while (current->next != NULL)
        {
            printf("%d ", current->item);
            current = current->next;
        }
        printf("%d", current->item);
    }
    printf("\n");

    free_list(list);

    return 0;
}
