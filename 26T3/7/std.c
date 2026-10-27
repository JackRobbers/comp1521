#include <stdio.h>
#include <unistd.h>

int main(void) {
    unsigned char c;
    scanf("%c", &c);
    printf("%c\n", c);
}

int main(void) {
    unsigned char c;
    read(0, &c, 1);
    
    unsigned char newline = '\n'; 
    write(1, &c, 1);
    write(1, &newline, 1);
}
// int main(void) {
//     unsigned char c;
//     fscanf(stdin, "%c", &c);
//     fprintf(stdout, "%c\n", c);
// }

// int main(void) {
//     unsigned char c;
//     fread(&c, 1, 1, stdin);

//     unsigned char newline = '\n'; 
//     fwrite(&c, 1, 1, stdout);
//     fwrite(&newline, 1, 1, stdout);
// }