//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_LETTER_H
#define INC_3D_TRAVERSAL_LETTER_H

#include "cube.h"
#include "face.h"

enum LETTER_STATE { INITIAL };

typedef struct Letter
{
    int             state;
    char            character;
    struct Letter  *topLetter;
    struct Letter  *bottomLetter;
    struct Letter  *northLetter;
    struct Letter  *southLetter;
    struct Letter  *eastLetter;
    struct Letter  *westLetter;
    struct Cube    *cubePtr;
}   LETTER;

extern LETTER *CreateLetter();
extern int CountNorthSouthLetters(LETTER *letterPtr);
extern int CountEastWestLetters(LETTER *letterPtr);
extern int CountTopDownLetters(LETTER *letterPtr);

#endif //INC_3D_TRAVERSAL_LETTER_H
