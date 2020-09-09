#include <cmake_test.hxx>

#include <iostream>
#include <vector>
#include <string>

int main() {
  std::cout << "Please enter a sequence of chars" << "\n" << ">";
  std::vector<char> charvec;
  char chr_in;
  while(std::cin >> chr_in){
    charvec.push_back(chr_in);
  }
  std::cout << vec2str(charvec);
  return 0;
}
