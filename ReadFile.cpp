//
// Created by dumanoglu on 25.12.2020.
//

#include "ReadFile.h"
#include <algorithm>
string ReadFile::readFromInputFile(const string &fileName) {
    ifstream myFile;
    string str;
    vector<string> infoVector;
    myFile.open(fileName);
    while(!myFile.eof()){//until the end of the file
        while(getline(myFile,str)){//reads line by line
            for_each(str.begin(),str.end(), [](char & c) {
                c = tolower(c);//lowercase all letters
            });
            infoVector.push_back(str);//pushes in a vector (for multilines)
        }
    }
    string result;
    for(auto & info : infoVector){
       result=result+info; //converts all strings to one string in the vector
    }
    myFile.close();
    return result;

}
vector<string> ReadFile::readFromAuxiliaryFiles(const string& fileName) {
    ifstream myFile;
    vector<string> vector;
    myFile.open(fileName);
    string info;
    if(myFile.is_open()){
        while(!myFile.eof()){
            while(getline(myFile,info)){//reads line by line
                vector.push_back(info);//pushes in a vector (for multilines)
            }
        }
    }
    myFile.close();
    return vector;
}
