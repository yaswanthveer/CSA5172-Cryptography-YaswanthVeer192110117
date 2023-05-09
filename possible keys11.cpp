#include <stdio.h>
#include <math.h>

int main() {
    long double keys = 1;
    int i;
    for (i = 0; i < 25; i++) {
        keys *= (26 - i);
    }
    printf("The Playfair cipher has approximately %.0Lf possible keys.\n", keys);
    printf("That is approximately 2 to the power of %.0f.\n", log2(keys));
    return 0;
}

