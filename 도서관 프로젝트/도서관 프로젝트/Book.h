#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Book {
public:
	Book()
		:bookname{ }, author{ }, genre{ }, booknum{ }{
	}
	Book(string bookname, string author, string genre, int booknum)
		:bookname{ bookname }, author{ author }, genre{ genre }, booknum{ booknum }{
	}

	string get_bookname() {
		return bookname;
	}

	int get_booknum() {
		return booknum;
	}

	void remove() {
		bookname = "";
		author = "";
		genre = "";
		booknum = 0;
	}

private:
	string bookname;
	string author;
	string genre;
	int booknum;
};