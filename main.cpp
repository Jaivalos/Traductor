#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#define NOMBRE_ARCHIVO "Palabras.csv"

using namespace std;

int x = 0;
int retorno = 0,f,y,temp;
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

int menu(){
	int op;
	system("cls");
	cout<<"1= Traducir palabra"<<endl;
	cout<<"2= Reporte"<<endl;
	cout<<"3= Salir"<<endl;
	cin>>op;
	return op;	
}

void reporte(){
	for(x=0; x<=50; x++) {
		// Imprimir
		cout << "==================" << endl;
		cout << "Espanol:  " << Pal[x].PalEs << endl;
		cout << "Italiano: " << Pal[x].PalIt << endl;
		cout << "Ingles:   " << Pal[x].PalIn << endl;
		cout << "Frances:  " << Pal[x].PalFr << endl;
		cout << "Aleman:   " << Pal[x].PalDe << endl;
	}
}

int idioma_origen(){
	system("cls");
	int op;
	cout<<"------\n Idioma de Origen:\n1. Espanol \n2. Italiano \n3. Ingles \n4. Frances \n5. Aleman \n(Escriba el numero asociado) \n------"<<endl;
	cin >> op;
	return op;
}

int idioma_destino(){
	system("cls");
	int op;
	cout<<"------\n Idioma de Destino: \n1. Espanol \n2. Italiano \n3. Ingles \n4. Frances \n5. Aleman \n(Escriba el numero asociado) \n------"<<endl;
	cin >> op;
	return op;
}

void busqueda(int origen, int destino, string palabra){
	if(origen == 1){
		for(y=0; y<=50; y++) {
			if(palabra==Pal[y].PalEs) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 2){
		for(y=0; y<=50; y++) {
			if(palabra==Pal[y].PalIt) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 3){
		for(y=0; y<=50; y++) {
			if(palabra==Pal[y].PalIn) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 4){
		for(y=0; y<=50; y++) {
			if(palabra==Pal[y].PalFr) {
				encontrado=true;
				break;
			}
		}
	}else if(origen == 5){
		for(y=0; y<=50; y++) {
			if(palabra==Pal[y].PalDe) {
				encontrado=true;
				break;
			}
		}
	}
	
	if(encontrado == true){
		if(destino == 1){
			cout << "Espanol:  " << Pal[y].PalEs << endl;
		}else if(destino == 2){
			cout << "Italiano: " << Pal[y].PalIt << endl;
		}else if(destino == 3){
			cout << "Ingles:   " << Pal[y].PalIn << endl;
		}else if(destino == 4){
			cout << "Frances:  " << Pal[y].PalFr << endl;
		}else if(destino == 5){
			cout << "Aleman:   " << Pal[y].PalDe << endl;
		}else{
			cout<<"La palabra no existe!!!"<<endl;
			encontrado=false;
		}
	}
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
				
				cout<<"------ Ingrese una palabra ------"<<endl;
				cin>>palabra;
				
				busqueda(origen, destino, palabra);
				
				cout<<endl<<endl<<"1 = Traducir una nueva palabra \n2 = Volver al menu principal"<<endl;
				cin>>f;
			} while(f!=2);
		}
		if(retorno==2) {
			do {
				system("cls");
				cout<<"------- Reporte -------"<<endl;
				reporte();
				cout<<"\n\n2: Salir al menú principal"<<endl;
				cin>>f;
			} while(f!=2);
		}
	} while(retorno!=3);
}


