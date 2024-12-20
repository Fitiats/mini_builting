
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>      

#define BUFFER_SIZE 10000

int main(void) 
{

    char buffer[BUFFER_SIZE];
    if(getcwd(buffer, BUFFER_SIZE) != NULL)
        printf("%s\n", buffer);
    return (0);
}
