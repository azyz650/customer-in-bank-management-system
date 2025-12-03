#ifndef DOUBLYLINKEDLISTMETH_H
#define DOUBLYLINKEDLISTMETH_H
#include "DoublyLinkedList.h"
Node* createNode(Loan l);
void destroyNode(Node* node);
List createList();
void destroyList(List* L);
bool isEmpty(const List& L);
bool isFull(const List& L);
int listSize(const List& L);
int insert(List* L, Loan e, int pos);
int removeAt(List* L, int pos);
Loan getElement(const List& L, int pos);
void displayList(const List& L);
List CopyList(const List& L);
#endif

