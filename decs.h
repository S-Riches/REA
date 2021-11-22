#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#include <array>
#include <cstdio>
#include <numeric>

/*
  in this file for the minimumm viable product we need to
  take in a file (txt file), convert to ascii values,
  implement the shift and then go from there
*/

int convertToDecSum(std::string line);
std::string encryptWord(std::string line, int keyAmount);

// converts strings to decimal then sums them (used for the private key)
int convertToDecSum(std::string line)
{
  int temp;
  int out;
  std::vector<int> vals;
  for(int i = 0; i < line.size(); i++)
  {
    temp = static_cast<int>(line.at(i));
    vals.push_back(temp);
  }
  // used to sum all decimal values in the vector, better then the old method of doing so as it wasnt working as expected.
  out = std::accumulate(vals.begin(), vals.end(), decltype(vals)::value_type(0));
  return out;
}