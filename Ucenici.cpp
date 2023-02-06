/*Napisati program u kome se citaju podaci o ucenicima iz postojece datoteke ucenici.txt i kreira niz
struktura tipa ucenik (ime, prezime, razred (1-4), uspjeh, prosjecna ocjena), a zatim štampa:
- ukupan broj ucenika u datoteci,
- broj ucenika 4. razreda,
- imena ucenika koji imaju odlican uspjeh,
- ime ucenika koji ima najbolju prosjecnu ocjenu,
- imena ucenika sortiranih po razredima.*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct ucenik{
	char ime[20];
	char prezime[20];
	int uspjeh;
	int razred;
	double prosjecnaOcjena;
};
int main(){
	ucenik u[20];
	int i=0, br=0;
	double suma=0, najboljaPC;
	ifstream ulaz("ucenici.txt", ios::in);
	if(!ulaz){
		cout<<"GRESKA!!!\n";
	}else{
		ucenik temp;
		while(ulaz>>temp.ime>>temp.prezime>>temp.uspjeh>>temp.razred>>temp.prosjecnaOcjena){
			u[i] = temp;
			if(u[i].prosjecnaOcjena>najboljaPC){
				najboljaPC = u[i].prosjecnaOcjena;
			}
			i++;
		}
	}
	ulaz.close();
	cout<<"Ukupan broj ucenika u datoteci: "<<i<<endl;
	cout<<"Najbolja prosjecna ocjena: "<<najboljaPC<<endl;
	cout<<"Imena ucenika 4-og razreda: \n";
	for(int j=0; j<i; j++){
		if(u[j].razred==4){
			cout<<u[j].ime<<endl;
		}
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(u[j].razred>u[k].razred){
				swap(u[j], u[k]);
			}
		}
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		cout<<"Ime: "<<u[j].ime<<endl;
		cout<<"Prezime: "<<u[j].prezime<<endl;
		cout<<"Uspjeh: "<<u[j].uspjeh<<endl;
		cout<<"Razred: "<<u[j].razred<<endl;
		cout<<"Prosjecna ocjena: "<<u[j].prosjecnaOcjena<<endl;
	}
	
	return 0;	
}
