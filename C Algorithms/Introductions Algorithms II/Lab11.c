#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strnode
{
    char str[5];          // String with at most 4 characters
    struct strnode *next; // Pointer to next node in list
};

struct strnode *create_node(char str[], struct strnode *next)
{
    struct strnode *newnode = malloc(sizeof(struct strnode));
    strcpy(newnode->str, str);
    newnode->next = next;
    return newnode;
}

struct strnode *free_node(struct strnode *node)
{
    struct strnode *next_node = NULL;
    if (node != NULL)
    {
        next_node = node->next;
        free(node);
    }
    return next_node;
}

void concat_nodes(struct strnode *head, char *str)
{
    if (head == NULL)
    {
        *str = '\0';
        return;
    }
    struct strnode *current = head;
    int index = 0;

    while (current != NULL)
    {
        strcpy(str + index, current->str);
        index += strlen(current->str);
        if (current->next != NULL)
        {
            *(str + index) = '-';
            index++;
        }
        current = current->next;
    }
}
// red blue fag
int main()
{
    char input[5];
    struct strnode *head = NULL;
    struct strnode *tail = NULL;

    while (1)
    {
        scanf("%4s", input);
        if (strcmp(input, "stop") == 0)
            break;
        struct strnode *new_node = create_node(input, NULL);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    char result[10000];
    concat_nodes(head, result);
    printf("%s\n", result);

    struct strnode *current = head;
    while (current != NULL)
    {
        struct strnode *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}