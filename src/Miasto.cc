#include "naglowki.h"

Miasto::Miasto(int nc, double stosunek, double S, double r)
{
	N = nc;
	N1 = round(N *stosunek);
	N2 = N - N1;
	size = S;
	R = r;
}
Miasto::Miasto(double r) 
{
	R = r;
};

void Miasto::wypelnij(string zpliku)
{
	ifstream myfile(zpliku + ".txt");
	if (myfile.is_open())
	{

		double X, Y;
		int B;
		string klub;
		int i = 0;
		while (!myfile.eof())
		{
			myfile >> X;
			myfile >> Y;
			myfile >> klub;

			++i;

			if (klub == "Polonia")
				B = 1;
			else
				B = 2;

			list.push_back(Kibic(X, Y, B));

		}
		myfile.close();
		N = list.size();
	}
	else
		cout << "Nie otworzono pliku";
	
}

int Miasto::getN()
{
	return N;
}

double Miasto::getw()
{
	
	return w;
}

double Miasto::getR()
{
	return R;
}

double Miasto::elementX(int i)
{
	double X = list.at(i).getX();
	return X;
}

int Miasto::getBel(int i)
{
	int a;
	a = list.at(i).getB();
	return a;
}


double Miasto::elementY(int i)
{
	double Y = list.at(i).getY();
	return Y;
}
void Miasto::zaludnij()
{

	double X, Y;
	int B;
	for (int i = 0; i < N; i++)
	{

		X =(double)rand()/ (double)RAND_MAX *  size;
		Y =(double)rand()/ (double)RAND_MAX * size;
		if (i < N1 )
		{
			B = 1;
		}
		else
			B = 2;
		//cout << X << "\t" << Y << "\t" << B << endl;
		list.push_back(Kibic(X, Y, B));
		
	}
}

void Miasto::sprawdz_zadowolenie()
{
	Miasto*r = this;
	 w = 0;
	for (int i = 0; i < N; i++)
	{
		w = w + list.at(i).zadowolenie(r);
	}
	w = w / N;
}

void Miasto::przeprowadzka()
{
	for (int i = 0; i < N; i++)
	{
		if (list.at(i).gethap() < 0)
			list.at(i).przeprowadzka(size, R);
	}


}

void Miasto::drukuj()
{
	for (int i = 0; i < N; i++)
	{
		cout <<i<<" "<< list.at(i).getX() <<"\t"<< list.at(i).getY()<<"\t"<< list.at(i).getB()<<"\t"<< list.at(i).gethap() <<endl;
	}
}


void Miasto::zapis(int iteration)
{
	string a = "iteration" + std::to_string(iteration) + ".txt";
	ofstream myfile (a);
	if (myfile.is_open())
	{
		for (int i = 0; i < N; i++)
		{
			myfile <<list.at(i).getX() << "\t" << list.at(i).getY() << "\t" << ((list.at(i).getB()==1)?"Polonia":"Legia") << endl;

		}
		myfile.close();
	}
	else cout << "Unable to open file";

}

void Miasto::zapis2(int iteration)
{
	string L = "Legia_iteration" + std::to_string(iteration) + ".txt";
	string P = "Polonia_iteration" + std::to_string(iteration) + ".txt";
	ofstream myfileP(P);
	ofstream myfileL(L);
	if (myfileP.is_open()&& myfileL.is_open())
	{
		for (int i = 0; i < N; i++)
		{
			if(list.at(i).getB() == 1)
				myfileP << list.at(i).getX() << "\t" << list.at(i).getY() << endl;

			if (list.at(i).getB() == 2)
				myfileL << list.at(i).getX() << "\t" << list.at(i).getY() << endl;
		}
		myfileP.close();
		myfileL.close();
	}
	else cout << "Unable to open files";

}



void Miasto::start(int iteracje,string zplik)
{
	if (zplik.compare("")) {
		wypelnij(zplik);
	}
	else{
		zaludnij();
	}
	
	drukuj();
	for (int i = 0; i <iteracje; i++)
	{

		sprawdz_zadowolenie();
		cout << "zadowolenie= " << getw() << endl;
		przeprowadzka();
		cout << i << "   --------------------------------------------------" << endl;
		//drukuj();
		zapis2(i);


	}
}

void Miasto::gnuplot(int iteration)
{

	ofstream skrypt("skryptpi.gp");

	iteration--;



	skrypt << "plot \"Legia_iteration"+ std::to_string(iteration) +".txt\" with points pointtype 7,\"Polonia_iteration"+ std::to_string(iteration) +".txt\" with points pointtype 7" << endl;
	skrypt << "pause -1 \"Wcisnij ENTER\" " << endl;

	skrypt.close();
	system("gnuplot skryptpi.gp");
}
