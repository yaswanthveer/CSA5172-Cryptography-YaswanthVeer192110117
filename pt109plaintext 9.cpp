#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grid[5][5]; // Playfair matrix

void generateGrid(char *key) {
    int i, j, k, used[26] = {0};
    char c;

    // Add key to the grid
    k = 0;
    for (i = 0; i < strlen(key); i++) {
        c = key[i] >= 'A' && key[i] <= 'Z' ? key[i] - 'A' + 'a' : key[i];
        if (c == 'j') c = 'i'; // replace 'j' with 'i'
        if (!used[c - 'a']) {
            grid[k / 5][k % 5] = c;
            used[c - 'a'] = 1;
            k++;
        }
    }

    // Add remaining letters to the grid
    for (i = 0; i < 26; i++) {
        if (i == 'j' - 'a') continue;
        c = i + 'a';
        if (!used[i]) {
            grid[k / 5][k % 5] = c;
            used[i] = 1;
            k++;
        }
    }
}

// Find the row and column of a character in the grid
void findPosition(char c, int *row, int *col) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (grid[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Decrypt the ciphertext using the Playfair cipher
void decrypt(char *ciphertext, char *key) {
    generateGrid(key);

    int i, j, r1, c1, r2, c2;
    char a, b;

    // Decrypt each pair of letters in the ciphertext
    for (i = 0; i < strlen(ciphertext); i += 2) {
        a = ciphertext[i];
        b = ciphertext[i + 1];

        // Find the row and column of each letter
        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2) { // same row
            printf("%c%c", grid[r1][(c1 + 4) % 5], grid[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) { // same column
            printf("%c%c", grid[(r1 + 4) % 5][c1], grid[(r2 + 4) % 5][c2]);
        } else { // different row and column
            printf("%c%c", grid[r1][c2], grid[r2][c1]);
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char key[] = "CIPHER";
    decrypt(ciphertext, key);
    return 0;
}

