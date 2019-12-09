// FootballLeagueApp.cpp.
//An application to prompt log-in from user and decide
//the type of menu to be displayed in relation to altering
//a league table.
//Authors Lorcan O Toole, Timos Mukoko, Declan.

//header files
#include "stdafx.h"
#include "FootballTeam.h"
#include "User.h"
using namespace std;

//DATABASE FILE ACCESS FUNCTIONS
void LoadTeamsFromDatabase(void);//Lorcan
void SaveTeamsToDatabase(void);//Lorcan
void LoadUsersFromDatabase(void);//Lorcan

//FUNCTION PROTOTYPES FOR USER INTERFACE
int ShowMenuForManager(void);
int ShowMenuForAssistant(void);

//CALLBACKS
void DoInitialize(void);//Timos
void DoDisplayLeague(void);//Timos
void DoEnterMatchResult(void);//Declan
void DoDeductPoints(void);//Declan
void DoBestDefence(void);//Declan
void DoRelegationZone(void);//Lorcan
void DoAddTeamToList(void);//Timos
char CheckLogin(void);//Timos
void DoQuit(void);

//HELPER FUNCTION
void sort(void);//lorcan

//Global Collection and Data
CFootballTeam  teamList[25];
int numTeamsInList = 0;
CUser userList[3];
bool quitFlag = false;
int numUsersInList = 3;
int counter = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	//system colour- aqua
	system("color 03");
	//load data from both files
	LoadUsersFromDatabase();
	LoadTeamsFromDatabase();

	//counter for attempts at log-in
	int counter = 0;
	//DISPLAY USER INTERFACE
	//three attempts
	for (int i = 0; i < 4; i++) {
		//log-in function.
		char type = CheckLogin();
		//if type returned is 'M' execute
		if (type == 'M')
		{
			int option;
			do
			{
				//call function to display appropriate menu
				option = ShowMenuForManager();
				switch (option)
				{
				case 0:
					//function to initialize team list
					DoInitialize();
					break;
				case 1:
					//function to display league table
					DoDisplayLeague();
					break;
				case 2:
					//function to enter match results
					DoEnterMatchResult();
					break;
				case 3:
					//function to deduct points from a team
					DoDeductPoints();
					break;
				case 4:
					//function to display best defence
					DoBestDefence();
					break;
				case 5:
					//function to execute relegation zone
					DoRelegationZone();
					break;
				case 6:
					//function to add team to league table
					DoAddTeamToList();
					break;
				case 7:
					//function to exit out of the menu
					DoQuit();
					break;
				default:
					cout << "invalid option\n";
				}
				//display menu while not ewqual to false
			} while (!quitFlag);
			// save data in league table
			SaveTeamsToDatabase();
			//end program
			return 0;
		}
		//if type returned is 'A' execute
		else if (type == 'A')
		{
			int option;
			do
			{
				//display menu for assistant
				option = ShowMenuForAssistant();
				switch (option)
				{
				case 0:
					//function to display league table
					DoDisplayLeague();
					break;
				case 1:
					//function to enter match result
					DoEnterMatchResult();
					break;
				case 2:
					//function to deduct points from a team
					DoDeductPoints();
					break;
				case 3:
					//function to display best defence
					DoBestDefence();
					break;
				case 4:
					//function to display relegation zone
					DoRelegationZone();
					break;
				case 5:
					//function to quit
					DoQuit();
					break;
				default:
					cout << "invalid option\n";
				}
				//display menu while not equal to false
			} while (!quitFlag);
			// save data in league table
			SaveTeamsToDatabase();
			//end program
			return 0;
		}
		else
			//if login unsuccessful add one to counter
			counter++;
		//if counter == 1 execute
		if (counter == 1)
		{ 
			cout << " You have two attempts left to log-in successfully." << endl;
		}
		//if counter == 2 execute
		else if (counter == 2)
		{
			cout << " You have one attempt left to log-in successfully." << endl;
		}
		//if counter == 3 execute
		else if (counter == 3)
		{
			cout << " You have failed to log-in correctly three times. Please try again later." << endl;
			cout << " *** Goodbye ***  ";
			return 0;
			
		}
		//display after each failed log-in
		cout << " Would you like to try again? Enter Y if you want to attempt again or N to exit? (Y/N)\n" << endl;
		char response;
		cin >> response;
		//exit if response == 'N'
		if (response == 'N' || response == 'n')
		{
			//break put of the loop
			break;
		}
	}
	//output 
	cout << "Goodbye.";
	
	
    return 0;
}

