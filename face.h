//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_FACE_H
#define INC_3D_TRAVERSAL_FACE_H

enum FACE_STATE { INITIAL };
enum FACE_ID { NORTH, SOUTH, TOP, BOTTOM, EAST, WEST };

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

