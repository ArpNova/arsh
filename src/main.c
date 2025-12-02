#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lsh_loop(void){
    char *line;
    char **args;
    int status;
    do
    {
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);
    } while (status);
    
}

int main(int argc, char **argv){

    lsh_loop();

    return EXIT_SUCCESS;
}