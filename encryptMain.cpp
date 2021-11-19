#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#include <array>

/*
  in this file for the minimumm viable product we need to
  take in a file (txt file), convert to ascii values,
  implement the shift and then go from there
*/

std::vector<std::string> names;

char convertToDec(std::string line);

std::string privateKeyGenerator(int length)
{
  std::string indexString;
  std::string outString;
  srand((unsigned int)time(NULL));
  // we create a huge vector, and depending on the length we create the private key
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

int convPrivKey(std::string outString)
{
  convertToDec(outString);
}

void fileInput()
{
  // gets file location input and attempts to open
  std::string fileLocation;
  std::cout << "Please input your file that you wish to encrypt : ";
  std::cin >> fileLocation;
  std::fstream fileOpener(fileLocation, std::ios::in);
}

/*
   ENCRYPTION FUNCTION ABSTRACTION
   the idea for this is to break each line down into characters, get each character and convert to its decimal value
   then shift depending on what the key is

   we'll start by writing a function to convert to decimal based on value.

   and then we will be able to re use this block of code
*/

char convertToDec(std::string line)
{
  int temp;
  for(int i = 0; i < line.size(); i++)
  {
    temp = static_cast<int>(line.at(i));
    std::cout << temp << std::endl;
  }
}



int main()
{
  // main running code
  fileInput();
  std::cout << privateKeyGenerator(4);
  return 0;

}
