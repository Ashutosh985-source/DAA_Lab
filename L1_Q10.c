# ATM Transaction System
• Create a menu-driven program to check balance, deposit money, withdraw money, and exit.
• Prevent a withdrawal when the balance is insufficient.
• Maintain and display the last five transactions.

  #include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 5

struct Transaction {
    char type[20];
    float amount;
    float balance;
};

int main() {
    float balance = 0;
    float amount;
    int choice;

    struct Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;

    while (1) {
        printf("\n========== ATM SYSTEM ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last Five Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Check Balance
            case 1:
                printf("\nCurrent Balance = %.2f\n", balance);
                break;

            // Deposit
            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount!\n");
                    break;
                }

                balance += amount;

                // Store transaction
                if (transactionCount < MAX_TRANSACTIONS) {
                    strcpy(transactions[transactionCount].type, "Deposit");
                    transactions[transactionCount].amount = amount;
                    transactions[transactionCount].balance = balance;

                    transactionCount++;
                } else {
                    // Shift transactions left
                    for (int i = 0; i < MAX_TRANSACTIONS - 1; i++) {
                        transactions[i] = transactions[i + 1];
                    }

                    strcpy(transactions[MAX_TRANSACTIONS - 1].type,
                           "Deposit");

                    transactions[MAX_TRANSACTIONS - 1].amount = amount;
                    transactions[MAX_TRANSACTIONS - 1].balance = balance;
                }

                printf("Amount deposited successfully!\n");
                printf("Current Balance = %.2f\n", balance);
                break;

            // Withdraw
            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount!\n");
                }
                else if (amount > balance) {
                    printf("Insufficient balance!\n");
                    printf("Current Balance = %.2f\n", balance);
                }
                else {
                    balance -= amount;

                    // Store transaction
                    if (transactionCount < MAX_TRANSACTIONS) {
                        strcpy(transactions[transactionCount].type,
                               "Withdrawal");

                        transactions[transactionCount].amount = amount;
                        transactions[transactionCount].balance = balance;

                        transactionCount++;
                    } else {
                        // Shift transactions left
                        for (int i = 0; i < MAX_TRANSACTIONS - 1; i++) {
                            transactions[i] = transactions[i + 1];
                        }

                        strcpy(transactions[MAX_TRANSACTIONS - 1].type,
                               "Withdrawal");

                        transactions[MAX_TRANSACTIONS - 1].amount = amount;
                        transactions[MAX_TRANSACTIONS - 1].balance = balance;
                    }

                    printf("Amount withdrawn successfully!\n");
                    printf("Current Balance = %.2f\n", balance);
                }
                break;

            // Display Transactions
            case 4:
                printf("\n===== LAST FIVE TRANSACTIONS =====\n");

                if (transactionCount == 0) {
                    printf("No transactions available.\n");
                }
                else {
                    for (int i = 0; i < transactionCount; i++) {
                        printf("\nTransaction %d\n", i + 1);
                        printf("Type    : %s\n",
                               transactions[i].type);
                        printf("Amount  : %.2f\n",
                               transactions[i].amount);
                        printf("Balance : %.2f\n",
                               transactions[i].balance);
                    }
                }
                break;

            // Exit
            case 5:
                printf("\nThank you for using the ATM!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
