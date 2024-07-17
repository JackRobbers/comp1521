// search either in stdin or files
// argv[1] is the string to search for
// argv[2...] is optional and are filenames to look in

#include <stdio.h>
#include <string.h>
#include <errno.h>  
#include <stdlib.h>

#define MAX 1024

void search(FILE *file, char *name, char *search);

int main(int argc, char *argv[]) {
    
    return 0;
}

// given a file, find any occurances of the search string
// and print them out.
void search(FILE *file, char *name, char *search) {
}