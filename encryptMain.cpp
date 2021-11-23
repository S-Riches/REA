/*
   PROGRAM TITLE : ENCRYPTION PROGRAM;
   we split the file into lines, reading each char in the line, and storing in an array
   then we check if the index of the array for each is divisiable by 2, if true we do
   a modulus of the key value, and either subtract the remainder or add it to change the value.
*/

#include <iostream>
#include "decs.h"

//stores the names to be indexed
std::vector<std::string> names;
std::vector<std::string> tempHolder;

// generates the private key
std::string privateKeyGenerator(int length)
{
  std::string indexString;
  std::string outString;
  srand((unsigned int)time(NULL));
  // we create a huge vector, and depending on the length given we create the private key
  std::fstream nameFile("words.txt");
  if(nameFile.is_open())
  {
    while(getline(nameFile, indexString))
    {
      names.push_back(indexString);
    }
    for(int i = 0; i < length; i++)
    {
      std::string temp;
      temp = names[rand() % names.size() + 1];
      outString.append(temp);
    }
    nameFile.close();
  }
  return outString;
}

std::string fileInput(int val)
{
  // gets file location input and attempts to open
  std::string tempLine;
  std::string fileLocation;
  std::cout << "Please input your file that you wish to encrypt : ";
  std::cin >> fileLocation;
  std::fstream fileOpener(fileLocation, std::ios::in);
  if(fileOpener.is_open())
  {
    while(std::getline(fileOpener, tempLine))
    {
      tempHolder.push_back(tempLine);
    } 
  }
  return fileLocation;
}


std::string encryptFunc(std::string line, int keyAmount)
{
  // needed to redesign how the encryption works
  std::string charToString;
  charToString = line.c_str();
  for(int i = 0; i < charToString.length(); i++)
  {
    int tempVal = static_cast<int>(charToString.at(i));
    if(i % 2 == 0)
    {

      // we do 126 as 127 is ascii for delete
      // shift forward down the ring of chars
      if(tempVal < 126 && tempVal > 31) 
      {
        int newAsciiVal = tempVal + (keyAmount % 126);
        if(newAsciiVal > 126)
        {
          int tempFix;
          tempFix = newAsciiVal % 126;
          newAsciiVal = 31 + tempFix;
        }
        std::cout << newAsciiVal << std::endl;
        charToString.at(i) = static_cast<char>(newAsciiVal);
        // need to output this to a return string
      }
    }
    else
    {
      if(tempVal < 126 && tempVal > 31)
      {
        int newAsciiVal = tempVal - (keyAmount % 126);
        if(newAsciiVal < 31)
        {
          if(newAsciiVal < 0)
          {
            newAsciiVal = 126 + newAsciiVal;
          }
          else
          {
            newAsciiVal = 126 - newAsciiVal;
          }
          std::cout << newAsciiVal << std::endl;
        }
        else
        {
          std::cout << newAsciiVal << std::endl;
          charToString.at(i) = static_cast<char>(newAsciiVal);
        }
      }
      // shift backward down the ring of chars

    }
  }
  std::string out(charToString);
  return out;
}

void outFile(int val, std::string fileName)
{
  std::string pushingString;
  std::vector<std::string> outFile;
  for(int i = 0; i < tempHolder.size(); i++)
  {
     pushingString = encryptFunc(tempHolder.at(i), val);
     outFile.push_back(pushingString);
  }
  std::remove(fileName.c_str());
  std::fstream newFile (fileName);
  // ios out refers the file for output functions
  newFile.open(fileName, std::ios::out);
  if(newFile.is_open())
  {
    for(int i = 0; i < outFile.size(); i++)
    {
      // debug : std::cout << outFile.at(i) << std::endl;
      newFile << outFile.at(i) << std::endl;

    }
    newFile.close();
  }
  else
  {
    std::cout << "Error occured when creating file?" << std::endl;
  }
}

int main()
{
  // main running code
  std::cout << "please make sure you save the private key at the bottom to decrypt the file" << std::endl;
  std::string key = privateKeyGenerator(4);
  int val = convertToDecSum(key);
  // store file name after input
  std::string fileloc = fileInput(val);
  //shows private key
  std::cout << "\nYour private key is : " << key << std::endl;
  // run encryption
  outFile(val, fileloc);
  
  return 0;
}
