#include <iostream>
using namespace std;
struct bolnica{
	char naziv[60];
	char grad[60];
	int brZaposlenih;
};

struct odjel{
	bolnica Bolnica;
	char naziv[60];
	float cijenaPoDanu;
};

struct pacijent{
	char ime[20];
	char prezime[20];
	odjel Odjel;
	int godiste;
	bool osiguran;
};

pacijent unosPacijenta(){
	pacijent Pacijent;
	cout<< "Unijeti ime pacijenta: "; cin.getline(Pacijent.ime, 20);
	cout<< "Unesite prezime pacijenta: "; cin.getline(Pacijent.prezime, 20);
	cout<< "Unesite naziv bolnice u kojoj je pacijent: "; cin.getline(Pacijent.Odjel.Bolnica.naziv, 60);
	cout<< "Unesite grad u kojem je bolnica: "; cin.getline(Pacijent.Odjel.Bolnica.grad, 60);
	cout<< "Unesite broj zaposlenih u bolnici: "; cin>>Pacijent.Odjel.Bolnica.brZaposlenih;
	cin.ignore();
	cout<< "Unesite naziv odjela na kojem je pacijent: "; cin.getline(Pacijent.Odjel.naziv, 60);
	cout<< "Unesite cijenu lezanja jednog dana na odjelu: "; cin>>Pacijent.Odjel.cijenaPoDanu;
	cout<< "Unesite godiste pacijenta: "; cin>>Pacijent.godiste;
	int temp;
	do{
		cout<<"Da li je pacijent osiguran: \n";
		cout<<"\t0 - NE\n";
		cout<<"\t1 - DA\n";
		cout<<"\tOdabir: ";
		cin>>temp;
	}while(temp<0 || temp>1);
	Pacijent.osiguran = static_cast<bool>(temp);
	cin.ignore();
	return Pacijent;
}

void ispisPacijenta(pacijent& Pacijent){
    cout<< "---------------------------------------";
    cout<< "\nPodaci o pacijentu:";
    cout<< "\nIme: " <<Pacijent.ime;
    cout<< "\nPrezime: "<<Pacijent.prezime;
    cout<< "\nBolnica: " <<Pacijent.Odjel.Bolnica.naziv<<" iz grada "<<Pacijent.Odjel.Bolnica.grad<< ". ("<<Pacijent.Odjel.Bolnica.brZaposlenih<<" zaposlenih)";
    cout<< "\nOdjel: "<<Pacijent.Odjel.naziv <<" - "<<Pacijent.Odjel.cijenaPoDanu<<" KM po danu.";
    cout<< "\nGodina: " <<2022-Pacijent.godiste;
    cout<< "\nOsiguran: " << (Pacijent.osiguran? "DA" : "NE");
    cout<< "\n---------------------------------------\n";
}
float cijena(odjel o, int n){
    if(n==1){
        return o.cijenaPoDanu;
    }else{
        return cijena(o,n-1)*0.95;
    }
}
int main() {
    pacijent novi = unosPacijenta();
    ispisPacijenta(novi);
    cout<<"Cijena odjela "<<novi.Odjel.naziv<<" na 10 dan: "<<cijena(novi.Odjel, 10);
    float suma = 0;
    for(int i=1;i<=10;i++){
        suma += cijena(novi.Odjel,i);
    }
    cout<<"\nUkupna cijena: "<<suma;
    return 0;
}




