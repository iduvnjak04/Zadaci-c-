#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct klijent{
	char ime[20];
	string prezime;
	char mjesto[60];
	char telefonskiBr[20];
	float Posljednjiracun;
};
int main(){
	klijent Klijenti[20];
	klijent Klijent;
	int broj=0; 
	float suma=0, najveciRacun=0;
	ifstream ulaz("klijenti.txt");
	if(!ulaz) cout<<"Greska. Datoteka nije ispravno otvorena."<<endl;
	else{
		while(ulaz>>Klijent.ime>>Klijent.prezime>>Klijent.mjesto>>Klijent.telefonskiBr>>Klijent.Posljednjiracun){
			Klijenti[broj] = Klijent;
			suma += Klijenti[broj].Posljednjiracun; 
			if(Klijenti[broj].Posljednjiracun>najveciRacun) najveciRacun = Klijenti[broj].Posljednjiracun;
			broj++; 
		}
	}
	ulaz.close();
	cout<<"Ukupan broj klijenata iznosi: "<<broj<<endl;
	cout<<"Prosjecan racun iznosi: "<<suma/broj<<endl;
	cout<<"Brojevi telefona klijenata iz Zenice: \n";
	for(int i=0; i<broj; i++){
		if(strcmp(Klijenti[i].mjesto, "Zenica")){
			cout<<"Ime: "<<Klijenti[i].ime;
			cout<<"\nPrezime: "<<Klijenti[i].prezime;
			cout<<"\nBroj telefona: "<<Klijenti[i].telefonskiBr<<endl;
		}
	}
	cout<<"Ime i broj telefona osobe sa najvecim racunom: \n";
	for(int i=0; i<broj; i++){
		if(Klijenti[i].Posljednjiracun==najveciRacun){
			cout<<"Ime: "<<Klijenti[i].ime;
			cout<<"\nBroj telefona: "<<Klijenti[i].telefonskiBr<<endl;
		}
	}
	//spisak klijenata sortiranih po prezimenu
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			for(int x=0; x<Klijenti[i].prezime.length(); x++){
				if(int(tolower(Klijenti[i].prezime[x]))>int(tolower(Klijenti[j].prezime[x]))){
					swap(Klijenti[i], Klijenti[j]);
					break;
				}
				else if (int(tolower(Klijenti[i].prezime[x]))==int(tolower(Klijenti[j].prezime[x]))) continue;
				else break;
			}
		}
	}
	cout<<"Sortirani klijenti po prezimenu: \n";
	for(int i=0; i<broj; i++){
		cout<<"\nPrezime: "<<Klijenti[i].prezime<<endl;
		cout<<"Ime: "<<Klijenti[i].ime<<endl;
		cout<<"Mjesto: "<<Klijenti[i].mjesto<<endl;
		cout<<"Broj: "<<Klijenti[i].telefonskiBr<<endl;
		cout<<"Posljednji racun: "<<Klijenti[i].Posljednjiracun<<endl;
	}
	return 0;
}




















