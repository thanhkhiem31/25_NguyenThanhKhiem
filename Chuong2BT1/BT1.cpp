#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "054204001759 - Nguyen Thanh Khiem " << endl;
    ifstream inFile("data.txt");
    if (!inFile.is_open())
    {
        cout << "Can not open this file" << endl;
        return 1;
    }
    string sLine;
    int iCountLines = 0;
    ofstream outFile("data1.txt");
    if (!outFile.is_open())
    {
        cout << "can not open file data for writing " << endl;
        return 1;
    }
    while (getline(inFile, sLine))
    {
        if (!sLine.empty())
        {
            iCountLines++;
        }
    }
    cout << "Số dòng bắt đầu bằng “-”: " << iCountLines << endl;
    inFile.clear();
    inFile.seekg(0);
    while (getline(inFile, sLine))
    {
        if (sLine.compare(0, 1, "-") == 0)
        {
            cout << sLine << endl;
            outFile << sLine.substr(1) << endl;
        }
    }
    cout << "Các dòng bắt đầu bằng “-”:";
    inFile.close();
    outFile.close();
    return 0;
}