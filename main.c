#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ){
    char ** args = malloc(5*sizeof(char*));
    int x = 0;
    while (line != NULL){
        args[x] = strsep(&line, " ");
        x++;
    }
    args[x] = NULL;
    return args;
}

int main(){

    char line[100] = "ls -a -l";
    char *s1 = line;
    char ** args = parse_args(line);
    execvp(args[0], args);
}
