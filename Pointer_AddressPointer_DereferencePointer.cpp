#include <iostream>

using namespace std;

int main() {
	int a;
	int* p;

	p = &a;
	a = 5;

	cout << "&p : " << &p << endl;
	cout << "p : " << p << endl;
	cout << "*p : " << *p << endl;
	cout << "a : " << a << endl;
	cout << "&a : " << &a << endl;
	//cout << "*a : " << *a << endl;
	return 0;
}

// &p : 0000005D3D6FF7C8
// p : 0000005D3D6FF7A4
// *p : 5
// a : 5
// &a : 0000005D3D6FF7A4
