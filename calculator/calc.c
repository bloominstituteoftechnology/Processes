#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW 4
#define COL 8
#define CHAR_INDEX_MAX 26

enum alph_enum {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

typedef struct _alphabets {
    char *line[ROW];
}alphabet;

alphabet chars[26];

init_a(enum alph_enum letter)
{
    int i;
    for (i=0 ; i<ROW ; i++) {
        chars[letter].line[i] = (char *) malloc(COL);
        if (chars[letter].line[i] == NULL) {
            printf("memory allocation failed \n");
            return;
        }
    }

    switch (letter) {
                                     /*0123 4567*/
    case H:
        strcpy(chars[letter].line[0], "|     | ");
        strcpy(chars[letter].line[1], "|_____| ");
        strcpy(chars[letter].line[2], "|     | ");
        strcpy(chars[letter].line[3], "|     | ");
        break;
    case E:
        strcpy(chars[letter].line[0], "|----- ");
        strcpy(chars[letter].line[1], "|_____ ");
        strcpy(chars[letter].line[2], "|      ");
        strcpy(chars[letter].line[3], "|_____ ");
        break;
    case L:
        strcpy(chars[letter].line[0], "|      ");
        strcpy(chars[letter].line[1], "|      ");
        strcpy(chars[letter].line[2], "|      ");
        strcpy(chars[letter].line[3], "|_____ ");
        break;
    case O:
        strcpy(chars[letter].line[0], "|'''''|");
        strcpy(chars[letter].line[1], "|     |");
        strcpy(chars[letter].line[2], "|     |");
        strcpy(chars[letter].line[3], "|.....|");
        break;    
    /*  for all the other alphabets */
    }

    return;

}

print_str(char word[])
{
    int i, j;

    printf("\n");
    for (i=0; i<ROW; i++) {
        for (j=0 ; j<strlen(word) ; j++) {
            printf("%s", chars[word[j] % 'A'].line[i]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}

int main(void)
{
    char operator;
    float num1, num2, result;
 
    printf("Calum's C Calculator\n");
    init_a(H);
    init_a(E);
    init_a(L);
    init_a(L);
    init_a(O);
    print_str("HELLO");
    printf("Enter First Number: \n");
    scanf("%f", &num1);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Enter Operator [+,-,*,/]: \n");
    scanf("%s", &operator);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Enter Second Number: \n");
    scanf("%f", &num2);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    fflush(stdin);
    
    switch(operator)
    {
    case '+': result = num1 + num2;
        break;
    case '-': result = num1 - num2;
        break;
    case '*': result = num1 * num2;
        break;
    case '/': result = num1 / num2;
        break;
    default : printf("Error in operationn");
        break;
    }
    printf("Answer = %.2f\n", result);

    return 0;
}