#include <stdio.h>
#include <string.h>

void reverseString(char* str, int index) {
    if (index < 0) return;
    putchar(str[index]);
    reverseString(str, index - 1);
}

int main() {
    char str[] = "hello";
    printf("Reversed: ");
    reverseString(str, strlen(str) - 1);
    printf("\n");
    return 0;
}
