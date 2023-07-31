#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buf[255];
    int ch = '\0';
    char *p = NULL;

    if(fgets(buf, sizeof(buf), stdin))
    {
        p = strchr(buf, '\n');
        if(p)
        {
            *p = '\n';
        }
        else
        {
            while(((ch = getchar()) != '\n' &&
                        !feof(stdin) &&
                        !ferror(stdin)));
        }
    }
    else
    {
        printf("Got an error!\n");
        return 1;
    
    }
    printf("%s\n", buf);
    return 0;
}
