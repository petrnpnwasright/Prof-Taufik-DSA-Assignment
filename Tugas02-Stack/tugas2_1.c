#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// GLOBAL VARIABLE
char brakets_arr[64];
int top = -1;

// Deklarasi Fungsi
bool is_balanced(char input_user[]);
void push(char);
char pop();
    
int main() {
    char input_user[100]; // Buffer untuk menampung input
    printf("Masukkan ekspresi kurung: ");
    fgets(input_user, sizeof(input_user), stdin);
    
    // Menghapus newline dari fgets jika ada
    input_user[strcspn(input_user, "\n")] = 0;

    if(is_balanced(input_user) == true){
        printf("Seimbang\n");
    } else {
        printf("Tidak Seimbang\n");
    }
    return EXIT_SUCCESS;
}

void push(char brackets){
    // Mengecek apakah stack penuh
    if(top == 64 - 1){
        printf("[!] Stack Penuh\n");
    } 
    // Masih ada slot kosong di dalam stack
    else {
        top++;
        brakets_arr[top] = brackets;
        // printf("[+] %c Berhasil Dimasukkan Ke STack\n", brackets);
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
        char pop_brakets = brakets_arr[top];
        top--;
        return pop_brakets;
    }
}

bool is_balanced(char input_user[]){
    top = -1;
    int expression_len = strlen(input_user);
    for(int i = 0; i < expression_len; i++){
        // Jika Ketemu Kurung Buka
        if 
        (
            input_user[i] == '(' ||
            input_user[i] == '{' ||
            input_user[i] == '['
        ) 
        { push(input_user[i]); }
        
        // Jika Ketemu Kurung Tutup
        else if 
        (
            input_user[i] == ')' ||
            input_user[i] == '}' ||
            input_user[i] == ']'
        )
        { 
            // Cek apakah stack kosong?
            if (top == -1){ return false; }
            
            // Jika tidak
            if
            (
                (input_user[i] == ')' && brakets_arr[top] != '(') ||
                (input_user[i] == '}' && brakets_arr[top] != '{') ||
                (input_user[i] == ']' && brakets_arr[top] != '[')
            )
            { return false; }
            pop();
        }        
    }
    
    if(top == -1){
        return true;
    } else {
        return false;
    }
}


