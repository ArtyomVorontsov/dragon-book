/* 
 Recursive decent syntax analyser
 Production
 S -> +SS | -SS | a
*/

#include <stdio.h>
#include <stdlib.h>

void S(void);
void match(char c);

char *current_char;

int main(void){
	char buffer[100], *str_end;
	current_char = buffer;
	str_end = buffer;

	printf("Type string which is in grammar S -> +SS | -SS | a\n");
	scanf("%s", buffer);
	while(*str_end++);
	str_end--;
	
	S();

	if(str_end == current_char)
		printf("String is correct\n");
	else 
		printf("Syntax error\n"), exit(1);

	return 0;

}

void S(void){
	switch(*current_char){
		case '+':
			match('+');
			S();
			S();
			break;

		case '-':
			match('-');
			S();
			S();
			break;

		case 'a':
			match('a');
			break;

		default:
			printf("Syntax error\n");
			exit(1);

	}
}

void match(char c){
	if(c == *current_char){
		current_char++; 
		return;
	} else 
		printf("Syntax error\n"), exit(1);
}

