#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct apartmani{
	char naziv[20];
	char mjesto[20];
	int brKreveta;
	float cijena;
};
int main(){
	apartmani a[20];
	int i=0, suma=0;
	ifstream ulaz("apartmani.txt", ios::in);
	if(!ulaz) cout<<"GRESKA!!!"<<endl;
	else{
		apartmani temp;
		while(ulaz>>temp.naziv>>temp.mjesto>>temp.brKreveta>>temp.cijena){
			a[i] = temp;
			suma += a[i].cijena;
			i++;
		}
	}
	ulaz.close();
	cout<<"Ukupan broj apartmana: "<<i<<endl;
	cout<<"Prosjecna cijena: "<<suma/i<<endl;
	int br=0;
	cout<<"Broj apartmana u mjestu Paralia: ";
	for(int j=0; j<i; j++){
		if(!strcmp(a[j].mjesto, "PARALIA")){
			br++;
		}
	}
	cout<<br<<endl;
/*	int najmanja = 0;
	cout<<"Naziv apartmana za 2 osobe sa najmanjom cijenom: ";
	for(int j=0; j<i; j++){
		if(a[j].cijena>najmanja && a[j].brKreveta==2){
			a[j].cijena=najmanja;
			cout<<a[j].naziv<<endl;
		}
	}*/
	cout<<"Spisak apartmana sortiranih po cijeni: \n";
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(a[j].cijena>a[k].cijena) swap(a[j], a[k]);
		}
	}
	for(int j=0; j<i; j++){
		cout<<"Naziv: "<<a[j].naziv<<endl;
		cout<<"Mjesto: "<<a[j].mjesto<<endl;
		cout<<"Broj kreveta: "<<a[j].brKreveta<<endl;
		cout<<"Cijena: "<<a[j].cijena<<endl;
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
}
