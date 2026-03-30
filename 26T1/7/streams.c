#include <stdio.h>
#include <unistd.h>

// int main(void) {
//     char c;
//     scanf("%c", &c);
//     printf("%c\n", c);
// }

// int main(void) {
//     unsigned char c;
//     fscanf(stdin, "%c", &c);
//     fprintf(stdout, "%c\n", c);
// }

// int main(void) {
//     unsigned char c;
//     char newline = '\n';
//     fread(&c, 1, 1, stdin);
//     fwrite(&c, 1, 1, stdout);
//     fwrite(&newline, 1, 1, stdout);
// }

int main(void) {
    char c;
    char newline = '\n';
    read(0, &c, 1);
    write(1, &c, 1);
    write(1, &newline, 1);
}