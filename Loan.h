#ifndef LOAN_H
#define LOAN_H
#include <string>
using namespace std;
struct Loan {
	int loanID;
	string loanType;
	double amount;
	double rate;
	int paid;
	string startDate;
	string endDate;
	string status;
	int balance;
};
#endif // LOAN_H
