#include <stdio.h>
#include <assert.h>
#include "25pair_colour_code_def.h"

const int MAX_COLORPAIR_NAME_CHARS = 16;
#define FIRST_PAIR 1

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void generate_reference_manual ()
{
	int pairNumber;
	ColorPair colorPair;
	char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
	int max_pairNumber = numberOfMajorColors * numberOfMinorColors;
	printf ("\n*********25-Pair Colour codes**********\n");
	printf ("Pair_Num Major Minor\n");
	
	for (pairNumber = FIRST_PAIR; pairNumber <= max_pairNumber; pairNumber++)
	{
		colorPair = GetColorFromPairNumber(pairNumber);
    
		ColorPairToString(&colorPair, colorPairNames);
		printf ("%d      |%s\n", pairNumber, colorPairNames);
	}
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
	
	generate_reference_manual ();
    return 0;
}
