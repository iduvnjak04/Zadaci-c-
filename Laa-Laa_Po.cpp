/*Laa-Laa i Po igraju igru. Laa-Laa zamisli broj X, a Po mora naci najveci neparni broj Y koji dijeli X. Kako je Laa-
Laa ipak nešto starija, ona malo bolje poznaje svijet brojki pa zamišlja prevelike brojeve, ali zato Po ima dobre
starije prijatelje koji ce mu pomoci!!!
Ulazni podaci
Putem tastature unosi se jedan prirodan broj X s maksimalno 9 cifara.
Izlazni podaci
Na zaslon je potrebno ispisati broj Y, odnosno najveci neparni djelitelj broja X.*/

#include <iostream>
using namespace std;
int main(){
	int broj;
	cout<<"Unesite broj: "; cin>>broj;
	for(int i=broj; i>=1; i--){
		if(broj%i==0 && i%2!=0){
			cout<<"Najveci broj koji dijeli "<<broj<<" je "<<i<<endl;
			return 0;
		}
	}
	
	return 0;
}
