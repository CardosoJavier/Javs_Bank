#pragma once
#include <string>
using namespace std;

/*
	Functions in Menus.cpp
*/

	// 1rs function
	int userSelection();
	int account_Interface();


/*
	Functions in Access.cpp
*/

	// 1rs function
	bool logIn();

	//2nd function
	void signUp();

	// 3rd function
	string return_Username();

/*
	Functions in Bank_System.cpp
*/

	// 1st function
	void run_System();

/*
	Functions in Bank_Actions.cpp
*/

	// 1st function
	void deposit();

	// 2nd function
	void withdraw();

	// 3rd function
	void check_Balance();

	// 4rd function
	void exit();