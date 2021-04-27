//
// Created by dumanoglu on 21.12.2020.
//

#ifndef UNTITLED5_TREENODE_H
#define UNTITLED5_TREENODE_H


class TreeNode {
    /*This class belongs to the tree nodes of the huffman tree*/
public:
    //character data & frequency data
    char character='\0';
    int countOfOccurrences=0;
    // pointer to left child & right child
    TreeNode *leftChildPtr= nullptr;
    TreeNode *rightChildPtr= nullptr;
    //constructor
    TreeNode(char chr,int frequency,TreeNode* leftChildPtr,TreeNode* rightChildPtr);
};



#endif //UNTITLED5_TREENODE_H
