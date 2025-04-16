#include "repchar.h"
#include <algorithm> // For std::fill

RepChar* generate(char c, int n) {
    if (n < 0) {
        return nullptr;
    }

    RepChar* repchar = new RepChar();
    repchar->length = n;
    repchar->data = new char[n + 1]; // Allocate space for n characters + null terminator
    std::fill(repchar->data, repchar->data + n, c);
    repchar->data[n] = '\0'; // Null-terminate the string

    return repchar;
}