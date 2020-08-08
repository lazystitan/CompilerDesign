//
// Created by Riton on 2020/8/8.
//

#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 4096

void match(char **);
void expr(char **);
void rest(char **);
void term(char **);

void match(char **lookaheadPos) {
    (*lookaheadPos)++;
}

void expr(char **lookahead) {
    term(lookahead);
    rest(lookahead);
}

void rest(char **lookahead) {
    if (**lookahead == '+') {
        match(lookahead);
        term(lookahead);
        printf("+ ");
        rest(lookahead);
    } else if (**lookahead == '-') {
        match(lookahead);
        term(lookahead);
        printf("- ");
        rest(lookahead);
    } else {}
}

void term(char **lookahead) {
    if ( **lookahead > '0' && **lookahead <= '9') {
        char t = **lookahead;
        match(lookahead);
        printf("%c ", t);
    } else {
        printf("syntax error");
        exit(1);
    }
}



int main() {
    char *inputBuffer = calloc(sizeof(char), MAX_INPUT_SIZE);
    char *lookahead = inputBuffer;

    scanf ("%s", inputBuffer);
//    strcpy(inputBuffer, "9+6-7");
//    printf("%s\n", inputBuffer);
    expr(&lookahead);
    free(inputBuffer);

    return 0;
}