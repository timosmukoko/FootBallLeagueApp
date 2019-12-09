#pragma once
using namespace std;
class CUser
{
public:
	CUser();
	~CUser();
private:
	string m_Name;
	int m_Password;
	
public:
	CUser(string name);
private:
	char m_UserType;
public:
	CUser(string name, int password, char userType);
	bool HasName(string name);
	bool HasPassword(int password);
	char GetUserType();
};

