#ifndef __GET_COLOUR_H__
#define __GET_COLOUR_H__

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
	
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


#endif
