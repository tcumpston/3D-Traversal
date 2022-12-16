//
// Created by tanya on 13/12/2022.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "exit.h"

FILE *wordFilePtr = NULL;

void CreateLibrary()
{
    FILE *wordFilePtr = fopen("Public Domain Word List.txt", "r");

    if (wordFilePtr == NULL) ExitMessage("fopen() failed in tools.c.");

    
}


unsigned int Hash(const char *str)
{
    unsigned long long hash = 0;
    char c;

    while (isalpha(c = (toupper(*str++))))
    {
        hash = (hash << 5) + (c - 'A' + 1);
    }

    hash = (hash >> 32) ^ (hash & 0xffffffff);
    hash = (hash >> 16) ^ (hash & 0xffff);
    hash &= 0xfff;

    return (unsigned int) hash;
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
