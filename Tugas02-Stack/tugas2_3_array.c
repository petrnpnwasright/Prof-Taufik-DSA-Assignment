#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> 

int expression_arr[64];
int top = -1;

void push(int numbers){
    // Mengecek apakah stack penuh
    if(top == 64 - 1){
        printf("[!] Stack Penuh\n");
    } 
    // Masih ada slot kosong di dalam stack
    else {
        top++;
        expression_arr[top] = numbers;
    }
}

char pop(){
    // Cek apakah stack-nya kosong
    if (top == -1) {
        printf("[!] Stack Kosong\n");
        return -1;
    } 
    // Jika Stack Punya elemen
    else { 
        int pop_numbers = expression_arr[top];
        top--;
        return pop_numbers;
    }
}

int evaluatePostfixExpression(char characters[]){
    int input_len = strlen(characters);
    char operator[] = "+-*/";
    
    for (int i = 0; i < input_len; i++) {
        // Jika elemen adalah operand
        if (isdigit(characters[i])){
            int num = 0;
            while (i < input_len && isdigit(characters[i])) {
                num = num * 10 + (characters[i] - '0');
                i++;
            }   
            push(num);
            i--;
        }

        // Jika elemen adalah spasi
        if(characters[i] == ' ') { continue; }

        // Jika elemen adalah operator
        if (strchr(operator, characters[i]) != NULL) {
            int operand1 = pop();
            int operand2 = pop();

            if(characters[i] == '+'){push(operand2 + operand1);}
            else if(characters[i] == '-') {push(operand2 - operand1);}
            else if(characters[i] == '*'){push(operand2 * operand1);}
            else if(characters[i] == '/'){push(operand2 / operand1);}            
        }
    }
    return pop();
}

int main(){
    char input[128];
    printf("Masukkan ekspresi postfix (pisahkan dengan spasi): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int res = evaluatePostfixExpression(input);
    printf("Hasil: %d\n", res);
    return 0;
}
