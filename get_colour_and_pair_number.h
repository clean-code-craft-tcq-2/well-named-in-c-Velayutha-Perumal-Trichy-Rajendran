#ifndef __GET_COLOUR_AND_PAIR_NUMBER_H__
#define __GET_COLOUR_AND_PAIR_NUMBER_H__
#include "25pair_colour_code_def.h"

ColorPair GetColorFromPairNumber(int pairNumber);
void ColorPairToString(const ColorPair* colorPair, char* buffer);
int GetPairNumberFromColor(const ColorPair* colorPair);

#endif
