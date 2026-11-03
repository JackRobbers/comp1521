// write a byte argv[2] at argv[1]

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r+"); 
    printf("offset is %d\n", atoi(argv[2]));
    fseek(file, atoi(argv[2]), SEEK_SET);
    char line[1024];
    fgets(line, 1024, stdin);
    fputs(line, file);
}