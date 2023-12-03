#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *temp;

node *p, *q;

node *start = NULL;

int count = 0;

node *node_create(int val)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    count++;
    return temp;
}

node *insertion(node *start)
{
    int number;
    printf("\nEnter the number of elements to be addded : ");
    scanf("%d", &number);
    int val;
    for (int i = 0; i < number; i++)
    {
        printf("\nEnter the %d element : ", (i + 1));
        scanf("%d", &val);
        // temp = (node *) malloc (sizeof(node));
        // temp -> data = val;
        // temp -> next = NULL;
        node_create(val);

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            p = start;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return start;
}

node *insertion_beg(node *start)
{
    printf("\nEnter the element to enter in the beggining : ");
    int val;
    scanf("%d", &val);
    node_create(val);
    temp->next = start;
    start = temp;
    return start;
}

node *insertion_position(node *start)
{
    printf("\nEnter the position to enter :");
    int pos;
    scanf("%d", &pos);
    printf("\nEnter the number to enter at %d position", pos);
    int val;
    scanf("%d", &val);
    p = start;
    q = NULL;
    node_create(val);
    for (int i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
    return start;
}

node *insertion_end(node *start)
{
    int val;

    printf("\nEnter the element : ");
    scanf("%d", &val);

    node_create(val);

    p = start;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return start;
}

node *display(node *start)
{

    p = start;

    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }

    return start;
}

node *deletion_beg(node *start)
{
    p = start;
    p = p->next;
    start = p;
    free(p);
    return start;
}

node *deletion_end(node *start)
{
    p = start;
    q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return start;
}

node *deletion_pos(node *start)
{
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    p = start;
    q = p;
    for (int i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next = NULL;
    free(p);
    return start;
}

node * reverse (node *start) {
    node * prev , * curr , *nex ;
    prev = NULL ;
    curr = nex = start;

    while (nex != NULL) {
        nex = nex -> next;
        curr -> next = prev;
        prev = curr;
        curr = nex;
    }
    start = prev;
    return start;
}
node * length (node *start) {
    int count = 0;
    p = start;
    while (p != NULL) {
        count++;
        p = p -> next;
    }
    printf("%d",count);
    return start;
}

int main()
{
    int option;
    do
    {

        printf("\n***********MAIN MENU************");
        printf("\n1. Insertion of the elements.");
        printf("\n2. Enter the element at the begginin.");
        printf("\n3. Enter the element at a particular position.");
        printf("\n4. Enter the element at the end.");
        printf("\n5. Display the LinkedList.");
        printf("\n6. Delete the element at the begginin.");
        printf("\n7. Delete the element at a particular position.");
        printf("\n8. Delete the element at the end.");
        printf("\n9. Reverse.");
        printf("\n10. Length of the Linked list.");
        printf("\n11.END");
        printf("\n************THE END*************");

        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insertion(start);
            break;

        case 2:
            start = insertion_beg(start);
            break;

        case 3:
            start = insertion_position(start);
            break;

        case 4:
            start = insertion_end(start);
            break;

        case 5:
            start = display(start);
            break;

        case 6:
            start = deletion_beg(start);
            break;

        case 7:
            start = deletion_pos(start);
            break;

        case 8:
            start = deletion_end(start);
            break;

        case 9:
            start = reverse(start);
            break;
        
        case 10:
            start = length(start);
            break;

        case 11:
            free(temp);
            break;

        default:
            printf("Enter the valid option.");
            break;
        }
    } while (option != 11);
}