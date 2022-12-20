//
// Created by tanya on 17/12/2022.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "exit.h"

FILE *wordFilePtr = NULL;

HASH_TABLE_ENTRY * hashTable[HAST_TABLE_LENGTH];

HASH_TABLE_ENTRY *CreateHashTableEntry()
{
    HASH_TABLE_ENTRY *hashTableEntry = calloc(1, sizeof(HASH_TABLE_ENTRY));

    if (hashTableEntry == NULL)
    {
        ExitMessage("calloc() failed in library.c[CreateHashTableEntry()].");
    }
    else
    {
        hashTableEntry->next = NULL;
        hashTableEntry->word = NULL;
    }
}

HASH_TABLE_ENTRY *CreateListEntry(int index)
{
    HASH_TABLE_ENTRY *entryPtr = hashTable[index];
    HASH_TABLE_ENTRY *previousEntryPtr = NULL;

    if (entryPtr == NULL)
    {
        return hashTable[index] = CreateHashTableEntry();
    }
    else
    {
        while (entryPtr != NULL)
        {
            previousEntryPtr = entryPtr;
            entryPtr = entryPtr->next;
        }

        return previousEntryPtr->next = CreateHashTableEntry();
    }
}

unsigned int Hash(const char *str)
{
    unsigned long long hash = 0;
    char c;

    while (isalpha(c = (toupper(*str++))))
    {
        c = c - 'A' + 1;
        hash = (hash << 5) + c;
    }

    hash %= HAST_TABLE_LENGTH;

    return (unsigned int) hash;
}

void CreateLibrary()
{
    FILE *fp = fopen("../Public Domain Word List.txt", "r");

    for (int i=0; i<HAST_TABLE_LENGTH; i++) hashTable[i] = NULL;

    if (fp != NULL)
    {
        char * buffer = NULL;
        char word[256];
        int length;
        int offset = 0;

        // Determine file length.
        fseek(fp, 0L, SEEK_END);                                   // int fseek(FILE *stream, long int offset, int whence);
        length = ftell(fp);                                                    // 85880
        rewind(fp);

        // Allocate suitable buffer to hole file contents.
        buffer = malloc(length + 1);

        if (buffer == NULL)
        {
            ExitMessage("fopen() failed in tools.c[CreateLibrary()].");
        }

        // Cope file contents into buffer.
        fread(buffer, 1, length, fp);                   // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

        int fieldsAssigned = 1;
        int wordCount = 0;

        // while (offset < length)
        while (1)
        {
            int wordLength = 0;
            char * wordEntry = NULL;
            fieldsAssigned = sscanf_s(buffer + offset, "%s", word, sizeof(word) -1);    // int sscanf_s(const char *restrict s, const char *restrict format, ...);

            if (fieldsAssigned > 0)
            {
                // Create permanent storage for the word we just extracted.
                wordLength = strlen(word);
                wordEntry = malloc(wordLength + 1);

                if (wordEntry == NULL)
                {
                    ExitMessage("malloc() failed in library.c[CreateLibrary()].");
                }
                else
                {
                    strncpy(wordEntry, word, wordLength);
                    wordEntry[wordLength] = 0;
                    CreateListEntry(Hash(wordEntry))->word = wordEntry;
                    wordCount++;
                    offset += wordLength + 1;
                }
            }
            else
            {
                break;
            }
        }

        fprintf(stderr, "%d words in file.\n", wordCount);
    }
    else
    {
        ExitMessage("fopen() failed in library.c[CreateLibrary()].");
    }
}

HASH_TABLE_ENTRY *FindHashTableEntry(char *word)
{
    int hash = Hash(word);
    int skipCount = 0;
    HASH_TABLE_ENTRY *hashTableEntry = hashTable[hash];

    while (hashTableEntry != NULL)
    {
        if (!strcmp(word, hashTableEntry->word))
        {
            if (DEBUG_ENABLED) fprintf(stderr, "Found %s == %s in library (hash==%x): entry %d in list..\n", word, hashTableEntry->word, hash, skipCount);
            return hashTableEntry;
        }
        else
        {
            skipCount++;
            hashTableEntry = hashTableEntry->next;
        }
    }

    return NULL;
}

void TestLibrary()
{
    FILE *fp = fopen("../Public Domain Word List.txt", "r");

    if (fp != NULL)
    {
        char * buffer = NULL;
        char word[256];
        int length;
        int offset = 0;

        // Determine file length.
        fseek(fp, 0L, SEEK_END);                                   // int fseek(FILE *stream, long int offset, int whence);
        length = ftell(fp);                                                    // 85880
        rewind(fp);

        // Allocate suitable buffer to hold file contents.
        buffer = malloc(length + 1);

        if (buffer == NULL)
        {
            ExitMessage("fopen() failed in library.c[CreateLibrary()].");
        }

        // Cope file contents into buffer.
        fread(buffer, 1, length, fp);                   // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

        int fieldsAssigned = 1;
        int wordCount = 0;

        int loopCount = 0;

        // while (offset < length)
        while (1)
        {
            int wordLength = 0;
            char * wordEntry = NULL;
            fieldsAssigned = sscanf_s(buffer + offset, "%s", word, sizeof(word) -1);    // int sscanf_s(const char *restrict s, const char *restrict format, ...);

            if (fieldsAssigned > 0)
            {
                wordLength = strlen(word);
                wordCount++;
                offset += wordLength + 1;
                HASH_TABLE_ENTRY *HashTableEntryPtr = FindHashTableEntry(word);

                if (HashTableEntryPtr == NULL)
                {
                    fprintf(stderr, "Processed %d words. Could not find %s in library.\n", wordCount, word);
                    ExitMessage("FindHashTableEntry() failed in library.c[TestLibrary()].");
                }
            }
            else
            {
                break;
            }
        }

        free (buffer);
        fprintf(stderr, "%d words in file.\n", wordCount);
    }
    else
    {
        ExitMessage("fopen() failed in tools.c[CreateLibrary()].");
    }
}

void TestHashFunction()
{
    // FILE *fopen(const char *filename, const char *mode)
    FILE *fp = fopen("../Public Domain Word List.txt", "r");
    char * buffer = NULL;
    char word[256];
    int length;
    int offset = 0;
    int hashSpread[16];

    for (int i=0; i<16; i++)
    {
        hashSpread[i] = 0;
    }

    if (fp != NULL)
    {
        // int fseek(FILE *stream, long int offset, int whence);
        fseek(fp, 0L, SEEK_END);

        length = ftell(fp);     // 85880

        rewind(fp);

        buffer = malloc(length);

        // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
        fread(buffer, 1, length, fp);

        for (int i = 0; i < 9999; i++)
        {
            // int sscanf_s(const char *restrict s, const char *restrict format, ...);
            sscanf_s(buffer + offset, "%s", word, sizeof(word) - 1);
            offset += strlen(word) + 1;

            int hash = Hash(word);

            // Restrict for testing
            hash = (hash >> 8) ^ (hash & 0xff);

            hash = (hash >> 4) ^ (hash & 0xf);

            hash &= 0xf;

            hashSpread[hash]++;
        }

        for (int i = 0; i < 16; i++)
        {
            fprintf(stderr, "hashSpread[%d] == %d \n", i, hashSpread[i]);
        }
    }
    else
    {
        ExitMessage("fopen() failed in tools.c[TestHashFunction()].");
    }
}
