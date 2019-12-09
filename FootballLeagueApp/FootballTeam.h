#pragma once
using namespace std;
class CFootballTeam
{
public:
	CFootballTeam();
	~CFootballTeam();
private:
	string m_Name;
	int m_GamesPlayed;
	int m_GoalsFor;
	int m_GoalsAgainst;
	int m_Points;
public:
	CFootballTeam(string name);
	CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points);
	string GetName();
	int GetGamesPlayed();
	int GetGoalsFor();
	int GetGoalsAgainst();
	int GetPoints();
	bool HasName(string searchName);
	void Display();
	void UpdateOnResult(int goalsFor, int goalsAgainst);
	void DeductPoints(int num);
	bool IsLessThan(CFootballTeam& team);
};

