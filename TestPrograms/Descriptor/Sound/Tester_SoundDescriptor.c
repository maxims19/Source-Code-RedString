/**
 * \file Tester_SoundDescriptor.c
 * \brief Tester of SoundDescriptor functions
 * \author Morgan Chabaud \n
 */


#include "SoundDescriptor.h"
#include "FileManager.h"
#include "Type_Bool.h"



Bool tests_createDescriptor(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundDescriptor:\n");
	
	hasPassed = tests_createDescriptor(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_createDescriptor: Success\n");
	else
		printf("\n\t\tTests_createDescriptor: Failure\n");

	printf("\tTester_End\n");
}

Bool tests_createDescriptor(Bool details)
{
	Bool testPassed = TRUE;
	FILE* testFile = fopen("/home/rayope/SRI/FilRouge/data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("Error tests_createDescriptor fopen");
		return FALSE;
	}

	globs_windowSize = 4096;//2048;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;
	// Display a file
	if(details)
		printf("\nIt displays the test file: ");
	if(createDescriptor(testFile) == NULL)
	{
		if(details)
			printf("Pass");
	}
	else
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}

	fclose(testFile);
	return testPassed;
}