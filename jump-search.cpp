#include <iostream>
#include <vector>
#include <math.h>

namespace spec {

template <typename T>
int jump_search(const std::vector<T>& vec, const T& value) {
  int jump_length = std::sqrt(vec.size());
  int index{};
  while (vec[index] < value) {
    if (index + jump_length < vec.size())
      index += jump_length;
    else
      index = vec.size() - 1;
  }
  for (int i{}; i < jump_length; ++i)
    if (vec[index - i] == value)
      return index - i;
  return -1;
}

} // spec

int main() {
  std::vector<int> vec;
  for (int i{}; i < 100; ++i) {
    vec.push_back(i);
  }
  std::cout << spec::jump_search(vec, 91) << std::endl;
}