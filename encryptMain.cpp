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
    return outString;
  }
}

void fileInput(int val)
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
}

/*
   ENCRYPTION FUNCTION:
   we split the file into lines, reading each char in the line, and storing in an array
   then we check if the index of the array for each is divisiable by 2, if true we do
   a modulus of the key value, and either subtract the remainder (+32 to the value to keep the chars visible) or add it to change the value.
*/

std::string encryptFunc(std::string line, int keyAmount)
{
  // each line
  std::string charToString;
  // make line to char array
  charToString = line.c_str();
  // for each element in the array
  int shiftAmount = (keyAmount % 128); 
  for(int i = 0; i < charToString.length(); i++)
  {
    int tempVal;
    // convert to dec
    tempVal = static_cast<int>(charToString.at(i));
    if(i % 2 == 0)
    {
      std::cout << charToString.at(i) <<" is even" << std::endl; 
      if(shiftAmount + tempVal < 128)
      {
        charToString.at(i) = static_cast<char>(shiftAmount + tempVal);
      }
      else
      {
        int tempMod = ((shiftAmount + tempVal) % 128) + 32;
        charToString.at(i) = static_cast<char>(tempMod);
      }
      std::cout << "\nnew value is : " << charToString.at(i) << std::endl << "\n";
      // add
    }

    else
    {
      std::cout << charToString.at(i) << " is odd" << std::endl; 
      if(shiftAmount + tempVal < 128)
      {
        charToString.at(i) = static_cast<char>(shiftAmount-tempVal);
      }
      else
      {
        int tempMod = ((shiftAmount - tempVal) % 128 + 32);
        charToString.at(i) = static_cast<char>(tempMod);
      }
      std::cout << "\nnew value is : " << charToString.at(i) << std::endl << "\n";
      //sub
    }
  }
  std::cout << "the string was : " << line << std::endl;
  std::string outStr(charToString);
  std::cout << "the string is now : " << outStr << std::endl;
  return outStr;
}

int convertToDecSum(std::string line)
{
  int temp;
  int out;
  for(int i = 0; i < line.size(); i++)
  {
    temp = static_cast<int>(line.at(i));
    out += temp;
  }
  return out;
}

int main()
{
  // main running code
  std::string key = privateKeyGenerator(4);
  int val = convertToDecSum(key);
  fileInput(val);
  std::cout << "Your private key is : " << key << std::endl;

  for(int i = 0; i < tempHolder.size(); i++)
  {
    std::cout << encryptFunc(tempHolder.at(i), val);
    
  }
  return 0;
}
