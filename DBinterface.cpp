// Filename: DBinterface.cpp
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include<iostream>
#include "MechPart.h"
#include "BTNode.h"
#include "BTree.h"
#include "DBinterface.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using lance_project::MechPart;
using lance_project::BTNode;
using lance_project::BTree;
using lance_project::DBinterface;

namespace lance_project {
	DBinterface::DBinterface() {
		this->tree = new BTree<MechPart>();
	}
	
	void DBinterface::openfile(ifstream& is) {
		bool open = false;
		do {
			cout << "Open file: " << endl;
			string filename;
			cin >> filename;
			is.open(filename.c_str());
			open = is.is_open();
			if (!open) {
				cout << endl << "File not found." << endl;
			}
		} while(!open);
	}
	
	void DBinterface::read() {
		ifstream infile;
		this->openfile(infile);
		
		std::string line;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);
			std::string code;
			std::string name;
			int quantity;
			if (iss >> code >> name >> quantity) {
				std::replace( name.begin(), name.end(), '_', ' ');
				this->tree->insert(new MechPart(code, name, quantity));
			}
		}
		
		cout << endl << endl << "Loaded successfully." << endl << endl;
	}
	
	void DBinterface::update() {
		ifstream infile;
		this->openfile(infile);
		
		std::string line;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);
			std::string code;
			int quantity;
			
			if (iss >> code >> quantity) {
				MechPart* obj = this->tree->search(this->tree->getRoot(), new MechPart(code));
				if (obj != NULL) {
					obj->setQuantity(obj->getQuantity() + quantity);
					if (obj->getQuantity() == 0) {
						this->tree->remove(obj);
					}
				}
			}
		}
		
		cout << endl << endl << "Successfully updated." << endl << endl;
	}
	
	int DBinterface::calculateTotal(BTNode<MechPart>* node) {
			int total = 0;
			if (node != NULL) {
				total = node->getData()->getQuantity();
				// traverses down the left branch, adding the returned total
				total += calculateTotal(node->getLeft());
				// traverses down the right branch, adding the returned total
				total += calculateTotal(node->getRight());
			}
			return total; // returns the total.
	}
	
	void DBinterface::statistics() {
		int size = this->tree->getSize();
		cout << endl << "Different Parts: " << size << endl;
		cout << "Total Quantity: " << this->calculateTotal(this->tree->getRoot()) << endl << endl;
	}
	
	// The comparisons method is used to add the total amount of comparisons it takes
	// to find a specific node. It traverses the entire tree, invoking the calcSearchDepth
	// method to find the amount it takes.
	int DBinterface::comparisons(BTNode<MechPart>* node) {
		int total = 0;
		if (node != NULL) {
			// Sets the total to the returned value from the calcSearchDepth method.
			total = this->tree->calcSearchDepth(this->tree->getRoot(), node->getData());
			// traverses down the left branch, adding the returned total 
			total += this->comparisons(node->getLeft());
			// traverses down the right branch, adding the returned total
			total += this->comparisons(node->getRight());
		}
		return total; // returns the total.
	}
	
	
	void DBinterface::search() {
		ifstream infile;
		this->openfile(infile);
		
		std::string line;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);
			std::string code;
			
			if (iss >> code) {
				if (code != "Code") {
					MechPart* obj = this->tree->search(this->tree->getRoot(), new MechPart(code));
					if (obj != NULL) {
						cout << obj << endl;
					} else {
						cout.width(20);
						cout << code;
						cout.width(60);
						cout << "";
						cout.width(3);
						cout << 0 << endl;
					}
				}
			}
		}
		
		int size = this->tree->getSize();
		if (size > 0) {
			cout << endl << "Average number of comparisons: " << (this->comparisons(this->tree->getRoot()) / this->tree->getSize()) << endl;
		}
		cout << endl;
	}
	
	void DBinterface::menu() {
		bool menu = true;
		do {	
			cout << "1) Read current inventory file" << endl;
			cout << "2) Read/Exec monthly update file" << endl;
			cout << "3) Display statistics" << endl;
			cout << "4) Search list items file" << endl;
			cout << "5) Quit" << endl;
			cout << endl << "Enter a menu Option: " << endl;
			
			std::string option;
			cin >> option;
			
			if (!option.empty() && option.find_first_not_of("0123456789") == std::string::npos) {
				std::istringstream ss(option);
				int menu_option;
				ss >> menu_option;
				
				switch (menu_option) {
					case 1:
						this->read();
						break;
					case 2:
						this->update();
						break;
					case 3:
						this->statistics();
						break;
					case 4:
						this->search();
						break;
					case 5:
						menu = false;
						break;
					default:
						cout << endl << "Invalid option" << endl;
						break;
				}
			}
		} while (menu);	
	}
	
	void DBinterface::display() {
		this->tree->print(this->tree->getRoot());
	}
}
