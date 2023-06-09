#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <MMsystem.h>
#include<stdio.h>
#include "colors.h"

#define NOMBRE_ARCHIVO "Palabras.csv"

using namespace std;

int x = 0;
int retorno = 0,f,y,temp;
string palabra;
bool encontrado=false;
LPCSTR ruta_lpcstr;

struct Palabra {
	string PalEs;
	string PalIt;
	string PalIn;
	string PalFr;
	string PalDe;
} Pal[101];

void CargarDatos() {
	ifstream archivo(NOMBRE_ARCHIVO);
	string linea;
	char delimitador = ';';
	while (getline(archivo, linea)) {

		stringstream stream(linea); // Convertir la cadena a un stream
		string espanol, italiano, ingles, frances, aleman;
		// Extraer todos los valores de esa fila
		getline(stream, espanol, delimitador);
		getline(stream, italiano, delimitador);
		getline(stream, ingles, delimitador);
		getline(stream, frances, delimitador);
		getline(stream, aleman, delimitador);

		Pal[x].PalEs = espanol;
		Pal[x].PalIt = italiano;
		Pal[x].PalIn = ingles;
		Pal[x].PalFr = frances;
		Pal[x].PalDe = aleman;

		x = x + 1;

	}
}

int menu(){
	int op;
	system("cls");
	
	cout << "|----------------------------------------------------------\n|\n|\n|";      
	
	cout << LGREEN << "                TRADUCTOR DE PALABRAS "<<endl;
	cout <<WHITE<< "|\n|                ----------------------\n|\n|\n";
	
	
	cout<<"|      1. Traducir palabra"<<endl;
	cout<<"|      2. Reporte"<<endl;
	cout<<"|      3. Salir\n|\n|"<<endl;
	
	cout<<"|      Ingrese una opci�n: ";cin>>op;
	
	cout << "|\n|\n|\n|----------------------------------------------------------";
	return op;	
}

void reporte(){
	for(x=0; x<=100; x++) {
		// Imprimir
		cout << "-----------------------" << endl;
		cout << "		Espanol :   "  << Pal[x].PalEs << endl;
		cout << "		Italiano:   "  << Pal[x].PalIt << endl;
		cout << "		Ingles  :   "  << Pal[x].PalIn << endl;
		cout << "		Frances :   "  << Pal[x].PalFr << endl;
		cout << "		Aleman  :   "  << Pal[x].PalDe << endl;
		cout << "-----------------------" << endl;
	}
}

int idioma_origen(){
	system("cls");
	int op;
	cout<<"------------------------------------\n\n     Idioma de Origen:\n     1. Espanol \n     2. Italiano \n     3. Ingles \n     4. Frances \n     5. Aleman \n     (Escriba el numero asociado) \n\n------------------------------------"<<endl;
	cin >> op;
	return op;
}

int idioma_destino(){
	system("cls");
	int op;
	cout<<"------------------------------------\n\n     Idioma de Destino: \n     1. Espanol \n     2. Italiano \n     3. Ingles \n     4. Frances \n     5. Aleman \n     (Escriba el numero asociado) \n\n------------------------------------"<<endl;
	cin >> op;
	return op;
}

void busqueda(int origen, int destino, string palabra){
	if(origen == 1){
		for(y=0; y<=100; y++) {
			if(palabra==Pal[y].PalEs) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 2){
		for(y=0; y<=100; y++) {
			if(palabra==Pal[y].PalIt) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 3){
		for(y=0; y<=100; y++) {
			if(palabra==Pal[y].PalIn) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 4){
		for(y=0; y<=100; y++) {
			if(palabra==Pal[y].PalFr) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 5){
		for(y=0; y<=100; y++) {
			if(palabra==Pal[y].PalDe) {
				encontrado=true;
				break;
			}
		}
	}
	
	if(encontrado == true){
		if(destino == 1){
			
			cout << LGREEN << "Espanol:  " << Pal[y].PalEs << endl;
			string ruta = "C:\\dic\\es\\"; ruta = ruta.append(Pal[y].PalEs); ruta = ruta.append(".wav");
			ruta_lpcstr = ruta.c_str();
			cout <<WHITE<< ruta;
			encontrado=false;
		
		}else if(destino == 2){
		
			cout <<LGREEN << "Italiano: " << Pal[y].PalIt << endl;
			string ruta = "C:\\dic\\it\\"; ruta = ruta.append(Pal[y].PalIt); ruta = ruta.append(".wav");
			ruta_lpcstr = ruta.c_str();
			cout <<WHITE<< ruta;
			encontrado=false;
		
		}else if(destino == 3){
			
			cout <<LGREEN << "Ingles:   " << Pal[y].PalIn << endl;
			string ruta = "C:\\dic\\in\\"; ruta = ruta.append(Pal[y].PalIn); ruta = ruta.append(".wav");
			ruta_lpcstr = ruta.c_str();
			cout <<WHITE<< ruta;
			encontrado=false;
			
		}else if(destino == 4){
			
			cout <<LGREEN << "Frances:  " << Pal[y].PalFr << endl;
			string ruta = "C:\\dic\\fr\\"; ruta = ruta.append(Pal[y].PalFr); ruta = ruta.append(".wav");
			ruta_lpcstr = ruta.c_str();
			cout <<WHITE<< ruta;		
			encontrado=false;
		
		}else if(destino == 5){
			
			cout <<LGREEN << "Aleman:   " << Pal[y].PalDe << endl;
			string ruta = "C:\\dic\\de\\"; ruta = ruta.append(Pal[y].PalDe); ruta = ruta.append(".wav");
			ruta_lpcstr = ruta.c_str();
			cout <<WHITE<< ruta;
			encontrado=false;
		
		}
	}else{
			cout<<RED<<"\n��La palabra no existe!!!"<<endl;
			cout << WHITE << "";
			encontrado=false;
		}
		
	PlaySound(ruta_lpcstr,NULL,SND_SYNC);
		
	}

int main() {
	
	
	
	CargarDatos();

	do{
		retorno = menu();
		if(retorno==1) {
			do{
				int origen  = idioma_origen();
				int destino = idioma_destino();
				
				system("cls");
				
				cout<<"---------------------------------------------------\n\n		Ingrese una palabra\n\n             -------------------------"<<ORANGE<<endl;
				cin>>palabra;
				
				busqueda(origen, destino, palabra);
				
				cout<<endl<<endl<< CYAN<<"	1 = Traducir una nueva palabra \n	2 = Volver al menu principal"<<endl;
				cout<<WHITE<<"";
				cin>>f;
			} while(f!=2);
		}
		if(retorno==2) {
			do {
				system("cls");
				cout<<"------- Reporte -------"<<endl;
				reporte();
				cout<<"\n\n2: Salir al men� principal"<<endl;
				cin>>f;
			} while(f!=2);
		}
	} while(retorno!=3);
}