//Load list from database
void LoadTeamsFromDatabase(void)
{
	//if file does not exist
	ifstream infile("ListInfo.dat");
	if(!infile)
	{
		//output
		cout << "database file ListInfo.dat does not exist\n";
		cout << "You should initialize the list or Quit\n";
	}
	else
	{
		//load data from the file
		string name;
		int gamesPlayed, goalsFor, goalsAgainst, points;

		infile >> numTeamsInList;

		for (int i = 0; i < numTeamsInList; i++)
		{
			//assign data to class list team for each number in array
			infile >> name >> gamesPlayed >> goalsFor >> goalsAgainst >> points;
			CFootballTeam  team(name, gamesPlayed, goalsFor, goalsAgainst, points);
			teamList[i] = team;
		}
	}
}

//saves the data to the file ListInfo.dat
void SaveTeamsToDatabase(void)
{
	//SAVE list TO DATABASE FILE
	//if no members exist return
	if (numTeamsInList == 0)
		return;
	//save to file ListInfo
	ofstream outfile("ListInfo.dat");
	outfile << numTeamsInList << endl;

	//get functions from class FootballTeam will be saved to class FootballTeam
	for (int i = 0; i < numTeamsInList; i++)
	{
		outfile << teamList[i].GetName() << "  "
			<< teamList[i].GetGamesPlayed() << "  "
			<< teamList[i].GetGoalsFor() << "  "
			<< teamList[i].GetGoalsAgainst() << "  "
			<< teamList[i].GetPoints() << endl;
	}
	//close the file after use
	outfile.close();
}

//show menu for manager
int ShowMenuForManager(void)
{
	int option;
	cout << endl;
	cout << "\t ========================================\n";
	cout << "\t|              Manager View              |\n";
	cout << "\t ========================================\n";
	cout << "\t|                                        |\n";
	cout << "\t|            LEAGUE APPLICATION          |\n";
	cout << "\t|                  MENU   	         |\n";
	cout << "\t =========================================\n";
	cout << "\t|                                        |\n";
	cout << "\t| 0.	 InitializeLeagueTable           |\n";     
	cout << "\t| 1.	 Display League Table            |\n";
	cout << "\t| 2.	 Enter a Match Result            |\n";
	cout << "\t| 3.	 Deduct Points                   |\n";
	cout << "\t| 4.	 Best Defence                    |\n";
	cout << "\t| 5.	 Relegation Zone                 |\n";
	cout << "\t| 6.	 Add Team to List                |\n";
	cout << "\t| 7.	 Quit                            |\n";
	cout << "\t ========================================\n";
	cout << endl;
	cout << "\t\tEnter option : "; 
	cin >> option;
	cout << endl << endl;
	return option;
}

//initailize league table 
void DoInitialize(void)
{
	//ofstream outfile("ListInfo.dat");
	//if data present in league table
	if (numTeamsInList > 0)
	{
		//output option to delete or continue with data
		cout << "\tA list already exists!! Enter Y if you want it deleted or N to display a menu? (Y/N)\n";
		char response;
		//take in response
		cin >> response;
		//if response == 'Y'
		if (response != 'Y' || response != 'y')
			//continue using data in the file 
			return;
	}
	//number of teams in list initialised to '0'
	numTeamsInList = 0;
	
	string name;
	int points = 0, gamesPlayed = 0, goalsFor = 0, goalsAgainst = 0;
	//pormtp user to initialise list
	cout << " To initialize the list you must enter The League details !\n";
	cout << " Enter in the team name ( or enter ' exit ' to terminate): ";
	cin >> name;

	//while user does not input 'exit' continue with initialising
	while (name != "exit")
	{
		//limit number of teams in list to 25
		if (numTeamsInList < 25)
		{
			cout << " Enter in Games Palyed: ";
			cin >> gamesPlayed;
			cout << " Enter in Goal For: ";
			cin >> goalsFor;
			cout << " Enter in Goals Against: ";
			cin >> goalsAgainst;
			cout << " Enter in points: ";
			cin >> points;
			cout << endl;
			
			CFootballTeam team(name, gamesPlayed, goalsFor, goalsAgainst, points);
			teamList[numTeamsInList] = team;
			numTeamsInList++;

			cout << " Enter in another team name (or Enter 'exit' to terminate: ";
			cin >> name;
			
		}
		
		//if number of teams is more than 25 do not allow further initialising
		else if (numTeamsInList == 25)
		{ 
			cout << " ***Sorry the limit number of the team on the list is 25 or less !***" << endl;
			cout << "---(enter 'exit' to terminate): ";
			cin >> name;
			cout << endl;
		}
		
	}
}
//function to display the league table
void DoDisplayLeague(void)
{

	cout << "\t\t\t\t     League\n";
	cout << "\t--------------------------------------------------------------------\n";
	cout << "\t" << setw(15) << left << "|   Team "
		<< setw(13) << left << "| Games Played "
		<< setw(10) << left << "| Goals For "
		<< setw(15) << left << "| Goal Against "
		<< setw(10) << left << "| Points " << "|\n";
	cout << "\t--------------------------------------------------------------------\n";
	//display each team and their points 
	for (int i = 0; i < numTeamsInList; i++)
	{
		teamList[i].Display();
	}
	cout << "\n\n";
	//pause to allow view of the table before continuing
	system("pause");
}

