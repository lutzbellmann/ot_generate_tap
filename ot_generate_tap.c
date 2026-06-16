#include "verhoeff_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// For a given number generates a Verhoeff digit
static int generate_verhoeff(const char *num) {
    int c;
    int len;
    c = 0;
    len = strlen(num);

    for (int i = 0; i < len; i++)
        c = verhoeff_d[c][verhoeff_p[((i + 1) % 8)][num[len - i - 1] - '0']];

    return verhoeff_inv[c];
}

const char *generate_tap() {
    char tap[9];
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        tap[i] = '0' + rand() % 10;
    }
    tap[8] = '\0';
    int verhoeff_digit = generate_verhoeff(tap);
    char *tap_with_verhoeff = malloc(10);
    snprintf(tap_with_verhoeff, 10, "%s%d", tap, verhoeff_digit);
    return tap_with_verhoeff;
}

int main(void) {
    printf("Generating TAP or \"One Time Passcode\" for Thread 1.4 credential sharing\n");
    printf("(c) 2026, Dr. Lutz Bellmann\n");
    const char *tap = generate_tap();
    printf("Generated TAP: %s\n", tap);
    free((void *)tap); // Don't forget to free the allocated memory
    return 0;
}   