#include "도서관.h"
#include <algorithm>
#include <fstream> //파일형식을 다루는 라이브러리
#include <string>
using namespace std;

Book book1{ "어린왕자","생텍쥐페리","동화",1000 };
Book book2{ "정의란 무엇인가","마이클 샌델","인문학",2000 };
Book book3{ "십자군 이야기","시오노 나나미","인문학",2001 };
Book book4{ "일반물리학","데이비드 홀리데이","과학/공학",3000 };
Book book5{ "신데렐라","샤를 페로","동화",1001 };
Book book6{ "코스모스","칼 세이건","과학/공학",3001 };
Book book7{ "메타버스","김상균","과학/공학",3002 };
Book book8{ "종의 기원","찰스 로버트 다윈","과학/공학",3003 };
Book book9{ "오디세이아","호메로스","소설",4000 };

int main() {
	locale::global(locale{ "Korean" });
	// wide file stream: 2바이트 이상의 문자도 읽을 수 있는 file stream
	fstream file;
	file.open("./user.txt", ios::in);
	//절대경로: 루트부터 내려가는 경로 
	//상대경로: 현재 디렉토리를 기준으로 하는 경로 
	//부모경로는 ..로 표기하며 현재 디렉토리는 .으로 표기
	//ios::in은 읽기모드, ios::out은 쓰기모드

	//ID, PW, 이름, 핸드폰번호, 유저넘버가 한줄에 들어가 있게 한다.
	//구분은 각각 띄어쓰기로 구분한다.
	//예제) anycatim 12345678 김현우 01038161033 100
	//토크나이징, 토크나이제이션: 문자열 자르기
	//string 자르기
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

	도서관 중앙도서관{}; // 중앙도서관 객체 생성

	중앙도서관.adduser(User{ temp[0],temp[1],temp[2],temp[3],stoi(temp[4]) });


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

	중앙도서관.addbook(Book{ temp[0],temp[1],temp[2],stoi(temp[3]) });
	file.close();

	while (true) {
		cout << "중앙도서관 관리 시스템" << endl << endl;
		cout << "1. 도서목록 확인" << endl << "2. 도서대출" << endl << "3. 도서반납" << endl <<
			"4. 도서추가" << endl << "5. 도서삭제" << endl << "6. 유저목록 확인" << endl <<
			"7. 유저추가" << endl << "8. 유저삭제" << endl << "9. 프로그램 종료" << endl << endl;

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
		case 1: // 도서목록 확인
			중앙도서관.displayBook();
			cout << endl;
			break;
		case 2: {// 도서대출
			cout << "유저이름과 책이름을 순서대로 입력해주세요" << endl;
			cin >> username >> bookname;
			중앙도서관.borrow(username, bookname);
			cout << endl;

			file.open("./user.txt", ios::out | ios::app);
			auto 중앙도서관_유저_반복자{ find_if(중앙도서관.getUserList().begin(), 중앙도서관.getUserList().end(), [=](User temp) {
				return temp.get_username() == username;
				}) };
			file << ' ' << 중앙도서관_유저_반복자->get_borrowstat() << ' ' << 중앙도서관_유저_반복자->get_booknum();
			file.close();
			break;
		}
		case 3: // 도서반납
			cout << "유저이름과 책이름을 순서대로 입력해주세요" << endl;
			cin >> username >> bookname;
			중앙도서관.returnbook(username, bookname);
			cout << endl;
			break;
		case 4: { //도서추가
			cout << "책이름과 저자, 장르,책번호를 순서대로 입력해주세요" << endl;
			cin >> bookname >> author >> genre >> booknum;
			Book tmp{ bookname, author, genre, booknum };
			중앙도서관.addbook(tmp);
			cout << endl;
			break; }
		case 5: { //도서삭제
			cout << "삭제할 책이름을 입력하세요" << endl;
			cin >> bookname;
			중앙도서관.removebook(bookname);
			cout << endl;
			break; }
		case 6: //유저목록 확인
			중앙도서관.displayuser();
			cout << endl;
			break;
		case 7: { //유저추가 
			cout << "유저이름과 핸드폰번호, 유저번호를 순서대로 입력해주세요" << endl;
			cin >> id >> pw >> username >> phonenum >> usernum;
			User tmp{ id, pw, username, phonenum, usernum };
			중앙도서관.adduser(tmp);
			cout << endl;
			break; }
		case 8: { //유저삭제
			cout << "삭제할 유저이름을 입력하세요" << endl;
			cin >> username;
			중앙도서관.removeuser(username);
			cout << endl;
			break; }
		default: return 0;
		}

		system("pause");
		system("cls");
	}
	return 0;
}