#include <stdio.h>

int main(void)
{
    printf("This is a program for calculating exchange rates\n");

    float rate, target_money = 0.0f, local_currency = 0.0f;
    int command1 = 1, command2 = 1;

    for (;;)
    {
    printf("Select exchange rate format:\n\
            1:1 Foreign Currency -> Local Currencies\n\
            2:1 Local Currency -> Foreign Currencies\n\
            3:100 Foreign Currencies -> Local Currencies\n\
            4:100 Local Currencies -> Foreign Currencies\n");
    printf("Enter command:");
    scanf("%d",&command1);

    if (command1 == 1 || command1 == 2 || command1 == 3 || command1 == 4)
    break;/* Judge whether the command is legal */

    printf("Error: Wrong command!\nPlease enter again\n");
    }
    
    switch (command1)
    {
    case 1:
        printf("Enter exchange rate: 1 (Foreign Currency) = (Local Currencies)");
        scanf("%f",&rate);
        break;
    case 2:
        printf("Enter exchange rate: 1 (Local Currency) = (Foreign Currencies)");
        scanf("%f",&rate);
        rate = 1.0f/(rate);
        break;
    case 3:
        printf("Enter exchange rate: 100 (Foreign Currencies) = (Local Currencies)");
        scanf("%f",&rate);
        rate = rate/100.0f;
        break;
    case 4:
        printf("Enter exchange rate: 100 (Local Currencies) = (Foreign Currencies)");
        scanf("%f",&rate);
        rate = 100.0f/(rate);
        break;
    }

    printf("Command Prompt: \n\
            1:Foreign Currency to Local Currency\n\
            2:Local Currency to Foreign Currency\n\
            3:Display exchange rate information\n\
            4:Modify current exchange rate(1 Foreign Currency -> Local Currencies)\n\
            5:Modify current exchange rate(1 Local Currency -> Foreign Currencies)\n\
            6:Modify current exchange rate(100 Foreign Currencies -> Local Currencies)\n\
            7:Modify current exchange rate(100 Local Currencies -> Foreign Currencies)\n\
            9:Display descriptive information\n\
            0:Exit\n\n");

    for (;;)
    {
        for (;;)
        {
        printf("Enter command:");
        scanf("%d",&command2);
        if (command2 >= 0 && command2 < 10)
        break;
        printf("Error: Wrong command!\nPlease enter again\n\n");
        }/* Judge whether the command is legal */
    
        switch (command2)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter number of Foreign Currencies:");
            scanf("%f",&target_money);
            local_currency = target_money*rate;
            printf("1 Foreign Currency = %.5f Local Currencies\n1 Local Currency = %.5f Foreign Currencies\n\n%.2f Foreign Currencies = %.2f Local Currencies\n\n" ,rate,1.0f/rate,target_money,local_currency);
            break;
        case 2:
            printf("Enter number of RMB:");
            scanf("%f",&local_currency);
            target_money = local_currency/rate;
            printf("1 Foreign Currency = %.5f Local Currencies\n1 Local Currency = %.5f Foreign Currencies\n\n%.2f Local Currencies = %.2f Foreign Currencies\n\n" ,rate,1.0f/rate,local_currency,target_money);
            break;
        case 3:
            printf("     1 Foreign Currency = %.5f Local Currencies\n",rate);
            printf("                  1 Local Currency = %.5f Foreign Currencies\n",1.0f/rate);
            printf(" 100 Foreign Currencies = %.5f Local Currencies\n",100.0f*rate);
            printf("                100 Local Currency = %.5f Foreign Currencies\n\n",100.0f/rate);
            break;
        case 4:
            printf("Enter new rate(1 Foreign Currency -> Local Currencies):");
            scanf("%f",&rate);
            break;
        case 5:
            printf("Enter new rate(1 Local Currency -> Foreign Currencies):");
            scanf("%f",&rate);
            rate = 1.0f/rate;
            break;
        case 6:
            printf("Enter new rate(100 Foreign Currencies -> Local Currencies):");
            scanf("%f",&rate);
            rate = rate/100.0f;
            break;
        case 7:
            printf("Enter new rate(100 Local Currencies -> Foreign Currencies):");
            scanf("%f",&rate);
            rate = 100.0f/(rate);
            break;
        case 9:
            printf("Command Prompt: \n\
            1:Foreign Currency to Local Currency\n\
            2:Local Currency to Foreign Currency\n\
            3:Display exchange rate information\n\
            4:Modify current exchange rate(1 Foreign Currency -> Local Currencies)\n\
            5:Modify current exchange rate(1 Local Currency -> Foreign Currencies)\n\
            6:Modify current exchange rate(100 Foreign Currencies -> Local Currencies)\n\
            7:Modify current exchange rate(100 Local Currencies -> Foreign Currencies)\n\
            9:Display descriptive information\n\
            0:Exit\n\n");
            break;
        }
    }
}