//function to enter the match result for two teams
void DoEnterMatchResult(void)
{
	
	string hometeam, awayteam;
	int homescore, awayscore;

	cout << " Please enter the Home Team name.";
	cin >> hometeam;
	cout << " Enter Home Score:";
	cin >> homescore;
	cout << endl;
	cout << " Please enter the Away Team name:";
	cin >> awayteam;
	cout << " Please enter the Away Team score";
	cin >> awayscore;
	cout << endl;
	//loop to see if teams exist in ListInfo
	for (int i = 0; i < numTeamsInList; i++)
	{
		//if hometeam exists
		if (teamList[i].HasName(hometeam) == true)
		{
			//update score in table
			teamList[i].UpdateOnResult(homescore, awayscore);
		}
		//if awayteam exists
		if (teamList[i].HasName(awayteam) == true)
		{
			//update result in table
			teamList[i].UpdateOnResult(awayscore, homescore);
		}
	}
	//sort function called to change the postion of the teams on the table
	sort();
}
//function to deduct points from a team
void DoDeductPoints(void)
{
	string name;
	cout << " Enter the Team name to deduct Points : ";
	cin >> name;
	cout << endl;

	//check to see if team exists in ListInfo
	for (int i = 0; i < numTeamsInList; i++)
	{
		//if it exists allow user to deduct points from the team
		if (teamList[i].HasName(name) == true)
		{
			int deductPoints;
			cout << " Enter the amount of Points you wish to deduct : ";
			cin >> deductPoints;
			cout << endl;
			teamList[i].DeductPoints(deductPoints);
		}
	}
	//call sort function to change the postion of the team on the table
	sort();
}

//function to display the team with the best defence
void DoBestDefence(void)
{
	//temporary variable
	int goalsTemp = 100;
	cout << "\t\t\t\t     Best Defense\n";
	cout << "\t------------------------------------------------------------------\n";
	cout << "\t" << setw(15) << left << "|   Team "
		<< setw(13) << left << "| Games Palyed "
		<< setw(10) << left << "| Goals For "
		<< setw(15) << left << "| Goal Against "
		<< setw(10) << left << "| Points " << "|\n";
	cout << "\t------------------------------------------------------------------\n";

	for (int i = 0; i < numTeamsInList; i++)
	{
		//function to get goals agianst the team
		teamList[i].GetGoalsAgainst();
		//if the goals against are less than the temp variable of 100
		if (teamList[i].GetGoalsAgainst() < goalsTemp)
		{
			//goals against the team are assigned to the temp variable
			goalsTemp = teamList[i].GetGoalsAgainst();
		}
	}
	for (int i = 0; i < numTeamsInList; i++)
	{
		//if the goals against the team are eqaul to the temp value display the team
		if (teamList[i].GetGoalsAgainst() == goalsTemp)
		{
			teamList[i].Display();
		}
	}
	//pause program to allow user to view the table
	system("pause");
}
//function to display final four in the league
void DoRelegationZone(void)
{
	cout << "\t\t\t\t     Relegation Zone\n";
	cout << "\t------------------------------------------------------------------\n";
	cout << "\t" << setw(15) << left << "|   Team "
		<< setw(13) << left << "| Games Palyed "
		<< setw(10) << left << "| Goals For "
		<< setw(15) << left << "| Goal Against "
		<< setw(10) << left << "| Points " << "|\n";
	cout << "\t------------------------------------------------------------------\n";
		for (int i = numTeamsInList-4; i < numTeamsInList; i++)
		{
			teamList[i].Display();
		}
}

