#include<stdio.h>

struct test {
  static int i;  // Error in C, but works in C++.
};

int main()
{
  struct test t;
  getchar();
  return 0;
}

// g++-4.8 static_in_c.cpp Works!
// mv static_in_c.cpp static_in_c.c
// g++-4.8 static_in_c.c Works!
// gcc-4.8 static_in_c.c Below Error
// static_in_c.c:4:3: error: expected specifier-qualifier-list before ‘static’
//   static int i;  // Error in C, but works in C++.
//   ^
