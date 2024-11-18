#include <stdio.h>
#include <string.h>

struct student
{
    int id;        // student ID
    char name[20]; // first name of student
};

int find_name(char *name, struct student arr[], int n, int ids[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
        {
            ids[count++] = arr[i].id;
        }
    }
    return count;
}

int main()
{
    struct student students[1000];
    int n = 0, ids[1000];
    char task[10], name[20];

    while (1)
    {
        scanf("%s", task);

        if (strcmp(task, "add") == 0)
        {
            scanf("%d %s", &students[n].id, students[n].name);
            n++;
        }
        else if (strcmp(task, "find") == 0)
        {
            scanf("%s", name);

            int found = find_name(name, students, n, ids);

            if (found == 0)
            {
                printf("Not found\n");
                break;
            }
            else
            {
                for (int i = 0; i < found; i++)
                {
                    printf("%d\n", ids[i]);
                }
                break;
            }
        }
    }

    return 0;
}
