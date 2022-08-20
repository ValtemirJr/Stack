#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 60

struct _browser{
    char site[N];
    struct _browser *next;
};
typedef struct _browser Browser;

typedef struct{
    Browser *top;
}Stack;

void push(Stack *stack, char site[]){
    Browser *new = malloc(sizeof(Browser));
    snprintf(new->site, sizeof(new->site), "%s", site);
    new->next = NULL;
    if(stack->top == NULL){
        stack->top = new;
        return;
    }
    new->next = stack->top;
    stack->top = new;
}

void pop(Stack *stack){
    Browser *aux = stack->top;
    if(stack->top == NULL){
        printf("Vazio\n");
        return;
    }
    printf("%s\n",stack->top->site);
    stack->top = stack->top->next;
    free(aux);
}

void freeStack(Stack *stack) {
    Browser *aux;
    if(stack->top == NULL)
        printf("!");
    while (stack->top != NULL) {
        aux = stack->top;
        stack->top = stack->top->next;
        printf("@");
        free(aux);
    }
}

int main(){
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;

    while(1){
        char site[N];
        scanf("%s", site);
        if(!strcmp(site, "B")){
            pop(stack);      
        }
        else if(!strcmp(site, "E")){
            freeStack(stack);
            printf("\n");
            return 0;
        }
        else{
            push(stack, site);
        }
    }
    return 0;
}