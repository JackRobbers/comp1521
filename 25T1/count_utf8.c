int main(int argc, char *argv[]) {
    int count = 0;
    int i = 0;
    char byte = argv[1][i];
    while(byte != '\0') {
        if (byte >> 7 == 0) {
            count+= a;
            i++;
        }

        

        byte = argv[1][i];
    }

    printf("There are %d codepoints in the string\n", count);
}