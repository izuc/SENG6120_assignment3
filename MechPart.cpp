// Filename: MechPart.cpp
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include<iostream>
#include<cstdlib>
#include "MechPart.h"

using namespace std;
using lance_project::MechPart;

namespace lance_project {

	// The default constructor.
	MechPart::MechPart() {
	
	}
	
	MechPart::MechPart(string code) {
		this->code = code;
	}
	
	// The constructor accepts the name, and grade.
	MechPart::MechPart(string code, string name, int quantity) {
		this->code = code;
		this->name = name;
		this->quantity = quantity;
	}
	
	// Setter for the name attribute.
	void MechPart::setName(string name) {
		this->name = name;
	}
	
	// Setter for the quantity attribute.
	void MechPart::setQuantity(int quantity) {
		this->quantity = quantity;
	}
	
	// Getter for the code attribute.
	string MechPart::getCode() {
		return this->code;
	}
	
	// Getter for the name attribute.
	string MechPart::getName() {
		return this->name;
	}
	
	// Getter for the grade attribute.
	int MechPart::getQuantity() {
		return this->quantity;
	}
	
	// The compareTo method receives a MechPart to compare the name with.
	int MechPart::compareTo(MechPart* object) {
		return this->getCode().compare(object->getCode());
	}
	
	// The overloaded print operator, prints out the name & grade.
	ostream & operator<<(ostream & out, MechPart* object) {
		out.width(20);
		out << object->getCode();
		out.width(60);
		out << object->getName();
		out.width(3);
		out << object->getQuantity();
		return out;
	}
}
