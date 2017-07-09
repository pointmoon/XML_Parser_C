#include "stdFunc.h"

/*
* Display info for help.
*/
void vInitial(){
    printf("Select:\n");
    printf("\t1 - Open file;\n");
    printf("\t2 - Display the file on screen;\n");
    printf("\t3 - Processing;\n");
    printf("\t4 - Create new file;\n");
    printf("\t5 - Close program.\n");
}

/*
* Free dynamic memory.
*/
void vDestruction(char** pStrArray, int* iStrCount){
    int i = 0;
    for(i = 0; i < *iStrCount; i++){
        free(pStrArray[i]);
    }
    free(pStrArray);
}

/*
* Read file from memory.
*/
char** vReadFile(FILE* pDescriptionFile, char** pStrArray, int* iStrCount){
    char line[1024];
    while((fgets(line, 1024, pDescriptionFile)) != NULL){
        pStrArray = (char **)realloc(pStrArray, (*iStrCount + 1) * sizeof(char *));
        pStrArray[(*iStrCount)++] = strdup(line);
    }
    return pStrArray;
}

/*
* Open file from memory.
*/
FILE* pFileOpen(char* pCFileName, char* pCFileMode){
    FILE* fXML;
    if((fXML=fopen(pCFileName,pCFileMode)) == NULL){
        printf("Can`t open file.\n");
        exit(1);
    }
    return fXML;
}


