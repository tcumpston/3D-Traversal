//
// Created by tanya on 17/12/2022.
//

#ifndef INC_3D_TRAVERSAL_LIBRARY_H
#define INC_3D_TRAVERSAL_LIBRARY_H

#define HAST_TABLE_LENGTH 20000

typedef struct HashTableEntry
{
    struct HashTableEntry * next;
    char * word;
}   HASH_TABLE_ENTRY;

extern HASH_TABLE_ENTRY * hashTable[HAST_TABLE_LENGTH];

extern void CreateLibrary();
extern void TestHashFunction();
extern void TestLibrary();
extern HASH_TABLE_ENTRY *CreateListEntry();
extern unsigned int Hash(const char *str);
extern HASH_TABLE_ENTRY *FindHashTableEntry(char *word);

#endif //INC_3D_TRAVERSAL_LIBRARY_H
