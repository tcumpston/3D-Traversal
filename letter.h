//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_LETTER_H
#define INC_3D_TRAVERSAL_LETTER_H

#include "cube.h"

typedef struct Letter
{
    char            character;
    struct Letter  *nextLetter;
    struct Letter  *previousLetter;
    struct Cube    *cubePtr;
}   LETTER;

extern LETTER *CreateLetter();

#endif //INC_3D_TRAVERSAL_LETTER_H
