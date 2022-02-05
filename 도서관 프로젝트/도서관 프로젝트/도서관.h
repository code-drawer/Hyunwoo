#pragma once
#include "Book.h"
#include "User.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class ������ {
public:
	������()
		: booklist{ }, userlist{ } {
	}
	������(Book booklist[20], User userlist[10] = nullptr) {
		
	}

	// å �߰�
	void addbook(Book ����å) {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_booknum() == 0) {
				booklist[i] = ����å;
				break;
			}
		}
	}

	// å ����
	void removebook(string bookname) {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_bookname() == bookname) {
				booklist[i].remove();
			}
		}
	}

	// ����ִ� å���� �̸� ���
	void displayBook() {
		for (int i = 0; i < 20; i++) {
			if (booklist[i].get_booknum() != 0) {
				cout << booklist[i].get_bookname() << endl;
			}
		}
	}

	//���� �߰�
	void adduser(User �߰�������) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_usernum() == 0) {
				userlist[i] = �߰�������;
				break;
			}
		}
	}

	//���� ����
	void removeuser(string username) {
		for (int i = 0; i < 10; i++) {
			if (userlist[i].get_username() == username) {
				userlist[i].remove();
			}
		}
	}

	//������� ���
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
						cout << "������ å�� ���������� ����Ǿ����ϴ�." << endl;
						return;
					}
					else {
						cout << "�Է��� å�� �������� �����ϴ�." << endl;
						return;
					}
				}
			}
			else {
				cout << "������ �̸��� ���� �ʽ��ϴ�." << endl;
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
						cout << "������ å�� ���������� �ݳ��Ǿ����ϴ�." << endl;
						return;
					}
					else {
						cout << "�ش� å�� �������� �ʾҽ��ϴ�." << endl;
						return;
					}
				}
			}
			else {
				cout << "������ �̸��� ���� �ʽ��ϴ�." << endl;
				return;
			}
		}
	}

private:
	Book booklist[20];

	User userlist[10];

};