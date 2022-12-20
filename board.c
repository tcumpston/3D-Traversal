//
// Created by tanya on 17/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "letter.h"
#include "board.h"
#include "face.h"

LETTER *board[BOARD_WIDTH * BOARD_WIDTH * BOARD_WIDTH];

void InitialiseBoard()
{
    for (int z = 0; z < BOARD_WIDTH; z++)
    {
        for (int y = 0; y < BOARD_WIDTH; y++)
        {
            for (int x = 0; x < BOARD_WIDTH; x++)
            {
                board[z * BOARD_WIDTH * BOARD_WIDTH + y * BOARD_WIDTH + z] = NULL;
            }
        }
    }
}

void PutLetter(LETTER *letter, int x, int y, int z)
{
    board[z * BOARD_WIDTH * BOARD_WIDTH + y * BOARD_WIDTH + z] = letter;
}

LETTER *GetLetter(LETTER *letter, int x, int y, int z)
{
    return board[z * BOARD_WIDTH * BOARD_WIDTH + y * BOARD_WIDTH + z];
}

int FindLetterOffsetInLine(LETTER *lineEntry)
{

}