#ifndef LECSER_H_INCLUDED
#define LECSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdFunc.h"

/*
* Lecser function
* bGlobalFlag = 0 - No tag errors;
* bGlobalFlag = 1 - Not enough close tags;
* bGlobalFlag = 1 - Not enough open tags.
* You can add specific values for the variable bGlobalFlag,
* for better orientation in results of treatment.
*/
void vLexer(char*, bool*, bool*);

/*
* Check for one line comment string:
* Return  0 - if one string comment
* Return -1 - else
*/
int iCheckForOneLineComment(char*);

/*
* Check for string is empty teg:
* Return  0 - if one empty teg in string
* Return -1 - else
*/
int iCheckForOneEmptyTeg(char*);

/*
* Delete all spaces.
*/
void DeleteSpaces(char*);

/*
* A function of calculating the required number of indents at the beginning of the row.
* Returns a number indicating the level at which should be a string.
*/
int Indentions(char*);

/*
* If the document contains any at least one tag?
* Return 1 - Tag find
* Return 0 - Tag not find
*/
int iFindOneTeg(char*);

/*
* Report about tag errors, return the quantity of errors.
*/
int TagsErrors(char*);

/*
* Get file name from file path
* Return - File name
*/
char* pCBreakPath(char*);
#endif // LECSER_H_INCLUDED
