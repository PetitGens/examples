#ifndef __INPUT_H__
#define __INPUT_H__

int isNewLineOrEOF(char c);

int includesNewLineOrEOF(const char* src);

void clearStdinBuffer();

short int promptShortIntegerMin(const char* promptMessage, int min);

/**
 * @deprecated
 */
int promptNumber(const char* promptMessage);

int promptInteger(const char* promptMessage);

int promptIntegerMin(const char* promptMessage, int min);

int promptIntegerMinMax(const char* promptMessage, int min, int max);

/**
 * @brief Demande un double à l'utilisateur, en affichant un message
 * @param promptMessage 
 * @return double 
 */
double promptDouble(const char* promptMessage);

double promptDoubleMin(const char* promptMessage, double min);

int promptBool(const char* promptMessage);

#endif //__INPUT_H__
