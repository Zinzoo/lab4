#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

void toWords(int x);
int isItBinary(long long int x);

int main(int argc, char *argv[])
{
	int x;
	unsigned long long int n;
	n=atoi(argv[1]);

	x=isItBinary(n);

	if(x>0)
	{
		cout<<"Szukana liczba to ";
		toWords(x);
	}
}

void toWords(int x)
{
	string words[5][9]={{"jeden", "dwa", "trzy", "cztery", "pięć","sześć","siedem","osiem","dziewięć"},
	{"jedenaście","dwanaście","trzynaście","czternaście","piętnaście","szesnaście","siedemnaście","osiemnaście","dziewiętnaście"},
	{"dziesięć","dwadzieścia","trzydzieści","czterdzieści","pięćdziesiąt","sześćdziesiąt","sziedemdziesiąt","osiemdziesiąt","dziewięćdziesiąt"},
	{"sto","dwieście","trzysta","czterysta","pięćset","sześćset","siedemset","osiemset","dziewięćset"},
	{"tysiąc","tysiące","tysięcy"}};

	if(x>=1000000)
	{
		if(x==1000000)
			cout<<"Milion"<<endl;
	};

	int digit[6];

	for(int i=5; i>=0; i--)
	{
		digit[i]=x%10;
		x/=10;
	};

	int n=0;
	if(digit[0]>0)												//Setki tysięcy
	{
		n=digit[0];
		cout<<words[3][n-1]<<" ";
	};

	if(digit[1]>0)												//Dziesiątki tysięcy
	{
		if(digit[1]==1&&(digit[2]!=0))
		{
			n=digit[1];
			cout<<words[1][n-1]<<" "<<words[4][2]<<" ";
		}else
		{
			n=digit[1];
			cout<<words[2][n-1]<<" ";
		};
	};
	if(digit[2]>=0)												//Tysiące
	{
		if(digit[2]==1&&(digit[0]==0&&(digit[1]==0)))
			cout<<words[4][0]<<" ";
		else if(digit[2]>1)
		{
			n=digit[2];
			cout<<words[0][n-1]<<" ";
			if(n==1 || n==5 || n==6 || n==7 || n==8 || n==9)
				cout<<words[4][2]<<" ";
			else if(n==2 || n==3 || n==4)
				cout<<words[4][1]<<" ";
		}else if(digit[2]==0&&(digit[0]>0||digit[1]>0))
			cout<<words[4][2]<<" ";
	};
	if(digit[3]>0)												//Setki
	{
		n=digit[3];
		cout<<words[3][n-1]<<" ";
	};
	if(digit[4]>1)												//Dziesiątki
	{
		n=digit[4];
		cout<<words[2][n-1]<<" ";
	}else if(digit[4]==1&&(digit[5]>0))
	{
		n=digit[5];
		cout<<words[1][n-1]<<" ";
	}else if(digit[4]==1&&(digit[5]==0))
		cout<<words[2][0]<<" ";
	if(digit[5]>0&&(digit[4]!=1))								//Jedności
	{
		n=digit[5];
		cout<<words[0][n-1]<<" ";
	};
	cout<<endl;

}

int isItBinary(long long int x)
{
	int k, j, o;		//stworzyłem zmienną o żeby móc zrobić kopię zmiennej j, która później będzie zmieniać swoją wartość

	bool isBinary;

	int *w;

	for(k=2; k<1000000; k++) //Główna pętla wewnątrz której szukane będzie k
	{
		j=x*k;
		o=j;

		if(j>100000)
		{
			cout<<"Ta liczba jest za duża i wychodzi poza skalę programu ;_;"<<endl; //Program liczy tylko do miliona więc trzeba się jakoś ograniczyć :v
			return 0;
		};
		
		string number = to_string(o);
										//}Zamieniłem wynik mnożenia na string, aby później sworzyć odpowiednio dużą tablicę
		w = new int[number.length()];

		for(int i=(number.length())-1; i>=0; i--) //Tutaj pętla umieszcza pojedyncze cyfry składające się na wynik mnożenia w tabeli
		{
			w[i]=j%10;
			j/=10;
		};

		for(int i=0; i<((number.length())); i++) //Ta pętla sprawdza czy liczby umieszczone w tabeli są równe 0 lub 1
		{
			if(w[i]==0 || (w[i]==1))
			{
				isBinary = true;				//Jeżeli tak to bool przyjmuje wartość 1
			}
			else
				{
					isBinary = false;
					break;
				};
		};
		if(isBinary==true)						//I na koniec jeżeli wartość boola po wykonaniu pętli wynosi 1 to program wypisuje szukaną liczbę
		{
			cout<<"Iloczyn wynosi: ";
			toWords(o);
			return k;
		}
	};
}