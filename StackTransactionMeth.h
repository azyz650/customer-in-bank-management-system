#ifndef STACKTRANSACTIONMETH_H
#define STACKTRANSACTIONMETH_H
#include "ArrayTransaction.h"
#include <stack>
using namespace std;
Stack* CreateStack();
void DestroyStack(Stack* S);
void DisplayStack(const Stack& S);
bool IsEmpty(const Stack& S);
bool IsFull(const Stack& S);
int StackSize(const Stack& S);
int Push(Stack* S, Transaction t );
int Pop(Stack* S);
int Top(const Stack& S);
Stack* CopyStack(const Stack& S);
bool CompareStacks(const Stack& S1, const Stack& S2);
#endif // STACKOP_H




