#pragma once
#ifndef MALLBANKACCOUNT_H
#define MALLBANKACCOUNT_H
#include "./customDataTypes.hpp"
class mallBankAccount {
    mallBankAccount(float balance);

    protected:
    public:
    struct bankAccount mallAccount;
    float balance;
    mallBankAccount(float Balance);
    void withdraw();
    void deposit();
    float getBalance();
};
#endif