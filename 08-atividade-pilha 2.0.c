/*
Por Tiago Flores Lindner
Atividade de pilhas

Esse acabei fazendo quase que inteiramente por conta.
S� precisei da ajuda pra um colega para fazer a passagem dos ponteiros das struct direito.
A fun��o Insere(push) foi ele que fez e eu modifiquei um pouco a penas para servir de base para a remover(pop)

A passagem de parametros para as fun��es � com a struct de no e n�o com a de contato pq achamos que seria mais f�cil.
Daria pra polir com certeza ja que n�o tem leitura de dados, apenas uma demonstra��o com dados j� definidos, mas acho que vale pra atividade.

At� poderia usar o teu c�digo de base para melhorar, mas a� acho que tiraria o prop�sito da atividade de "se virar" para fazer a pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char email[150];
    char fone[15];
} contato;

typedef struct
{
    contato c;
    struct no* prox;
} no;

typedef struct
{
    no *topo;
} pilha;


void inicializa(pilha *p) {
    p->topo = NULL;
} // inicializa

int vazia(pilha *p) {
    return (p->topo == NULL);
} // vazia

void insere(pilha *p, no *n) {

    no *no_aux;
    no_aux = (no*)malloc(sizeof(no));

    if(p->topo == NULL) {

        p->topo = n;

    } else {

        no_aux = p->topo;
        p->topo = n;

    } // fim if/else

}// fim insere

void remover(pilha *p) {

    if (p->topo == NULL){
        printf("ERRO!");

    } else {

    no *no_aux;
    no_aux = (no*)malloc(sizeof(no));

        no_aux = p->topo;
        p->topo = p->topo->prox;
        free(no_aux);

}

}// fim remover

void imprime(no *n){

    if(n == NULL){
        printf("No vazio");
        printf("\n");

    } else {
        puts(n->c.nome);
        puts(n->c.email);
        puts(n->c.fone);
        printf("\n");
    }

} //imprime

int main ()
{
    contato *c1, *c2, *c3;
    no *n1, *n2, *n3;
    pilha *tPilha;

    c1 = (contato*)malloc(sizeof(contato));
    c2 = (contato*)malloc(sizeof(contato));
    c3 = (contato*)malloc(sizeof(contato));
    n1 = (no*)malloc(sizeof(no));
    n2 = (no*)malloc(sizeof(no));
    n3 = (no*)malloc(sizeof(no));
    tPilha = (pilha*)malloc(sizeof(pilha));
    //inicializar o topo da pilha como vazio e tal
    tPilha->topo = NULL;

    strcpy(c1->nome, "ABC");
    strcpy(c1->email, "123@email");
    strcpy(c1->fone, "1234");

    strcpy(c2->nome, "DEF");
    strcpy(c2->email, "456@email");
    strcpy(c2->fone, "5678");

    strcpy(c3->nome, "GHI");
    strcpy(c3->email, "789@email");
    strcpy(c3->fone, "9101");

    //n1->c recebe uma struct, ent�o recebe uma struct do tipo contato como entrada, c1 � um ponteiro(que cont�m um endere�o de mem�ria), por�m *c1 cont�m uma struct do tipo contato
    n1->c = *c1; // contato de n1 recebe contato c1
    n1->prox = NULL; // recebe o no anterior
    insere(tPilha, n1); //atualiza o topo
    imprime(tPilha->topo); //imprime o topo da pilha


    n2->c = *c2; //contato de n2 recebe contato c2
    n2->prox = n1; // recebe o no anterior
    insere(tPilha, n2); //atualiza o topo
    imprime(tPilha->topo); //imprime o topo da pilha

    n3->c = *c3; //contato de n3 recebe contato c3
    n3->prox = n2; // recebe o no anterior
    insere(tPilha, n3); //atualiza o topo
    imprime(tPilha->topo); //imprime o topo da pilha

    remover(tPilha); // remove o topo
    imprime(tPilha->topo); //imprime o topo da pilha

    remover(tPilha); // remove o topo
    imprime(tPilha->topo); //imprime o topo da pilha


    // inserindo novo contato
    c2 = (contato*)malloc(sizeof(contato));
    n2 = (no*)malloc(sizeof(no));

    strcpy(c2->nome, "ASD");
    strcpy(c2->email, "1122@email");
    strcpy(c2->fone, "3470");

    n2->c = *c2; //contato de n2 recebe contato c2
    n2->prox = n1; // recebe o no anterior
    insere(tPilha, n2); //atualiza o topo
    imprime(tPilha->topo); //imprime o topo da pilha


    remover(tPilha); // remove o topo
    imprime(tPilha->topo); //imprime o topo da pilha

    remover(tPilha); // remove o topo
    imprime(tPilha->topo); //imprime o topo da pilha


    remover(tPilha); // remove o topo

    return 0;
}
