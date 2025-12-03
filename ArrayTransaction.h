#ifndef ARRAYTRANSACTION_H
#define ARRAYTRANSACTION_H
#include "StructTransaction.h"
using namespace std;
constexpr int Max = 100;
struct Stack {
    Transaction element[Max];   // store Transaction objects
    int top;                   // index of the last element
};
#endif // ARRAYTRANSACTION_H
