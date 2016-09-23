#include <iostream>

template <unsigned long N>
struct binary {
  static unsigned const value
  = binary<N/10>::value * 2 + N%10;
};

template <>
struct binary<0>
{
  static unsigned const value = 0;
};

unsigned const one = binary<1>::value;
unsigned const five = binary<101>::value;

int main(int argc, char *argv[])
{
  std::cout<<five<<std::endl;
}
