#include "easyfind.hpp"

int main () {
  std::array<int , 1>myarray = {1};
  // std::vector<int> myvector(4,122);
  std::cout << easyfind(myarray, 122) << std::endl;
}