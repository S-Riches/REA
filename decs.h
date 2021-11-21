#pragma once

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

char convertToDec(std::string line);
int convertToDecSum(std::string line);
int convPrivKey(std::string outstring);
void encryptWord(std::string line, int keyAmount);