#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

int main(){
	
	char sonido[] = "C:\Aplausos.wav";
	cout << PlaySound((LPCSTR)sonido , NULL , SND_FILENAME);
	
	
	getch();
	return 0;
	
}
