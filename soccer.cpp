// This program will store player information (name, number, and goals scored),
// and display, and manipulate the information provided from file.
// Jazmin Even Dorra


// Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Players Structure
struct Players
{
	string name;
	int number;
	int goals;
};


// Function prototype
void getTeamData(Players &);
void displayTeamRoster(Players&);
void getTeamGoals();
void displayTeamStar();

ifstream infoPlayers;

int main()
{
	// Definitions
	int option;
	const int INFO = 1;
	const int ROSTER = 2;
	const int GOALS = 3;
	const int STAR = 4;
	const int QUIT = 5;
	
	
	string filename = "AtlantaUnited.txt";

	

	// PlayersArray definition 
	Players pArray[11];

	// Intro
	cout << "Soccer Team Goals ...\n";

	// Menu
	do
	{
		// Intro + ask for option
		cout << "\nChoose one of the following options\n"
			<< "\t1. Load team's information.\n"
			<< "\t2. Display team's roster.\n"
			<< "\t3. Display team's goals.\n"
			<< "\t4. Display team's star(s).\n"
			<< "\t5.Quit\n"
			<< "Option: ";
		cin >> option;



		if (option != QUIT)
		{
			// Drive menu options
			switch (option)
			{
				case INFO: // Read team's info

					// Ask for file name
					cout << "\nEnter File Name: ";
					cin >> filename;

					

					//read data from the file and store into variables
					
					for (int index = 0; index < 11; index++)
					{
						// Open file for reading
						infoPlayers.open("AtlantaUnited.txt");

						getTeamData(pArray[index]);
						
						// Close File
						infoPlayers.close();

					}

					
					break;

				case ROSTER: // display team roster

					
					cout << "Player Name\t Number\t\tGoals\n"
						<< "----------------------------------------\n";				

					for (Players val : pArray)
					{
						displayTeamRoster(val);
					}
					
					// Close File
					infoPlayers.close();

					break;
				case GOALS: //display team goals
					
					getTeamGoals();
					break;
				case STAR: //display team star
					displayTeamStar();
					break;
				case QUIT:
					cout << "Good Bye ...";
					break;
			}
		}
	} while (option != QUIT);
	return 0;
}

void getTeamData(Players &pa)
{

		
	// Read player info
	getline(infoPlayers, pa.name);
	infoPlayers >> pa.number;
	infoPlayers >> pa.goals;
	
	

	return;
}

void displayTeamRoster(Players &pa)
{
	
	cout << endl << pa.name << "\t  "<< pa.number << "\t\t  " << pa.goals << endl;
	

	return;
}

void getTeamGoals()
{
	int goals = 120;
	cout << "\nTotal goals scored: " << goals << endl;
}

void displayTeamStar()
{
	cout << "\nTop team player(s): " << "Josef Martinez ( 90 goals )" << endl;
}