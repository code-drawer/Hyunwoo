#include "������.h"
#include <algorithm>
#include <fstream> //���������� �ٷ�� ���̺귯��
#include <string>
using namespace std;

Book book1{ "�����","�������丮","��ȭ",1000 };
Book book2{ "���Ƕ� �����ΰ�","����Ŭ ����","�ι���",2000 };
Book book3{ "���ڱ� �̾߱�","�ÿ��� ������","�ι���",2001 };
Book book4{ "�Ϲݹ�����","���̺�� Ȧ������","����/����",3000 };
Book book5{ "�ŵ�����","���� ���","��ȭ",1001 };
Book book6{ "�ڽ���","Į ���̰�","����/����",3001 };
Book book7{ "��Ÿ����","����","����/����",3002 };
Book book8{ "���� ���","���� �ι�Ʈ ����","����/����",3003 };
Book book9{ "�����̾�","ȣ�޷ν�","�Ҽ�",4000 };

int main() {
	locale::global(locale{ "Korean" });
	// wide file stream: 2����Ʈ �̻��� ���ڵ� ���� �� �ִ� file stream
	fstream file;
	file.open("./user.txt", ios::in);
	//������: ��Ʈ���� �������� ��� 
	//�����: ���� ���丮�� �������� �ϴ� ��� 
	//�θ��δ� ..�� ǥ���ϸ� ���� ���丮�� .���� ǥ��
	//ios::in�� �б���, ios::out�� ������

	//ID, PW, �̸�, �ڵ�����ȣ, �����ѹ��� ���ٿ� �� �ְ� �Ѵ�.
	//������ ���� ����� �����Ѵ�.
	//����) anycatim 12345678 ������ 01038161033 100
	//��ũ����¡, ��ũ�������̼�: ���ڿ� �ڸ���
	//string �ڸ���
	string line;
	vector<string> temp{ };
	int previous{ }, current{ };
	while (getline(file, line)) {
		current = line.find(' ');
		while (current != string::npos) {
			temp.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(" ", previous);
		}
		temp.push_back(line.substr(previous, current - previous));
	}

	file.close();

	������ �߾ӵ�����{}; // �߾ӵ����� ��ü ����

	�߾ӵ�����.adduser(User{ temp[0],temp[1],temp[2],temp[3],stoi(temp[4]) });


	temp.clear();

	current = 0;
	previous = 0;
	file.open("./book.txt", ios::in);
	while (getline(file, line)) {
		current = line.find(' ');
		while (current != string::npos) {
			temp.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(" ", previous);
		}
		temp.push_back(line.substr(previous, current - previous));
	}

	�߾ӵ�����.addbook(Book{ temp[0],temp[1],temp[2],stoi(temp[3]) });
	file.close();

	while (true) {
		cout << "�߾ӵ����� ���� �ý���" << endl << endl;
		cout << "1. ������� Ȯ��" << endl << "2. ��������" << endl << "3. �����ݳ�" << endl <<
			"4. �����߰�" << endl << "5. ��������" << endl << "6. ������� Ȯ��" << endl <<
			"7. �����߰�" << endl << "8. ��������" << endl << "9. ���α׷� ����" << endl << endl;

		string id;
		string pw;
		string bookname;
		string username;
		string phonenum;
		int usernum;
		string author;
		string genre;
		int booknum;

		int choice(0);
		cin >> choice;
		switch (choice) {
		case 1: // ������� Ȯ��
			�߾ӵ�����.displayBook();
			cout << endl;
			break;
		case 2: {// ��������
			cout << "�����̸��� å�̸��� ������� �Է����ּ���" << endl;
			cin >> username >> bookname;
			�߾ӵ�����.borrow(username, bookname);
			cout << endl;

			file.open("./user.txt", ios::out | ios::app);
			auto �߾ӵ�����_����_�ݺ���{ find_if(�߾ӵ�����.getUserList().begin(), �߾ӵ�����.getUserList().end(), [=](User temp) {
				return temp.get_username() == username;
				}) };
			file << ' ' << �߾ӵ�����_����_�ݺ���->get_borrowstat() << ' ' << �߾ӵ�����_����_�ݺ���->get_booknum();
			file.close();
			break;
		}
		case 3: // �����ݳ�
			cout << "�����̸��� å�̸��� ������� �Է����ּ���" << endl;
			cin >> username >> bookname;
			�߾ӵ�����.returnbook(username, bookname);
			cout << endl;
			break;
		case 4: { //�����߰�
			cout << "å�̸��� ����, �帣,å��ȣ�� ������� �Է����ּ���" << endl;
			cin >> bookname >> author >> genre >> booknum;
			Book tmp{ bookname, author, genre, booknum };
			�߾ӵ�����.addbook(tmp);
			cout << endl;
			break; }
		case 5: { //��������
			cout << "������ å�̸��� �Է��ϼ���" << endl;
			cin >> bookname;
			�߾ӵ�����.removebook(bookname);
			cout << endl;
			break; }
		case 6: //������� Ȯ��
			�߾ӵ�����.displayuser();
			cout << endl;
			break;
		case 7: { //�����߰� 
			cout << "�����̸��� �ڵ�����ȣ, ������ȣ�� ������� �Է����ּ���" << endl;
			cin >> id >> pw >> username >> phonenum >> usernum;
			User tmp{ id, pw, username, phonenum, usernum };
			�߾ӵ�����.adduser(tmp);
			cout << endl;
			break; }
		case 8: { //��������
			cout << "������ �����̸��� �Է��ϼ���" << endl;
			cin >> username;
			�߾ӵ�����.removeuser(username);
			cout << endl;
			break; }
		default: return 0;
		}

		system("pause");
		system("cls");
	}
	return 0;
}