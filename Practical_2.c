#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

// Transition table
int transition[MAX_STATES][MAX_SYMBOLS];

// Function to get the index of a symbol
int getSymbolIndex(char symbols[], int numSymbols, char symbol) {
    for (int i = 0; i < numSymbols; i++) {
        if (symbols[i] == symbol)
            return i;
    }
    return -1; // Symbol not found
}

int main() {
    int numSymbols, numStates, numAcceptStates;
    char symbols[MAX_SYMBOLS];
    int initialState;
    int acceptingStates[MAX_STATES];
    char inputString[100];

    // Input number of input symbols
    printf("Number of input symbols: ");
    scanf("%d", &numSymbols);

    // Input symbols
    printf("Input symbols: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf(" %c", &symbols[i]);
    }

    // Input number of states
    printf("Enter number of states: ");
    scanf("%d", &numStates);

    // Input initial state
    printf("Initial state: ");
    scanf("%d", &initialState);

    // Input number of accepting states
    printf("Number of accepting states: ");
    scanf("%d", &numAcceptStates);

    // Input accepting states
    printf("Accepting states: ");
    for (int i = 0; i < numAcceptStates; i++) {
        scanf("%d", &acceptingStates[i]);
    }

    // Initialize transition table
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            transition[i][j] = -1; // -1 indicates no transition
        }
    }

    // Input transition table
    printf("Transition table (state to symbol -> next state):\n");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            printf("State %d to %c -> ", i + 1, symbols[j]);
            scanf("%d", &transition[i][j]);
        }
    }

    // Input string to validate
    printf("Input string: ");
    scanf("%s", inputString);

    // Validate the string
    int currentState = initialState;
    bool isValid = true;

    for (int i = 0; i < strlen(inputString); i++) {
        int symbolIndex = getSymbolIndex(symbols, numSymbols, inputString[i]);

        if (symbolIndex == -1) {
            isValid = false;
            break;
        }

        currentState = transition[currentState - 1][symbolIndex];

        if (currentState == -1) {
            isValid = false;
            break;
        }
    }

    // Check if the final state is an accepting state
    if (isValid) {
        isValid = false;
        for (int i = 0; i < numAcceptStates; i++) {
            if (currentState == acceptingStates[i]) {
                isValid = true;
                break;
            }
        }
    }

    // Output result
    if (isValid) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }

    return 0;
}
