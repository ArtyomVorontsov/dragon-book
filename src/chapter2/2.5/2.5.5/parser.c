#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// expr -> expr + term { print('+') }
// expr -> expr + term { print('-') }
// term

void expr();
void term();
void match(char c);

char buffer[100];
char *lookahead = buffer;
char *input_end = buffer;

int main(void){
	printf("Type infix expression: ");
	scanf("%s", buffer);

	while(*input_end++);
	input_end--;

	expr();
	printf("\n");

	if(input_end != lookahead){
		printf("Syntax error (length)\n");
		exit(1);
	}

	return 0;
}

void expr(){
	term();
	while(true){
		if(*lookahead == '+'){
			match('+');
			term();
			printf("+");
			continue;
		}

		if(*lookahead == '-'){
			match('-');
			term();
			printf("-");
			continue;
		}

		break;	
	}
}

void term(){
	if(isdigit(*lookahead)) {
		printf("%c", *lookahead);
		match(*lookahead);
	} else {
		printf("Syntax error (term)\n");
		exit(1);
	}
}

void match(char c){
	if(*lookahead == c){
	       	lookahead++;
	} else {
		printf("Syntax error (match)\n");
		exit(1);
	}
}
