
#include "interface.h"
#include "naglowki.h"




int main()
{
    Interface interfejs; // init interfejs
    string tmp;

	srand(time(0));
	char A;
	A = 'B';
	while (A != 'T' && A != 'N')
	{

		cout << "Czy chcesz wczytac dane z pliku (T/N): ";

		cin >> A;
	}


	double promien;
	do {
		cout << endl << "Podaj promien otoczenia mieszkanca: ";
		cin >> tmp;
        promien = interfejs.extract_double_from_string(tmp);
	} while (promien == 0);




	int iteracje;
    do {
        cout << endl << "Podaj ilo¿¿ iteracji:";
        cin >> tmp;
        iteracje = interfejs.extract_int_from_string(tmp);
    } while (iteracje == 0);



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

		int N;
		do{
			cout << endl << "Podaj iloœæ mieszkañców:";
			cin >> tmp;
            N = interfejs.extract_int_from_string(tmp);
		}while (N == 0);

		double p;
        do{
			cout << endl << "Podaj stosunek kibiców legii do populacji kibiców (0,1):";
			cin >> tmp;
            p = interfejs.extract_double_from_string(tmp);
            cout<<p;
		}while (p <= 0 || p >= 1);

		Miasto gdansk(N, p, 25,promien);

		gdansk.start(iteracje);
		gdansk.gnuplot(iteracje);
	}

	return 0;
}
