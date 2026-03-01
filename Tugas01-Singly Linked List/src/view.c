#include <stdio.h>
#include <ctype.h>
#include "../include/linkedlist.h"
#include "../include/view.h"

void handle_menu(){
    int choice;
    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Tampilkan List Berdasarkan Huruf\n");
        printf("2. Hapus Kata Dari List\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        if(scanf("%d", &choice) != 1){
            printf("[!] Input tidak valid");
            return;
        };

        switch (choice)
        {
        case 1:
            handle_menu_option_1();
            break;
            case 2:
            handle_menu_option_2();
            break;
        default:
            printf("[!] Program Dihentikan");
            break;
        }
    } while (choice != 3);
}

void handle_menu_option_1(){
    printf("[+] Masukkan Huruf Yang Ingin Ditampilkan: ");
    char letter;
    scanf(" %c", &letter);
    display_list(alphabets, tolower(letter));
    printf("\n");
}

void handle_menu_option_2(){
    printf("[-] Masukkan Kata Yang Ingin Dihapus: ");
    char word[64];
    scanf(" %s", word);
    if ( delete_word(alphabets, word) == 1 )
    {
        printf("[-] Kata %s Berhasil Dihapus Dari List!\n", word);
    } else {
        printf("[!] Word Not FOund\n");
    }
    
    
}
