#include <iostream>
#include<fstream>

using namespace std;
typedef int faq;
struct emal
{
	emal* link;

	faq inf;
};
void read(const char* name,emal*& first,emal*& last, emal*& fir, emal*& las)
{
	int x;
	ifstream f(name);
	while (f >> x)
	{
		if (x >= 0)
		{
			emal* tmp = new emal;
			tmp->inf = x;
			tmp->link = NULL;
			if (last != NULL)
				last->link = tmp;
			last = tmp;
			if (first == NULL)
				first = tmp;
		}
		else
		{
			emal* tmp = new emal;
			tmp->inf = x;
			tmp->link = NULL;
			if (las != NULL)
				las->link = tmp;
			las = tmp;
			if (fir == NULL)
				fir = tmp;
		}

	}
	

}
void sliv(emal*& fir, emal*& first)
{
	int k = 0;
	while (first->link != NULL)
	{
		
		if (k % 2 !=0)
		{
			emal* tmp = new emal;
			tmp->inf = fir->inf;
			tmp->link = first->link;
			first = tmp;
			first = first->link;
			fir = fir->link;
		}
		else
			first = first->link;
		k++;
	}
}
faq dequeue(emal*& first, emal*& last)
{
	emal* tmp = first->link;
	faq value = first->inf;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}
int main()
{
	emal* first = NULL;
	emal* last = NULL;
	emal* fir = NULL;
	emal* las = NULL;

	read("1234.txt",first,last,fir,las);
	sliv(fir, first);
	while (first!=NULL)
	{
		cout << dequeue(first, last) << "  " ;
	}
}