#include <stdio.h>

enum State { IDLE, COIN_INSERTED, DISPENSE, OUT_OF_STOCK };

enum State nextState(enum State current, int command, int stock) {
    switch (current) {
        case IDLE:
            if (stock <= 0) return OUT_OF_STOCK;
            if (command == 1) return COIN_INSERTED; // 1: Insert coin
            break;
        case COIN_INSERTED:
            if (command == 2) return DISPENSE;      // 2: Buy / Request dispense
            if (command == 0) return IDLE;          // 0: Cancel / Refund
            break;
        case DISPENSE:
            // Automatically transitions back to IDLE or OUT_OF_STOCK after dispensing
            return (stock - 1 <= 0) ? OUT_OF_STOCK : IDLE;
        case OUT_OF_STOCK:
            if (command == 3) return IDLE;          // 3: Restock machine
            break;
    }
    return current; // Stay in the same state if transition is invalid
}

int main() {
    enum State currentState = IDLE;
    int stock = 2;

    printf("Initial State: IDLE (Stock: %d)\n", stock);

    // Demonstration of valid and invalid transitions
    // 1. Valid: IDLE + Insert Coin (command 1) -> COIN_INSERTED
    currentState = nextState(currentState, 1, stock);
    printf("Command: Insert Coin -> State: COIN_INSERTED\n");

    // 2. Valid: COIN_INSERTED + Dispense/Buy (command 2) -> DISPENSE -> IDLE
    currentState = nextState(currentState, 2, stock);
    stock--;
    printf("Command: Dispense Item -> State: IDLE (Stock remaining: %d)\n", stock);

    // 3. Invalid: Try to dispense directly from IDLE without inserting a coin (command 2)
    currentState = nextState(currentState, 2, stock);
    printf("Command: Dispense from IDLE (Invalid) -> State: IDLE (Unchanged)\n");

    // 4. Valid: Insert coin again (command 1) -> COIN_INSERTED
    currentState = nextState(currentState, 1, stock);
    printf("Command: Insert Coin -> State: COIN_INSERTED\n");

    // 5. Valid: Dispense last item -> transitions to OUT_OF_STOCK
    currentState = nextState(currentState, 2, stock);
    stock--;
    printf("Command: Dispense Last Item -> State: OUT_OF_STOCK (Stock: %d)\n", stock);

    return 0;
}