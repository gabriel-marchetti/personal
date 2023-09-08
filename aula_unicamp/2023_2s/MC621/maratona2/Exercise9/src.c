#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedlist{
    int info;
    struct _linkedlist *pos;
    struct _linkedlist *ant;
} linkedlist, node;

void AdicionaNode(linkedlist **head, linkedlist **tail, int info)
{
    node *add = (linkedlist *)calloc(1, sizeof(linkedlist));
    add->info = info;
    if( *head == NULL ){
        (*head) = add;
        (*tail) = add;
    } else {
        (*tail)->pos    = add;
        add->ant        = (*tail);
        (*tail)         = (*tail)->pos;
    }
}

int tiraEsquerda(linkedlist **head, linkedlist **tail)
{
    node *aux = NULL;
    if ( (*head) == NULL ){
        return -1;
    } else if ( (*head) == (*tail) ){
        int value   = (*head)->info;
        free((*tail));
        return(value);
    } else{
        aux         = (*head);
        (*head)     = (*head)->pos;
        int value   = aux->info;
        free(aux);
        return(value);
    }
}

int tiraDireita(linkedlist **head, linkedlist **tail)
{
    node *aux = NULL;
    if ( (*tail) == NULL ){
        return -1;
    } else if ( (*tail) == (*head) ){
        int value   = (*tail)->info;
        free( (*tail) );
        return(value);
    } else {
        aux         = (*tail);
        (*tail)     = (*tail)->ant;
        int value   = aux->info;
        free(aux);
        return(value);
    }
}

void printLinkedList(linkedlist *head, linkedlist *tail)
{
    while( head != tail){
        printf("%d ", head->info);
    } 
    printf("%d\n", head->info);
}

int main()
{
    int n;
    scanf("%d ", &n);

    // Vou usar uma lista-ligada com cabeça e cauda para resolver isso.
    linkedlist *head = NULL, *tail = NULL;
    int value;
    // Os números surjem aos pares! Por isso 2*n
    for(int i = 0; i < 2*n; i++){
        scanf("%d ", &value);
        AdicionaNode(&head, &tail, value);
    }

    printLinkedList(head, tail);

    return 0;
}