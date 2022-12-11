//
// Created by tanya on 11/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "word.h"
#include "letter.h"

WORD *wordList = 0;     // linked list of WORDs

// A WORD is a linked list of LETTERs. Need to initialise:
//  int     length;
//  LETTER *letter;     // linked list of LETTERs
WORD *CreateWord()
{
    WORD *wordPtr = calloc(1, sizeof(WORD));

    if (wordPtr == NULL)
    {
        ExitMessage("Calloc() failed in word.c (1).");
    }
    else
    {
        wordPtr->letter = CreateLetter();

        if (wordPtr->letter == NULL)
        {
            ExitMessage("Calloc() failed in word.c (2).");
        }

        return wordPtr;
    }
}

