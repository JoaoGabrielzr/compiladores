#include <stdio.h>
#include <stdlib.h>
#include "analex.h"
#include "pilha.h"

int token;

void E();
void E_linha();
void T();
void T_linha();
void F();

void erro_sint(){
    printf("Erro sintatico\n");
    exit(1);
}

void consumir(int t)
{
    if (token == t)
    {
        token = analex();
    }
    else{
        printf("\nErro ao consumir\n");
       exit(-1);
    }
}

void E()
{
    T();
    E_linha();
}

void E_linha()
{
    switch (token)
    {
    case '+':
        push(token);
        consumir('+');
        T();
        E_linha();
        break;

    case '-':
        push(token);
        consumir('-');
        T();
        E_linha();
        break;

    default:
        //printf("\ndefault da E_linha!!\n");
        break;
    }
}

void T()
{
    F();
    T_linha();
}

void T_linha()
{
    switch (token)
    {
    case '*':
        push(token);
        consumir('*');
        F();
        T_linha();
        break;

    case '/':
        push(token);
        consumir('/');
        F();
        T_linha();
    default:
        //printf("\ndefault da T_linha!\n");
        break;
    }
}

void F()
{
    switch(token){
        case NUM:
        printf("%d", tokenval);
        push(token);
        consumir(NUM);
        break;

       case '(':
        push(token);
        consumir('(');
        E();
        consumir(')');
    }
}

int main(){
    int a, b, op, res;

    push('!');
    token = analex();
    E();
   if(token == ';')
        printf("\nSem erros sintaticos");
    else{
        printf("\nErro na main!");
        erro_sint();


    printf("Número combinado: %d\n", NUM);
    }
    return 0;

}
