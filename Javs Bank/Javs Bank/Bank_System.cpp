/*
*	Developer: Javier Cardoso.
*	File Name: Bank_System.cpp
*
*	Description:
*		A specific file to join together all the functions and logistic of the program
*		in one single function called run_System().
*/

// libraries
#include <iostream>

// headers
#include "Javs_Bank.h"

using namespace std;


/*
* Function name: run_System
*
* Function Description:
*	Join together all the functions and logic to run the whole program.
*
*	Information:
*		Type: int
*		Parameters: None
*		Return: login(1) or sign up(2)
*/
void run_System() {

	// variable initialized with the returning value of userAccess to 
	// login or sign up

	int selection = userSelection();

	while (selection != 0) {

		// if statements to either login or sign up
		if (selection == 1) {

			// if statement to check if access was granted
			bool checkAccess = false;
			checkAccess = logIn();

			if (checkAccess == true) {

				int userAction = account_Interface();

				// while loop to let the user make several transactions into the account.
				while (userAction != 0) {

					// switch statements to let the user pick an option
					switch (userAction) {

						case 1:
							deposit();
							userAction = account_Interface();
							break;

						case 2:
							withdraw();
							userAction = account_Interface();
							break;

						case 3:
							check_Balance();
							userAction = account_Interface();
							break;

						case 0:
							cout << "Good bye, " << "user" << endl;
							userAction = 0;
							break;
					}
				}

			}

			else {

				selection = 0;
			}

		}

		else {
			// calls the signUp function to let the user create an account.
			signUp();

			// once the user creates an account, the user needs to log in or exit
			// the program.
			cout << "1 - Login\n0 - exit" << endl;
			cout << "Selection: ";
			cin >> selection;

			// if else statement to make sure the user enters the right input
			if ((selection == 1) || (selection == 0)) {

				selection == selection;
			}

			else {

				while (selection != 1 && selection != 0) {

					cout << "\nInvalid option. Enter an option from the menu." << endl;

					cout << "1 - Login\n0 - exit" << endl;
					cout << "Selection: ";
					cin >> selection;
				}
			}
		}


		// selection = 0 to ende the program
		selection = 0;

	}

	cout << "\nGood bye!" << endl;

}