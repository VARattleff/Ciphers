#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cipher.h"

void get_shift_value(int *shift_value);
void get_choice_input(char *choice);
void get_text_input(char *text);

int main() 
{
    printf("\nWelcome to the Caesar program\n");
    printf("------------------------------\n");

    bool exit_system = false;
    char choice;
    int shift_value;
    char text[255]; 

    while (!exit_system) {
        printf("Please select if you want to encrypt or decrypt\n");
        printf("(d) -> for decrypt\n");
        printf("(e) -> for encrypt\n");
        printf("(q) -> to quit system\n");
        printf("Input the value here and press enter: ");

        get_choice_input(&choice);  

        switch (choice) {
        case 'd':
        case 'D':
            printf("You selected decrypt\n");
            printf("Please provide the shift amount for the Caesar cipher: ");
            get_shift_value(&shift_value);  
            if (shift_value <0 || shift_value > 29) {
                printf("\n\n-------------------------------------------\n");
                printf("Error reading input. Returning main menu...\n");
                printf("-------------------------------------------\n\n");
            } else {
                printf("Enter the text to decrypt:\n");
                get_text_input(text);
                decrypt(text, shift_value);
                printf("Decrypted text: %s\n", text);
            }
            exit_system = false;
            break;
        case 'e':
        case 'E':
            printf("You selected encrypt\n");
            printf("Please provide the shift amount for the Caesar cipher: ");
            get_shift_value(&shift_value);
            if (shift_value < 0 || shift_value > 29) {  
                printf("\n\n-------------------------------------------\n");
                printf("Error reading input. Returning main menu...\n");
                printf("-------------------------------------------\n\n");
            } else {
                printf("Enter the text to encrypt:\n");
                get_text_input(text);
                encrypt(text, shift_value);
                printf("Encrypted text: %s\n", text);
            }
            exit_system = false;
            break;
        case 'q':
        case 'Q':
            exit_system = true;
            break;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }

    return 0;
}

void get_choice_input(char *choice) 
{
    char buffer[255];
    if (fgets(buffer, sizeof(buffer), stdin)) 
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] != '\0') 
        {
            *choice = buffer[0];
        } 
        else 
        {
            *choice = '\0'; 
        }
    } 
    else 
    {
        *choice = '\0'; 
    }
}

void get_shift_value(int *shift_value) 
{
    char buffer[255];
    if (fgets(buffer, sizeof(buffer), stdin)) 
    {
        *shift_value = atoi(buffer);
        if (*shift_value <= 0) 
        {
            *shift_value = 0; 
        }
    } 
    else 
    {
        *shift_value = 0; 
    }
}

void get_text_input(char *text) 
{
    char buffer[255];
    if (fgets(buffer, sizeof(buffer), stdin)) 
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] != '\0') 
        {
            strcpy(text, buffer);  
        } 
        else 
        {
            text[0] = '\0'; 
        }
    } 
    else 
    {
        text[0] = '\0'; 
    }
}