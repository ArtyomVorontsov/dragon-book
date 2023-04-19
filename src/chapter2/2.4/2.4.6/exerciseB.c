#include <stdio.h>
#include <stdlib.h>
// S -> S ( S ) S | ε

char input[100];
char *input_end = input;
char *current = input;

void S();
int match(char c);

int main()
{
    printf("Input string: \n");
    scanf("%s", input);
    
    
    while(*input_end++);
    input_end--;
    
    S();
    
    if(input_end != current) {
        printf("Syntax error in length\n");
        exit(1);
    } 
    printf("Syntax is correct\n");

    return 0;
}

void S(){
    switch(*current){
        case '(':
            match('(');
            S();
            match(')');
            S();
            break;
        
        default:
           return;
    }
}

int match(char c){
    if(c == *current) {
        current++;
    } else {
        printf("Syntax error in match\n");
        exit(1);
    }
    
    return 0;
}

