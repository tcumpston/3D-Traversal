//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_FACE_H
#define INC_3D_TRAVERSAL_FACE_H

enum FACE_STATE { INITIAL };

#include "cube.h"
#include "letter.h"

typedef struct Face
{
    int         state;
    struct Cube *      parentCube;     // link to CUBE to which this FACE belongs
    struct Letter *      nextLetter;     // link to next LETTER in WORD
}   FACE;

extern FACE * CreateFace(struct Cube *cubePtr);

#endif //INC_3D_TRAVERSAL_FACE_H

