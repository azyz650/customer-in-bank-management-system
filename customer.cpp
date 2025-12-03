#include "StructCustomer.h"
#include "DoublyLinkedListMeth.h"
#include "StructTransaction.h"
#include "StackTransactionMeth.h"
#include <iostream>
using namespace std;
void createCustomerArray(Customer customers[], int size) {
	for (int i = 0; i < size; i++) {
		customers[i] = Customer();
	}
}
int Withdraw(Customer & customer, double withdrawamount) {
	if (withdrawamount > customer.balance) {
		cout << "Sorry u don't have enough to withdraw";
		return 1;
	}
	else {
		customer.balance = customer.balance - withdrawamount;
		cout << "with draw is seccessful";
	}
	return 0;
}

int Deposit(Customer& customer, double depositAmount) {
	customer.balance += depositAmount;
	cout << "Your deposit is successful\n";
	return 0;
}
int ViewLoans(const Customer customers[], int customerCount, int accountNumber) {
	// find customer by account number
	int idx = -1;
	for (int i = 0; i < customerCount; i++) {
		if (customers[i].accountNumber == accountNumber) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		cout << "Customer not found.\n";
		return 1;
	}

	List* loans = customers[idx].loans;
	if (!loans || loans->size == 0) {
		cout << "You have no loan for the moment." << endl;
		return 1;
	}

	Node* current = loans->head;
	while (current != nullptr) {
		cout << "Loan ID: " << current->data.loanID << endl;
		cout << "Amount: " << current->data.amount << endl;
		cout << "Type: " << current->data.loanType << endl;
		cout << "Status: " << current->data.status << endl;
		cout << "------------------------" << endl;
		current = current->next;
	}
	return 0;
}
int SubmitLoanRequest(Loan L, List* Loans) {
	if (!Loans) {
		cout << "Invalid applications list (null).\n";
		return 1;
	}

	Node* appliedloan = createNode(L);
	if (!appliedloan) {
		cout << "Space error please contact your agency\n";
		return 1;
	}

	appliedloan->next = nullptr;
	appliedloan->prev = nullptr;

	if (Loans->size == 0) {
		Loans->head = appliedloan;
		Loans->tail = appliedloan;
	}
	else {
		Loans->tail->next = appliedloan;
		appliedloan->prev = Loans->tail;
		Loans->tail = appliedloan;
	}

	Loans->size++;
	return 0;
}
int ViewTransactions(const Customer customers[], int customerCount, int accountNumber) {
	// find customer by account number
	int idx = -1;
	for (int i = 0; i < customerCount; ++i) {
		if (customers[i].accountNumber == accountNumber) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		cout << "Customer not found.\n";
		return 1;
	}

	Stack* transactions = customers[idx].transactions;
	if (!transactions || transactions->top == -1) {
		cout << "No transactions available.\n";
		return 1;
	}

	for (int i = transactions->top; i >= 0; --i) {
		const Transaction& t = transactions->element[i];
		cout << "Transaction ID: " << t.transactionID << endl;
		cout << "Account Number: " << t.accountNumber << endl;
		cout << "Type: " << t.type << endl;
		cout << "Amount: " << t.amount << endl;
		cout << "Date: " << t.date << endl;
		cout << "------------------------" << endl;
	}
	return 0;
}
int undoTransaction(Customer& customer) {
	Stack* transactions = customer.transactions;
	if (!transactions || transactions->top == -1) {
		cout << "No transactions to undo.\n";
		return 1;
	}

	// Get last transaction then decrement the top index
	 Transaction lastTransaction = transactions->element[transactions->top];
	transactions->top--;

	if (lastTransaction.type == "deposit") {
		customer.balance -= lastTransaction.amount;
	}
	else if (lastTransaction.type == "withdrawal") {
		customer.balance += lastTransaction.amount;
	}

	cout << "Last transaction undone successfully.\n";
	return 0;
}

int main() {
	Customer customers[100];
	int customerCount = 0;
	char choice1;
	cout << "enter choice";
	cin >> choice1;
	if (choice1 == '1') {
		string password;
		cout << "Give me the password: ";
		cin >> password;

		bool granted = false;
		int foundIdx = -1;
		for (int i = 0; i < customerCount; ++i) {
			if (customers[i].password == password) {
				granted = true;
				foundIdx = i;
				break;
			}
		}

		if (granted) {
			cout << "access granted\n";
			
		}
		else {
			cout << "access denied\n";
			
		}
	}
	char choice2;
	cout << "enter choice: ";
	cin >> choice2;
	switch (choice2) {
	case '1': {
		int accountNumber;
		cout << "Enter account number: ";
		cin >> accountNumber;
		ViewLoans(customers, customerCount, accountNumber);
		break;
	}
	case '2': {
		int accNumber;
		cout << "Enter account number to apply loan for: ";
		cin >> accNumber;

		// find customer by account number
		int idx = -1;
		for (int i = 0; i < customerCount; ++i) {
			if (customers[i].accountNumber == accNumber) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			cout << "Customer not found.\n";
			break;
		}

		Loan loan{};
		cout << "Enter loan ID: ";
		cin >> loan.loanID;
		cout << "Enter loan type: ";
		cin >> loan.loanType;
		cout << "Enter amount: ";
		cin >> loan.amount;
		cout << "Enter rate: ";
		cin >> loan.rate;
		cout << "Enter start date: ";
		cin >> loan.startDate;
		cout << "Enter end date: ";
		cin >> loan.endDate;
		cout << "Enter status: ";
		cin >> loan.status;
		cout << "Enter balance: ";
		cin >> loan.balance;
		cout << "Enter paid amount: ";
		cin >> loan.paid;

		if (!customers[idx].loans) {
			customers[idx].loans = new List;
			*customers[idx].loans = createList();
		}

		SubmitLoanRequest(loan, customers[idx].loans);
		break;
	}
	case '3': {
		int accountNumber;
		cout << "Enter account number: ";
		cin >> accountNumber;
		ViewTransactions(customers, customerCount, accountNumber);
		break;
	}
	case '4': {
		double depositamout;
		int accNumber;
		cout << "Enter account number: ";
		cin >> accNumber;

		// find customer by account number
		int idx = -1;
		for (int i = 0; i < customerCount; i++) {
			if (customers[i].accountNumber == accNumber) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			cout << "Customer not found. Add the customer first.\n";
			break;
		}

		cout << "Enter deposit amount: ";
		cin >> depositamout;
		Deposit(customers[idx], depositamout); 
		break;


	}
	case '5': {
		double withdrawamount;
		int accNumber;
		cout << "Enter account number: ";
		cin >> accNumber;
		// find customer by account number
		int idx = -1;
		for (int i = 0; i < customerCount; i++) {
			if (customers[i].accountNumber == accNumber) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			cout << "Customer not found. Add the customer first.\n";
			break;
		}
		cout << "Enter withdraw amount: ";
		cin >> withdrawamount;
		Withdraw(customers[idx], withdrawamount); 
		break;
	}
	case'6': {
		int accNumber;
		cout << "Enter account number: ";
		cin >> accNumber;
		// find customer by account number
		int idx = -1;
		for (int i = 0; i < customerCount; i++) {
			if (customers[i].accountNumber == accNumber) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			cout << "Customer not found. Add the customer first.\n";
			break;
		}
		undoTransaction(customers[idx]); 
		break;
	}
	default:
		cout << "invalid choice";
	}
	return 0;
}



	