#include "./lib/cutest-1.5/CuTest.h"
#include <stdio.h>

CuSuite *exercise_2_4_6_A_getSuite();

void RunAllTests(void) {
	// Create output buffer
	CuString *output = CuStringNew();
	// Create new suite 
	CuSuite *suite = CuSuiteNew();

	// Assign function which is tested to suite
	CuSuiteAddSuite(suite, exercise_2_4_6_A_getSuite());

	// Run all suites
	CuSuiteRun(suite);

	// Print tests stuff
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

