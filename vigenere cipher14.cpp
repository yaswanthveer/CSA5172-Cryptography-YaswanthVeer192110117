#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int n = strlen(plaintext);
    int i, j;
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == strlen(key)) j = 0;
        ciphertext[i] = ((plaintext[i] + key[j] - 2 * 'A') % 26) + 'A';
    }
    ciphertext[i] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int n = strlen(ciphertext);
    int i, j;
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == strlen(key)) j = 0;
        plaintext[i] = ((ciphertext[i] - key[j] + 26) % 26) + 'A';
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[MAX_LEN];
    char key[MAX_LEN];
    char ciphertext[MAX_LEN];

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_LEN, stdin);

    // Remove newline characters
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}


