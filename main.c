#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool only_digits(char* string);

int main(int argc, char* argv[]) {

    if(argc != 2) {
       printf("Usage: ./caesar key\n");
       return 1; 
    }

    if (!only_digits(argv[1])) {
        printf("Usage: ./caesar key\n");
       return 1; 
    }

    char *plaintext = NULL;
    size_t buffer_size = 0;
    printf("plaintext: ");
    getline(&plaintext, &buffer_size, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    int key = atoi(argv[1]) % 26;

    printf("ciphertex: ");
    for(int i = 0, n = strlen(plaintext); i < n; i++) {
        char c = plaintext[i];

        if(isalpha(c)) {
            if(isupper(c)) {
                printf("%c", ((c - 'A' + key) % 26) + 'A');
            } else if(islower(c)) {
                printf("%c", ((c - 'a' + key) % 26) + 'a');
            }
        } else {
            printf("%c", c);

        }
    
    }
    printf("\n");

    free(plaintext);
    return 0;

}

bool only_digits(char* string) {
    for(int i = 0; i < strlen(string); i++) {
        if(!isdigit(string[i])) {
            return false;
        }
    }
    return true;
}