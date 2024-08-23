#include <unistd.h>
#include <stdio.h>

int main() {
    const char *target = "sample.txt";
    const char *link_name = "softlink";

    if (symlink(target, link_name) == -1) {
        perror("symlink");
        return 1;
    } else printf("cREATED sUCCESFULLY \n");

    return 0;
}
