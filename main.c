/* 
Author: Orane Adjali
Date: 31/05/2021
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /*=  "strings "$*" | grep -i '\.dll$' */

 	if(argc == 1) {
        printf("ERROR: You have to input one file...\n");
        return 0;
    }

    int i, v = 0, size = argc - 1;

    char *str = (char *)malloc(v);

    for(i = 1; i <= size; i++) {
        str = (char *)realloc(str, (v + strlen(argv[i])));
        strcat(str, argv[i]);
        //strcat(str, " ");
    }


    char* command = "strings \"";
    char* pipe = "\" | grep -i '\\.dll$'";
    //char* buffer[100];

    char inter[100];
    strcat(inter, command);
    strcat(inter, str);
    strcat(inter, pipe);

    system(inter);

   	//strcat()
    //system()
    char buffer[100];
    char* find = "find ~/* -name \"*";
    char* endString = "*\" | grep ."; 
    strcat(buffer, find);



    return 0;

}
