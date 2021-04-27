//
// Created by dumanoglu on 2.01.2021.
//
#include <vector>
#include <fstream>
#include "TreeNode.h"
#include "HuffmanTree.h"
#include "ReadFile.h"
#include <iterator>
#ifndef UNTITLED5_OPERATIONS_H
#define UNTITLED5_OPERATIONS_H
using namespace std;
class Operations {
public:
    /*encodeOperation function creates nodes with information from the file.Creates the frequency table.
    creates Huffman Tree.Prints the encoded string.Saves the resulting tree to the file(for -l command)*/
    static void encodeOperation(HuffmanTree &huffmanTree,string &str);
    /*decodeOperation function reconstructs the tree using the frequencies saved in the temporary file.
     And it uses tree to decode.*/
    static void decodeOperation(HuffmanTree &huffmanTree,string &str);
    /*The list tree function prints the tree (we previously saved as an intermediate step) to the console.*/
    static void listTreeOperation();
    /*This function returns the huffman code value of a given character.(Uses the previously saved code table in the
     encode.txt)*/
    static void findCodeOfCharacterOperation(const string& character);

private:
    /*Creates the nodes and put in a vector with using the frequency table.
     (The intermediate step of the encodeOperation function)*/
    static void createNodes(string &str, vector<TreeNode*> &nodeVector,map<char,int> &frequencyMap);
    /*Saves the frequency table to a file for later to use in decode operation.
     (The intermediate step of the encodeOperation function)*/
    static void writeFrequencyTableToFile(map<char,int> &frequencyMap);
    /*adds the nodes back from nodeVector to the huffman tree*/
    static void createTreeFromFile(HuffmanTree &huffmanTree,vector<TreeNode*> &vec);
    /*It recreates nodes by reading the frequencies table in the temp file and keeps it in a vector.
     (The intermediate step of the decodeOperation function)*/
    static vector<TreeNode*> createTreeNodesFromFile(vector<string> &vec);
};


#endif //UNTITLED5_OPERATIONS_H
