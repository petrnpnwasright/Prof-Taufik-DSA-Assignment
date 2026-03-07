#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Data Structure
typedef struct stacknode * StackNodePtr;
typedef struct stacknode
{
    int element;
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

int push( Stack * ps, int element){
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
    int pop_value = temp->element;
    ps->top = ps->top->next;
    free(temp);
    ps->size--;
    return pop_value;
}

// Free stack
void free_stack(Stack * ps) {
    StackNodePtr current = ps->top;
    StackNodePtr next;

    while (current != NULL) {
        next = current->next; 
        free(current);        
        current = next;      
    }

    ps->top = NULL; 
    ps->size = 0;   
}

//
int evaluatePostfixExpression(Stack * ps, char characters[]){
    int input_len = strlen(characters);
    char operator[] = "+-*/";

    for (int i = 0; i < input_len; i++){
        // Jika elemen adalah operand
        if (isdigit(characters[i])){
            int num = 0;
            while (i < input_len && isdigit(characters[i])) {
                num = num * 10 + (characters[i] - '0');
                i++;
            }   
            push(ps,num);
            i--;
        }

        // Jika elemen adalah spasi
        if(characters[i] == ' ') { continue; }

        // Jika elemen adalah operator
        if (strchr(operator, characters[i]) != NULL) {
            int operand1 = pop(ps);
            int operand2 = pop(ps);

            if(characters[i] == '+'){push(ps , operand2 + operand1);}
            else if(characters[i] == '-') {push(ps , operand2 - operand1);}
            else if(characters[i] == '*'){push(ps , operand2 * operand1);}
            else if(characters[i] == '/'){push(ps , operand2 / operand1);}            
        }
    }
    return pop(ps);
}

int main(){
    Stack st;
    make_stack(&st);

    char input[100];
    printf("Masukkan ekspresi postfix (pisahkan dengan spasi): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    int res = evaluatePostfixExpression(&st,input);
    printf("Hasil: %d\n", res);

    return 0;
}