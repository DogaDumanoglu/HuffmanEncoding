//
// Created by dumanoglu on 20.12.2020.
//

#ifndef UNTITLED5_HUFFMANTREE_H
#define UNTITLED5_HUFFMANTREE_H
#include "TreeNode.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
class HuffmanTree {
public:
    /*constructor & destructor*/
    HuffmanTree();
    ~HuffmanTree();
    /*insert function combines two elements from the beginning by ordering the vector at each step until the
     tree is formed.*/
    void insert(vector<TreeNode*> &sortedVector );
    /*encode function encodes the characters with using inorder traversal, it puts the huffman codes in the map.
     Then using this map it finds codes of characters and combines this codes as a one encoded string and returns it.*/
    string encode(string& str);
    /*writeTreeToFile function writes the tree to the tree.txt file in a recursive way, first left side written then
     right side.*/
    void writeTreeToFile();
    /*decode function recursively decodes the given cod.*/
    void decode(string& str);

private:
    TreeNode* root;
    /*inOrderTraversalEncode (helps encode function )encodes the tree by recursively assigning 0 to the left child and
     1 to the right child, in the inorder traversal direction.If node is leaf, it puts in encode map.*/
    void inOrderTraversalEncode(TreeNode* tempRoot,map<char,string> &encodedMap,const string& str);
    /*writeCodeTableToFile function saves the encoded table to encode.txt so that we can use it in the -s operation.*/
    static void writeCodeTableToFile(map<char,string> &encodedMap);
    /*buildTreeByRecursion function recursively lists the tree. It specifies the root, right branch, left branch, right leaf, and left leaf.*/
    void buildTreeByRecursion(const string& space, const TreeNode* tempRoot, bool left,vector<string> &tree);
    /*recursiveDecode:in the given string code,if digit is 0 ,it goes to the left and if it is 1, it goes to the right.when reach the
     leaf node it writes it on the console.If the encode characters still exists, it starts the process from the
     beginning until no code left.(helps decode function.)*/
    void  recursiveDecode(TreeNode* tempRoot,string &str);
    /*destroyRecursive recursively delete first left children , then right children when it reaches to leaves.(Helps destructor).*/
    void destroyRecursive(TreeNode* node);
};



#endif //UNTITLED5_HUFFMANTREE_H





