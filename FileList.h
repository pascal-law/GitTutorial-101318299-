#ifndef FILELIST_H
#define FILELIST_H

#include "defs.h"
#include "File.h"

class FileList {
	public:
		//constructor
		FileList();
				
		//destructor
		~FileList();
		
		//other
		bool add(File* f);
		File* get(const string& name);
		File* get(int index);
		File* remove(const string& name);
		File* remove(int index);
		int size();
		bool isFull();
	
	private:
		int numFiles;
		File** fileList;
};


#endif