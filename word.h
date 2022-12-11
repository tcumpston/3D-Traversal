//
// Created by tanya on 11/12/2022.
//

#ifndef INC_3D_TRAVERSAL_WORD_H
#define INC_3D_TRAVERSAL_WORD_H

#include "word.h"
#include "letter.h"

typedef struct Word
{
    LETTER *letter;     // linked list of LETTERs
}   WORD;

extern WORD *wordList;     // linked list of WORDs

extern WORD *CreateWord();


#endif //INC_3D_TRAVERSAL_WORD_H
