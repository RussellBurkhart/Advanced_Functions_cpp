/**********************************************************************************************
* Russell Burkhart
* Lisa Carter
* C++ II
*
* As the manager of the credit card department for the Tidewater Credit Card Company,
* you are responsible for overseeing the daily operations. To facilitate the requests
* demanded of your department, you have decided to create a menu driven program that
* allows for searching account numbers and creating daily reports sorted on names and balances.
*
*
* Menu selections for the program should include the following. Multiple functions should be implemented all the code.
* 1. Search for a credit card number displaying the number, name and balance of the account. A message should be displayed for invalid numbers.
* 2. Display all the accounts in alphabetical order in a neatly formatted report. All numeric values should be displayed to 2 decimal places.
* 3. Display all the accounts in descending order by current balance. Use a different sorting routine than was implemented above.
*    The output should again be in a report format with headings. Values should be aligned and numeric values should be displayed to 2 decimal places.
* 4. Display the total of the balances owed by all the customers.
* 5. Quit
*
***********************************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

void welcomeScreen();
void menu(int &c);
void cardSearch(std::string param1[], int param2[], double param3[], int size);
void alphabeticalSort(std::string param1[], int param2[], double param3[], int size);
void currentBalSort(std::string param1[], int param2[], double param3[], int size);
void addTotalOwed(double param[], int size);

int main()
{

    std::cout << std::setprecision(2) << std::fixed;
    int choice;

    std::string name[] = {"Ross, Betsy", "Duck, Donald", "Nella, Sam", "Crockett, Dave", "Que, Susie", "Deere, John", "Mossy, Mark"};
    int cardNumbers[] = {400692, 285426, 850273, 991482, 343410, 731397, 555286};
    double currentBalance[] = {5677.54, 367.11, 45698.44, 863.50, 1010.36, 42.11, 6331.00};

    welcomeScreen();

    do
    {
        menu(choice);

        switch(choice)
        {
        case 1:
            cardSearch(name, cardNumbers, currentBalance, 7);

            break;

        case 2:
            alphabeticalSort(name, cardNumbers, currentBalance, 7);

            break;

        case 3:
            currentBalSort(name, cardNumbers, currentBalance, 7);

            break;

        case 4:
            addTotalOwed(currentBalance, 7);

            break;

        case 5:

            break;
            }

    }while(choice != 5);

    return 0;
}

void welcomeScreen()
{

    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setw(120) << "*" << std::endl;
    std::cout << "\n";
    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setw(120) << "*" << std::endl;
    std::cout << "\n";
    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setw(120) << "*" << std::endl;
    std::cout << std::setfill(' ') << std::setw(73) << "Welcome to Debt Management" << "\n" << std::endl;
    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setw(120) << "*" << std::endl;
    std::cout << "\n";
    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setw(120) << "*" << std::endl;
    std::cout << "\n";
    std::cout << std::setw(120) << std::setfill('*') << "*" << std::endl;
    std::cout << std::setfill(' ') << std::setw(73) << "Press Enter to Continue..." ;
    std::cin.get();

}

void menu(int &c)
{
    system("cls");
    std::cout << "Please Make A Choice" << std::endl;
    std::cout << "(1.) Search by Credit Card Number" << std::endl;
    std::cout << "(2.) All Accounts Alphabetical" << std::endl;
    std::cout << "(3.) All Accounts Descending Balances owed" << std::endl;
    std::cout << "(4.) Total of Balances owed by Customers" << std::endl;
    std::cout << "(5.) QUIT" << std::endl;
    std::cout << "\nChoice:";
    std::cin >> c;

    while(c < 1 || c > 5)
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n";
            std::cout << std::setw(70) << std::setfill('!') << "ERROR ERROR ERROR ERROR" << std::setw(50) << "!" << std::endl;
            std::cout << std::setw(72) << std::setfill('!') << "Please Enter A Valid Option" << std::setw(48) << "!" << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("cls");
            std::cout << "1. Search by Credit Card Number" << std::endl;
            std::cout << "2. All Accounts Alphabetical" << std::endl;
            std::cout << "3. All Accounts Descending Balances owed" << std::endl;
            std::cout << "4. Total of Balances owed by Customers" << std::endl;
            std::cout << "5. QUIT" << std::endl;
            std::cout << "\nChoice:";
            std::cin >> c;
        }

}

void cardSearch(std::string param1[], int param2[], double param3[], int size)
{

    int cardNumber;
    bool found = false;

        system("cls");
        std::cout << "Please Enter The Card Number: ";
        std::cin >> cardNumber;
        for(int i = 0; i < size; i++)
        {

            if(cardNumber == param2[i])
            {
                system("cls");
                std::cout << std::setw(30) << "Name" << std::setw(30) << "Card Number" << std::setw(30) << "Current Balance" << std::endl;
                std::cout << "\n";
                std::cout << std::setw(30) << param1[i] << std::setw(30) << param2[i] << std::setw(22) << "$" << param3[i] << std::endl;
                std::cin.ignore();
                std::cin.get();
                found = true;
            }

        }
        if(found == false)
        {
            system("cls");
            std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
            std::cout << std::setw(70) << std::setfill('!') << "ERROR ERROR ERROR ERROR" << std::setw(50) << "!" << "\n" << std::endl;
            std::cout << std::setw(45) << std::setfill(' ') << cardNumber << " is not a recognized Card Number" << std::setw(40) << ' ' << std::endl;
            std::cin.ignore();
            std::cin.get();
        }

}

void alphabeticalSort(std::string param1[], int param2[], double param3[], int size)
{

    std::string swapHolder1;
    int swapHolder2;
    double swapHolder3;

    int minIndex;

    for(int i = 0; i < (size - 1); i++)
    {
        minIndex = i;
        swapHolder1 = param1[i];

        for(int j = (i + 1); j < size; j++)
        {
            if(param1[j] < swapHolder1)
            {
                swapHolder1 = param1[j];
                swapHolder2 = param2[j];
                swapHolder3 = param3[j];
                minIndex = j;
            }
        }
        param1[minIndex] = param1[i];
        param1[i] = swapHolder1;

        param2[minIndex] = param2[i];
        param2[i] = swapHolder2;

        param3[minIndex] = param3[i];
        param3[i] = swapHolder3;
    }

    system("cls");
    std::cout << std::setw(30) << "Name" << std::setw(30) << "Card Number" << std::setw(30) << "Current Balance" << std::endl;

    for(int i = 0; i < size; i ++)
    {
        std::cout << std::setw(30) << param1[i] << std::setw(30) << param2[i] << std::setw(22) << "$" << param3[i] << std::endl;
    }

    std::cin.ignore();
    std::cin.get();

}

void currentBalSort(std::string param1[], int param2[], double param3[], int size)
{
    double swapHolder1;
    std::string swapHolder2;
    int swapHolder3;
    int end = 7;

    for(int j = size - 1; j > 0; j--)
    {

        for(int i = 0; i < size; i ++)
        {
             if(param3[i] < param3[i + 1])
             {
                 swapHolder1 = param3[i];
                 param3[i] = param3[i + 1];
                 param3[i + 1] = swapHolder1;

                 swapHolder2 = param1[i];
                 param1[i] = param1[i + 1];
                 param1[i + 1] = swapHolder2;

                 swapHolder3 = param2[i];
                 param2[i] = param2[i + 1];
                 param2[i + 1] = swapHolder3;
             }
        }
        end--;
    }

    system("cls");
    std::cout << std::setw(30) << "Name" << std::setw(30) << "Card Number" << std::setw(30) << "Current Balance" << std::endl;

    for(int i = 0; i < size; i ++)
    {
        std::cout << std::setw(30) << param1[i] << std::setw(30) << param2[i] << std::setw(22) << "$" << param3[i] << std::endl;
    }

    std::cin.ignore();
    std::cin.get();
}

void addTotalOwed(double param[], int size)
{
    double total = 0;

    for(int i = 0; i < size; i++)
    {
        total += param[i];
    }

    system("cls");
    std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
    std::cout << std::setw(80) << "The total balance owed by all customers is $" << total;
    std::cin.ignore();
    std::cin.get();
}
