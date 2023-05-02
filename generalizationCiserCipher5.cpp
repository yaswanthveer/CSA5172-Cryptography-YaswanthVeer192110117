#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b, i;
    
    printf("Enter a and b (separated by a space): ");
    scanf("%d %d", &a, &b);
    
    // Check whether a is allowed or not
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            break;
        }
    }
    if (gcd(a, 26) != 1) {
        printf("a = %d is not allowed.\n", a);
    } else {
        printf("a = %d is allowed.\n", a);
    }
    
    return 0;
}

