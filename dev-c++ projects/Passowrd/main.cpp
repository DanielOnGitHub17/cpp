#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
   int a = system("choice /n /c YN /m shutdown???");
   if (a-1){
   	   system("shutdown /p");
   }
   return 0;
}
