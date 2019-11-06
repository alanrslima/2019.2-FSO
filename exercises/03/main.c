#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int element;
    struct Queue* next;
};

typedef struct Queue queue;

void print(queue* head)
{
    queue* aux;

    for(aux = head; aux != NULL; aux = aux->next)
    {
        printf("%d ", aux->element);
    }
    printf("\n");
}

void push_back(queue** head, queue** tail, int element)
{
    queue* new = (queue *) malloc(sizeof(queue));

    new->element = element;
    new->next = NULL;

    if(!(*head))
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
    
}

void pop_front(queue** head)
{
    if(*head)
    {
        *head = (*head)->next;
    }
}

int find(queue* head, queue* tail, int element)
{
    if(!head) return 0;
    if(head->element == element)
        return 1;
    else if(tail->element == element)
        return 1;

    queue* aux = head->next;
    while(aux)
    {
        if(aux->element == element)
            return 1;
        aux = aux->next;
    }
    return 0;
}

int main(void)
{
    int N;
    int Q;
    int i, j, k;
    int page_faults = 0;
    
    scanf("%d", &N);

    int reference[N];
    
    for(i = 0; i < N; ++i)
        scanf("%d", &reference[i]);

    for(i = 0; scanf("%d", &Q) != EOF; ++i)
    {
        queue* head = NULL;
        queue* tail = NULL;

        int page_faults = Q;

        for(j = 0; j < Q; ++j)
        {
            int result = find(head, tail, reference[j]);
            if(!result)
                push_back(&head, &tail, reference[j]);
            else
                Q++;
            
        }
        for(k = j; k < N; ++k)
        {
            int result = find(head, tail, reference[k]);
            print(head);
            printf("elemento para entrar = %d\nresult = %d\n", reference[k], result);

            if(!result)
            {
                pop_front(&head);
                push_back(&head, &tail, reference[k]);
                page_faults++;
            }
            print(head);
            printf("\n\n");
        }

        // print(head);
        printf("page faults = %d\n", page_faults);
    }




    return 0;
}