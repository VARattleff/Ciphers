#include "cipher.h"
#include <ctype.h>
#include <string.h>

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
const int ALPHABET_LENGTH = 29;

int letterToNumber(char letter) {
    letter = toupper(letter); 
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        if (ALPHABET[i] == letter) {
            return i; 
        }
    }
    return -1; 
}

char numberToLetter(int number) {
    if (number >= 0 && number < ALPHABET_LENGTH) {
        return ALPHABET[number]; 
    }
    return ' '; 
}

int shift(int number, int shiftValue) {
    return (number + shiftValue + ALPHABET_LENGTH) % ALPHABET_LENGTH;
}

void encrypt(char* text, int shiftValue) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (isalpha(c)) {
            int number = letterToNumber(c);
            if (number >= 0) { 
                int shiftedNumber = shift(number, shiftValue);
                text[i] = numberToLetter(shiftedNumber);
            }
        } else {
            text[i] = c; 
        }
    }
}

void decrypt(char* text, int shiftValue) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (isalpha(c)) {
            int number = letterToNumber(c);
            if (number >= 0) { 
                int shiftedNumber = shift(number, -shiftValue);
                text[i] = numberToLetter(shiftedNumber);
            }
        } else {
            text[i] = c;
        }
    }
}