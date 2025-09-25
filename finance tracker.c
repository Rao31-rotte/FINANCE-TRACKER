#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000

typedef struct {
    int id;
    char date[11];
    char category[20];
    char description[50];
    float amount;
    int type; // 0=expense, 1=income
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

void addTransaction() {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Database full!\n");
        return;
    }
    
    Transaction t;
    t.id = transaction_count + 1;
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", t.date);
    
    printf("Enter category (food/transport/entertainment/etc.): ");
    scanf("%s", t.category);
    
    printf("Enter description: ");
    scanf(" %[^\n]", t.description); // Read entire line
    
    printf("Enter amount: ");
    scanf("%f", &t.amount);
    
    printf("Type (0=expense, 1=income): ");
    scanf("%d", &t.type);
    
    transactions[transaction_count++] = t;
    printf("Transaction added successfully!\n");
}

void showBalance() {
    float total_income = 0, total_expenses = 0;
    
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].type == 1) {
            total_income += transactions[i].amount;
        } else {
            total_expenses += transactions[i].amount;
        }
    }
    
    printf("\n=== FINANCIAL SUMMARY ===\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Net Balance: $%.2f\n", total_income - total_expenses);
}

int main() {
    int choice;
    
    printf("=== PERSONAL FINANCE TRACKER ===\n");
    
    while (1) {
        printf("\n1. Add Transaction\n");
        printf("2. View Balance\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addTransaction(); break;
            case 2: showBalance(); break;
            case 3: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}