#include <stdio.h>
#include "myBank.h"
#define SIZE 50
#define OPEN 1
#define CLOSE 0
#define MIN_ACCOUNT_NUMBER 901

double bank[50][2] = {{0}};

void openAccount(double amount){
    int accountNumber;
    for(int i=0 ; i<SIZE ;i++){
        if(bank[i][0] == CLOSE){
            bank[i][0] = OPEN;
            bank[i][1] = amount;
            accountNumber = i+MIN_ACCOUNT_NUMBER;
            printf("New account number is: %d \n",accountNumber);
            return;
        }
    }
    printf("The Bank is full, sorry\n");
    return;
}

void balance(int account_number){
    int index = account_number - MIN_ACCOUNT_NUMBER;
    double balance;
    if(bank[index][0] == OPEN){
        balance = bank[index][1];
        printf("The balance of account number %d is: %0.2lf\n",account_number, balance);
    }
    else{
        printf("This account is closed\n");
    }
    return;
}

void deposit(int account_number, double amount){
    int index = account_number - MIN_ACCOUNT_NUMBER;
    double updatedAmount;
    if(bank[index][0] == OPEN){
        bank[index][1]+=amount;
        updatedAmount = bank[index][1];
        printf("The new balance is: %0.2lf\n",updatedAmount);
    }
    else{
        printf("This account is closed\n");
    }
}

void withdrawal(int account_number, double amount){
    int index = account_number - MIN_ACCOUNT_NUMBER;
    double updatedAmount;
    if(bank[index][0] == OPEN){
        if(bank[index][1] >= amount){
            bank[index][1] -= amount;
            updatedAmount =  bank[index][1];
            printf("The new balance is: %0.2lf\n",updatedAmount);
        }
        else{
            printf("Cannot withdraw more than the balance\n");
        }
    }
    else{
        printf("This account is closed\n");
    }
    return;
}

void closeAccount(double account_number){
    int index = account_number - MIN_ACCOUNT_NUMBER;
    if(bank[index][0] == OPEN){
        bank[index][0] = CLOSE;
        bank[index][1] = 0;
        printf("Closed account number %0.0lf\n",account_number);
    }
    else{
        printf("This account is already closed\n");
    }
    return;
}

void interest(double interest_rate){
    double rate = (100+interest_rate)/100;
     for(int i=0 ; i<SIZE ;i++){
        if(bank[i][0] == OPEN){
            bank[i][1] *= rate;
        }
     }
    return;

}

void printAllAccounts(){
    for(int i=0 ; i<SIZE ;i++){
        if(bank[i][0] == OPEN){
            printf("The balance of account number %d is: %0.2lf\n",(i+901),bank[i][1]);
        }
    }
    return;
}

void closeAllAccounts(){
    for(int i=0 ; i<SIZE ; i++){
        if(bank[i][0] == OPEN){
            bank[i][0] = CLOSE;
            bank[i][1] = 0;
        }
    }
    return;
}
