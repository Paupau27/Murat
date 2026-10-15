#include <stdio.h>
#include <time.h>

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

    time_t now;
    struct tm *dateTime;
    printf("\n================================\n");
    printf("       SELECT ACCOUNT\n");
    printf("================================\n");
    printf("1. %s\n", names[0]);
    printf("2. %s\n", names[1]);
    printf("3. %s\n", names[2]);
    printf("4. Exit\n");
    printf("--------------------------------\n");
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

    account--;
    printf("\n================================\n");
    printf("          ATM MENU\n");
    printf("================================\n");
    printf("Account: %s\n", names[account]);
    printf("1. Withdraw\n");
    printf("2. Check Balance\n");
    printf("3. Exit\n");
    printf("--------------------------------\n");
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
            printf("Current balance: PHP %.2f\n",
                   balances[account]);
            return 0;
        }

        balances[account] -= total;

        now = time(NULL);
        dateTime = localtime(&now);

        printf("\n");
        printf("----------------------------------------\n");
        printf("%30s\n", "ATM TRANSACTION");
        printf("----------------------------------------\n");

        printf("%-20s %18s\n",
               "TERMINAL #", "65425899");

        printf("%-20s %18d\n",
               "SEQUENCE #", sequence++);

        if (dateTime != NULL)
        {
            printf("%-20s %02d:%02d %02d/%02d/%04d\n",
                   "DATE",
                   dateTime->tm_hour,
                   dateTime->tm_min,
                   dateTime->tm_mday,
                   dateTime->tm_mon + 1,
                   dateTime->tm_year + 1900);
        }
        else
        {
            printf("%-20s %s\n", "DATE", "Unavailable");
        }

        printf("\n");

        printf("%-20s %18s\n",
               "CARD NUMBER", cards[account]);

        printf("\n");

        printf("%-20s %18s\n",
               "CUSTOMER NAME", names[account]);

        printf("\n");

        printf("%-24s PHP %10.2f\n",
               "REQUESTED AMOUNT", amount);

        printf("%-24s PHP %10.2f\n",
               "TERMINAL FEE", fee);

        printf("\n");

        printf("%-24s PHP %10.2f\n",
               "TOTAL AMOUNT", total);

        printf("----------------------------------------\n");

        printf("\nWithdrawal successful!\n");
        printf("Remaining balance: PHP %.2f\n",
               balances[account]);

        printf("\nThank you for using the ATM!\n");
    }
    else if (choice == 2)
    {
        printf("\n================================\n");
        printf("          ACCOUNT INFO\n");
        printf("================================\n");
        printf("Customer: %s\n", names[account]);
        printf("Card Number: %s\n", cards[account]);
        printf("Balance: PHP %.2f\n", balances[account]);
        printf("================================\n");

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
