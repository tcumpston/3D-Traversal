//
// Created by tanya on 11/12/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "cube.h"
#include "face.h"

//  Need to initialise:
//      struct FACE    *north;
//      struct FACE    *south;
//      struct FACE    *top;
//      struct FACE    *bottom;
//      struct FACE    *east;
//      struct FACE    *west;
CUBE *CreateCube(void)
{
    CUBE *cubePtr = calloc(1, sizeof(CUBE));

    if (cubePtr == NULL)
    {
        ExitMessage("Calloc() failed in CreateCube().");
    }
    else
    {
        // Create the six faces of the cube
        cubePtr->north  = CreateFace(cubePtr);
        cubePtr->south  = CreateFace(cubePtr);
        cubePtr->top    = CreateFace(cubePtr);
        cubePtr->bottom = CreateFace(cubePtr);
        cubePtr->east   = CreateFace(cubePtr);
        cubePtr->west   = CreateFace(cubePtr);

        return cubePtr;
    }
}

