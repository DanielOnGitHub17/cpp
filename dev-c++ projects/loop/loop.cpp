#include <iostream>
using namespace std;
int main() {
 int r;
 while (true){
 	r++;
 	if (int(r/1000) == r/1000) {
	 cout << "\rDaniel is "<< r/1000 << " years old";
	};
 }
 return 0;
}
