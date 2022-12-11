//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_CUBE_H
#define INC_3D_TRAVERSAL_CUBE_H

#include "face.h"

typedef struct Cube
{
    struct Face    *north;     // pointer to north face
    struct Face    *south;     // pointer to south face
    struct Face    *top;       // pointer to top face
    struct Face    *bottom;    // pointer to bottom face
    struct Face    *east;      // pointer to east face
    struct Face    *west;      // pointer to west face
}   CUBE;

extern CUBE *CreateCube(void);

#endif //INC_3D_TRAVERSAL_CUBE_H
