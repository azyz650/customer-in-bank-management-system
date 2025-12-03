#ifndef STRUCTTRANSACTION_H
#define STRUCTTRANSACTION_H
#include <string>
using namespace std;
struct Transaction {
    string transactionID;
    string accountNumber;
    string type;                           // deposit, withdrawal // deposit, withdrawal
    double amount;
    string date;
};
#endif // STRUCTTRANSACTION_H