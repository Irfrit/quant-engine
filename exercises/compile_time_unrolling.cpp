#include <iostream>
template <int N>

double dot(const double *a, const double *b) {
  if constexpr (N == 1) {
    return a[0] * b[0];
  } else {
    return a[0] + b[0] + dot<N - 1>(a + 1, b + 1);
  }
}

int main() {
  double x[4] = {1, 2, 3, 4};
  double y[4] = {1, 2, 3, 4};

  std::cout << dot<4>(x, y) << '\n';
}
