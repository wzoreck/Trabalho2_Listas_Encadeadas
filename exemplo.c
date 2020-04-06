#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int d;
    struct elemento *p;
} elemento;

int listarElementos(elemento *e);
int inserirElementoInicio(elemento **inicio, int d);
int inserirElementoFinal(elemento **inicio, int d);
int inserirElementoIndice(elemento **inicio, int d, int idx);
int removerInicio(elemento **i);
int removerFim(elemento **i);
int removerElementoValor(elemento **inicio, int v);
int removerElementoIndice(elemento **inicio, int idx);
int tamanho(elemento *e);
elemento *getElemento(elemento *e, int indice);

int main()
{
    elemento *inicio = NULL;

    return 0;
}

int listarElementos(elemento *e)
{
    if (e == NULL)
        return 1; //return 1: lista vazia
    while (e != NULL)
    {
        printf("%p -> %d | %p\n", e, e->d, e->p);
        e = e->p;
    }
    return 0; //return 0: operação realizada com sucesso
}

int inserirElementoInicio(elemento **i, int d)
{
    elemento *novo = malloc(sizeof(elemento));
    if (novo == NULL)
        return -1; // return -1: não foi possivel alocar memória
    novo->d = d;
    novo->p = *i;
    *i = novo;
    return 0; //return 0: operação realizada com sucesso
}

int inserirElementoFinal(elemento **i, int d)
{
    if (*i == NULL)
        return inserirElementoInicio(i, d);
    elemento *novo = malloc(sizeof(elemento));
    novo->d = d;
    novo->p = NULL;
    if (novo == NULL)
        return -1; //return -1: não foi possivel alocar memória
    elemento *aux = *i;
    while (aux->p != NULL)
    {
        aux = aux->p;
    }
    aux->p = novo;
    return 0; //return 0: operação realizada com sucesso
}

int inserirElementoIndice(elemento **i, int d, int idx)
{
    if (idx < 0)
        return -2; // return -2: indice invalido
    else if (idx == 0)
        return inserirElementoInicio(i, d);
    else if (*i == NULL)
        return -3; // return -3: indice não existe
    else
    {
        elemento *aux = *i;
        int idxAux = 0;
        while (aux != NULL && idxAux < idx - 1)
        {
            aux = aux->p;
            idxAux++;
        }
        if (idxAux < idx - 1)
            return -3; // return -3: indice não existe
        elemento *novo = malloc(sizeof(elemento));
        if (novo == NULL)
            return -1; // return -1: não foi possivel alocar memória
        novo->d = d;
        novo->p = aux->p;
        aux->p = novo;
        return 0; //return 0: operação realizada com sucesso
    }
}

int removerInicio(elemento **i)
{
    if (*i == NULL)
        return -3; // return -3: indice não existe
    elemento *aux = *i;
    *i = aux->p;
    free(aux);
    return 0; //return 0: operação realizada com sucesso
}

int removerFim(elemento **i)
{
    if (*i == NULL)
        return -3; // return -3: indice não existe
    elemento *aux = *i;
    if (aux->p == NULL)
    {
        *i = NULL;
        free(aux);
    }
    while (aux->p != NULL)
    {
        aux = aux->p;
    }
    free(aux->p);
    aux->p = NULL;
}

int removerElementoIndice(elemento **i, int idx)
{
    if (idx < 0)
        return -2; // return -2: indice invalido
    else if (*i == NULL)
        return -3; // return -3: indice não existe
    else if (idx == 0)
    {
        elemento *aux = *i;
        *i = aux->p;
        free(aux);
        return 0; //return 0: operação realizada com sucesso
    }
    else
    {
        elemento *aux = *i;
        int idxAux = 0;
        while (aux != NULL && idxAux < idx - 1)
        {
            aux = aux->p;
            idxAux++;
        }
        if (idxAux < idx - 1 || aux->p == NULL)
            return -3; // return -3: indice não existe
        elemento *aux2 = aux->p;
        aux->p = aux2->p;
        free(aux2);
        return 0; //return 0: operação realizada com sucesso
    }
}

int removerElementoValor(elemento **i, int v)
{
    if (*i == NULL)
        return -4; // return -4: elemento não existe
    else
    {
        elemento *aux = *i;
        if (aux->d == v)
        {
            *i = aux->p;
            free(aux);
            return 0; //return 0: operação realizada com sucesso
        }
        else
        {
            while (aux->p != NULL)
            {
                if (aux->p->d == v)
                    break;
                else
                    aux = aux->p;
            }
            if (aux->p == NULL)
                return -4; // return -4: elemento não existe
            elemento *aux2 = aux->p;
            aux->p = aux2->p;
            free(aux2);
            return 0; //return 0: operação realizada com sucesso
        }
    }
}

elemento *getElemento(elemento *e, int idx)
{
    if (idx < 0)
        return NULL; //elemento não está na lista
    if (idx <= tamanho(e))
        return NULL; //elemento não está na lista
    int idxE = 0;
    while (idxE < idx)
    {
        idxE++;
        e = e->p;
    }
    return e;
}

int buscaValor(elemento *e, int v)
{
    if (e == NULL)
        return -2;
    int idx = 0;
    while (e->d != v && e->p != NULL)
    {
        idx++;
        e = e->p;
    }
    if (e->d == v)
        return idx;
    return -3;
}

int tamanho(elemento *e)
{
    int idx = 0;
    while (e != NULL)
    {
        e = e->p;
        idx++;
    }
    return idx;
}