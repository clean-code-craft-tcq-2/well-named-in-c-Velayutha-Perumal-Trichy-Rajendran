#ifndef __COLOUR_CODES_H_
#define __COLOUR_CODES_H_

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};


typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

extern int numberOfMajorColors, numberOfMinorColors;
enum colour_attribute {MAX_COLORPAIR_NAME_CHARS = 16, FIRST_PAIR_NUMBER = 1};
//const int MAX_COLORPAIR_NAME_CHARS = 16;
//const int FIRST_PAIR_NUMBER = 1;

ColorPair GetColorFromPairNumber(int pairNumber);
void ColorPairToString(const ColorPair* colorPair, char* buffer);
int GetPairNumberFromColor(const ColorPair* colorPair);

#endif