/*Postoji šest permutacija bez ponavljanja brojeva 1, 2 i 3. To su 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2 i 3,2,1. Napisat
program koji ispisuje sve permutacije bez ponavljanja brojeva 1,2,3,4 i 5 (ima ih 120)*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int niz[] = {1, 2, 3, 4, 5};
	sort(niz, niz+5);
	do{
		cout<<niz[0]<<" "<<niz[1]<<" "<<niz[2]<<" "<<niz[3]<<" "<<niz[4]<<" "<<endl;
	}while(next_permutation(niz, niz+5));
	return 0;
}
