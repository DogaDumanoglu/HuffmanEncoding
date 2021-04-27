//
// Created by dumanoglu on 2.01.2021.
//

#include "Operations.h"

void Operations::encodeOperation(HuffmanTree &huffmanTree,string &str) {
    vector<TreeNode*> sortedVector;
    map<char,int>frequencyMap;
    createNodes(str,sortedVector,frequencyMap);//Creates nodes with information from the file.
    writeFrequencyTableToFile(frequencyMap);//creates the frequency table
    huffmanTree.insert(sortedVector);//Huffman creates Tree
    cout<<huffmanTree.encode(str);//prints the encoded string
    huffmanTree.writeTreeToFile();//saves resulting tree to tree.txt
}

void Operations::createNodes(string &str, vector<TreeNode*> &nodeVector,map<char,int> &frequencyMap){
    for(char & chr : str){
        frequencyMap[chr]++;
    }

    //using the frequency table creates the nodes
    map<char,int>::iterator itr ;
    for(itr=frequencyMap.begin();itr!=frequencyMap.end();++itr){
        auto *treeNode=new TreeNode(itr->first,itr->second, nullptr, nullptr);
        nodeVector.push_back(treeNode);
    }
}

void Operations::writeFrequencyTableToFile(map<char,int> &frequencyMap){
    ofstream  myFile;
    myFile.open("temp.txt");
    map<char,int>::iterator itr ;
    //save frequency table to file for decode operation
    for(itr=frequencyMap.begin();itr!=frequencyMap.end();++itr){
        //format: character \t frequency
        myFile<<itr->first<<"\t"<<itr->second<<endl;
    }
}

//**********************************************************************************************************************

void Operations::decodeOperation(HuffmanTree &huffmanTree, string &str) {
    vector<string> frequencyVector=ReadFile::readFromAuxiliaryFiles("temp.txt");
    vector<TreeNode*>nodeVector=createTreeNodesFromFile( frequencyVector);
    createTreeFromFile(huffmanTree,nodeVector);//recreates the tree
    huffmanTree.decode(str);//decodes the string with using tree
}

vector<TreeNode *> Operations::createTreeNodesFromFile(vector<string> &vec) {
    vector<TreeNode*> treeNodes;
    for(auto & i : vec){
        int pos=i.find('\t');//finds tab's position
        if(pos!=-1){
            char c=i.substr(0,pos).c_str()[0];//character
            auto* treeNode=new TreeNode(c/*character*/, stoi(i.substr(pos+1,i.length()))/*frequency*/, nullptr,
                                        nullptr);
            treeNodes.push_back(treeNode);
        }
    }
    return  treeNodes;
}
void Operations::createTreeFromFile(HuffmanTree &huffmanTree,vector<TreeNode *> &nodeVector) {
    huffmanTree.insert(nodeVector);
}
//**********************************************************************************************************************

void Operations::listTreeOperation() {//Print the previously saved tree from the tree.txt
    vector<string> vector=ReadFile::readFromAuxiliaryFiles("tree.txt");
    for(auto & i : vector){
        cout<<i<<endl;
    }
}

//**********************************************************************************************************************

void Operations::findCodeOfCharacterOperation(const string& character) {
    vector<string> vector=ReadFile::readFromAuxiliaryFiles("encode.txt");
    for(auto & i : vector){
        int pos=i.find('\t');
        if(pos!=-1){
            string c=i.substr(0,pos);/*character*/
            if( character == c){//If it finds the character, it prints the code.
                cout << i.substr(pos + 1, i.length());//code value of given char
            }
        }
    }
}

