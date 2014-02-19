// Filename: MechPart.h
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_MECHPART_H
#define LANCE_MECHPART_H
namespace lance_project {
	class MechPart {
		public:
			// The default constructor.
			MechPart();
			// The default constructor.
			MechPart(std::string code);
			// The constructor recieves the name, and quantity.
			MechPart(std::string code, std::string name, int quantity);
			// Setter for the code.
			void setCode(std::string code);
			// Setter for the name.
			void setName(std::string name);
			// Setter for the grade.
			void setQuantity(int quantity);
			// Getter for the code.
			std::string getCode();
			// Getter for the name.
			std::string getName();
			// Getter for the grade.
			int getQuantity();
			// Compare to
			int compareTo(MechPart* mechPart);
		private:
			std::string code;
			std::string name;
			int quantity; 
	};

	std::ostream & operator<<(std::ostream & out, MechPart* mechPart);
}
#endif
