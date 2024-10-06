#ifndef REPO_H
#define REPO_H

#include "FileList.h"

class Repo {
	public:
		// constructor
		Repo(const string& title, const string& owner);
		
		// destructor
		~Repo();

		// others

		const string& getTitle();
		const string& getOwner();

		bool lessThan(Repo& r);
		bool addFile(const string& name, const string& content, Date& date);
		bool removeFile(int index);
		int getNumFiles();
		void print();
		void printFiles();
		void printContents(int index);

	private:
		string title;
		string owner;
		FileList* fl;
};

#endif