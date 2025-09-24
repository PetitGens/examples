#include <stdio.h>
#include "input.h"

int isNewLineOrEOF(char c) {
  return c == '\n' || c == '\0';
}

int includesNewLineOrEOF(const char* src) {
  for (int i = 0; src[i] != '\0'; i++) {
    if (isNewLineOrEOF(src[i])) return 1;
  }
  return 0;
}

void clearStdinBuffer() {  
  while (! isNewLineOrEOF(getchar())) {}
}

short int promptShortInteger(const char* promptMessage) {
  short int input = 0;
  int valid = 0;
  do {
    printf("%s", promptMessage);
    if (scanf("%hd", &input) >= 1) valid = 1;
    clearStdinBuffer();
  } while (! valid);
  return input;
}

short int promptShortIntegerMin(const char* promptMessage, int min) {
  int value = 0;
  do {
    value = promptShortInteger(promptMessage);
  } while(value < min);
  return value;
}

int promptNumber(const char* promptMessage) {
  return promptInteger(promptMessage);
}

int promptInteger(const char* promptMessage) {
  int input = 0;
  int valid = 0;
  do {
    printf("%s", promptMessage);
    if (scanf("%d", &input) >= 1) valid = 1;
    clearStdinBuffer();
  } while (! valid);
  return input;
}

int promptIntegerMin(const char* promptMessage, int min) {
  int value = 0;
  do {
    value = promptInteger(promptMessage);
  } while(value < min);
  return value;
}

int promptIntegerMinMax(const char* promptMessage, int min, int max) {
  int value = 0;
  do {
    value = promptInteger(promptMessage);
  } while(value < min || value > max);
  return value;
}

double promptDouble(const char* promptMessage) {
  double input = 0;
  int valid = 0;

  do {
    printf("%s", promptMessage);
    if (scanf("%lf", &input) >= 1) valid = 1;
    clearStdinBuffer();
  } while (! valid);

  return input;
}

double promptDoubleMin(const char* promptMessage, double min) {
  double value = 0;
  do {
    value = promptDouble(promptMessage);
  } while(value < min);
  return value;
}

int promptBool(const char* promptMessage) {
  return promptIntegerMinMax(promptMessage, 0, 1);
}
