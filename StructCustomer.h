#ifndef STRUCTCUSTOMER_H
#define STRUCTCUSTOMER_H
#include <string>
#include "DoublyLinkedList.h"
#include "ArrayTransaction.h"
using namespace std;
struct Customer {
	string password;
	int accountNumber;
	string accounttype;
	double balance;
	int IBAN;
	int branchcode;
	string name;
	string openDate;
	string status;
	List * loans;
	Stack * transactions;
	

	
};
#endif // STRUCTCUSTOMER_H

