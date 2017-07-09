#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdFunc.h"
#include "Lecser.h"

int main(){
    system("CHCP 1251");
    system("CLS");
    bool    bMainFlag = true,
            bGlobalFlag = true;
    int i = 0,
        strcount = 0;
    char pCFileName[256];
    char** strarray = NULL;
    FILE* fXML = NULL;

    while(1){
        int iDoing = 0;
        vInitial();
        scanf("%i", &iDoing);
        switch(iDoing){
            case 1:{
                printf("Input path to file .xml:\n");
                scanf("%s", pCFileName);
                fXML = pFileOpen(pCFileName, "r+");
                strarray = vReadFile(fXML, strarray, &strcount);
                break;
            }
            case 2:{
                for(i = 0; i < strcount; i++){
                    printf("%s", strarray[i]);
                }
                break;
            }
            case 3:{
                for(i = 0; i < strcount; i++){
                    vLexer(strarray[i], &bMainFlag, &bGlobalFlag);
                }
                if (!bMainFlag || !bGlobalFlag){
                        system("CLS");
                    printf("Error processing code.\n");
                    printf("The code is not valid.\n");
                    vDestruction(strarray, &strcount);
                    exit(EXIT_FAILURE);
                }
                break;
            }
            case 4:{
                fXML = NULL;
                fXML = pFileOpen("output_file.xml", "w+");
                for(i = 0; i < strcount; i++){
                    int j = 0,
                        iCount = 0;
                    iCount = Indentions(strarray[i]);
                    if(iCount != 0){
                        iCount--;
                        for(j = 0; j < iCount; j++){
                            fprintf(fXML, "\t");
                        }
                    }
                    fprintf(fXML, "%s", strarray[i]);
                }
                break;
            }
            case 5:{
                vDestruction(strarray, &strcount);
                exit(EXIT_SUCCESS);
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}
