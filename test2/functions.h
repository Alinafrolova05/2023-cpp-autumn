#ifndef HASH_TABLE
typedef struct Element {
    char key;
    struct Element* next;
} Element;

typedef struct Hash_table {
    Element** table;
} Hash_table;

int hash(char* key);

Hash_table* createTable();

void insert(Hash_table* hash_table, char* key);
//inserts element
int search(Hash_table* hash_table, char* key);
//searchs element
void freeTable(Hash_table* hash_table);
//cleans hashtable
int test(void);

#endif