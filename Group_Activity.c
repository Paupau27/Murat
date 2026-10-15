#include <stdio.h>
#include <string.h>
#include <time.h>

void printCentered(const char *text)
{
    int padding = (40 - (int)strlen(text)) / 2;

    printf("%*s%s\n", padding, "", text);
}

int main()
{
    char names[3][50] = {"Gywenth Alday", "Sundy Mundy", "Hermione Labaclado"};
    char cards[3][20] = {"XXXXXXXXXXXX1001", "XXXXXXXXXXXX1002", "XXXXXXXXXXXX1003"};
    float balances[3] = {5000.00, 3000.00, 7000.00};
    float amount;
    float fee = 1.25;
    float total;
    int account, choice;
    int sequence = 8564;
    char date[20];

    time_t now;
    struct tm *dateTime;

    // Account selection
    printf("\n========================================\n");
    printCentered("SELECT ACCOUNT");
    printf("========================================\n");
    printf("  1. %s\n", names[0]);
    printf("  2. %s\n", names[1]);
    printf("  3. %s\n", names[2]);
    printf("  4. Exit\n");
    printf("----------------------------------------\n");
    printf("Choose account: ");

    if (scanf("%d", &account) != 1)
    {
        printf("Invalid input! Numbers only.\n");
        return 0;
    }

    if (account == 4)
    {
        printf("\nThank you for using the ATM!\n");
        return 0;
    }

    if (account < 1 || account > 3)
    {
        printf("Invalid account number.\n");
        return 0;
    }

    // Atm menu
    account--;
    printf("\n========================================\n");
    printCentered("ATM MENU");
    printf("========================================\n");
    printf("%-14s %s\n", "Account:", names[account]);
    printf("  1. Withdraw\n");
    printf("  2. Check Balance\n");
    printf("  3. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input! Numbers only.\n");
        return 0;
    }
    if (choice == 1)
    {
        printf("\nEnter withdrawal amount: PHP ");

        if (scanf("%f", &amount) != 1)
        {
            printf("Invalid input! Numbers only.\n");
            return 0;
        }

        if (amount <= 0)
        {
            printf("Invalid withdrawal amount.\n");
            return 0;
        }

        total = amount + fee;

        if (total > balances[account])
        {
            printf("Insufficient balance.\n");
            printf("%-21s PHP %14.2f\n",
                   "CURRENT BALANCE", balances[account]);
            return 0;
        }

        balances[account] -= total;

        now = time(NULL);
        dateTime = localtime(&now);

        //Atm transaction receipt
        printf("\n");
        printf("----------------------------------------\n");
        printCentered("ATM TRANSACTION");
        printf("----------------------------------------\n");

        printf("%-21s %18s\n",
               "TERMINAL #", "65425899");

        printf("%-21s %18d\n",
               "SEQUENCE #", sequence++);

        if (dateTime != NULL)
        {
            strftime(date, sizeof(date), "%H:%M %d/%m/%Y", dateTime);
            printf("%-21s %18s\n", "DATE", date);
        }
        else
        {
            printf("%-21s %18s\n", "DATE", "Unavailable");
        }

        printf("\n");

        printf("%-21s %18s\n",
               "CARD NUMBER", cards[account]);

        printf("\n");

        printf("%-21s %18s\n",
               "CUSTOMER NAME", names[account]);

        printf("\n");

        printf("%-21s PHP %14.2f\n",
               "REQUESTED AMOUNT", amount);

        printf("%-21s PHP %14.2f\n",
               "TERMINAL FEE", fee);

        printf("\n");

        printf("%-21s PHP %14.2f\n",
               "TOTAL AMOUNT", total);

        printf("----------------------------------------\n");

        printf("\nWithdrawal successful!\n");
        printf("%-21s PHP %14.2f\n",
               "REMAINING BALANCE", balances[account]);

        printf("\nThank you for using the ATM!\n");
    }
    else if (choice == 2)
    {
        now = time(NULL);
        dateTime = localtime(&now);

        printf("\n========================================\n");
        printCentered("ACCOUNT INFO");
        printf("========================================\n");
        printf("%-21s %18s\n", "Customer:", names[account]);
        printf("%-21s %18s\n", "Card Number:", cards[account]);
        if (dateTime != NULL)
        {
            strftime(date, sizeof(date), "%H:%M %d/%m/%Y", dateTime);
            printf("%-21s %18s\n", "DATE:", date);
        }
        else
        {
            printf("%-21s %18s\n", "DATE:", "Unavailable");
        }
        printf("%-21s PHP %14.2f\n", "BALANCE", balances[account]);
        printf("========================================\n");

        printf("\nThank you for using the ATM!\n");
    }
    else if (choice == 3)
    {
        printf("\nThank you for using the ATM!\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
    return 0;
}
