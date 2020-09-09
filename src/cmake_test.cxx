#include <cmake_test.hxx>

#include <iostream>
#include <vector>
#include <string>

std::string vec2str(std::vector<char> vec_c_str){
  std::string ret_str = "";
  for (auto& character : vec_c_str){
    ret_str.push_back(character);
  }
  std::cout << ret_str;
  return ret_str;
}

std::vector<char> str2vec(std::string str){
  std::vector<char> ret_vec;
  for (auto& letter : str){
    ret_vec.push_back(letter);
  }
  for (auto& character : ret_vec){
    std::cout << character << " ";
  }
  std::cout << "\n";
  return ret_vec;
}
