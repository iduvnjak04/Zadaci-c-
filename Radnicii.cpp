/*Napisati program u kome se citaju podaci o radnicima iz postojece datoteke radnici.txt i kreira niz
struktura tipa radnik (ime, prezime, broj godina radnog staža, stepen strucne spreme i plata), a zatim
štampa:
- ukupan broj radnika u datoteci,
- prosjecna plata radnika,
- broj radnika koji imaju više od 5 godina radnog staža,
- imena radnika sa najvišim stepenom strucne spreme,
- spisak radnika sortiranih po imenima.*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct radnik{
	char ime[20];
	char prezime[20];
	int godRadnogS;
	char strucnaSprema[10];
	float plata;
};
int main(){
	radnik r[20];
	int i=0,br=0;
	float suma=0; 
	ifstream ulaz("radnicii.txt", ios::in);
	if(!ulaz){
		cout<<"GRESKA!!!"<<endl;
	}else{
		radnik temp;
		while(ulaz>>temp.ime>>temp.prezime>>temp.godRadnogS>>temp.strucnaSprema>>temp.plata){
			r[i] = temp;
			suma += r[i].plata;
			i++;
		}
	}
	ulaz.close();
	cout<<"Broj radnika u datoteci: "<<i<<endl;
	cout<<"Prosjecna plata radnika: "<<suma/i<<endl;
	cout<<"Broj radnika koji imaju vise od 5 godina radnog staza: ";
	for(int j=0; j<i; j++){
		if(r[i].godRadnogS>5) br++;
	}
	cout<<br<<endl;
	cout<<"Imena radnika sa visom strucnom spremom: \n";
	for(int j=0; j<i; j++){
		if(!strcmp(r[j].strucnaSprema, "VSS")){
			cout<<r[j].ime<<endl;
		}
	}
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(r[j].ime>r[k].ime) swap(r[j], r[k]);
		}
	}
	for(int j=0; j<i; j++){
		cout<<"Ime: "<<r[j].ime<<endl;
		cout<<"Prezime: "<<r[j].prezime<<endl;
		cout<<"Broj godina radnog staza: "<<r[j].godRadnogS<<endl;
		cout<<"Strucna sprema: "<<r[j].strucnaSprema<<endl;
		cout<<"Plata: "<<r[j].plata<<endl;
	}
	return 0;	
}
