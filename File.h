#ifndef FILE_H
#define FILE_H

#include <string>
#include "Date.h"

using namespace std;

class File {
	public:
		// constructor
		File(string name, string content, Date& date);
		
		// others
		bool lessThan(Date& d);
		void print();
		void printContents();

	private:
		string fileName;
		string fileContent;
		Date fileDate;
};

#endif