#include <stdio.h>

// Hash Table: https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "face.h"
#include "word.h"
#include "tools.h"

// FUNCTIONS

void Startup()
{

    CreateLibrary();
    wordList = CreateWord();            // Create the first word
}

/*
ProcessFace (FACE * face)
{
    if (face->state == INITIAL)
    {
        face->state = FindWord(Start);
    }

    Push Current Cube Pointer on Cube Pointer Stack
    Set Current Cube Pointer to Cube Pointer for Face
    Process Cube
}

Count Letters (Cube Pointer, Face)
{
}

Valid Word (Cube Pointer, Face)
{
}

Create Palindrome (Cube Pointer, Face)
{
}

Assign Value to Word (Cube Pointer, Face)
{
}

Discovered Word Start (Face)
        {
                If (Face->State == FIND_START)
        {
            If
                    (
                            Valid Word (Cube Pointer, Face)
            OR
            Valid Word (Create Palindrome (Cube Pointer, Face), Face)
            )
            {
                Add Cube Pointer to Word List
                Set Word Letter Count to Count Letters (Cube Pointer, Face)
                Assign Value to Word (Cube Pointer, Face)
            }

            Set Face State to Initial
            Pop Cube Pointer from Cube Pointer Stack
        }
        }

Process Cube
        {
                if (North Cube Pointer exists)
                {
                    Process Face (North)
                }
                else
                {
                    Discovered Word Start (North)
                    Return
                }

                if (South Cube Pointer exists)
                {
                    Process Face (South)
                }
                else
                {
                    Discovered Word Start (South)
                    Return
                }

                if (East Cube Pointer exists)
                {
                    Process Face (East)
                }
                else
                {
                    Discovered Word Start (East)
                    Return
                }

                if (West Cube Pointer exists)
                {
                    Process Face (West)
                }
                else
                {
                    Discovered Word Start (West)
                    Return
                }

                if (Top Cube Pointer exists)
                {
                    Process Face (Top)
                }
                else
                {
                    Discovered Word Start (Top)
                    Return
                }

                if (Bottom Cube Pointer exists)
                {
                    Process Face (Bottom)
                }
                else
                {
                    Discovered Word Start (Bottom)
                    Return
                }
        }
*/

int main()
{
    Startup();
    return 0;
}
