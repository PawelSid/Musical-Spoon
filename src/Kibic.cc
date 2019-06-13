#include "naglowki.h"




Kibic::Kibic(double X, double Y, int B)
{
	hap = 0;
	xax = X;
	yax = Y;
	bel = B;
};




double Kibic::getX()
{
	return xax;
};

double Kibic::getY()
{
	return yax;
};

int Kibic::getB()
{
	return bel;
};

int Kibic::gethap()
{
	return hap;
};

void Kibic::przeprowadzka(double size, double r)
{
	double w = 2 * PI2 * (double)rand() / (RAND_MAX);
	xax =(xax + r*sin(w));  //, 25.0
	yax =(yax + r*cos(w));
	if (xax > size) xax -= size;
	if (xax < 0) xax += size;
	if (yax > size) yax -= size;
	if (yax < 0) yax += size;
}

int Kibic::zadowolenie(Miasto *M)
{
	hap = 0;
	double R = M->getR();

	int N1, N2;
	N1 = 0;
	N2 = 0;
	for (int i = 0; i < M->getN(); i++)
	{
		double D;
		D = sqrt((xax - M->elementX(i)) * (xax - M->elementX(i)) + (yax - M->elementY(i)) * (yax - M->elementY(i)));
		if (D < R)
		{
			if (1 == M->getBel(i))
				N1++;
			else
				N2++;
		}
	}
	if (bel == 1)
	{
		N1 = N1 - 1;
		hap = N1 - N2;

	}
	if (bel == 2)
	{
		N2 = N2 - 1;
		hap = N2 - N1;
	}

	return hap;
}
