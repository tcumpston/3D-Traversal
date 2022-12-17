//
// Created by tanya on 11/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"

void ExitMessage(char *messagePtr)
{
    if (DEBUG_ENABLED) fprintf(stderr, messagePtr);
    exit(1);
}
