#include <iostream>
#include "Auto.h"

using namespace std;

//Getter Definieren
unsigned int Auto::get_radzahl() const { return radzahl; }
string Auto::get_farbe() const { return farbe; }
unsigned int Auto::get_ps() const { return ps; }
unsigned int Auto::get_anzahl_sitze() const { return anzahl_sitze; }
float Auto::get_spritverbrauch() const { return spritverbrauch; }
float Auto::get_tankinhalt() const { return tankinhalt; }
float Auto::get_tankgroesse() const { return tankgroesse; }

//Settermethode f�r Tankinhalt
bool Auto::set_tankinhalt(float getankte_liter) {
	//Pr�fen ob gew�schte menge noch in den Tank passt, wenn ja Tanken, wenn nein nicht tanken
	if (getankte_liter > 0 and (this->tankinhalt + getankte_liter) <= this->tankgroesse) {
		this->tankinhalt += getankte_liter;
		return true;
	}
	else {
		return false;
	}
}

//Methode fahren
float Auto::fahren(float strecke) {
	//Pr�fen ob gew�scnhte Strecke noch gefahren werden kann, wenn ja fahren, wenn nein so viel Fahren wie m�glich
	if ((abs(strecke) * (this->spritverbrauch/100)) < this->tankinhalt) {
		this->tankinhalt -= (abs(strecke) * (this->spritverbrauch/100));
		return abs(strecke);
	}
	else
	{
		float gefahrenestrecke = this->tankinhalt / (this->spritverbrauch / 100);
		this->tankinhalt = 0;
		return (gefahrenestrecke);
	}
}