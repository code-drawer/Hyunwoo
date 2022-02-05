#include "������.h"

Book book1{ "�����","�������丮","��ȭ",1000 };
Book book2{ "���Ƕ� �����ΰ�","����Ŭ ����","�ι���",2000 };
Book book3{ "���ڱ� �̾߱�","�ÿ��� ������","�ι���",2001 };
Book book4{ "�Ϲݹ�����","���̺�� Ȧ������","����/����",3000 };
Book book5{ "�ŵ�����","���� ���","��ȭ",1001 };
Book book6{ "�ڽ���","Į ���̰�","����/����",3001 };
Book book7{ "��Ÿ����","����","����/����",3002 };
Book book8{ "���� ���","���� �ι�Ʈ ����","����/����",3003 };
Book book9{ "�����̾�","ȣ�޷ν�","�Ҽ�",4000 };

User user1{ "������","01038161033",100 };
User user2{ "������","01030414307",101 };
User user3{ "�ڵ���","01039041238",102 };
User user4{ "�赵��","01079416794",103 };
User user5{ "�ȼ�ȯ","01059821975",104 };

int main() {
	������ �߾ӵ�����{}; // �߾ӵ����� ��ü ����

	�߾ӵ�����.addbook(book1); // �߾ӵ������� book1 �߰�
	�߾ӵ�����.addbook(book2); // �߾ӵ������� book2 �߰�
	�߾ӵ�����.addbook(book3); // �߾ӵ������� book3 �߰�
	�߾ӵ�����.addbook(book4); // �߾ӵ������� book4 �߰�
	�߾ӵ�����.addbook(book5); // �߾ӵ������� book5 �߰�

	�߾ӵ�����.adduser(user1);
	�߾ӵ�����.adduser(user2);
	�߾ӵ�����.adduser(user3);
	�߾ӵ�����.adduser(user4);
	�߾ӵ�����.adduser(user5);

	while (true) {
		cout << "�߾ӵ����� ���� �ý���" << endl << endl;
		cout << "1. ������� Ȯ��" << endl << "2. ��������" << endl << "3. �����ݳ�" << endl <<
			"4. �����߰�" << endl << "5. ��������" << endl << "6. ������� Ȯ��" << endl << 
			"7. �����߰�" << endl << "8. ��������" << endl << "9. ���α׷� ����" << endl << endl;

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
		case 2: // ��������
			cout << "�����̸��� å�̸��� ������� �Է����ּ���" << endl;
			cin >> username >> bookname;
			�߾ӵ�����.borrow(username, bookname);
			cout << endl;
			break;
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
			cin >> username >> phonenum >> usernum;
			User tmp{ username, phonenum, usernum };
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
	}
	return 0;
}