#include "std_lib_facilities.h"

int square(int x) {
  int sum = 0;
  for (int i = 0; i < x; i++) {
    sum += x;
  }
  return sum;
}

int main() {

  for (int i = 0; i < 1000; i++) {
    cout << i << ' ' << square(i) << "\n";
  }
}