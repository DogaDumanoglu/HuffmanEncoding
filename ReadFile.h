//
// Created by dumanoglu on 25.12.2020.
//

#ifndef UNTITLED5_READFILE_H
#define UNTITLED5_READFILE_H
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class ReadFile {
    /*This class is for reading all used files and preparing them for operations.*/
public:
    /*readFromInputFile function reads the string in the file and returns the string by converting its letters to lowercase.*/
    static string readFromInputFile(const string& fileName);
    /*readFromAuxiliaryFiles function takes the information in the given file and puts it into the vector.
    Used for auxiliary files*/
    static vector<string> readFromAuxiliaryFiles(const string& fileName);
};


#endif //UNTITLED5_READFILE_H
