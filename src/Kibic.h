

class Kibic
{

public:

	double xax;			//miejsce na ox
	double yax;			//miejsce na oY
	int bel;			//belong przynale¿noœæ
	int hap;			//happines zadowolenie



	Kibic(double X, double Y, int B);
	double getX();
	double getY();
	int getB();
	int gethap();
	int zadowolenie(Miasto *M);
	void przeprowadzka(double, double);

};

