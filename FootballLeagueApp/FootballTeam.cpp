//class FootballTeam
#include "stdafx.h"
#include "FootballTeam.h"
using namespace std;

//default constructor to instantiate collection
CFootballTeam::CFootballTeam()
	: m_GamesPlayed(0)
	, m_GoalsFor(0)
	, m_GoalsAgainst(0)
	, m_Points(0)
	, m_Name("")
{
}


CFootballTeam::~CFootballTeam(void)
{
}

/* 'New Team' constructor will be passed a name of a team.
used for initialising the league by instantiating objects for each team*/
CFootballTeam::CFootballTeam(string name)
	: m_GamesPlayed(0)
	, m_GoalsFor(0)
	, m_GoalsAgainst(0)
	, m_Points(0)
	, m_Name(name)
{
}

/* database construstor will be passed data for all objects.
Used when data is retrieved from a file and used to populate the collection*/
CFootballTeam::CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points)
	: m_GamesPlayed(gamesPlayed)
	, m_GoalsFor(goalsFor)
	, m_GoalsAgainst(goalsAgainst)
	, m_Points(points)
	, m_Name(name)
{
}

//get name of team
string CFootballTeam::GetName()
{
	return m_Name;
}

//get games played from team
int CFootballTeam::GetGamesPlayed()
{
	return m_GamesPlayed;
}

//get goals scored from team
int CFootballTeam::GetGoalsFor()
{
	return m_GoalsFor;
}

//get goals scored against team
int CFootballTeam::GetGoalsAgainst()
{
	return m_GoalsAgainst;
}

//get points from the team
int CFootballTeam::GetPoints()
{
	return m_Points;
}

//to see if the team exists in the list
bool CFootballTeam::HasName(string searchName)
{
	if (m_Name == searchName)
	{
		return true;
	}
	else
	return false;
}

//display league table
void CFootballTeam::Display(void)
{
	cout << "\t|" << setw(22) << left << m_Name  
		<< setw(13) << left << m_GamesPlayed
		<< setw(13) << left << m_GoalsFor
		<< setw(13) << left << m_GoalsAgainst
		<< setw(5) << left << m_Points <<"|"<< endl;
	cout << "\t--------------------------------------------------------------------\n";
}

//update the league table after each result of a match is entered
void CFootballTeam::UpdateOnResult(int goalsFor, int goalsAgainst)
{
	m_GamesPlayed += 1;
	m_GoalsFor = m_GoalsFor + goalsFor;
	m_GoalsAgainst = m_GoalsAgainst + goalsAgainst;
	if (goalsFor < goalsAgainst)
	{
		m_Points = m_Points + 0;
	}
	else if (goalsFor > goalsAgainst)
	{
		m_Points = m_Points + 3;
	}
	else
		m_Points = m_Points + 1;
}


//deduct points from team
void CFootballTeam::DeductPoints(int num)
{
	m_Points = m_Points - num;
}

//compare two teams as their postitions may need to be swapped
bool CFootballTeam::IsLessThan(CFootballTeam& team)
{
	if (team.m_Points<m_Points)
	{
		return false;
	}
	else if (team.m_Points == m_Points)
	{
		int goalDifference = m_GoalsFor - m_GoalsAgainst;
		int goalDifference2 = team.m_GoalsFor - team.m_GoalsAgainst;
		if(goalDifference2<goalDifference)
		{
			return false;
		}
		return false;
	}
	else if (team.m_GamesPlayed < m_GamesPlayed)
	{
		return false;
	}
	else
		return true;
}
