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
    struct Letter  *nextLetter;
    struct Letter  *previousLetter;
    struct Cube    *cubePtr;
}   LETTER;

extern LETTER *CreateLetter();
int CountLetters(LETTER *letterPtr);

#endif //INC_3D_TRAVERSAL_LETTER_H
