#include <stdio.h>
#include <string.h>

int checkString(char str[]) {
    int i = 0;
    int string_len = strlen(str);
    if (string_len < 2) {
        return 0; 
    }
    if (str[string_len - 1] != 'b' || str[string_len - 2] != 'b') {
        return 0; 
    }
    for (i = 0; i < string_len - 2; i++) {
        if (str[i] != 'a') {
            return 0;
        }
    }

    return 1; 
}

int main() {
    char str[100];
    printf("Enter String: ");
    scanf("%s", str);
    if (checkString(str)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }
    return 0;
}