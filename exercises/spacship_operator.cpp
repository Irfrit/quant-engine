#include <compare>
#include <iostream>

int main() {
  std::cout << (10 <=> 20 == std::strong_ordering::less) << '\n';
  std::cout << (20 <=> 20 == std::strong_ordering::equal) << '\n';
  std::cout << (30 <=> 20 == std::strong_ordering::greater) << '\n';
}
