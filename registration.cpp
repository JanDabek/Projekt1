#include <iostream>

using namespace std;

class Uzytkownik {
	string login, haslo;
	/*
	bool chkPass(string pass) {
		if (pass == haslo) return true;

		return false;
	}
	*/
public:
	Uzytkownik() :login(""), haslo("") {}
	Uzytkownik(string log, string pass) : login(log), haslo(pass) {}
	/*
	bool chkLogin(string log, string pass){
		if (login == log) return chkPass(pass);
		return false;
	}
	*/
	string getUser() {
		return login;
	}
};

class ADMIN {
	Uzytkownik USER;
	int lvl = 1;
public:
	ADMIN() : USER(Uzytkownik("Admin", "root385256hash9463moore7643")) {}
	ADMIN(string name, string pass, int level) : USER(Uzytkownik(name, pass)), lvl(level) {}
};




Uzytkownik* BazaDanych = new Uzytkownik[100];
void rejestruj();
int main() {
	BazaDanych[0] = Uzytkownik("AdamNowak", "Kawasaki");
	BazaDanych[1] = Uzytkownik("adamEk", "normandy");
	BazaDanych[2] = Uzytkownik("roleypoley", "shgaifgs");
	BazaDanych[3] = Uzytkownik("aser", "njnmsfksd");
	BazaDanych[4] = Uzytkownik("v", "hsdjk");
	BazaDanych[5] = Uzytkownik("jsdgiiolh", "nhasdild");
	BazaDanych[6] = Uzytkownik("ahiugfyait", "GYUKgf");
	BazaDanych[7] = Uzytkownik("7764328", "JKjmbnKGfi");
	BazaDanych[8] = Uzytkownik("645", "DSJGHL");
	BazaDanych[9] = Uzytkownik("hjhghjggjdcv", "nmnhg");
	BazaDanych[10] = Uzytkownik("Dabr", "Kornflaik12");


	while (true) {
		cout << "1 - rejestruj \n2 - exit" << endl;
		int idx = 0;
		cin >> idx;

		switch (idx)
		{
		default:
			break;
		case 1:
			rejestruj();
			break;
		case 2:
			return 0;
		}
		cout << endl;
	}
}









bool weryfikacja(string login);
void sukces();
void blad();
void utworzUser(string user, string pass);

	void rejestruj() {
		string user, pass;
		cout << "USER: ";
		cin >> user;
		cout << "PASSWORD: ";
		cin >> pass;

		if (weryfikacja(user)) {
			sukces();
		}
		else {
			blad();
			return;
		}
		utworzUser(user, pass);

	}


	bool bladWeryfikacji();
	bool weryfikacja(string login) {
		int i = 0;
		while (BazaDanych[i].getUser() != "") {
			if (BazaDanych[i].getUser() == login) {
				return bladWeryfikacji();
			}
			i++;
		}
		return true;
	}
	bool bladWeryfikacji() {
		return false;
	}



	void sukces() {
		cout << "Rejestracja potwierdzona." << endl;
	}
	void blad() {
		cout << "rejestruj sie nie powiodla." << endl;
	}

	void dodajDoBazy(string user, string pass, int place);
	void utworzUser(string user, string pass) {
		int i = 0;
		while (BazaDanych[i].getUser() != "") {
			i++;
		}
		dodajDoBazy(user, pass, i);
	}




	void dodajDoBazy(string user, string pass, int place) {
		BazaDanych[place] = Uzytkownik(user, pass);
	}
