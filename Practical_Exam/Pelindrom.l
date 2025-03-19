%{
#include <stdio.h>
#include <string.h>
#include<ctype.h>

void check_palindrome(char *str);
%}

%%
[a-zA-Z]+  { check_palindrome(yytext); }
\n         {  }
.          {  }
%%

void check_palindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            printf("%s is not a palindrome\n", str);
            return;
        }
    }
    printf("%s is a palindrome\n", str);
}

int main() {
    yylex();
    yywrap();
    return 0;
}

int yywrap()
{
    return 1;
}