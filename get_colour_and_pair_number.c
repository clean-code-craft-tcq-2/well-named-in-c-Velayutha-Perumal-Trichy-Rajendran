#include <stdio.h>
#include "colour_codes_def.h"
#include "get_colour.h"

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s-%s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void validate_and_generate_reference_manual ()
{
	int pairNumber, expectedpairNumber;
	ColorPair colorPair;
	char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
	int max_pairNumber = numberOfMajorColors * numberOfMinorColors;

	printf ("\n*********%d-Pair Colour codes**********\n", max_pairNumber);
	printf ("Pair_Num Colour-Pair\n");
	
	for (pairNumber = FIRST_PAIR_NUMBER; pairNumber <= max_pairNumber; pairNumber++)
	{
		colorPair = GetColorFromPairNumber(pairNumber);
		expectedpairNumber = GetPairNumberFromColor(&colorPair);
		ColorPairToString(&colorPair, colorPairNames);
		if (expectedpairNumber == pairNumber){
			printf ("%-8d %-10s\n", pairNumber, colorPairNames);
		}
	}
}