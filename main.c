#include <stdio.h>
#include "myBank.h"
#include "myBank.c"
int main()
{
    char choice;
    do{
        int account = 0;
        double amount = 0;
        double rate = 0;
        printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");

       if(scanf(" %c", &choice) == 1){ 
        switch (choice){
            
        case 'O':
            amount = 0;
            printf("Please enter amount for deposit: ");
            if(scanf(" %lf", &amount) == 1){
                if(amount>0){
                    openAccount(amount);
                    break;
                }
                else{
                    printf("Invalid Amount\n");
                    break;
                }
            }
            else{
                printf("Failed to read the amount\n");
                break;
            }
            break;
            
        case 'B':
            account = 0;
            printf("Please enter account number: ");
            if(scanf("%d", &account)==1){
                if(account<=950 && account>900){
                    balance(account);
                    break;
                }
                else{
                    printf("Account number must be between 901 to 950!\n");   
                    break;
                }
            }
            else{
                printf("Failed to read the account number\n");
                break;
            }
            
        case 'D':
            account = 0;
            amount = 0;
            printf("Please enter account number: ");
            if(scanf("%d", &account)==1){
                if(account<=950 && account>900){
                    if(bank[account-901][0] == OPEN){
                        printf("Please enter the amount to deposit: ");
                    }
                    else{
                        printf("This account is closed\n");
                        break;
                    }
                }
                else{
                    printf("Invalid account number\n");
                    break;
                }
            }
            else{
                printf("Failed to read the account number\n"); 
                break;
            }
            
            if(scanf("%lf",&amount)==1){
                if (amount>0){
                    deposit(account,amount);
                    break;
                }
                else{
                   printf("Cannot deposit a negative amount\n");
                   break;
                }
            }
           else{
               printf("Failed to read the amount\n");
               break;
           }
           break;
            
        case 'W':
            account = 0;
            amount = 0;
            printf("Please enter account number: ");
            if(scanf("%d", &account)==1){
                if(account<=950 && account>900){
                    if(bank[account-901][0] == OPEN){
                        printf("Please enter the amount to withdraw: ");
                    }
                    else{
                        printf("This account is closed\n");
                        break;
                    }
                }
                else{
                    printf("Invalid account number\n");
                    break;
                }
            }
            
            else{
                printf("Failed to read the account number\n");
                break;
            }
            
            if(scanf("%lf", &amount)==1){
                if(amount>0){
                    withdrawal(account, amount);
                    break;
                }
                else{
                    deposit(account, (amount*(-1)));
                    break;
                }
            }
            else{
                printf("Illegal input\n");
                break;
            }
            
        case 'C':
            account = 0;
            printf("Please enter account number: ");
            if(scanf("%d", &account)==1){
                if(account<=950 && account>900){
                    if(bank[account-901][0] == OPEN){
                        closeAccount(account);
                        break;
                    }
                    else{
                        printf("This account is already closed\n");
                        break;
                    }
                }
                else{
                    printf("Failed to read the account number\n");
                    break;
                }
            }
            else{
                printf("Failed to read the account number\n");
                break;
            }
            
        case 'I':
            rate = 0;
            printf("Please enter interest rate: ");
            if(scanf(" %lf", &rate)==1){
                if(rate>0){
                    interest(rate);
                    break;
                }
                else{
                    printf("Invalid interest rate\n");
                    break;
                }
            }
            else{
                printf("Failed to read the interest rate\n");
            }

        case 'P':
            printAllAccounts();
            break;
            
        case 'E':
            closeAllAccounts();
            break;
            
        default:
            printf("Invalid transaction type\n");
            break;
        }
        }
    } 
    while (choice != 'E');

    return 0;
}