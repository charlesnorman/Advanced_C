#include <stdio.h>
#include <stdlib.h>

/* int sprintf ( char * str, const char * format, ... );
Composes a string with the same text that would be printed
if format was used on printf, but instead of being printed,
the content is stored as a C string in the buffer pointed by str.
UNSAFE CAN over write char**/

/* int fprintf ( FILE * stream, const char * format, ... );
   Writes the C string pointed by format to the stream.
   If format includes format specifiers (subsequences beginning with %),
   the additional arguments following format are formatted and
   inserted in the resulting string replacing their respective specifiers.*/

int main()
{
    /********************************************************************************/
    /** sprintf**/
    char string[100];
    sprintf(string, "\nHello, this is the number: %d", 55);
    puts(string);

    /********************************************************************************/
    /** fprintf**/
    FILE *f = NULL;
    /** Open file for read write operations**/
    if((f = fopen("test.txt", "a+")) == NULL) {
        printf("Cannot open file...");
        return 1;
    }
    for(int i = 0; i < 10; i++)
    {
        fprintf(f, "The count number is %d\n", i);
    }
    fclose(f);
    /** open, read and print contents of file**/
    if((f = fopen("test.txt", "r+")) == NULL) {
        printf("Cannot open file...");
        return 1;
    }
    printf("\nFile contents is--\n");
    printf("********************************************************************************\n");

    while(!feof(f)){
        fgets(string, 100, f);
        printf("%s", string);
    }
    fclose(f);
    return 0;
}