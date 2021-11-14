#include "main.hpp"
using namespace std;

int main() {

    // Declare all the vectors
    vector<recognisedPerson> vRecognisedPersons;
    vector<recognisedOrganisation> vRecognisedOrganisations;
    vector<shopDetails> vShopDetails;
    vector<employee> vEmployees;
    vector<mallEmployees> vMallEmployees;

    // make store functons for theses vectors
    vector<transaction> vTransactions;
    vector<payout> vPayouts;
    vector<payment> vPayments;

    // initiate mall bank account
    mallBankAccount acMall(0);

    // Welcome message
    cout << "\nWelcome to shopping mall management system!" << endl;

    cout << "\n\n\nPlease wait while loading database..." << endl;

    // Loading Database
    loadDatabase(vRecognisedPersons, vRecognisedOrganisations, vShopDetails, vEmployees, vMallEmployees);
    bool repeat = true;

    // Show options to user
    while (repeat) {
        char choice;
        cout << "\n\n\nChoose action to perform: "
             << "\n1    :   Add/Remove/Display Person"
             << "\n2    :   Add/Remove/Display Organisation"
             << "\n3    :   Add/Remove/Display Shop"
             << "\n4    :   Add/Remove/Display Employee"
             << "\n5    :   Add/Remove/Display Mall Employee"
             << "\n6    :   Edit MallAccount Details"
             << "\n7    :   Finance Related: "
             << "\ne    :   EXIT"
             << "\nENTER YOUR CHOICE: ";
        cin >> choice;
        switch (choice) {
        case '1':
            optionPerson(vRecognisedPersons);
            break;
        case '2':
            optionOrganisation(vRecognisedOrganisations);
            break;
        case '3':
            optionShop(vShopDetails);
            break;
        case '4':
            optionEmployee(vEmployees);
            break;
        case '5':
            optionMallEmployee(vMallEmployees);
            break;
        case '6':
            acMall.accessMallBankAccount();
            break;
        case '7':
            optionFinance(acMall, vMallEmployees, vTransactions, vPayouts, vPayments);
            break;
        case 'e':
            repeat = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        system("cls");
    }

    // exiting application
    cout << "\n\n\nExiting application..." << endl;
    cout << "Saving changes to database" << endl;
    cout << "Please wait ..." << endl;

    // Store to the database
    saveDatabase(vRecognisedPersons, vRecognisedOrganisations, vShopDetails, vEmployees, vMallEmployees);
    cout << "\n\nFinished\nPress any key to exit" << endl;

    // exit after user aknowledges
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
