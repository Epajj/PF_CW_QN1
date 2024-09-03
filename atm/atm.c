
#include <stdio.h>
#include <string.h>

// Structure to store account information
typedef struct {
    char userId[20];
    char password[20];
    float balance;
} Account;

// Function prototypes
void createAccount(Account *account);
int login(Account *account);
void mainMenu(Account *account);
void depositMoney(Account *account);
void withdrawMoney(Account *account);
void requestBalance(Account *account);

int main() {
    Account account = {"", "", 0.0};  // Initialize account with empty fields and 0 balance
    char option;

    printf("Hi! Welcome to the ATM Machine!\n");

    while (1) {
        printf("Please select an option from the menu below:\n");
        printf("l -> Login\n");
        printf("c -> Create New Account\n");
        printf("q -> Quit\n");
        printf("> ");
        scanf(" %c", &option);

        if (option == 'l') {
            if (login(&account)) {
                printf("Access Granted!\n");
                mainMenu(&account);
            } else {
                printf("*** LOGIN FAILED! ***\n");
            }
        } else if (option == 'c') {
            createAccount(&account);
        } else if (option == 'q') {
            printf("Thank you for using the ATM Machine! Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount(Account *account) {
    printf("Please enter your user name: ");
    scanf("%s", account->userId);
    printf("Please enter your password: ");
    scanf("%s", account->password);
    account->balance = 0.0;  // Initialize balance to 0
    printf("Thank You! Your account has been created!\n");
}

// Function to login
int login(Account *account) {
    char userId[20];
    char password[20];

    printf("Please enter your user id: ");
    scanf("%s", userId);
    printf("Please enter your password: ");
    scanf("%s", password);

    if (strcmp(account->userId, userId) == 0 && strcmp(account->password, password) == 0) {
        return 1;  // Login successful
    } else {
        return 0;  // Login failed
    }
}

// Main menu after successful login
void mainMenu(Account *account) {
    char option;

    while (1) {
        printf("d -> Deposit Money\n");
        printf("w -> Withdraw Money\n");
        printf("r -> Request Balance\n");
        printf("q -> Quit\n");
        printf("> ");
        scanf(" %c", &option);

        if (option == 'd') {
            depositMoney(account);
        } else if (option == 'w') {
            withdrawMoney(account);
        } else if (option == 'r') {
            requestBalance(account);
        } else if (option == 'q') {
            printf("Logging out...\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
}

// Function to deposit money
void depositMoney(Account *account) {
    float amount;
    printf("Amount of deposit: $");
    scanf("%f", &amount);
    account->balance += amount;
}

// Function to withdraw money
void withdrawMoney(Account *account) {
    float amount;
    printf("Amount of withdrawal: $");
    scanf("%f", &amount);

    if (amount > account->balance) {
        printf("Insufficient balance! Withdrawal failed.\n");
    } else {
        account->balance -= amount;
    }
}

// Function to request balance
void requestBalance(Account *account) {
    printf("Your balance is $%.2f.\n", account->balance);
}
