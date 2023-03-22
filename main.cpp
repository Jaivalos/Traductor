
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

int main()
{
	
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
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

    archivo.close();
}
