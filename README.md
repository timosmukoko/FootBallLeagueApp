# FootBallLeagueApp

LOGIN: User: Tom
       psw: 1234


SOFTWARE TEST DOCUMENTATION (STD)

Option 0.  (DoInitialze)
-	If the file does not exist. User manager have to initialize the list or exit …
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
 

-	Enter in another team details…
 

-	If numOfTeamInList == 25 teams

else if (numTeamsInList == 25)

		
-	If the list exists. Display the existing list or delete it …
 
if (numTeamsInList > 0)
{
cout << "list already exists!! Enter Y if you want it deleted or N to display a menu? (Y/N)\n";
char response;
cin >> response;
if (response != 'Y' || response != 'y')
return;
}
numTeamsInList = 0;

Screenshot of “Listfile.dat”
 

Option 1. (DoDisplayLeague)

for (int i = 0; i < numTeamsInList; i++)
{
	teamList[i].Display();
}
	cout << "\n\n";
	system("pause");

Screenshot of “Listfile.dat”


 

Option 6. (AddTeamToList)
  
   
CheckLogin() :
-	If user login successful. Display the appropriate Menu…



for (int i = 0; i < numUsersInList; i++)
{
if (userList[i].HasName(name) == true && userList[i].HasPassword(password) == true)
{
type = userList[i].GetUserType();
cout << "\t\t\tWelcome " << name << endl;
cout << endl;}}












-	If user fails to login successfully. User has two more attempts…
 
int counter = 0;
	//DISPLAY USER INTERFACE
	//three attempts
	for (int i = 0; i < 4; i++) {
		//log-in function.
		char type = CheckLogin();

-	If the user fails 3 times. Program will close…
 
if (counter == 1)
{ 
cout << " You have two attempts left to log-in successfully." << endl;
}
else if (counter == 2)
{
cout << " You have one attempt left to log-in successfully." << endl;
}
else if (counter == 3)
{
cout << " You have failed to log-in correctly three times. Please try again later." << endl;
	return 0;
}

FLOWCHART
Option 0.  (DoInitialze)