//function to add a team to the league
void DoAddTeamToList(void)
{
	string name;
	int gamesPlayed, goalsFor, goalsAgainst, points;

	cout << " Add in the team name ( or enter ' exit ' to terminate): ";
	cin >> name;

	while (name != "exit")
	{
		//if limit has not exceeded allow the user to enter the team
		if (numTeamsInList < 25)
		{
			cout << " Enter Games Palyed: ";
			cin >> gamesPlayed;
			cout << " Enter in Goal For: ";
			cin >> goalsFor;
			cout << " Enter in Goals Against: ";
			cin >> goalsAgainst;
			cout << " Enter in points: ";
			cin >> points;
			cout << endl;

			CFootballTeam team(name, gamesPlayed, goalsFor, goalsAgainst, points);
			teamList[numTeamsInList] = team;
			numTeamsInList++;

			cout << " Add in another Team name (or enter 'exit'to terminate) : ";
			cin >> name;
			
		}
		//if it exceeds the number in the list do not allow user to add the team
		else if (numTeamsInList == 25)
		{
			cout << " ***Sorry the limit number of the team on the list is 25 !***" << endl;
			cout << " ---(enter 'exit' to terminate): ";
			cin >> name;
			cout << endl;
		}
	}
}

//function to sort the teams into their positions in the league table
void sort(void)
{

	CFootballTeam temp;
	//loop to terminate on the number in the list minus 1
	for (int pass = 0; pass < numTeamsInList - 1; pass++)
	{
		bool swapFlag = false;
		for (int pair = 0; pair < numTeamsInList - 1; pair++)
		{
			//if the team number in pair is less than the team after it in the array
			if (teamList[pair].IsLessThan(teamList[pair + 1]))
			{
				//switch the place of the two teams in the league table
				temp = teamList[pair];
				teamList[pair] = teamList[pair + 1];
				teamList[pair + 1] = temp;
				swapFlag = true;
			}
		}
		//once bool flag equals false terminate
		if (swapFlag == false)
			break;
	}
}
//function to quit the program
void DoQuit(void)
{
	quitFlag = true;
}
//function to load users form the data file UserFile
void LoadUsersFromDatabase(void)
{
	ifstream infile("UserFile.dat");
	string name;
	int password;
	char userType;
	

	for (int i = 0; i < 3; i++)
	{
		infile >> name >> password >> userType;
		CUser  user(name, password, userType);
		userList[i] = user;
	}
}
//function to display the menu for the assistants
int ShowMenuForAssistant(void)
{
	int option;
	cout << "\t ========================================\n";
	cout << "\t|             Assistant View             |\n";
	cout << "\t ========================================\n";
	cout << "\t|                                        |\n";
	cout << "\t|            LEAGUE APPLICATION          |\n";
	cout << "\t|                  MENU   	         |\n";
	cout << "\t =========================================\n";
	cout << "\t|                                        |\n";
	cout << "\t| 0.	 Display League Table            |\n";
	cout << "\t| 1.	 Enter a Match Result            |\n";
	cout << "\t| 2.	 Deduct Points                   |\n";
	cout << "\t| 3.	 Best Defence                    |\n";
	cout << "\t| 4.	 Relegation Zone                 |\n";
	cout << "\t| 5.	 Quit                            |\n";
	cout << "\t ========================================\n";
	cout << endl;
	cout << "\t\tEnter option : ";
	cin >> option;
	cout << endl << endl;
	return option;
}
//function to check the name and password of each memeber and also return their user type
char CheckLogin(void)
{
	string name;
	int password;
	cout << endl;
	cout << endl;
	cout << "\t ===================================\n";
	cout << "\t|              User Login           |\n";
	cout << "\t ===================================\n";
	cout << "\t|               Log-in              |\n";
	cout << "\t ===================================\n";
	cout << endl;
	cout << "\tName: ";
	cin >> name;
	cout << "\tEnter password: ";
	cin >> password;
	char type = 'n';
	//if both the name and password are exact return the user type
	for (int i = 0; i < numUsersInList; i++)
	{
		if (userList[i].HasName(name) == true && userList[i].HasPassword(password) == true)
		{
			type = userList[i].GetUserType();
			cout << "\t\t\tWelcome " << name << endl;
			cout << endl;
		}
	}
	return type;

}
