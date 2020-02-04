

//Person.h
#pragma once
#include <string>
#include "PrintExt.h"

enum class Gender : unsigned short
{
	male,
	female,
	diverse
};

std::string to_string(Gender g)
{
	switch (g)
	{
	case Gender::male:
		break;
	case Gender::female:
		break;
	case Gender::diverse:
		break;
	default:
		break;
	}
	return "*unknown gender*";
}

class Person
{
public:
	std::string name;
	unsigned int birthdate; //YYYYMMDD
	Gender gender;

public:
	Person(const std::string& n, unsigned int b, Gender g)
		: name(n), birthdate(b), gender(g)
	{   }

	virtual ~Person()
	{   };

	virtual std::ostream& sout(std::ostream& os) const //für Schleife bzgl. Typen Ausgabe!
	{
		os << "Person = {";
		os << PrintExt::to_PrintItemStr("name", name) << ",";
		os << PrintExt::to_PrintItemStr("birthdate", birthdate) << ",";
		os << PrintExt::to_PrintItemStr("gender", to_string(gender)); //für string, switch case zeile 12-26 erstellen!
		os << "}";
		return os;
	}
};

inline std::ostream& operator <<(std::ostream& os, const Person& p) {

/*	os << "Person = {";
	os << PrintExt::to_PrintItemStr("name", name) << ",";
	os << PrintExt::to_PrintItemStr("birthdate", birthdate) << ",";
	os << PrintExt::to_PrintItemStr("gender", to_string(gender)); //für string, switch case zeile 12-26 erstellen!
	os << "}";
	return os;*/ //in virtuelle Funktion oben kopieren!

	return p.sout(os); //vituelle Funktion aufrufen
} 

//Student.h

#pragma once
#include "Person.h"
#include "Email.h" 

using MATNR = unsigned long long;

class Student :
	public Person, public Email
{
public:
	//unsigned long long matrikelnummer; //10-stelliger Int
	MATNR matrikelnummer;

public:
	Student(const std::string& n, unsigned int b, Gender g, MATNR m, const std::string& e)
		: Person(n, b, g), matrikelnummer(m), Email(e)
	{   }

	virtual ~Student()
	{   }

	std::ostream& sout(std::ostream& os) const override
	{
		os << "Student = {";
		Person::sout(os); //Basisklasse aufrufen
		os << PrintExt::to_PrintItemStr("matrikelnummer", matrikelnummer) << ",";
		os << PrintExt::to_PrintItemStr("email", getEmail());
		os << "}";
		return os;
	}
};

//Teacher.h
#pragma once
#include "Person.h"
#include "Email.h" 

using SHORTSVNR = unsigned short;

class Teacher :
	public Person, public Email
{
protected:
	SHORTSVNR svnr; //Integer XXXX

public:
	Teacher(const std::string& n, unsigned int b, Gender g, SHORTSVNR s, const std::string& e)
		:Person(n,b,g), svnr(s), Email(e)
	{   }
	virtual ~Teacher()
	{   }

	std::string getExtSVNr() const {
		std::string sbd = std::to_string(birthdate);
		return std::to_string(svnr) + "-" + sbd.substr(6, 2) + sbd.substr(4, 2) + sbd.substr(2, 2);
	}

	std::ostream& sout(std::ostream& os) const override
	{
		os << "Teacher = {";
		Person::sout(os); //Basisklasse aufrufen
		os << PrintExt::to_PrintItemStr("svnr", svnr) << ",";
		os << PrintExt::to_PrintItemStr("email", getEmail());
		os << "}";
		return os;
	}
};

//Email.h
#pragma once
#include <string>

class Email
{
	std::string email;

public:
	Email(const std::string& e)
		: email(e)
	{
			validate(e); //am Ende
	}

	std::string getEmail() const { return email; }
	void setEmail(const std::string& e) { validate(e); email = e; } //validate(e) am Ende bzgl exceptions

	static bool validate(const std::string& e); //statische methode(bool), die string (einer emailadr) entgegen nimmt

};

//Email.cpp
#include "pch.h"
#include "Email.h"
#include <stdexcept> //für runtime

bool Email::validate(const std::string& e)
{
	size_t kapos = e.find('@');

	if (kapos == std::string::npos) //npos=keine emailadr gefunden
		throw std::runtime_error("Missing @");

	if (kapos == 0)
		throw std::runtime_error("Missing private part"); //bei pos 0

	if (kapos+1 >= e.length())
		throw std::runtime_error("Missing domain part");

	return true;
}

//PrinExe.h
#pragma once
#include <string>


namespace PrintExt {

	template<typename T>

	inline std::string to_PrintItemStr(const std::string& p1, const T& p2) {

		return "\"" + p1 + "\"=" + std::to_string(p2);
	}

