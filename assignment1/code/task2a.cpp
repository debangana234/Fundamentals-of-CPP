#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  v.reserve(50);
  int i; //i was not declared

  for ( i = 0; i < 50; ++i) {
    v.push_back(i);
  }

  for ( i = v.size() - 1; i >= 0; --i) {
    std::cout << i << ": " << v[i] << std::endl;
  }
  return 0;
}
// "i" used in the for loop as a variable was not initialized,
// when we print without initializing i as int, it remains as an unassigned variable.
// Unassigned variables do not take negative values.