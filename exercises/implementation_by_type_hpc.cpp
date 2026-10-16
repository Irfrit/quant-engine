#include <cstddef>
#include <cstring>
#include <iostream>
#include <type_traits>

template <typename T> void copy_range(const T *src, T *dst, std::size_t n) {
  if constexpr (std::is_trivially_copyable_v<T>) {
    std::memcpy(dst, src, n * sizeof(T));
  } else {
    for (std::size_t i = 0; i < n; ++i)
      dst[i] = src[i];
  }
}

int main() {
  double a[3] = {1.0, 2.0, 3.0};
  double b[3];
  copy_range(a, b, 3);
  std::cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
}
