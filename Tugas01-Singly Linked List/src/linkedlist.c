#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/linkedlist.h"

/*==== Initialize AND Free List Functions ====*/
void init_list(List * lptr){
    lptr->head = NULL;
    lptr->size = 0;
}

void free_list(List * lptr){
    NodePtr next = lptr->head;
    NodePtr current = next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    lptr->head = NULL;
    lptr->size = 0;
}

/*==== Delete AND Add Function ====*/
int find_word_index(List alphabets[], char * word){
    if (word == NULL || !isalpha(word[0])) return -1;
    int index = tolower(word[0]) - 'a';
    return add_word_to_list(&alphabets[index], word);
}

int delete_word(List alphabets[], char * word_to_delete){
    int index = word_to_delete[0] - 'a';
    int deleted = 0;
    NodePtr current = alphabets[index].head;
    NodePtr previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->word, word_to_delete) == 0)
        {
            NodePtr node_to_free = current;
            if (previous == NULL){
                alphabets[index].head = current->next;
            } else {
                previous->next = current->next;
            }
            current = current->next;
            free(node_to_free);
            alphabets[index].size--;
            deleted = 1;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (deleted == 1) { return 1; }

    return 0;
}

int add_word_to_list(List * lptr, char *word){
    NodePtr new;
    new = malloc(sizeof(Node));

    if (new == NULL)
    {
        printf("[!] Failed Allocating Memory\n");
        return 0;
    }
    
    strcpy(new->word, word);
    new->next = lptr->head;
    lptr->head = new;
    lptr->size++;
    return 1;
}

/*==== Display List FUnction ====*/
void display_list(List alphabets[], char letter){
    int index = letter - 'a';
    if (alphabets[index].head == NULL)
    {
        printf("Kata dengan huruf awal %c tidak ditemukan\n", index + 'a');
        return;
    }

    NodePtr current = alphabets[index].head;
    for (int i = 0; i < 25 && current != NULL; i++)
    {
        printf("%s -> ", current->word);      
        current = current->next;
    }
}

