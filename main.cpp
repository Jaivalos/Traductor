#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "Palabras.csv"

using namespace std;

int x = 0;
int retorno,f,y,temp;
string palabra;
bool encontrado=false;

struct Palabra {
	string PalEs;
	string PalIt;
	string PalIn;
	string PalFr;
	string PalDe;
} Pal[51];

void CargarDatos() {
	ifstream archivo(NOMBRE_ARCHIVO);
	string linea;
	char delimitador = ',';
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

int main() {
	CargarDatos();

	do {
		system("cls");
		cout<<"1= Traducir palabra"<<endl;
		cout<<"2= Reporte"<<endl;
		cout<<"3= Salir"<<endl;
		cin>>retorno;

		if(retorno==1) {
			do {
				system("cls");
				cout<<"INGRESE PALABRA"<<endl;
				cin>>palabra;

				for(y=0; y<=50; y++) {
					if(palabra==Pal[y].PalEs) {
						encontrado=true;
						break;

					}
				}
				if(encontrado==true) {
					cout << "Espanol:  " << Pal[y].PalEs << endl;
					cout << "Italiano: " << Pal[y].PalIt << endl;
					cout << "Ingles:   " << Pal[y].PalIn << endl;
					cout << "Frances:  " << Pal[y].PalFr << endl;
					cout << "Aleman:   " << Pal[y].PalDe << endl;

				} else {
					cout<<"La palabra no existe!!!"<<endl;
					encontrado=false;
				}
				cout<<endl<<endl<<"1= Traducir una nueva palabra 2= salir al menu principal"<<endl;
				cin>>f;

			} while(f!=2);
		}

		if(retorno==2) {
			system("cls");
			do {
				system("cls");
				cout<<"REPORTE"<<endl;

				for(x=0; x<=50; x++) {

					// Imprimir
					cout << "==================" << endl;
					cout << "Espanol:  " << Pal[x].PalEs << endl;
					cout << "Italiano: " << Pal[x].PalIt << endl;
					cout << "Ingles:   " << Pal[x].PalIn << endl;
					cout << "Frances:  " << Pal[x].PalFr << endl;
					cout << "Aleman:   " << Pal[x].PalDe << endl;
				}

				cout<<endl<<endl<<"2= salir al menu principal"<<endl;
				cin>>f;
			} while(f!=2);
		}
		if(retorno==3) {
			system("exit");
		}
	} while(retorno!=3);



}


