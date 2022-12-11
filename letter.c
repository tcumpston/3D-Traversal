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
        letterPtr->topLetter = NULL;
        letterPtr->bottomLetter = NULL;
        letterPtr->northLetter = NULL;
        letterPtr->southLetter = NULL;
        letterPtr->eastLetter = NULL;
        letterPtr->westLetter = NULL;
        letterPtr->cubePtr = CreateCube();  // the cube associated with this letter

        if (letterPtr->cubePtr == NULL)
        {
            ExitMessage("Calloc() failed in letter.c.");
        }

        return letterPtr;
    }
}

LETTER *NextLetter(LETTER *letterPtr, int face)
{
    switch (face)
    {
        case NORTH:
            return letterPtr->northLetter;
            break;

        case SOUTH:
            return letterPtr->southLetter;
            break;

        case TOP:
            return letterPtr->topLetter;
            break;

        case BOTTOM:
            return letterPtr->bottomLetter;
            break;

        case EAST:
            return letterPtr->eastLetter;
            break;

        case WEST:
            return letterPtr->westLetter;
            break;
    }
}

int CountNorthSouthLetters(LETTER *letterPtr)
{
    int letterCount = 0;

    while (letterPtr->northLetter != NULL) letterPtr = letterPtr->northLetter;

    while (letterPtr->state != INITIAL)
    {
        letterCount++;
        letterPtr = letterPtr->southLetter;
    }

    return letterCount;
}

int CountEastWestLetters(LETTER *letterPtr)
{
    int letterCount = 0;

    while (letterPtr->westLetter != NULL) letterPtr = letterPtr->westLetter;

    while (letterPtr->state != INITIAL)
    {
        letterCount++;
        letterPtr = letterPtr->eastLetter;
    }

    return letterCount;
}

int CountTopDownLetters(LETTER *letterPtr)
{
    int letterCount = 0;

    while (letterPtr->topLetter != NULL) letterPtr = letterPtr->topLetter;

    while (letterPtr->state != INITIAL)
    {
        letterCount++;
        letterPtr = letterPtr->bottomLetter;
    }

    return letterCount;
}
