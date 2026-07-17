#include <stdio.h>
#include <unistd.h>

int main(void) {
    char c;
    scanf("%c", &c);
    printf("%c\n", c);
}

int main(void) {
    char c;
    fscanf(stdin, "%c", &c);
    fprintf(stdout, "%c\n", c);
}

int main(void) {
    char c;
    fread(stdin, 2, &c);
    fwrite(stdout, "%c\n", 2);
}

int main(void) {
    char c;
    read(0, 2, &c);
    write(1, "%c\n", 2);
}

