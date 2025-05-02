// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cmath>

unsigned int faStr1(const char *str) {
    int count = 0;
    int size = strlen(str);
    bool wordFlag = false;
    bool digitFlag = false;

    for (int i = 0; i < size; i++) {
        if (isblank(str[i]) || i == size - 1) {
            if (wordFlag) {
                if (!digitFlag) {
                    count++;
                }
                digitFlag = false;
                wordFlag = false;
            }
        }
        else if (isdigit(str[i])) {
            digitFlag = true;
        }
        else {
            wordFlag = true;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    int size = strlen(str);
    bool upAlphaFlag = false;
    bool correctWord = true;
    bool startWord = true;

    for (int i = 0; i < size; i++) {
        if (isalpha(str[i]) && startWord && isupper(str[i])) {
            upAlphaFlag = true;
            startWord = false;
        }

        else if (startWord && isalpha(str[i]) && !isupper(str[i])) {
            correctWord = false;
        }

        else if ((isalpha(str[i]) && upAlphaFlag && !islower(str[i]))) {
            correctWord = false;
        }
        else if (!isalpha(str[i]) && !isblank(str[i])) {
            correctWord = false;
        }

        if (isblank(str[i]) || i == size - 1) {
            if (correctWord && !startWord && upAlphaFlag) {
                count++;
            }
            upAlphaFlag = false;
            correctWord = true;
            startWord = true;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    int wordCount = 0;
    int alphaCount = 0;
    int size = strlen(str);
    bool wordFlag = false;

    for (int i = 0; i < size; i++) {
        if (isalpha(str[i])) {
            alphaCount++;
            wordFlag = true;
        }
        if (isblank(str[i]) || i == size - 1) {
            if (wordFlag) {
                wordCount++;
                wordFlag = false;
            }
        }
    }

    return round((alphaCount * 1.0) / wordCount);
}
