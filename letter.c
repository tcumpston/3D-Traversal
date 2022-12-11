//
// Created by tanya on 11/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "letter.h"
#include "cube.h"

// Need to initialise:
//  char            character;
//  struct LETTER  *nextLetter;
//  struct LETTER  *previousLetter;
//  struct CUBE    *cubePtr;
LETTER *CreateLetter()
{
    LETTER *letterPtr = calloc(1, sizeof(LETTER));

    if (letterPtr == NULL)
    {
        ExitMessage("Calloc() failed.");
    }
    else
    {
        letterPtr->character = '?';
        letterPtr->nextLetter = NULL;
        letterPtr->previousLetter = NULL;
        letterPtr->cubePtr = CreateCube();  // the cube associated with this letter

        if (letterPtr->cubePtr == NULL)
        {
            ExitMessage("Calloc() failed.");
        }

        return letterPtr;
    }
}

