#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

int l=0;

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
  else{
    l++;
    return fibonacci_recursive(sequence - 1) +
           fibonacci_recursive(sequence - 2);
  }
  
}

int main() {

  //std::cout << fibonacci_iterative(42)<<std::endl;
 // std::cout<<std::endl;
  std::cout<< fibonacci_recursive(42)<<std::endl;
  std::cout<<"liczba wywołań rek "<<l;
  return 0;
}
