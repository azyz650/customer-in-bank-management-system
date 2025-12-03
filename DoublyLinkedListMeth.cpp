#include "DoublyLinkedListMeth.h"
#include <iostream>
using namespace std;
Node* createNode( Loan value) {
	Node* node = new (nothrow) Node{ value, nullptr, nullptr };
	if (!node) cout << "\nMemory allocation failed for node\n";
	return node;
}
void destroyNode(Node* node) {
	delete node;
}
List createList() {
	return List{ nullptr, nullptr, 0 };
}
void destroyList(List* L) {
	if (!L) return;
	Node* current = L->head;
	while (current) {
		Node* temp = current;
		current = current->next;
		destroyNode(temp);
	}
	L->head = nullptr;
	L->tail = nullptr;
	L->size = 0;
}
bool isEmpty(const List& L) {
	return L.size == 0;
}
bool isFull(const List& L) {
	Node* test = new (nothrow) Node;
	if (!test) return true;
	delete test;
	return false;
}
int listSize(const List& L) {
	return L.size;
}
int insert(List* L, Loan e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	Node* n = createNode(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		if (L->head) {
			L->head->prev = n;
		}
		L->head = n;
		if (L->size == 0) {
			L->tail = n;
		}
	}
	else if (pos == L->size + 1) {
		n->prev = L->tail;
		L->tail->next = n;
		L->tail = n;
	}
	else {
		Node* prev = nullptr;
		Node* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->prev = prev;
		n->next = current;
		current->prev = n;
	}


	L->size++;
	return 1;
}
int removeAt(List* L, int pos) {
	if (!L || isEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position\n";
		return 0;
	}
	Node* current = L->head;
	if (pos == 1) {
		L->head = current->next;
		if (L->head) {
			L->head->prev = nullptr;
		}
		if (L->size == 1) {
			L->tail = nullptr;
		}
	}
	else if (pos == L->size) {
		current = L->tail;
		L->tail = current->prev;
		if (L->tail) {
			L->tail->next = nullptr;
		}
	}
	else {
		for (int i = 1; i < pos; i++) {
			current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	destroyNode(current);
	L->size--;
	return 1;
}
Loan getElement (const List& L, int pos) {
	Loan l = {};
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return l ;
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return l;
	}
	Node* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->data;
}
void displayList(const List& L) {
	if (isEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	Node* current = L.head;
	while (current) {
		cout << current->data.loanID << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}
List CopyList(const List& L) {
	List newList = createList();
	Node* current = L.head;
	Node* tail = nullptr;
	while (current) {
		Node* newNode = createNode(current->data);
		if (!newNode) {
			destroyList(&newList);
			return newList;
		}
		if (!newList.head) {
			newList.head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		current = current->next;
	}
	newList.tail = tail;
	newList.size = L.size;
	return newList;
}


