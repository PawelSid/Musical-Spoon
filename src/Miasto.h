

class Miasto
{

public:
	int N;					//liczba mieszka�c�w
	int N1, N2;			//liczba jedynek i dw�jek n1+n2=N
	vector<Kibic> list;	 //zbi�r mieszka�c�w

	double size;		//km zakres 0 - 25
	double R;			// neighbour
	double w;			//srednie zadowolenie
	
	double elementX(int i);
	double elementY(int i);

	Miasto(double);
	Miasto(int nc, double stosunek, double S, double pr);



	void zaludnij();
	void sprawdz_zadowolenie();

	void przeprowadzka();
	int getN();
	double getR();
	int getBel(int i);
	double getw();
	void drukuj(); 
	void zapis(int);
	void wypelnij(string);
	void start(int a,string tr="");
	void zapis2(int);
	void gnuplot(int);
};
