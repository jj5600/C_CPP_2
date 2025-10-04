#include <iostream>
#include <fstream>
using namespace std;
void OpenFileBinary(const char *fileName, ifstream &inFile)
{
    // attempt to open the file to read in binary format
    inFile.open(fileName, ios_base::binary);
    // test to see if opening the file succeeded
    if(!inFile.is_open())
    {
        cerr << "Failed to open: "<< fileName<<endl;
        exit(EXIT_FAILURE);
    }

}
