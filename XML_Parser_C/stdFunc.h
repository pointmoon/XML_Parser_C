#ifndef STDFUNC_H_INCLUDED
#define STDFUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lecser.h"

/*
* Display info for help.
*/
void vInitial();

/*
* Free dynamic memory.
*/
void vDestruction(char**, int*);

/*
* Read file from memory.
*/
char** vReadFile(FILE*, char**, int*);

/*
* Open file from memory.
*/
FILE* pFileOpen(char*, char*);

#endif // STDFUNC_H_INCLUDED
