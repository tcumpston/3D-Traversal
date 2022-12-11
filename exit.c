//
// Created by tanya on 11/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

void ExitMessage(char *messagePtr)
{
    fprintf(stderr, messagePtr);
    exit(1);
}
