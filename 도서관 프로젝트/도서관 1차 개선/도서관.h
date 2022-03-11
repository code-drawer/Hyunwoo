#pragma once
#include "Book.h"
#include "User.h"
#include <vector> //vector: 가변길이 배열

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::vector;

class 도서관 {
public:
	도서관()
		: booklist{ }, userlist{ } {
	}
	도서관(Book booklist[20], User userlist[10] = nullptr) {

	}

	// 책 추가
	void addbook(Book 넣을책) {
		booklist.resize(booklist.size() + 1); // booklist의 크기를 1 증가시켜준다.
		// 범위 기반 반복문
		// auto: 초기화 할 값에 따라 자료형을 자동으로 추론하는 키워드
		for (auto& elem : booklist) {
			if (elem.get_booknum() == 0) {
				elem = 넣을책;
				break;
			}
		}
	}

	// 책 삭제
	void removebook(string bookname) {
		for (auto& elem : booklist) {
			if (elem.get_bookname() == bookname) {
				elem.remove();
			}
		}
	}

	// 들어있는 책들의 이름 출력
	void displayBook() {
		for (auto& elem : booklist) {
			if (elem.get_booknum() != 0) {
				cout << elem.get_bookname() << endl;
			}
		}
	}

	//유저 추가
	void adduser(User 추가할유저) {
		userlist.resize(userlist.size() + 1);

		for (auto& elem : userlist) {
			if (elem.get_usernum() == 0) {
				elem = 추가할유저;
				break;
			}
		}
	}

	//유저 삭제
	void removeuser(string username) {
		for (auto& elem : userlist) {
			if (elem.get_username() == username) {
				elem.remove();
			}
		}
	}

	//유저목록 출력
	void displayuser() {
		for (auto& elem : userlist) {
			if (elem.get_usernum() != 0) {
				cout << elem.get_username() << endl;
			}
		}
	}

	void borrow(string username, string bookname) {
		for (auto& userElem : userlist) {
			if (userElem.get_username() == username) {
				for (auto& bookElem : booklist) {
					if (bookElem.get_bookname() == bookname && userElem.get_borrowstat() == false) {
						userElem.set_booknum(bookElem.get_booknum());
						userElem.set_borrowstat();
						cout << "선택한 책이 정상적으로 대출되었습니다." << endl;
						return;
					}
				}
				cout << "입력한 책이 도서관에 없습니다." << endl;
				return;
			}
		}
		cout << "유저의 이름이 같지 않습니다." << endl;
		return;
	}

	void returnbook(string username, string bookname) {
		for (auto& userElem : userlist) {
			if (userElem.get_username() == username) {
				for (auto& bookElem : booklist) {
					if (bookElem.get_bookname() == bookname && userElem.get_borrowstat() == true) {
						userElem.set_booknum(-1);
						userElem.set_borrowstat();
						cout << "선택한 책이 정상적으로 반납되었습니다." << endl;
						return;
					}
				}
				cout << "해당 책을 대출하지 않았습니다." << endl;
				return;
			}
		}
		cout << "유저의 이름이 같지 않습니다." << endl;
		return;
	}

	vector<Book>& getBookList() {
		return booklist;
	}

	vector<User>& getUserList() {
		return userlist;
	}

private:
	vector<Book> booklist;

	vector<User> userlist;
};