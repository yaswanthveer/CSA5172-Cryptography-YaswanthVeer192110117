#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
void encrypt(char message[], int key)
{
    int i, ch;
    char encrypted[MAX_LEN];
    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = (ch + key - 'A') % 26 + 'A';
        }

        encrypted[i] = ch;
    }

    encrypted[i] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

int main()
{
    char message[MAX_LEN];
    int key, i;
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LEN, stdin);
    printf("Enter the shift key (1-25): ");
    scanf("%d", &key);
    if(key < 1 || key > 25)
    {
        printf("Invalid key. The key must be between 1 and 25.\n");
        return 1;
    }
    i = strlen(message) - 1;
    if(message[i] == '\n')
    {
        message[i] = '\0';
    }
    encrypt(message, key);

    return 0;
}
