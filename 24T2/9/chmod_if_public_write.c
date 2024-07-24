#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    // loop through filenames in argv[]
    for (int i = 1; i < argc; i++) {
        chmod_if_needed(argv[i]);
    }
    return 0;
}

void chmod_if_needed(char *pathname) {

}