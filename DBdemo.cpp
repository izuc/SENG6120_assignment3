// Filename: DBdemo.cpp
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "MechPart.h"
#include "BTNode.h"
#include "BTree.h"
#include "DBinterface.h"

using namespace std;
using lance_project::MechPart;
using lance_project::BTNode;
using lance_project::BTree;
using lance_project::DBinterface;

int main() {
	DBinterface* interface = new DBinterface();
	
	interface->menu();
	
	//cout << "------------------------------------------------" << endl;
	//cout << "Print all" << endl;
	//cout << "------------------------------------------------" << endl;
	
	//interface->display();
	return 0;
}
