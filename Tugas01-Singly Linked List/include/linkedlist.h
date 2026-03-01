typedef struct node* NodePtr;
typedef struct node
{
    char word[64];
    NodePtr next;
} Node;

typedef struct list
{
    NodePtr head;
    unsigned size;
} List;

extern List alphabets[26];

void init_list(List *);
int add_word_to_list(List *, char *);
void display_list(List *, char);
void free_list(List *);
int find_word_index(List *, char * );
int delete_word(List *, char *);

