#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void PRETENDTHERESSOMETHINGHERE();

class User {
	string user;
	string pass;
	User* next;
	User* prev;
public:
	static User* newUser(User* user, string login, string haslo) {
		if (user == NULL) {
			user = new User;
			user->user = login;
			user->pass = haslo;
			user->next = NULL;
			user->prev = NULL;
		}
		else {
			user->next = newUser(user->next, login, haslo);
			user->next->prev = user;
		}
		return user;
	}
	static void findUser(User* user, string login, string haslo) {
		if (user == NULL) {
			cout << "LOGIN FAILED, USER DOES NOT EXIST." << endl;
			return;
		}
		else if (user->user == login) {
			Login(user, login, haslo);
		}
		else {
			findUser(user->next, login, haslo);
		}
	}
	static void Login(User* user, string login, string haslo) {
		if (user == NULL) {
			cout << "LOGIN FAILED, USER DOES NOT EXIST." << endl;
			return;
		}
		else if (user->user == login) {
			if (user->pass == haslo) {
				cout << "LOGIN SUCCESS" << endl;
				PRETENDTHERESSOMETHINGHERE();//run system
				return;
			}
			else {
				cout << "ACCESS DENIED" << endl;
				return;
			}
		}
		else {
			findUser(user->next, login, haslo);
		}
	}
};

void SYS();
int main() {

	//cout << "Hello, World!" << endl;

	User* user = NULL;

	SYS();

	return 0;
}

void SYS() {
	int i = 0;
	User* USER = NULL;
	while (i < 1000) {
		string login, pass;
		int choice;
		cout << "OPTIONS:\nLOGIN - 1\nCREATE NEW - 2\nEXIT - 3" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			try {
				cout << endl << "USER: ";
				cin >> login;
				cout << "PASS: ";
				cin >> pass;
				cout << endl;
				User::Login(USER, login, pass);
				break;
			}
			catch (exception e) {}
		case 2:
			try {
				cout << endl << "USER: ";
				cin >> login;
				cout << "PASS: ";
				cin >> pass;
				cout << endl;
				USER = User::newUser(USER, login, pass);
				break;
			}
			catch (exception e) {

			}
		case 3:
			return;
		default:
			cout << "UNKNOWN COMMAND. PLEASE TRY AGAIN." << endl;
		}
		
		

		i++;
	}
}
void PRETENDTHERESSOMETHINGHERE() {
	system("pause");
}