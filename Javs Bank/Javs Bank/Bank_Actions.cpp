/*
*	Developer: Javier Cardoso.
*	File Name: Bank_Actions.cpp
*
*	Description:
*		A specific file to store all the actions used by the user in
*		the account interface;
*/

// libraries
#include <iostream>
#include <fstream>
#include <string>

// headers
#include "Javs_Bank.h"

using namespace std;

// prototypes

void deposit();
void withdraw();
void check_Balance();
void exit();
double readBalance();
void writeBalance(double newBalance);

/*
* Function name: deposit
*
* Function Description:
*	Let the user deposit an amount greater than 0.
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: None
*/
void deposit() {

	cout << "\n\n------------------------------------------------\n\n\n";

	// asks the user to enter an amount to deposit
	double amount;
	cout << "Enter amount: ";
	cin >> amount;
	cout << endl;
	
	// if statement to make the user enter an amount greater than 0.
	if (amount <= 0) {


		while (amount <= 0) {

			cout << "\n\nDeposit amount must be greater than 0." << endl << endl;

			cout << "Enter amount: ";
			cin >> amount;
		}

	}

	// calculates the new balance
	double old_Balance = readBalance();
	double new_Balance = old_Balance + amount;

	// displayes the balance before deposit
	cout << "Previous Balance: " << old_Balance << endl;

	// writes in the balance file
	writeBalance(new_Balance);

	// displays the balance after deposit
	cout << "New Balance: " << readBalance() << endl;



	cout << "\n\n------------------------------------------------\n\n";
}

/*
* Function name: withdraw
*
* Function Description:
*	Let the user writhdraw an amount greater than 0.
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: None
*/
void withdraw() {

	cout << "\n\n------------------------------------------------\n\n\n";

	// if statement to make sure the user has more than 0 funds.
	int currentBalance = readBalance();

	if (currentBalance < 1) {

		cout << "Current Balance: " << readBalance() << endl << endl;
		cout << "\You don't have enough funds to withdraw." << endl;

		cout << "\n\n------------------------------------------------\n\n";

		return;
	}

	// if more than 0 in balance, asks for the amount to withdraw.
	else {

		// asks the user to enter the amount to withdraw

	// displays current balance
		cout << "Current Balance: " << readBalance() << endl << endl;

		// asks for amout
		double amount;
		cout << "Enter amount: ";
		cin >> amount;
		cout << endl;

		// if statement to make sure the user enters an amount bigger than 0.
		if (amount <= 0) {

			while (amount <= 0) {

				cout << "\n\nDeposit amount must be greater than 0." << endl << endl;

				cout << "Enter amount: ";
				cin >> amount;
				cout << endl;
			}
		}

		else if (amount > readBalance()) {

			while (amount > readBalance()) {

				cout << "\n\nInsuficient founds. Enter a valid amount." << endl << endl;

				cout << "Enter amount: ";
				cin >> amount;
				cout << endl;
			}


		}

		// gets the current balance
		double old_Balance = readBalance();

		// displays the old balance
		cout << "Previous Balance: " << old_Balance << endl;

		// calculates the new balance after amount
		double new_Balance = old_Balance - amount;

		// writes the new balance after withdrawing 
		writeBalance(new_Balance);

		// displays the new balance
		cout << "New Balance: " << readBalance() << endl;

	}

	cout << "\n\n------------------------------------------------\n\n";
}

/*
* Function name: check_Balance
*
* Function Description:
*	Let the user check the totol balance in the account.
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: None
*/
void check_Balance() {

	cout << "\n\n------------------------------------------------\n\n\n";
	// stores the actual balance in the variable balance to display it.
	double balance = readBalance();

	// display the balance.
	cout << "Balance: " << balance;

	cout << "\n\n------------------------------------------------\n\n";
}

/*
* Function name: exit
*
* Function Description:
*	Prints good bye, username when the user selects exit.
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: None
*/
void exit() {

	cout << "\nGood bye, " + return_Username() << endl;
}

/*
* Function name: readBalance
*
* Function Description:
*	reads the file with the balance and returns it.
*
*	Information:
*		Type: double
*		Parameters: None
*		Return: double
*/
double readBalance() {

	// opens, reads, and close the balance file
	ifstream readBalance;
	double balance = 0;

	readBalance.open("C:\\Users\\Cardo\\Desktop\\Personal Projects\\Using C++\\Javs_Bank\\Javs Bank\\Javs Bank\\Credentials\\" + return_Username() + "_Balance.txt");

	if (readBalance) {

		readBalance >> balance;

		readBalance.close();
	}

	else {

		cout << "\nRead object failed to open the file." << endl;
	}

	return balance;

}

/*
* Function name: writeBalance
*
* Function Description:
*	writes the file with the new balance and saves it.
*
*	Information:
*		Type: void
*		Parameters: 
*		Return: none
*/


void writeBalance(double newBalance) {

	// opens, writes, and close the balance file
	ofstream writeBalance;

	writeBalance.open("C:\\Users\\Cardo\\Desktop\\Personal Projects\\Using C++\\Javs_Bank\\Javs Bank\\Javs Bank\\Credentials\\" + return_Username() + "_Balance.txt");

	if (writeBalance.fail()) {

		cout << "\nWrite file failed to open" << endl;
	}

	else {

		writeBalance << newBalance;

		writeBalance.close();

	}
}

