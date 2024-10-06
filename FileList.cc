#include "FileList.h"

FileList::FileList() {
	numFiles = 0;
	fileList = new File*[MAX_ARRAY];
}
	
FileList::~FileList() {
	// each fileList[i] (there are numFiles of them) has been created in the FileList::add(File* f) function
	// (should be a "new", otherwise the param would not be of File* type)
	for (int i = 0; i < numFiles; i++) {
		delete fileList[i];
	}
	// delete the fileList array of MAX_ARRAY File pointers, which was created using "new" in the constructor and is of type File**
	delete [] fileList;
}

bool FileList::add(File* f){
	if (numFiles >= MAX_ARRAY) return false;
	for (int i = numFiles; i > 0; --i){
		if (f->lessThan(*fileList[i-1])){
			fileList[i] = fileList[i-1];
		}else{
			fileList[i] = f;
			++numFiles;
			return true;
		}
	}
	// if we get here, f is the smallest element
	fileList[0] = f;
	++numFiles;
	return true;
 
}

File* FileList::get(const string& name) {
	for (int i = 0; i < numFiles; ++i){
        if (fileList[i]->getName() == name){
            return fileList[i];
        }
    }
    return nullptr;
}

File* FileList::get(int index) {
	if (index < 0 || index >= numFiles) return nullptr;
	return fileList[index];
}

File* FileList::remove(const string& name) {
	int index = 0;
	while (!(fileList[index]->getName() == name) && index < numFiles) {
		++index;
	}
	return remove(index);
}

File* FileList::remove(int index){
	if (index < 0 || index >= numFiles) return nullptr;
	File* f = fileList[index];
	while (index < numFiles - 1) {
		fileList[index] = fileList[index + 1];
		++index;
	}
	--numFiles;
	return f;
}

int FileList::size(){
	return numFiles;
}

bool FileList::isFull(){
	return numFiles >= MAX_ARRAY;
}