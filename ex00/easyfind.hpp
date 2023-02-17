#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

template<class Iterator> Iterator find (Iterator first, Iterator last, int val)
{
  while (first!=last) {
    if (*first == val)
        return first;
    first++;
  }
  return last;
}

template <typename T> bool easyfind(T& var, int n)
{
    if(find(var.begin(), var.end(), n) != var.end())
        return(true);
    return(false);
}
#endif