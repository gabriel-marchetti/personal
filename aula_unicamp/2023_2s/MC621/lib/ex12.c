#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedlist{
    char info;
    struct _linkedlist *next;
} ll, nLL;

void destroy(ll **pLL)
{   
    ll *aux;
    while(*pLL != NULL){
        aux = *pLL;
        (*pLL) = (*pLL)->next;
        free(aux);
    }
}

ll *criall(char info){
    ll *p = calloc(1, sizeof(ll));
    p->info = info;
    return p;
}

void addll(char info, ll **pLL){
    if( (*pLL) == NULL ){
        *pLL = criall(info);
    }else{
        ll *addNode = criall(info);
        ll *aux = *pLL;
        while( aux->next != NULL ){
            aux = aux->next;
        }
        aux->next = addNode;
    }
}

int remll(char info, ll **pLL){
    ll *atual = *pLL, *anterior = NULL;
    while( atual->info != info ){
        anterior    = atual;
        atual       = atual->next;
    }
    if( atual == NULL ) return 0; //Nao consegui remover
    if ( anterior == NULL ) {
        anterior = (*pLL);
        (*pLL) = (*pLL)->next;
        free(anterior); 
    } else {
        anterior->next  = atual->next;
        atual->next     = NULL;
        free(atual);
    }
    return 1;
}

int checkOdd(int num)
{
    if ( num % 2 == 1 ){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    //char tel[n+1];
    //scanf("%s", tel);
    char save;
    ll *linkedlist = NULL;
    for(int i = 0; i < n; i++){
        scanf("%c", &save);
        addll(save, &linkedlist);
    }

    ll *adventurer = NULL, *laggedAdventurer = NULL;
    while( n != 11 ){
        laggedAdventurer = NULL;
        adventurer = linkedlist;
        if( checkOdd(n) ){
            for(int i = 0; i < n; i++){
                if( adventurer->info != '8'){
                    // remll(adventurer->info, &linkedlist);
                    if(laggedAdventurer == NULL){
                        linkedlist = linkedlist->next;
                        free(adventurer);
                    } else {
                        laggedAdventurer->next = adventurer->next;
                        free(adventurer);
                    }
                    break;
                } else {
                    laggedAdventurer = adventurer;
                    adventurer = adventurer->next;
                }
            }
        } else {
            for(int i = 0; i < n; i++){
                if( adventurer->info == '8'){
                    // remll(adventurer->info, &linkedlist);
                    if (laggedAdventurer == NULL){
                        linkedlist = linkedlist->next;
                        free(adventurer);
                    } else {
                        laggedAdventurer->next = adventurer->next;
                        free(adventurer);
                    }
                    break;
                }else{
                    laggedAdventurer = adventurer;
                    adventurer = adventurer->next;
                }
            }
        }
        n--;
    }

    if( linkedlist->info == '8' ){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    destroy(&linkedlist);
    return 0;
}