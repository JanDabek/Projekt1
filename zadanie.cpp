#include <iostream>
#include <array>
#include <vector>

using namespace std;
#define zadanie3

#ifdef zadanie1



void zamien(double in_km, double& out_mileL, double &out_mileM)
{
	out_mileL = in_km * 1.6;
	out_mileM = in_km * 1.8;
}

int main()
{
	double km;
	double mileL;
	double mileM;
	cout << "podaj kilometry: ";
	cin >> km;
	zamien(km, mileL, mileM);
	cout << "mile ladowe: " << mileL << endl;
	cout << "mile morski: " << mileM << endl;
}
#endif 

#ifdef zadanie2

vector<int> ruchytablicy(array<int, 10>& tablica)
{
	vector<int> tablicaD;
	tablicaD.reserve(tablica.size());

	for (int i = 0; i < tablica.size(); i++)
	{
		if (tablica[i] < 0)
		{
			tablicaD.push_back(tablica[i]);
		}
	}
	tablicaD.shrink_to_fit();

	return tablicaD;
}



int main()
{
	
	array<int, 10> tablica;
	cout << "podaj wartosci: " << endl;
	for (int i = 0; i < tablica.size(); i++)
	{
		cin >> tablica[i];

	}
	auto ujemne = ruchytablicy(tablica);
	
	cout << "ilosc ujemnych : " << ujemne.size() << endl;
	int pominiete = tablica.size() - ujemne.size();
	cout << "pomiete: " << pominiete;
}

#endif 

#ifdef zadanie3
	
	int* ruchytablicy(int* tablica, const int ROZMIAR, int& out_licznik) 
	{
	
		out_licznik = 0;
		for (int i = 0; i < ROZMIAR; i++)
		{
			if (tablica[i] < 0)
			{
				out_licznik++;
			}
		}

		int* tablicaD = new int[out_licznik];

		int p = 0;
		for (int i = 0; i < ROZMIAR; i++)
		{
			if (tablica[i] < 0)
			{
										
				tablicaD[p] = tablica[i];
				p++;
			}
		}
		
		return tablicaD;

	}
	int main()
	{
		const int ROZMIAR = 10;
		int tablica[ROZMIAR] = { 1,2,4,-3,-4,6,5,-5,4,5 };
		int p;
		
		int* wsk = ruchytablicy(tablica, ROZMIAR, p);
		int w;
		w = ROZMIAR - p;
		cout << "liczba ujemnych: " << p << " pominiete: " << w << endl;

		delete wsk;
	}


#endif 
