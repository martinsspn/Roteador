#include <iostream>
using namespace std;

void X(int * x){
	x = new int(11);
}

int main(){
	int * x = new int(5);
	cout << &x << endl;
	X(x);
	cout << &x << endl;
}
