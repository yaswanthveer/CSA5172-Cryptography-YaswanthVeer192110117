#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16

// Function to perform CBC MAC calculation
void cbcMac(const unsigned char *key, const unsigned char *message, int messageLength, unsigned char *mac) {
    unsigned char previousBlock[BLOCK_SIZE] = { 0 };

    for (int i = 0; i < messageLength; i += BLOCK_SIZE) {
        // XOR current message block with previous block or previous MAC value
        for (int j = 0; j < BLOCK_SIZE; j++) {
            previousBlock[j] ^= message[i + j];
        }

        // Encrypt the XORed block using the key (assume a suitable encryption function)
        // Replace this line with your encryption function or library call
        // encryptBlock(previousBlock, key);

        // Update the previous block with the encrypted value
        memcpy(previousBlock, mac, BLOCK_SIZE);
    }

    // Copy the final MAC value to the output
    memcpy(mac, previousBlock, BLOCK_SIZE);
}

int main() {
    unsigned char key[BLOCK_SIZE] = {
        0x01, 0x23, 0x45, 0x67,
        0x89, 0xAB, 0xCD, 0xEF,
        0xFE, 0xDC, 0xBA, 0x98,
        0x76, 0x54, 0x32, 0x10
    };

    unsigned char message[BLOCK_SIZE] = {
        0x12, 0x34, 0x56, 0x78,
        0x9A, 0xBC, 0xDE, 0xF0,
        0x01, 0x23, 0x45, 0x67,
        0x89, 0xAB, 0xCD, 0xEF
    };

    unsigned char mac[BLOCK_SIZE];

    // Calculate the MAC for the one-block message
    cbcMac(key, message, BLOCK_SIZE, mac);

    printf("MAC for one-block message: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", mac[i]);
    }
    printf("\n");

    // Calculate the MAC for the two-block message X || (X ? T)
    unsigned char twoBlockMessage[2 * BLOCK_SIZE];
    memcpy(twoBlockMessage, message, BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        twoBlockMessage[BLOCK_SIZE + i] = message[i] ^ mac[i];
    }

    cbcMac(key, twoBlockMessage, 2 * BLOCK_SIZE, mac);

    printf("MAC for two-block message X || (X ? T): ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", mac[i]);
    }
    printf("\n");

    return 0;
}
