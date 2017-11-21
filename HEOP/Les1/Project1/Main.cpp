#include <iostream>
#include <string>
#include "Functions.h" 
#include "Block.h"

using namespace std;

#pragma once
/*
Nodige attributen

Variabelen:
	Begin tijd les
		Uur
		Minuut

	Lesduur

	Weeknummer 1-52
	Dagnummer  1-7

	Betrokken leraren
		Voornaam
		Achternaam

	Betrokken klassen
	Lokaal
	Modulenaam

Functies:
	Lesblok aanmaken
	Lesblok aanpassen

Om het rooster te tekenen gebruik je een rooster van 7*288 blokken
7 voor de 7 dagen van een week en 
288 voor het aantal keer 5 minuten in een dag.

lessonTime zal in duizendtallen doorgegeven worden. 15:30 zal genoteerd worden als 1530 en 17:45 als 1745
lessonDuration zal in minuten doorgegeven worden. Een les van 2 uur zal dan als 120 minuten doorgegeven worden en een les van 1 uur en 3 kwartier als 105

De namen van de leraren, de klassen en modulenamen kunnen allemaal ook binnen enums opgeslagen worden.
*/
int lessonTime, weekNum, dayNum, lessonDuration;
string fNameTeacher, lNameTeacher, classes, classroomNo, moduleName;


