#include <iostream>
#include "HuffmanTree.h"
#include "ReadFile.h"
#include "Operations.h"
using namespace std;
int main(int argc, char *argv[]) {
    if(string(argv[1])=="-i"){//input file
        HuffmanTree huffmanTree;
        string str=ReadFile::readFromInputFile(argv[2]);
        if(string(argv[3]) =="-encode"){//encode
            Operations::encodeOperation(huffmanTree,str);
        }
        else if(string(argv[3]) =="-decode"){//decode
            Operations::decodeOperation(huffmanTree,str);
        }
    }
    else if(string(argv[1]) =="-l"){//list tree
        Operations::listTreeOperation();
    }
    else if(string(argv[1]) =="-s"){//code of given char
        if(argc==3){
            Operations::findCodeOfCharacterOperation(argv[2]);
        }
        else if(argc==2){
            Operations::findCodeOfCharacterOperation(" ");
        }
    }
}
