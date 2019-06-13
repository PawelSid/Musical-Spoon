
#include "interface.h"
#include "naglowki.h"




int main()
{
	srand(time(0));
	char A;
	A = 'B';
	while (A != 'T' && A != 'N')
	{

		cout << "Czy chcesz wczyta¿ dane z pliku (T/N)";

		cin >> A;
	}


	string promienn = "promienn";
	double promien;
	do {
		cout << endl << "Podaj promie¿ otoczenia mieszka¿ca";

		cin >> promienn;
	} while (atof(promienn.c_str()) == 0.0);

	promien = atof(promienn.c_str());




	int iteracje;

	cout << endl << "Podaj ilo¿¿ iteracji:";

	cin >> iteracje;

		while (cin.fail())
		{

			cout << endl << "Podaj ilo¿¿œæ iteracji:";
			cin.clear();
			cin >> iteracje;

		}







	if (A == 'T')
	{
		cout << endl << "Podaj nazwê pliku(bez rozszerzenia):";
		string nazwa;
		cin >> nazwa;


		Miasto gdansk(promien);
		gdansk.start(iteracje,nazwa);
		gdansk.gnuplot(iteracje);
	}
	if(A=='N')
	{

		string LN = "Liczba_n";
		int N;


		while (atoi(LN.c_str()) == 0.0)
		{
			cout << endl << "Podaj iloœæ mieszkañców:";

			cin >> LN;

		}
		N = atoi(LN.c_str());

		string stosunek = "stosunek";
		double p;
		while (atof(stosunek.c_str()) == 0.0 && atof(stosunek.c_str())<=1 && atof(stosunek.c_str()) >=0)
		{
			cout << endl << "Podaj stosunek kibiców legii do populacji kibiców (0,1):";

			cin >> stosunek;
		}

		p = atof(stosunek.c_str());

		Miasto gdansk(N, p, 25,promien);

		gdansk.start(iteracje);
		gdansk.gnuplot(iteracje);
	}



	return 0;
}
