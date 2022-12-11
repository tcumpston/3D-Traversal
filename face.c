//
// Created by tanya on 11/12/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "face.h"

//  Need to initialise:
//      enum FACE_STATE     state;
//      struct CUBE *       parentCube;
//      struct LETTER *     nextLetter;
FACE *CreateFace(CUBE *cubePtr)
{
    FACE *facePtr = calloc(1, sizeof(FACE));

    if (facePtr == NULL)
    {
        ExitMessage("Calloc() failed in CreateFace().");
    }
    else
    {
        facePtr->parentCube = cubePtr;  // link to CUBE to which this FACE belongs
        return facePtr;
    }
}

