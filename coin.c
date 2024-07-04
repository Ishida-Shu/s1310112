#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* coin_toss() {
    return rand() % 2 == 0 ? "Heads" : "Tails";
}

int main() {
    srand(time(0)); // Initialize random number generator

    char name[50];
    printf("Who are you?\n> ");
    fgets(name, sizeof(name), stdin);
    // Remove trailing newline character from name
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);

    printf("Tossing a coin...\n");
    int heads = 0;
    int tails = 0;

    for (int i = 1; i <= 3; i++) {
        const char* result = coin_toss();
        printf("Round %d: %s\n", i, result);
        if (result == "Heads") {
            heads++;
        } else {
            tails++;
        }
    }

    printf("Heads: %d, Tails: %d\n", heads, tails);
    if (heads > tails) {
        printf("%s won!\n", name);
    } else {
        printf("%s lost!\n", name);
    }

    return 0;
}