	inline std::string to_PrintItemStr(const std::string& p1, const std::string& p2) {

		return "\"" + p1 + "\"=" + "\"" + p2 + "\"";
	}

	inline std::string to_PrintItemStr(const std::string& p1, const char* p2){
		
		return "\"" + p1 + "\"=" + "\"" + std::string(p2) + "\"";
	}
}

//FHHumans.cpp
// FHHumans.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "PrintExt.h"

void check_email_validation(const std::string& s)
{
	// Aufruf der Email Validierungsfunktion und Abfangen einer m�glichen 
	// Exception zur Ausgabe einer Fehlermeldung auf cerr
	try {
		Email::validate(s);
	}catch(std::runtime_error e){
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
	}
}

int main()
{
	// -------------------------------------------------------------------
	// Person instanziieren
	Person  p1("Mustermann, Max", 19770707, Gender::male);
	// Student instanziieren
	Student s1("Example, Eva Maria", 19970217, Gender::female, 1910581005, "evae@gmail.com");
	// Teacher instanziieren
	Teacher t1("Tempo, Theox", 20010605, Gender::diverse, 8976, "ttempo@fh.co.at");
	// Einf�gen eines Studenten s2 mit den eigenen Daten
	Student s2("Reiter, Antonia", 21051994, Gender::female, 1610555012, "a.reiter.its-b2017@fh-salzburg.ac.at");

	// -------------------------------------------------------------------
	// Testen der Methode getExtSVNr
	auto xsnv = t1.getExtSVNr();

	// Testen der Klasse Email mit Getter und Setter
	auto em = t1.getEmail();

	// -------------------------------------------------------------------
	// Testen der Function to_PrintItemStr aus dem Namensraum PrintExt
	auto st1 = PrintExt::to_PrintItemStr("name", "Milena Klotz");
	auto st2 = PrintExt::to_PrintItemStr("svnr", 1234);

	// -------------------------------------------------------------------
	//  Container f�r Person, Studenten und Teacher bef�llen
	std::vector<std::shared_ptr<Person>> persons; //shared_ptr auf eine Person entgegennehmen und soll persons heißen!
	persons.push_back(std::make_shared<Person>("Mustermann, Max", 19770707, Gender::male));
	persons.push_back(std::make_shared<Student>("Example, Eva Maria", 19970217, Gender::female, 1910581005, "evae@gmail.com"));
	persons.push_back(std::make_shared <Teacher>("Tempo, Theox", 20010605, Gender::diverse, 8976, "ttempo@fh.co.at"));
	persons.push_back(std::make_shared <Student>("Klotz, Milena", 21051994, Gender::female, 1610555012, "m.klotz.its-b2016@fh-salzburg.ac.at"));

	// -------------------------------------------------------------------
	// Wir testen die operator << Methode einzeln f�r jeden Typ
	//std::cout << p1 << std::endl;
	//std::cout << s1 << std::endl;
	//std::cout << t1 << std::endl;

	// -------------------------------------------------------------------
	// Geben Sie in einer Schleife �ber alle Elemente des Container die 
	// einzelnen Elemente so auf cout aus, dass eine Ausgabe passend f�r 
	// den jeweils zugrundeliegenden Typ erfolgt.
	for (auto p : persons) {
		std::cout << *p << std::endl;
	}

	// -------------------------------------------------------------------
	// Alle Nachname in der Collection mit Hilfe von transform() und einer 
	// lambda function in Gro�buchstaben konvertieren

	std::transform(persons.begin(), persons.end(), persons.begin(), [](std::shared_ptr<Person> p) -> auto {
		std::string n = (*p).name; //durch * bekommt man von share_ptr das eigentliche Objekt auf den der ptr zeigt
		size_t found = n.find(','); //comma suchen
		if (found != std::string::npos) { //wenn gefunden
			std::string nn = n.substr(0, found); //Pos 0 bis found
			std::string vn = n.substr(found + 1); //found plus 1 bis zum schluss lesen
			std::transform(nn.begin(), nn.end(), nn.begin(), ::toupper);
			(*p).name = nn + "," + vn; //Ergebnis zuweisen
		}
		return p;
	});

	// [](std::shared_ptr<Person> p) -> auto {return p;}); Lambda Minimalversion, shared_ptr, weil aus Collection

	// -------------------------------------------------------------------
	// Email validieren �ber eigene kleine Validierungsfunktion
	check_email_validation("roland.graf@fh-salzburg.ac.at");
	check_email_validation("@fh-salzburg.ac.at");
	check_email_validation("roland.graf.fh-salzburg.ac.at");
	check_email_validation("roland.graf@");

	std::cout << "Bye!\n";
}


    
