#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *prox;
} No;

typedef struct Lista{
    int tam;
    No *head;
}Lista;

void criaLista(Lista *l);
void vazia(Lista *l);
void tamanho(Lista *l);
void modifica(Lista *l,int pos, int val);
void insere(Lista *l, int pos, int val);
void retira(Lista *l, int pos);
void imprime(Lista *l);

void criaLista(Lista *l){
  l->tam=0;
  l->head=NULL;
}

void vazia(Lista *l){
  if(l->tam==0 || l->tam<0){
    printf("A lista eh vazia\n");
  }else{
    printf("A lista nao eh vazia\n");
  }
}

void tamanho(Lista *l){
  printf("O tamanho da lista eh:%d\n",l->tam);
}

void modifica(Lista *l,int pos, int val){
  No *no=l->head;
  for(int i=1;i<pos;i++){
    no=no->prox;
  }
  no->valor=val;
}

void insere(Lista *l, int pos, int val){
    No *aux=l->head;
    No *novo=malloc(sizeof(No));
    novo->valor=val;
    if(pos==1 && l->tam==0){    //insere vazia
        l->head=novo;
        l->tam++;
    }else if(pos==1 && l->tam!=0){  //insere no inicio
        novo->prox=aux;
        l->head=novo;
        l->tam++;
    }else if(pos>1||pos<=l->tam){       //insere meio da lista
        for(int i=1;i<pos-1;i++){
            aux=aux->prox;
        }
        novo->prox=aux->prox;
        aux->prox=novo;
        l->tam++;  //ver se ta certo
    }else if(l->tam+1){          //insere no fim
        for(int i=1;i<l->tam;i++){
            aux=aux->prox;
        }
        aux->prox=novo;
    }else{
        printf("Posicao invalida\n");
    }
}

void retira(Lista *l, int pos){    //ver os pontos criticos
  No *aux=l->head;
  No *p;
  if(pos==1 && l->tam==1){  //remove quando só tem 1
    free(aux);
    l->tam--;
    l->head=NULL;
  }else if(pos==1 && l->tam>1){
    l->head=aux->prox;
    free(aux);
    l->tam--;
  }else if(pos>1 && pos<l->tam){              //remove no meio
    for(int i=1;i<pos-1;i++){
      aux=aux->prox;
    }
    p=aux->prox;          //valor a ser removido
    aux->prox=p->prox;    //ajeita apontamento
    free(p);
    l->tam--;             //decrementa tamanho da lista
  }else{
    printf("Nao foi possivel remover elemento\n");
  }
}

void imprime(Lista *l){
  No *no=l->head;
  for(int i=1;i<=l->tam;i++){
    printf("O valor da posicao %d eh:%d\n",i,no->valor);
    no=no->prox;
  }
}

int main(void){     //tirar duvida sobre como formatar texto

    Lista *c;
    criaLista(&c);

    insere(&c, 1, 5);
    insere(&c, 2, 7);
    insere(&c, 2, 21);
    imprime(&c);
    retira(&c,2);
    modifica(&c,1,47);
    imprime(&c);
    tamanho(&c);
    retira(&c,1);
    retira(&c,7);
    retira(&c,1);
    vazia(&c);
}
