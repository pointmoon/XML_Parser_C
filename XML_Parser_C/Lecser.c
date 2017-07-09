#include "Lecser.h"

/*
* Lecser function
* bGlobalFlag = 0 - No tag errors;
* bGlobalFlag = 1 - Not enough close tags;
* bGlobalFlag = 1 - Not enough open tags.
* You can add specific values for the variable bGlobalFlag,
* for better orientation in results of treatment.
*/
void vLexer(char* pCStrArray, bool* bMainFlag, bool* bGlobalFlag){
    int iResult_find = 0,
        iError = 0;
    DeleteSpaces(pCStrArray);
    iResult_find = iFindOneTeg(pCStrArray);
    if(iResult_find == 0){
        *bMainFlag = 0;
    }
    iError = TagsErrors(pCStrArray);
    if (iError == 0){
        //printf("No tag errors\n");
        *bGlobalFlag = 0;
    }
    if (iError > 0){
        //printf("Not enough close tags\n");
        *bGlobalFlag = 1;
    }
    if (iError < 0){
        //printf("Not enough open tags\n");
        *bGlobalFlag = 1;
    }
}

/*
* Check for one line comment string:
* Return  0 - if one string comment
* Return -1 - else
*/
int iCheckForOneLineComment(char* pCStrArray){
    if( pCStrArray[0] == '<' &&
        pCStrArray[1] == '!' &&
        pCStrArray[2] == '-' &&
        pCStrArray[3] == '-'){
            size_t lenstr = 0;
            lenstr = strlen((const char*)pCStrArray);
            if( pCStrArray[lenstr - 4] == '-' &&
                pCStrArray[lenstr - 3] == '-' &&
                pCStrArray[lenstr - 2] == '>'){
                    return 0;
            }
    }
    return -1;
}

/*
* Check for string is empty tag:
* Return  0 - if one empty tag in string
* Return -1 - else
*/
int iCheckForOneEmptyTeg(char* pCStrArray){

    return -1;
}

/*
* Report about tag errors, return the quantity of errors.
*/
int TagsErrors(char *str){
	static int a = 0;
	int len = strlen(str);
    int i;
    if ((str[0] == '<') && (str[1] == '/')){
            a--;
    }
    else{
        if ((str[0] == '<') && (str[1] != '!') && (str[1] != '?')){
            for(i = 0; i < len; i++){
                if (str[i] != '/' && str[i+1]=='>'){
                    a++;
                }
            }
        }
    }
    return a;
}

/*
* Delete all spaces.
*/
void DeleteSpaces(char *str){
	int a = 0,
        b = 0,
        c,
        len = strlen(str);
	while(str[a++] == ' '){
		b++;
	}
	for(a = 0; a < len; a++){
        str[a] = str[a+b];
	}
 	len = strlen(str);
	for(a = 0; a < len; a++){
        if(str[a]==' ' && str[a+1]==' '){
            c = a + 1;
            b = 0;
            while(str[c++]==' '){
                b++;
            }
            for(c = a + 1; c < len; c++){
                str[c] = str[c+b];
            }
            len = strlen(str);
		}
    }
	a = strlen(str);
	b = 0;
	while(str[a] == ' '){
        a--;
	}
	if(str[a-1] == ' '){
        str[--a] = 0;
	}
	else{
        str[a] = 0;
	}
}

/*
* A function of calculating the required number of indents at the beginning of the row.
* Returns a number indicating the level at which should be a string.
*/
int Indentions(char *str){
	static int  a = 1,
                b = 0;
    int len = strlen(str),
        i;
    if((str[0] == '<') && (str[1] == '/')){
            a--;
            if (b == 1){
                a++;
            }
    }
    else{
        if(str[0] == '<'){
            for(i = 0; i < len; i++){
                if (str[i] != '/' && str[i+1]=='>'){
                    a = a + b;
                    b = 1;
                }
                else{
                    if (str[i] == '/' && str[i+1]=='>'){
                        a = a + b;
                        b = 0;
                    }
                }
            }
        }
    }
    if((str[0] == '/') || (str[0] == ' ') || (str[0] == '\n')){
        return 0;
    }
	else{
        return a;
	}
}

/*
* If the document contains any at least one tag?
* Return 1 - Tag find
* Return 0 - Tag not find
*/
int iFindOneTeg(char* pCStr){
    bool    bFlag_1 = false,
            bFlag_2 = false;
    int lenstr = strlen(pCStr) - 2;
    register int i = 0;
    for(i = 0; i < lenstr; i++){
        if(pCStr[i] == '<'){
            bFlag_1 = true;
        }
        if(pCStr[i] == '>' && bFlag_1 == true){
            bFlag_2 = true;
            break;
        }
    }
    if(bFlag_1 == true && bFlag_2 == true){
        return 1;
    }
    else{
        return 0;
    }
}

/*
* Get file name from file path.
* Return - File name.
*/
char* pCBreakPath(char* cPPathToFile){
    char* FileName = NULL;
    FileName = (char*)malloc((strlen(cPPathToFile) - strlen("new.xml")) * sizeof(char*));
    return (char*)strncpy(FileName,cPPathToFile, strlen(cPPathToFile) - strlen(".xml"));
}
