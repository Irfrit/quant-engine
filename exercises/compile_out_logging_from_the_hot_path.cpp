#include <algorithm>
#include <iostream>
template <bool Logging> double payoff(double spot, double strike) {
  double result = std::max(spot - strike, 0.0);
  if constexpr (Logging) {
    std::cerr << "payoff=" << result << '\n';
  }
  return result;
}

int main() {
  payoff<true>(105.0, 100.0);
  payoff<false>(105.0, 100.0);
}
