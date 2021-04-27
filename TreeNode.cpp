//
// Created by dumanoglu on 21.12.2020.
//

#include "TreeNode.h"


TreeNode::TreeNode(char chr, int frequency,TreeNode* leftChild,TreeNode* rightChild) {
    this->character = chr;
    this->countOfOccurrences=frequency;
    // Left and right child for node
    this->leftChildPtr=leftChild;
    this->rightChildPtr =rightChild;
}