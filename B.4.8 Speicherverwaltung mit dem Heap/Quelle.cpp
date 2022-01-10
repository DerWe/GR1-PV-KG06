#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen f�r die jeweiligen Aufgaben definieren
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Mittelwert berechnen
float f_mittelwert(float werte[], int size) {	//Pointer des Arrays und die l�nge �bergeben

	float summe = 0;							//Variablen vordefinieren
	float mittelwert = 0;

	for (int i = 0; i < size; i++) {			//Schleife durch alle Werte des Arrays
		summe += werte[i];						//Einzelwerte auf Summe aufaddieren
	}

	mittelwert = summe / size;					//Durch size teilen --> Mittelwert
	return mittelwert;							//Mittelwert als float zurr�ckgeben
}

//Varianz berechnen
float f_varianz(float werte[], int size) {					//Pointer des Arrays und die l�nge �bergeben

	float mittelwert = f_mittelwert(werte, size);			//Variablen vordefinieren und Mittelwert mit obriger Funktion berechnen
	float zwischensumme = 0;
	float varianz = 0;

	for (int i = 0; i < size; i++) {						//Schleife durch alle Werte des Arrays
		zwischensumme += pow(werte[i] - mittelwert, 2);		//Messwert - Mittelwert zum Quadrat aufaddieren
	}

	varianz = zwischensumme / (size - 1);					//Zwischensumme durch N-1 Teilen
	return varianz;											//Varianz als float zurr�ckgeben
}

//Array komplett ausgeben
void f_printarray(float werte[], int size) {	//Pointer des Arrays und die l�nge �bergeben

	cout << "Messwerte [m]\n"					//Kopf ausgeben
		<< "------------- \n";

	for (int i = 0; i < size; i++) {			//Schleife durch alle Werte des Arrays
		cout << werte[i] << "\n";				//Jeden Messwert mit cout ausgeben
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Hauptprogramm
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {

	//Arrays und Variablen vordefinieren, zun�chst l�nge abfragen
	int messwerte_size = 0;
	cout << "Anzahl der Messwerte: ";
	cin >> messwerte_size;

	//entsprechend ben�tigten Speicherplatz Heap anfordern und reservieren
	float* messwerte;
	messwerte = new float[messwerte_size];
	
	//So viele Messwerte, wie anfangs vom User eingegeben abfragn und in den Speicherplatz schreiben
	for (int i = 0; messwerte_size > i; i++) {
		cout << "Messwert " << i+1 << ": ";
		cin >> messwerte[i];
	}

	//Oben geschriebene Funktionen zur Berechnung des Mittelwertes und Varianz verwenden
	float mittelwert = f_mittelwert(messwerte, messwerte_size);
	float varianz = f_varianz(messwerte, messwerte_size);

	//Array der Messwerte per Funktion ausgeben
	system("cls");
	f_printarray(messwerte, messwerte_size);
	cout << "\n";

	//Schlusszeile mit Mittelwert und Varianz ausgeben
	cout << "Mittelwert = " << mittelwert << "m Varianz = " << varianz << " quadratmeter";

	delete[] messwerte;

	return 0;
}