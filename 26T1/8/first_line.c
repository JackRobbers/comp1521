// one command-line argument, the name of a file,
// prints the first line of that file to stdout. 
// If given an incorrect number of arguments, 
// if there was an error opening the file, 
///it should print a suitable error message. 

#include <stdio.h>
#include <string.h>
    
#define MAX 10

int main(int argc, char *argv[]) {

    // argv could be anything
    if (argc != 2) {
        printf("Incorrect number of arguments\n");
        printf("Usage: ./first_line.c filename\n");
        return 1;
    }
    // argv can only be ['program_name, 'filename]

    FILE *file = fopen(argv[1], "r");
    // file could be valid, or null
    if (file == NULL) {
        perror(argv[1]);
        return 1;
    } 
    // file must be valid  
    char line[MAX];
    if (fgets(line, MAX, file) == NULL) {
        perror(argv[1]);
    }
    

    //line could be longer than 1024
    int last_char = strlen(line);
    if (last_char == MAX - 1 &&  line[MAX - 1] != '\n') {
        fprintf(stderr, "Line too long, will mess up output, aborting\n");
        return 1;
    }
    // line is at most 1024 chars, and includes a newline as the last char
   
    fputs(line, stdout);
    

    
    return 0;
}