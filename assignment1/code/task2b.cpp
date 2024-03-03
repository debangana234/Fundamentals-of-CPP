#include <iostream>
#include <vector>

unsigned int get_max(unsigned int a, unsigned int b) {
  unsigned int c = a > b ? a : b;
  return c;
}

int main() {
  std::vector<unsigned int> v(10000, 0);
  v[9999] = 1000u;

  unsigned int max = 0u;
  for(unsigned int e : v){
    max = get_max(max, e);
  }
  std::cout << "Maximum: " << max << std::endl;
  return 0;
}
// the function takes a reference to the variable.
// On removing the & we get the corrected output of printing the maximum.