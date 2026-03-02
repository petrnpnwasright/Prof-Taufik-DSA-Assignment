#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/linkedlist.h"
#include "include/view.h"

List alphabets[26];

int main(){
    FILE *fptr = fopen("dbterms.txt", "r");
    char buf[64];

    if (fptr == NULL){
        printf("[!] Failed Opening File");
        return EXIT_FAILURE;
    }
    
    // Inisialisasi List Untuk Setiap Alphabets
    for (int i = 0; i < 26; i++) { init_list(&alphabets[i]); }
    
    // Mengambil Kata Dari File .txt Untuk Disimpan Ke dalam List
    while (fgets(buf, sizeof(buf), fptr) != NULL)
    {
        buf[strcspn(buf, "\n")] = '\0';
        find_word_index(alphabets , buf);
    }
    fclose(fptr);
    
    // Menampilkan Menu Pilihan
    handle_menu();
    
    // Free Setiap List Alphabets
    for (int i = 0; i < 26; i++) { free_list(&alphabets[i]); }
    return EXIT_SUCCESS;
}