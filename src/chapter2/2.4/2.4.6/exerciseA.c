/* 
 Recursive decent syntax analyser
 Production
 S -> +SS | -SS | a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../../lib/cutest-1.5/CuTest.h"

int G(char *inp);
void S(void);
void match(char c);

char *current_char;
char *str_end;
bool success = true;

int main(int argc, char *argv[]){

	if(argc > 1){
		if(strcmp(argv[1], "--test") == 0){
			RunAllTests();
			return 0;
		}

		printf("Not supported parameter(s) is(are) passed\n");
		return 1;
	}


	printf("Type string which is in grammar S -> +SS | -SS | a\n");

	char buffer[100];

	// Get string
	scanf("%s", buffer);


	return G(buffer);
}

int G(char *inp){
	current_char = inp;
	str_end = inp;

	// Get string length
	while(*str_end++);
	str_end--;
	
	S();

	if(str_end == current_char && success != false)
		printf("String is correct\n");
	else 
		printf("Syntax error\n"), success = false;

	return !success;
}

void S(void){
	if(success == false) return;
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
			success = false;

	}
}

void match(char c){
	if(success == false) return;
	if(c == *current_char){
		current_char++; 
		return;
	} else 
		printf("Syntax error\n");
		success = false;
}



/* Tests */
void TestG1(CuTest *tc);
void TestG2(CuTest *tc);
void TestG3(CuTest *tc);
void TestG1Unhappy(CuTest *tc);

CuSuite *exercise_2_4_6_A_getSuite(void){
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestG1);
	SUITE_ADD_TEST(suite, TestG2);
	SUITE_ADD_TEST(suite, TestG3);
	SUITE_ADD_TEST(suite, TestG1Unhappy);

	return suite;
}

// happy

void TestG1(CuTest *tc){
	char *input = strdup("+aa");
	int expected = 0;

	int actual = G(input);

	CuAssertIntEquals(tc, expected, actual);
}

void TestG2(CuTest *tc){
	char *input = strdup("+a+aa");
	int expected = 0;

	int actual = G(input);

	CuAssertIntEquals(tc, expected, actual);
}


void TestG3(CuTest *tc){
	char *input = strdup("+a+a+aa");
	int expected = 0;

	int actual = G(input);

	CuAssertIntEquals(tc, expected, actual);
}

// unhappy

void TestG1Unhappy(CuTest *tc){
	char *input = strdup("+a++aa");
	int expected = 1;

	int actual = G(input);

	CuAssertIntEquals(tc, expected, actual);
}

