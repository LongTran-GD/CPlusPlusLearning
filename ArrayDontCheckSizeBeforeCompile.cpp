#include<iostream>

using namespace std;

int main(){
	int a[] = {0};
	for (int i = 0; i < 5; i++) {
		a[i] = i;
		cout << a[i] << endl;
	}
	return 0;
}
