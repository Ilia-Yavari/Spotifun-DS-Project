#include "../include/DataStructures.h"

void HistoryStack::push(Music* m) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = m;
    }
}

Music* HistoryStack::pop() {
    if (top >= 0) return stack[top--];
    return nullptr;
}

Music* HistoryStack::peek() const {
    if (top >= 0) return stack[top];
    return nullptr;
}

void HistoryStack::removeMusic(int musicId) {
    Music* temp[MAX_STACK_SIZE];
    int tempTop = -1;

    while(top >= 0) {
        Music* m = stack[top--];
        if(m->id != musicId) {
            temp[++tempTop] = m;
        }
    }

    while(tempTop >= 0) {
        stack[++top] = temp[tempTop--];
    }
}