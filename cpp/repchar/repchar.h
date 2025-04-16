#ifndef REPCHAR_H
#define REPCHAR_H

struct RepChar {
    int length;
    char * data;
};

RepChar* generate(char c, int n);
// void extend(RepChar* s);

#endif // REPCHAR_H