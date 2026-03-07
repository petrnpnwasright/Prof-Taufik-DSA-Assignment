#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Data Structure
typedef struct stacknode * StackNodePtr;
typedef struct stacknode
{
    char element;
    StackNodePtr next;
} StackNode;

typedef struct stack
{
    StackNodePtr top;
    unsigned size;
} Stack;

// Stack Functions
int make_stack(Stack * ps){
    ps->top = NULL;
    ps->size = 0;
    return 1;
}

int push( Stack * ps, char element){
    StackNodePtr new;
    new = malloc(sizeof(StackNode));
    if( new == NULL ) { return 0; }

    new->element = element;
    new->next = ps->top;
    ps->top = new;
    ps->size++;
    return 1;
}

int pop( Stack * ps){
    StackNodePtr temp;
    if( ps->top == NULL) { return 0; }

    temp = ps->top;
    ps->top = ps->top->next;
    printf("%c ", temp->element);
    free(temp);
    ps->size--;
    return 1;
}

// Infix To Postfix Function
void infix_to_postfix( Stack * ps, char input_user[]){
    int input_len = strlen(input_user);
    char operator[] = "+-*/";
    for (int i = 0; i < input_len; i++) {
        // Jika elemen adalah operand
        if (isdigit(input_user[i])){
            while (i < input_len && isdigit(input_user[i])) {
                printf("%c", input_user[i]);
                i++;
            }
            printf(" ");
            i--;
        }
        
        // Jika Tanda kurung
        if(input_user[i] == '(') { continue; }

        // Jika element adalah operator
        if (strchr(operator, input_user[i]) != NULL) {
            push(ps, input_user[i]);
        }
        
        // Jika element kurung tutup
        if(input_user[i] == ')'){
            pop(ps);
        }
    }

    while (ps->top != NULL) { pop(ps); }
}

int main(){
    char input_user[128];
    printf("Masukkan ekspresi infix: ");
    fgets(input_user, sizeof(input_user), stdin);
    input_user[strcspn(input_user, "\n")] = 0;

    Stack st;
    make_stack(&st);

    infix_to_postfix(&st, input_user);
    printf("\n");
    return EXIT_SUCCESS;
}