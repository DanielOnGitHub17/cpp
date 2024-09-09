#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int a, char** b) {
	int aa = a; char bb = **b;
	cout << aa <<" and " << bb << "\n";
	system("pause");
}
