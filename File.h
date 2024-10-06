#ifndef FILE_H
#define FILE_H

#include <string>
#include "Date.h"

using namespace std;

class File {
	public:
		// constructor
		File();
		File(const string& name, const string& content, Date& date);

		const string& getName();
		Date getDate();
		
		// others
		bool lessThan(File& f);
		void print();
		void printContents();

	private:
		string name;
		string content;
		Date date;
};

#endif