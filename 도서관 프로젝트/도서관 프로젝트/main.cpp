#include "도서관.h"

Book book1{ "어린왕자","생텍쥐페리","동화",1000 };
Book book2{ "정의란 무엇인가","마이클 샌델","인문학",2000 };
Book book3{ "십자군 이야기","시오노 나나미","인문학",2001 };
Book book4{ "일반물리학","데이비드 홀리데이","과학/공학",3000 };
Book book5{ "신데렐라","샤를 페로","동화",1001 };
Book book6{ "코스모스","칼 세이건","과학/공학",3001 };
Book book7{ "메타버스","김상균","과학/공학",3002 };
Book book8{ "종의 기원","찰스 로버트 다윈","과학/공학",3003 };
Book book9{ "오디세이아","호메로스","소설",4000 };

User user1{ "김현우","01038161033",100 };
User user2{ "정연한","01030414307",101 };
User user3{ "박도현","01039041238",102 };
User user4{ "김도영","01079416794",103 };
User user5{ "안수환","01059821975",104 };

int main() {
	도서관 중앙도서관{}; // 중앙도서관 객체 생성

	중앙도서관.addbook(book1); // 중앙도서관에 book1 추가
	중앙도서관.addbook(book2); // 중앙도서관에 book2 추가
	중앙도서관.addbook(book3); // 중앙도서관에 book3 추가
	중앙도서관.addbook(book4); // 중앙도서관에 book4 추가
	중앙도서관.addbook(book5); // 중앙도서관에 book5 추가

	중앙도서관.adduser(user1);
	중앙도서관.adduser(user2);
	중앙도서관.adduser(user3);
	중앙도서관.adduser(user4);
	중앙도서관.adduser(user5);

	while (true) {
		cout << "중앙도서관 관리 시스템" << endl << endl;
		cout << "1. 도서목록 확인" << endl << "2. 도서대출" << endl << "3. 도서반납" << endl <<
			"4. 도서추가" << endl << "5. 도서삭제" << endl << "6. 유저목록 확인" << endl << 
			"7. 유저추가" << endl << "8. 유저삭제" << endl << "9. 프로그램 종료" << endl << endl;

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
		case 2: // 도서대출
			cout << "유저이름과 책이름을 순서대로 입력해주세요" << endl;
			cin >> username >> bookname;
			중앙도서관.borrow(username, bookname);
			cout << endl;
			break;
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
			cin >> username >> phonenum >> usernum;
			User tmp{ username, phonenum, usernum };
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
	}
	return 0;
}