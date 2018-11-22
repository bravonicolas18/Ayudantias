#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main() {

	int cant=5,i=0;
	
	srand(time(NULL));
	for(i=0;i<cant;i++)
		cout<<rand()%889+111<<endl;
	cout<<endl;
	
	system("pause");
	return 0;
}
