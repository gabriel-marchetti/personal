#include<bits/stdc++.h>

using namespace std;

struct pilha{
    int info;
    struct pilha *prox;
};

void empilha(pilha **P, int info)
{
    pilha *aux = (pilha *)calloc(1, sizeof(pilha));
    aux->info = info;
    aux->prox = NULL;
    if( P == NULL ){
        (*P) = aux;
    } else {
        aux->prox = (*P);
        *P = aux;
    }
}

void desempilha(pilha **P)
{
    pilha *aux = NULL;
    aux = (*P);
    (*P) = (*P)->prox;
    cout << aux->info << ' ';
    free(aux);
}

int main()
{
    int n{}, position{};
    cin >> n;
    int array[n-1]{};
    int i{0};
    for( i = 0; i < n - 1; i++){
        cin >> array[i];
    }

    pilha *P    = NULL;
    position    = n - 2;
    empilha(&P, n);
    while( array[position] != 1 ){
        empilha(&P, array[position]);
        position = array[position] - 2;  
    }
    empilha(&P, 1);

    while( P != NULL ){
        desempilha(&P);
    }

    return 0;
}