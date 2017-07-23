#include <iostream>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;

// generic output operator for pairs (limited solution)
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm,
                           const std::pair<T1,T2>& p)
{
  return strm << "[" << p.first << "," << p.second << "]";
}

int main(int argc, char *argv[])
{
  typedef std::pair<int,float> IntFloatPair;
  IntFloatPair p1(42,3.14);
#if 0
  std::get<0>(p) // yields p.first
    std::get<1>(p) // yields p.second
    std::tuple_size<IntFloatPair>::value // yields 2
    std::tuple_element<0,IntFloatPair>::type // yields int
#endif
    int i = 0;
  auto p2 = std::make_pair(std::ref(i),std::ref(i)); // creates pair<int&,int&>
  ++p2.first; // increments i
  ++p2.second; // increments i again
  std::cout << "i: " << i << std::endl; // prints i: 2

  std::pair<char,char> p3=std::make_pair('x','y'); // pair of two chars
  char c;
  std::tie(std::ignore, c) = p3;//extract second value into c (ignore first one)
  std::cout<<"c = "<<c<<std::endl;
    
  return 0;
}
