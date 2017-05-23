#include <stdio.h>
#include <stdlib.h>
#include "camelCaser.h"

void print_output(char **output){
    printf("Got the following:\n");
    if(output){
        char ** line = output;
        while(*line){
            printf("\"%s\",", *line);
            line++;
        }
    } else{
        printf("NULL POINTER!\n");
    }
    printf("\n-----------------------------------------------------------------------------------------\n");
}

void print_input(char * input){
    printf("testing: \n\t'%s'\n\n", input);
}

int main() {
    char * inputs[] = {
       "This is awesome, I love 241 cs and furthermore, love computer science as a whole!",
        NULL
    };

    char ** input = inputs;
    while(*input){
        print_input(*input);
        char **output = camel_caser(*input);
        print_output(output);
        input++;
    }
    return 0;
}