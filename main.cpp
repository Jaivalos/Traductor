#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "Palabras.csv"

using namespace std;

struct Palabra {
	string PalEs;
	string PalIt;
	string PalIn;
	string PalFr;
	string PalDe;
} Pal[51];

int x = 0;
int retorno,f;

int main() {
 	ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    
       
    
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
				
				
				cout<<endl<<endl<<"1= Traducir una nueva palabra 2= salir al menu principal"<<endl;
				cin>>f;
			} while(f!=2);

		}

		if(retorno==2) {
			system("cls");
			do {
				system("cls");
				cout<<"REPORTE"<<endl;
				while (getline(archivo, linea))
    {

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
		
		// Imprimir
        cout << "==================" << endl;
        cout << "Español:  " << Pal[x].PalEs << endl;
        cout << "Italiano: " << Pal[x].PalIt << endl;
        cout << "Ingles:   " << Pal[x].PalIn << endl;
        cout << "Frances:  " << Pal[x].PalFr << endl;
        cout << "Aleman:   " << Pal[x].PalDe << endl;
		
		x = x + 1;
		
        
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


