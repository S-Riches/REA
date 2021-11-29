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
    for(int i = 0; i < decryptVec.size(); i++)
    {
        decryptLine(decryptVec.at(i), privateKey);
    }
}

std::string decryptLine(std::string line, std::string privateKey)
{
    std::string charArray = line.c_str();
    // write the decryption algorithm when my brain isnt completley fried
    for(int i = 0; i < charArray.length(); i++)
    {
        int tempVal = static_cast<int>(charArray.at(i));
        // get the shift value from the private key
        int shiftAmount = ((convertToDecSum(privateKey)) % 126);
        if(i % 2 == 0)
        {
            if(shiftAmount + tempVal < 126 && shiftAmount + tempVal > 31)
            {
                charArray.at(i) = static_cast<char>(shiftAmount - tempVal); 
            }
            else 
            {


            }
            //added shift needs to be subtracted
        }
        else
        {
            //sub NEEDS ADDITION
        }
        std::cout << charArray.at(i) << std::endl;
    }
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