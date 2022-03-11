#pragma once
#include "Book.h"
#include "User.h"
#include <vector> //vector: �������� �迭

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::vector;

class ������ {
public:
	������()
		: booklist{ }, userlist{ } {
	}
	������(Book booklist[20], User userlist[10] = nullptr) {

	}

	// å �߰�
	void addbook(Book ����å) {
		booklist.resize(booklist.size() + 1); // booklist�� ũ�⸦ 1 ���������ش�.
		// ���� ��� �ݺ���
		// auto: �ʱ�ȭ �� ���� ���� �ڷ����� �ڵ����� �߷��ϴ� Ű����
		for (auto& elem : booklist) {
			if (elem.get_booknum() == 0) {
				elem = ����å;
				break;
			}
		}
	}

	// å ����
	void removebook(string bookname) {
		for (auto& elem : booklist) {
			if (elem.get_bookname() == bookname) {
				elem.remove();
			}
		}
	}

	// ����ִ� å���� �̸� ���
	void displayBook() {
		for (auto& elem : booklist) {
			if (elem.get_booknum() != 0) {
				cout << elem.get_bookname() << endl;
			}
		}
	}

	//���� �߰�
	void adduser(User �߰�������) {
		userlist.resize(userlist.size() + 1);

		for (auto& elem : userlist) {
			if (elem.get_usernum() == 0) {
				elem = �߰�������;
				break;
			}
		}
	}

	//���� ����
	void removeuser(string username) {
		for (auto& elem : userlist) {
			if (elem.get_username() == username) {
				elem.remove();
			}
		}
	}

	//������� ���
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
						cout << "������ å�� ���������� ����Ǿ����ϴ�." << endl;
						return;
					}
				}
				cout << "�Է��� å�� �������� �����ϴ�." << endl;
				return;
			}
		}
		cout << "������ �̸��� ���� �ʽ��ϴ�." << endl;
		return;
	}

	void returnbook(string username, string bookname) {
		for (auto& userElem : userlist) {
			if (userElem.get_username() == username) {
				for (auto& bookElem : booklist) {
					if (bookElem.get_bookname() == bookname && userElem.get_borrowstat() == true) {
						userElem.set_booknum(-1);
						userElem.set_borrowstat();
						cout << "������ å�� ���������� �ݳ��Ǿ����ϴ�." << endl;
						return;
					}
				}
				cout << "�ش� å�� �������� �ʾҽ��ϴ�." << endl;
				return;
			}
		}
		cout << "������ �̸��� ���� �ʽ��ϴ�." << endl;
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