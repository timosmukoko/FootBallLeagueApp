//class user
#include "stdafx.h"
#include "User.h"
using namespace std;

//default constructor to instantiate collection
CUser::CUser()
: m_Name("")
, m_Password(0)
, m_UserType(0)
{
}


CUser::~CUser()
{
}

//'User' constructor will be passed a name of a user
CUser::CUser(string name)
: m_Name(name)
, m_Password(0)
, m_UserType(0)
{
}



/* database construstor will be passed data for all objects.
Used when data is retrieved from a file and used to populate the collection*/
CUser::CUser(string name, int password, char userType)
: m_Name(name)
, m_Password(password)
, m_UserType(userType)
{
}

//see if name entered equals name in list
bool CUser::HasName(string name)
{
	if( m_Name==name)
	{
		return true;
	}
	else
		return false;
	
}

//to see if password equals password in list
bool CUser::HasPassword(int password)
{
	if (m_Password == password)
	{
		return true;
	}
	else
		return false;
}

//return usertype
char CUser::GetUserType()
{
	return m_UserType;
}
