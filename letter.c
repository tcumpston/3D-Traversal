//
// Created by tanya on 11/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "letter.h"
#include "cube.h"
#include "face.h"

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
        letterPtr->state = INITIAL;
        letterPtr->character = '?';
        letterPtr->nextLetter = NULL;
        letterPtr->previousLetter = NULL;
        letterPtr->cubePtr = CreateCube();  // the cube associated with this letter

        if (letterPtr->cubePtr == NULL)
        {
            ExitMessage("Calloc() failed in letter.c.");
        }

        return letterPtr;
    }
}

FACE *SelectFace(CUBE *cubePtr, int face)
{
    switch (face)
    {
        case NORTH:
            return cubePtr->north;
            break;

        case SOUTH:
            return cubePtr->south;
            break;

        case TOP:
            return cubePtr->top;
            break;

        case BOTTOM:
            return cubePtr->bottom;
            break;

        case EAST:
            return cubePtr->east;
            break;

        case WEST:
            return cubePtr->west;
            break;
    }
}

int CountLetters(LETTER *letterPtr)
{
    int letterCount = 0;

    while (letterPtr->previousLetter != NULL) letterPtr = letterPtr->previousLetter;

    while (letterPtr->state != INITIAL)
    {
        letterCount++;
        letterPtr = letterPtr->nextLetter;
    }

    return letterCount;
}
