//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_FACE_H
#define INC_3D_TRAVERSAL_FACE_H

enum FACE_ID { NORTH, SOUTH, TOP, BOTTOM, EAST, WEST };

#include "cube.h"
#include "letter.h"

typedef struct Face
{
    struct Cube *      parentCube;     // link to CUBE to which this FACE belongs
}   FACE;

extern FACE * CreateFace(struct Cube *cubePtr);

#endif //INC_3D_TRAVERSAL_FACE_H

