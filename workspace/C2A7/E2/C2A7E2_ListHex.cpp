#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void ListHex(ifstream &inFile, int bytesPerLine)
{
    int readIn;
    // set output formatting to hex.
    cout << hex;
    // inFile.get returns a INT !
    int byteCounter =0;
    // keep reading in a byte until the EOF is reached
    while((readIn = inFile.get())!= EOF)
    {
        // keep track of byte count, once met newline and restart count
        if(byteCounter == bytesPerLine)
        {
            cout << "\n";
            byteCounter =0;
        }
        cout << setw(2) << setfill('0') <<readIn <<" ";
        byteCounter++;
    }
}
