#include "stack.h"

int main(int argc, char const *argv[])
{
   g3::stack<int> a = {1,2,3,4,5,6,7,8,9};

   a.push(55);
  //  std::cout << a.top() << std::endl; 
  //  while(!a.empty()) {
  //    std::cout << a.top() <<  " ";
  //    a.pop();
  //  }

   g3::stack<int> s1 = {1,2,3,4,5,6,7,8,9};
   s1.push(33);
  //  s1 = a; // copy assigment operator 
  //  while(!s1.empty()) {
  //     std::cout << s1.top() <<  " "; 
  //     s1.pop();
  //  }

  //  s1 = std::move(a); // move assigment operator 
  //  while(!s1.empty()) {
  //      std::cout << s1.top() << " ";
  //      s1.pop();
  //  }

  // a.push(55);
  // a.push(33);
  // a.push(22);
  // while(!a.empty()) {
  //   std::cout << a.top() << " ";
  //   a.pop();
  // }

  //  if (a == s1 ) {
  //     std::cout << "This stacks is equal " << std::boolalpha << std::endl; 
  //  } else {
  //     std::cout << "This stacks is not equal " << std::boolalpha << std::endl; 
  //  }
      
      // if (a > s1) {
      //    std::cout << "s1 grether then a " << std::boolalpha << std::endl; 
      // } else {
      //     std::cout << "s1 less then a " << std::boolalpha << std::endl; 
      // }

      // if (a < s1) {
      //    std::cout << "s1 grether then a " << std::boolalpha << std::endl; 
      // } else {
      //     std::cout << "s1 less then a " << std::boolalpha << std::endl; 
      // }

      // if (a >= s1) {
      //    std::cout << "s1 grether then a " << std::boolalpha << std::endl; 
      // } else {
      //     std::cout << "s1 less then a " << std::boolalpha << std::endl; 
      // }

      // if (a <= s1) {
      //    std::cout << "s1 grether then a " << std::boolalpha << std::endl; 
      // } else {
      //     std::cout << "s1 less then a " << std::boolalpha << std::endl; 
      // }

      // if (a != s1) {
      //    std::cout << "s1 is not equal a " << std::boolalpha << std::endl; 
      // } else {
      //     std::cout << "s1 is equal a " << std::boolalpha << std::endl; 
      // }


}
