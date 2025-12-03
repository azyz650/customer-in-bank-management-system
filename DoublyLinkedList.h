#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Loan.h"
using namespace std;
struct Node {
	Loan data;
	Node* next;
	Node* prev;
};
struct List {
	Node* head;
	Node* tail;
	int size;
};
#endif // DOUBLYLLINKEDLIST_H



