#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

char *encrypt(char *plaintext, int key);
char *decrypt(char *ciphertext, int key);

int main() {
    char plaintext[MAX_LEN], ciphertext[MAX_LEN];
    int key, choice;

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);

    do {
        printf("Enter the key value (1-25): ");
        scanf("%d", &key);
    } while (key < 1 || key > 25);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        strcpy(ciphertext, encrypt(plaintext, key));
        printf("The encrypted message is: %s\n", ciphertext);
    } else if (choice == 2) {
        strcpy(plaintext, decrypt(ciphertext, key));
        printf("The decrypted message is: %s\n", plaintext);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

char *encrypt(char *plaintext, int key) {
    char *ciphertext = (char *) malloc(sizeof(char) * MAX_LEN);
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            } else {
                ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
    return ciphertext;
}

char *decrypt(char *ciphertext, int key) {
    char *plaintext = (char *) malloc(sizeof(char) * MAX_LEN);
    int i;

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[i] = ((ciphertext[i] - 'A' + 26 - key) % 26) + 'A';
            } else {
                plaintext[i] = ((ciphertext[i] - 'a' + 26 - key) % 26) + 'a';
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[i] = '\0';
    return plaintext;
}

