#pragma once
#include "Book.h"
#include "User.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class 도서관 {
public:
	도서관()
		: booklist{ }, userlist{ } {
	}
	도서관(Book booklist[20], User userlist[10] = nullptr) {
		
	}

	// 책 추가
	void addbook(Book 넣을책) {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_booknum() == 0) {
				booklist[i] = 넣을책;
				break;
			}
		}
	}

	// 책 삭제
	void removebook(string bookname) {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_bookname() == bookname) {
				booklist[i].remove();
			}
		}
	}

	// 들어있는 책들의 이름 출력
	void displayBook() {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_booknum() != 0) {
				cout << booklist[i].get_bookname() << endl;
			}
		}
	}

	//유저 추가
	void adduser(User 추가할유저) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_usernum() == 0) {
				userlist[i] = 추가할유저;
				break;
			}
		}
	}

	//유저 삭제
	void removeuser(string username) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_username() == username) {
				userlist[i].remove();
			}
		}
	}

	//유저목록 출력
	void displayuser() {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_usernum() != 0) {
				cout << userlist[i].get_username() << endl;
			}
		}
	}

	void borrow(string username, string bookname) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_username() == username) {
				for (int j = 0; j < 20; j++) {
					if (booklist[j].get_bookname() == bookname && userlist[i].get_borrowstat() == false) {
						userlist[i].set_booknum(booklist[j].get_booknum());
						userlist[i].set_borrowstat();
						cout << "선택한 책이 정상적으로 대출되었습니다." << endl;
						return;
					}
					else {
						cout << "입력한 책이 도서관에 없습니다." << endl;
						return;
					}
				}
			}
			else {
				cout << "유저의 이름이 같지 않습니다." << endl;
				return;
			}
		}
	}
	
	void returnbook(string username, string bookname) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_username() == username) {
				for (int j = 0; j < 20; j++) {
					if (booklist[j].get_bookname() == bookname && userlist[i].get_borrowstat() == true) {
						userlist[i].set_booknum(-1);
						userlist[i].set_borrowstat();
						cout << "선택한 책이 정상적으로 반납되었습니다." << endl;
						return;
					}
					else {
						cout << "해당 책을 대출하지 않았습니다." << endl;
						return;
					}
				}
			}
			else {
				cout << "유저의 이름이 같지 않습니다." << endl;
				return;
			}
		}
	}

private:
	Book booklist[20];

	User userlist[10];

};