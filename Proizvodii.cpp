/*Napisati program u kome se citaju podaci o proizvodima u jednoj prodavnici auto-djelova iz postojece
datoteke proizvodi.txt i kreira niz struktura tipa proizvod ( naziv, proizvodac, cjena, kolicina),a zatim
štampa:
- ukupan broj proizvoda u datoteci,
- ukupna vrijednost svih proizvoda u prodavnici,
- spisak proizvoda cija je kolicina 0,
- broj proizvoda koje proizvodi FIAT,
- spisak proizvoda sortiranih po cjeni.*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct proizvod{
	char naziv[20];
	char proizvodjac[20];
	float cijena;
	int kolicina;
};
int main(){
	proizvod p[20];
	int i=0, suma=0;
	int kolicina;
	float cijena;
	string naziv, proizvodjac;
	ifstream ulaz("proizvodii.txt");
	if(!ulaz){
		cout<<"GRESKA"<<endl;
	}else{
		proizvod temp;
		while(ulaz>>temp.naziv>>temp.proizvodjac>>temp.cijena>>temp.kolicina){
			p[i]=temp;
			suma += p[i].cijena;
			i++;
		}
	}
	ulaz.close();
	cout<<"Ukupan broj proizvoda u datoteci je: "<<i<<endl;
	cout<<"Cijena svih proizvoda iznosi: "<<suma<<endl;
	cout<<"Proizvodi cija je kolicina nula: \n";
	for(int j=0; j<i; j++){
		if(p[j].kolicina==0){
			cout<<p[j].naziv<<endl;
		}
	}
	int br=0;
	cout<<"Broj proizvoda koje proizvodi fiat: ";
	for(int j=0; j<i; j++){
		if(!strcmp(p[j].proizvodjac, "FIAT")) br++;
	}
	cout<<br<<endl;
	cout<<"Sortirani proizvodi po cijeni: \n";
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(p[j].cijena>p[k].cijena) swap(p[j], p[k]);
		}
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		cout<<"Naziv proizvoda: "<<p[j].naziv<<endl;
		cout<<"Proizvodjac: "<<p[j].proizvodjac<<endl;
		cout<<"Cijena: "<<p[j].cijena<<endl;
		cout<<"Kolicina: "<<p[j].kolicina<<endl;
		cout<<endl;
	}
	return 0;
	
}
