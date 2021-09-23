#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

int fibonacci_iterative(int sequence) {
  int first = 0;
  int second = 1;
  int third = 1;
  if (sequence < 2)
    return sequence;
  else
    for (int i = 1; i < sequence; i++) {
      third = first + second;
      first = second;
      second = third;
    }
  return third;
}

int fibonacci_recursive(int sequence) {
  if (sequence < 2)
    return sequence;
  else
    return fibonacci_recursive(sequence - 1) +
           fibonacci_recursive(sequence - 2);
}

int main() {

  std::cout << fibonacci_iterative(35);
  std::cout<<std::endl;
  std::cout<< fibonacci_recursive(35);
  return 0;
}
