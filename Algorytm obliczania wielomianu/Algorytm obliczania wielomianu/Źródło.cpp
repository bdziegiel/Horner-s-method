#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
#include<Windows.h>

using namespace std;

int* readfromfile() {
	int stopien;

	fstream czytaj;
	czytaj.open("Text.txt");

	czytaj >> stopien;

	int* wspolczynniki = new int[stopien + 1];
	wspolczynniki[0] = stopien;

	for (int i = 1; i <= (stopien + 1); i++) {
		czytaj >> wspolczynniki[i];
	}
	czytaj.close();
	return wspolczynniki;
}

int mnozeniaHorner = 0;
int dodawaniaHorner = 0;

int horner(int wspolczynniki[], int stopien, int x) {
	if (stopien == 0)
		return wspolczynniki[1];

	mnozeniaHorner++;
	dodawaniaHorner++;

	return x * horner(wspolczynniki, stopien - 1, x) + wspolczynniki[stopien + 1];
}

int dodawania = -1;
int mnozenia = 0;

int zDefinicji(int*wspolczynniki, int stopien, int x) {

	int wynik = 0;

	for (int i = 1, j = stopien; i <= (stopien + 1); i++, j--) {
		wynik = wynik + wspolczynniki[i] * pow(x, j);
		dodawania = dodawania + 1;
		mnozenia = mnozenia + 1 + (j - 1);
	}

	return wynik;
}

int zDefinicji3(int*wspolczynniki, int stopien, int x) {
	int wynik = 0;
	for (int i = 1, j = stopien; i <= (stopien + 1); i++, j--) {
		wynik = wynik + wspolczynniki[i] * pow(x, j);
	}
	return wynik;
}

int zDefinicji2(int*wspolczynniki, int stopien, int x) {
	int dodawania = -1;
	int mnozenia = 0;
	int wynik = 0;

	for (int i = 1, j; i < (stopien + 1); i++) {
		int potega = x;
		cout << "POTEGOWANIE" << endl;
		for (j = (stopien - i); j > 0; j--) {
			cout << potega << " x " << x << endl;
			potega = potega * x;
			mnozenia = mnozenia + 1;
		}
		cout << "DODAWANIE" << endl << wynik << " + " << wspolczynniki[i] << " x " << potega << endl;
		wynik = wynik + wspolczynniki[i] * potega;

		mnozenia = mnozenia + 1;
		dodawania = dodawania + 1;
	}
	cout << wynik << " + " << wspolczynniki[stopien + 1] << endl;
	wynik = wynik + wspolczynniki[stopien + 1];
	dodawania = dodawania + 1;

	cout << "Wykonano " << dodawania << " dodawan i " << mnozenia << " mnozen" << endl;
	return wynik;
}


int main() {

	int *wspolczynniki = readfromfile();
	int stopien = wspolczynniki[0];


	int x;

	cout << "Wielomian jest postaci: \n W = ";
	for (int i = 0, j = stopien; i < stopien; i++, j--) {
		cout << wspolczynniki[i + 1] << " * " << "x^" << j << " + ";
	} cout << wspolczynniki[stopien + 1] << endl << endl;

	cout << "Podaj wartosc x: ";
	cin >> x;




	cout << "\nAlgorytm oparty o schemat Hornera:" << endl;

	cout << "Wartosc wielomianu = " << horner(wspolczynniki, stopien, x) << endl;


	cout << "Wykonano " << dodawaniaHorner << " dodawan oraz " << mnozeniaHorner <<
		" mnozen. Lacznie " << mnozeniaHorner + dodawaniaHorner << " operacji" << endl << endl;

	cout << "Alogrytm wprost z definicji:" << endl;

	cout << "Wartosc wielomianu  = " << zDefinicji(wspolczynniki, stopien, x) << endl;

	cout << "Wykonano " << dodawania << " dodawan oraz " << mnozenia << " mnozen. Lacznie "
		<< dodawania + mnozenia << " operacji" << endl << endl;

	system("pause");
}