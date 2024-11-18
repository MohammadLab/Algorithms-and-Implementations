#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct student
{
    int id;     // student ID
    char *name; // first name of student
};

// create_student(id, name) creates a new student record with given id and name;
//   allocates memory to store structure and name (caller must free with
//   free_student); returns a pointer to the structure, or NULL if memory
//   allocation fails
// requires: name points to a valid string
struct student *create_student(const int id, const char *name)
{
    struct student *new_student = malloc(sizeof(struct student));
    if (new_student == NULL)
    {
        return NULL;
    }

    new_student->id = id;

    new_student->name = malloc(strlen(name) + 1);
    if (new_student->name == NULL)
    {
        free(new_student);
        return NULL;
    }
    strcpy(new_student->name, name);
    return new_student;
}

// change_name(s, new_name) renames the student s to have the name given by
//   new_name; returns true when the name was successfully changed
// requires: s points to a valid student and new_name points to a valid string

bool change_name(struct student *s, const char *new_name)
{

    if (s == NULL || new_name == NULL)
    {
        return false;
    }

    char *temp = realloc(s->name, strlen(new_name) + 1);
    if (temp == NULL)
    {
        return false;
    }
    s->name = temp;

    strcpy(s->name, new_name);

    return true;
}

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student *s)
{
    free(s->name);
    free(s);
}

// print_student() prints the ID and then the name of the given student s
//   the ID and name are separated by a single space and end with a newline
void print_student(const struct student *s)
{
    printf("%d ", s->id);
    printf("%s\n", s->name);
}

int main(void)
{

    struct student *student1 = create_student(10000001, "Andrew");
    struct student *student2 = create_student(10000002, "Tristan");
    struct student *student3 = create_student(110139413, "Mohammad");

    // student 1
    assert(student1 != NULL);
    assert(student1->id == 10000001);

    assert(strcmp(student1->name, "Andrew") == 0);
    // student 2
    assert(student2->id == 10000002);
    assert(strcmp(student2->name, "Tristan") == 0);
    // me
    assert(student3->id == 110139413);
    assert(strcmp(student3->name, "Mohammad") == 0);

    // change test
    const char *new_name = "Luc";
    bool changed = change_name(student1, "Luc");
    assert(strcmp(student1->name, new_name) == 0);

    free(student1->name);
    free(student1);
    free(student2->name);
    free(student2);
    free(student3->name);
    free(student3);
    // ====================================================
    // Automatic Testing on Codeforces (DO NOT CHANGE THIS)
    // If the tests don't pass, update your functions
    // ====================================================
    int id, namelen;
    scanf("%d", &id);
    scanf("%d", &namelen);
    char *sname = malloc(sizeof(char) * (namelen + 1));
    scanf("%s", sname);
    struct student *s = create_student(id, sname);
    free(sname);
    print_student(s);
    sname = malloc(sizeof(char) * (namelen + 1));
    scanf("%s", sname);
    change_name(s, sname);
    free(sname);
    print_student(s);
    free_student(s);
}