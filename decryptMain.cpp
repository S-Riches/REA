/*
    PROGRAM TITLE : DECRYPTOR PROGRAM;
    this file is the decryptor for the encryption algorithm, the 
    user needs to put in the private key to allow the program to
    be able to decrypt it.
*/

#include <iostream>
#include "decs.h"

// Declarations
std::string privateKey;
std::string fileLoc;

void decryptLoop(std::string privateKey, std::string fileLoc)
{
    // Declaration
    std::string tempLine;
    std::fstream encryptedFile(fileLoc, std::ios::in);
    std::vector<std::string> decryptVec;

    if(encryptedFile.is_open())
    {
        while (getline(encryptedFile, tempLine))
        {
            decryptVec.push_back(tempLine);
        }
        for(int i = 0; i < decryptVec.size(); i++)
        {
            std::cout << decryptVec.at(i) << std::endl;
        }
    }
}

char decryptLine(std::string line)
{
    std::string test = line.c_str();
    
}

int main()
{
    // get shift value from key
    std::cout << "Please input the private key : ";
    std::cin >> privateKey;
    std::cout << convertToDecSum(privateKey);
    std::cout << "\nPlease input the encrypted file name : ";
    std::cin >> fileLoc;
    decryptLoop(privateKey, fileLoc);

    return 0;
}