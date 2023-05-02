#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 5

void generateMatrix(char *key, char matrix[ROWS][COLS]);
void encrypt(char matrix[ROWS][COLS], char *plaintext, char *ciphertext);

int main() {
    char key[100];
    char plaintext[100];
    char ciphertext[100];
    char matrix[ROWS][COLS];

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // remove newline character

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline character

    generateMatrix(key, matrix);
    encrypt(matrix, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

void generateMatrix(char *key, char matrix[ROWS][COLS]) {
    int i, j, k, len;
    char *p;
    char letters[26] = "abcdefghiklmnopqrstuvwxyz";

    // remove duplicate letters from the key
    len = strlen(key);
    for (i = 0; i < len; i++) {
        key[i] = tolower(key[i]);
        if (key[i] == 'j') {
            key[i] = 'i';
        }
        for (j = i + 1; j < len; j++) {
            if (key[i] == key[j]) {
                for (k = j; k < len; k++) {
                    key[k] = key[k + 1];
                }
                len--;
                j--;
            }
        }
    }

    // fill the matrix with the key
    p = key;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (*p != '\0') {
                matrix[i][j] = *p;
                p++;
            } else {
                break;
            }
        }
        if (*p == '\0') {
            break;
        }
    }

    // fill the rest of the matrix with the remaining letters
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] == '\0') {
                while (1) {
                    if (!strchr(key, letters[0])) {
                        matrix[i][j] = letters[0];
                        letters++;
                        break;
                    }
                    letters++;
                }
            }
        }
    }

    // print the matrix
    printf("Matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void encrypt(char matrix[ROWS][COLS], char *plaintext, char *ciphertext) {
    int i, j, k, len;
    char c1, c2;

    len = strlen(plaintext);

    // pad plaintext with 'x' if necessary
    if (len % 2 == 1) {
        plaintext[len] = 'x';
        len++;
    }

    // encrypt plaintext two letters at a time
    for (i = 0, k = 0; i < len; i += 2, k += 2)


