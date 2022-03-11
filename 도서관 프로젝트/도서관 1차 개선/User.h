#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class User {
public:
	User() 
		:ID{ }, Password{ }, name{ }, phonenum{ }, usernum{ }, borrowstat{ },
		booknum{ } {
	}
	User(string id, string pw, string name, string phonenum, int usernum, bool borrowstat=false, int booknum=-1)
		:ID{ id }, Password{ pw }, name{ name }, phonenum{ phonenum }, usernum{ usernum }, borrowstat{ borrowstat },
		booknum{ booknum }{
	}

	string get_username() {
		return name;
	}

	bool get_borrowstat() {
		return borrowstat;
	}

	void set_borrowstat() {
		if (borrowstat == true) borrowstat = false;
		else borrowstat = true;
	}

	int get_booknum() {
		return booknum;
	}

	void set_booknum(int num) {
		booknum = num;
	}

	int get_usernum() {
		return usernum;
	}

	void remove() {
		name = "";
		phonenum = "";
		usernum = 0;
	}

private:
	string name;
	string phonenum;
	string ID;
	string Password;
	int usernum;
	bool borrowstat;
	int booknum;
};