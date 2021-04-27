#include "HuffmanTree.h"
bool comparator(TreeNode* freq1,TreeNode* freq2){
    //Used to sort the vector according to frequencies when building the tree
    return freq1->countOfOccurrences<freq2->countOfOccurrences;
}

//**********************************************************************************************************************

HuffmanTree::HuffmanTree() {//constructor
    root= nullptr;
}

//**********************************************************************************************************************

void HuffmanTree::insert(vector<TreeNode *> &sortedVector) {
    while(sortedVector.size() != 1){
        /*Each step vector is sorted by frequency, the smallest two elements are taken  from it to build tree.
         stable sort is used to guarantee the addition order of nodes with the same frequency.*/
        stable_sort(sortedVector.begin(),sortedVector.end(),comparator);
        //smallest two elements are taken and combined as one node
        TreeNode* leftChild=sortedVector[0];
        sortedVector.erase(sortedVector.begin());
        TreeNode* rightChild=sortedVector[0];
        sortedVector.erase(sortedVector.begin());
        auto* combinedTree=new TreeNode('\0',leftChild->countOfOccurrences+rightChild->countOfOccurrences,
                                        leftChild,rightChild);
        //put back in the vector to reorder and reused
        sortedVector.push_back(combinedTree);
    }
    //the last node remaining is the combination of all nodes and root of the tree.So we assign it to root.
    root=sortedVector.front();
    sortedVector.erase(sortedVector.begin());
}

//**********************************************************************************************************************

string HuffmanTree::encode(string& str) {
    /*encode function encodes the characters with using inorder traversal, it puts the huffman codes in the map.
    Then using this map it finds codes of characters and combines this codes as a one encoded string and returns it.*/
    string encodedString;
    map<char,string> encodedMap;
    TreeNode* temp=root;
    //codes tree with using inorder traversal
    inOrderTraversalEncode(temp,encodedMap,"");
    writeCodeTableToFile(encodedMap);
    //finds codes in the map and combines
    for(char & chr : str){
        encodedString+=encodedMap[chr];
    }
    return encodedString;
}

void HuffmanTree::inOrderTraversalEncode(TreeNode* tempRoot,map<char,string> &encodedMap,const string& str) {
    /*encodes the tree by recursively assigning 0 to the left child and 1 to the right child, in the inorder
     traversal direction.If node is leaf, it puts in encode map.*/
    if(tempRoot!= nullptr){
        inOrderTraversalEncode(tempRoot->leftChildPtr,encodedMap,str+"0");
        if(tempRoot->leftChildPtr== nullptr && tempRoot->rightChildPtr== nullptr){
            encodedMap[tempRoot->character]=str;
        }
        inOrderTraversalEncode(tempRoot->rightChildPtr,encodedMap,str+"1");
    }
}

void HuffmanTree::writeCodeTableToFile(map<char,string> &encodedMap){
    /*It saves the encoded table to encode.txt so that we can use it in the -s operation.*/
    ofstream  myFile;
    myFile.open("encode.txt");
    map<char,string>::iterator itr ;
    //saving format: character \t code
    for(itr=encodedMap.begin();itr!=encodedMap.end();++itr){
        myFile<<itr->first<<"\t"<<itr->second<<endl;
    }
}

//**********************************************************************************************************************

void HuffmanTree::buildTreeByRecursion(const string &space, const TreeNode *tempRoot, bool left,vector<string> &tree) {
    if( tempRoot != nullptr ){
        tree.push_back(space);//space: sets the space between children and their parents.
        tree.emplace_back(left ? "├──>" : "└──>" );
        //if a node has no child it means that it is leaf
        if(tempRoot->leftChildPtr== nullptr && tempRoot->rightChildPtr== nullptr&& tempRoot!=root){
            //position of leaf sets.
            tree.emplace_back((left ? "left leaf":"right leaf"));
            //frequency of leaf and it is character sets.
            tree.push_back("("+to_string(tempRoot->countOfOccurrences)+")"+'"'+tempRoot->character+'"'+"\n");
        }
        else{
            if(tempRoot==root && root->rightChildPtr== nullptr && root->leftChildPtr == nullptr){
                //if only one character it means that it is the root it writes root and it is frequency and character
                tree.push_back("root("+to_string(tempRoot->countOfOccurrences)+")"+'"'+tempRoot->character+'"'+"\n");

            }
            else if(tempRoot==root){
                //it writes root and it is frequency(it has no character value)
                tree.push_back("root("+to_string(tempRoot->countOfOccurrences)+")"+"\n");
            }
            else{
                //it writes left and right branches and their frequencies(they have no character value)
                tree.emplace_back((left ? "left branch":"right branch"));//position of branch sets.
                tree.push_back("("+to_string(tempRoot->countOfOccurrences)+")"+"\n");
            }
        }
        buildTreeByRecursion( space+  (left ? "│        " : "        "), tempRoot->leftChildPtr, true,tree);
        buildTreeByRecursion( space + (left ? "│        " : "        "), tempRoot->rightChildPtr, false,tree);
    }
}

void HuffmanTree::writeTreeToFile(){
    /*writeTreeToFile function writes the tree to the tree.txt file in a recursive way, first left side written then
    right side.*/
    ofstream myFile;
    myFile.open("tree.txt");
    vector<string> tree;
    TreeNode* tempRoot=root;
    buildTreeByRecursion("", tempRoot, false,tree);
    for(auto & i : tree){
        myFile<<i;
    }
}

//**********************************************************************************************************************

void HuffmanTree::decode(string&str) {
    TreeNode* tempRoot=root;
    recursiveDecode(tempRoot,str);
}

void HuffmanTree::recursiveDecode(TreeNode *tempRoot, string &str) {
    /*in the given string code,if digit is 0 ,it goes to the left and if it is 1, it goes to the right.
     when reach the leaf node it writes it on the console.If the encode characters
     still exists, it starts the process from the beginning until no code left.*/
    if(tempRoot->rightChildPtr== nullptr&&tempRoot->leftChildPtr==nullptr){
        cout<<tempRoot->character;
        if(!str.empty()){
            decode(str);
        }
        return;
    }
    else{
        if(str[0]=='0'){
            str.erase(0,1);
            recursiveDecode(tempRoot->leftChildPtr,str);

        }
        else{
            str.erase(0,1);
            recursiveDecode(tempRoot->rightChildPtr,str);
        }
    }
}

//**********************************************************************************************************************

void HuffmanTree::destroyRecursive(TreeNode* node){
    //recursively delete first left children , then right children when it reaches to leaves
    if(node!= nullptr){
        destroyRecursive(node->leftChildPtr);
        destroyRecursive(node->rightChildPtr);
        delete node;
    }
}

HuffmanTree::~HuffmanTree(){
    //destructor
    destroyRecursive(root);
}

