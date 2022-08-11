#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _element {
    char value;
    struct _element *next;
};
typedef struct _element Element;

typedef struct{
    Element *top;
} Stack;

char pop(Stack *stack){
    Element *aux = stack->top;
    if(stack->top == NULL)
        return -1;
    char retorno = aux->value;
    stack->top = stack->top->next;
    free(aux);
    return retorno;
}

void push(Stack *stack, char value){
    Element *new = malloc(sizeof(Element));
    new->value = value;
    new->next = NULL;

    if(stack->top == NULL){
        stack->top = new;
        return;
    }
    new->next = stack->top;
    stack->top = new;
}

void printStack(Stack *stack){
    Element *aux;
    for(aux = stack->top; aux !=NULL; aux = aux->next){
        printf("%c . ", aux->value);
    }
}

int main(){
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;

    char string[50];
    int i = 0;
    int flag = 0;

    scanf("%s", string);

    while(string[i] != '\0'){

        if(string[i] == '(' || string[i] == '{' || string[i] == '[')
            push(stack, string[i]);
        else{
            char ehtop = pop(stack);
            if (ehtop == -1 || (ehtop == '(' && string[i] != ')')
            || (ehtop == '{' && string[i] != '}')
            || (ehtop == '[' && string[i] != ']')){
                flag = 1;
                break;
            }
        }
        i++;
    }

    if(!flag && stack->top == NULL)
        printf("Deu BUENO\n");
    else
        printf("Deu RUIHH\n");


    return 0;
}
