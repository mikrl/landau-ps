#include <cmake_test.hxx>

#include <iostream>
#include <vector>
#include <string>

std::string vec2str(std::vector<char> vec_c_str){
  std::string ret_str = "";
  for (auto& character : vec_c_str){
    ret_str.push_back(character);
  }
  return ret_str;
}

std::vector<char> str2vec(std::string str){
  std::vector<char> ret_vec;
  for (auto& letter : str){
    ret_vec.push_back(letter);
  }
  return ret_vec;
}
