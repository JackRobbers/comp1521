#include <stdio.h>
#include <unistd.h>

// int main(void) {
//     char c;
//     scanf("%c", &c);
//     printf("%c\n", c);
// }

// int main(void) {
//     char c;
//     fscanf(stdin, "%c", &c);
//     fprintf(stdout, "%c\n", c);
// }

// int main(void) {
//     char c[2];
//     fread(c, 1, 1, stdin);
//     c[1] = '\n';
//     fwrite(c, 2, 1, stdout);
// }

int main(void) {
    char c[2];
    read(0, c, 1);
    c[1] = '\n';
    write(1, c, 2);
}
