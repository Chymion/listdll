/* 
	Author: Orane Adjali
	Date: 05/31/2021
	Version: 0.2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
#if defined(_WIN32) || defined(_WIN64)
	printf("This program cannot run on Windows!\n");
	printf("Terminating...\n");
	return 0;
#endif

 	if(argc == 1) {
        printf("List the dependencies of given PE executable or dll file\n");
        printf("Usage: listdll [file]\n\n");
        return 0;
    }

    int i, v = 0, size = argc - 1;

    char *str = (char *)malloc(v);

    for(i = 1; i <= size; i++) {
        str = (char *)realloc(str, (v + strlen(argv[i])));
        strcat(str, argv[i]);
    }


    char* command = "strings \"";
    char* secondPart = "\" | grep -i '\\.dll$' > /tmp/temp.txt";
 
    char buffer[100];
    strcat(buffer, command);
    strcat(buffer, str);
    strcat(buffer, secondPart);
    system(buffer);

	FILE * fptr;
	int c;

    fptr = fopen("/tmp/temp.txt", "r");  
                                    
    while(1){
        c = fgetc(fptr);
        if(c!= EOF)
            printf("%c", c);        
        else
            break;                  
    }

    fclose(fptr);                 
    remove("/tmp/temp.txt");      

    return 0;
}
