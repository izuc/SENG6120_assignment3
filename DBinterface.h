// Filename: DBinterface.h
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_DBINTERFACE_H
#define LANCE_DBINTERFACE_H
namespace lance_project {
	class DBinterface {
		public:
			DBinterface();
			void menu();
			void display();
		private:
			void read();
			void update();
			void statistics();
			void search();
			int calculateTotal(BTNode<MechPart>* node);
			int comparisons(BTNode<MechPart>* node);
			void openfile(std::ifstream& is);
			BTree<MechPart>* tree;
	};
}
#endif


