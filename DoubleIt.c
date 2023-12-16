#include "logic.c"
Node *doubleIt(Node *head)
{

    Node *p = head;
    if (head->next == NULL)
    {
        p->data = p->data * 2;
        if (p->data >= 10)
        {
            Node *nn = (Node *)malloc(sizeof(Node));
            nn->data = 1;
            nn->next = p;
            head = nn;
        }
        return head;
    }
    Node *q = p->next;
    if (head->data * 2 >= 10)
    {
        Node *nn = (Node *)malloc(sizeof(Node));
        nn->data = 1;
        nn->next = p;
        head = nn;
    }
    while (q != NULL)
    {
        if (q->data >= 5)
        {
            printf("%d ", p->data);
            p->data = (p->data * 2 + 1) % 10;
        }
        else
        {
            printf("%d ", p->data);

            p->data = p->data * 2 % 10;
        }

        p = p->next;
        q = q->next;
        printf("%p \n",q);
    }
    

    // p = p->next;
    printf("%d ", p->data);
    p->data = (p->data * 2) % 10;

    return head;
}
int main(int argc, char const *argv[])
{
    Node *head;
    init(&head);

    append(&head, 1);
    append(&head, 8);
    append(&head, 9);

    display(head);
    head = doubleIt(head);
    display(head);
    return 0;
}
