#include <iostream>

using namespace std;

#if 0 //不能用于int*的数据交换
template <class ForwardIterator1, class ForwardIterator2>
void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
{
  typename ForwardIterator1::value_type tmp = *l1;
  *i1 = *i2;
  *i2 = tmp;
}
#endif

#if 0
template <class ForwardIterator1, class ForwardIterator2>
void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
{
  typename iterator_traits<ForwardIterator1>::value_type tmp = *l1;
  *i1 = *i2;
  *i2 = tmp;
}

template <class ForwardIterator>
void iter_swap(ForwardIterator i1, ForwardIterator i2)
{
  std::swap(*l1, *l2);
}

#endif

#if 0 //代理类型
struct proxy
{
  proxy& operator=(bool x)
  {
    if (x)
      bytes[pos/8] |= (1u << (pos%8));
    else
      bytes[pos/8] &= ~(1u << (pos%8));
    return *this;
  }

  operator bool() const
  {
    return bytes[pos/8] & (1u << (pos%8));
  }

  unsigned char *bytes;
  size_t pos;
};

struct bit_iterator
{
  typedef bool value_type;
  typedef proxy reference;
  //more typedef...

  proxy operator*() const;
  //more operation
};
#endif


/**
 *  根据如下条件来决定是否使用快速的swap版本：
 *  1. 同一个类型
 *  2. 真正的引用类型
 */
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <iterator> //针对iterator_traits
#include <utility> //针对swap

#if 0

namespace std {
  template <bool use_swap>  struct iter_swap_impl;

  template <class ForwardIterator1, class ForwardIterator2>
  void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
  {
    typedef iterator_traits<ForwardIterator1> traits1;
    typedef typename traits1::value_type v1;
    typeid typename traits1::reference r1;

    typedef  iterator_traits<ForwardIterator2> traits2;
    typedef typename traits2::value_type v2;
    typedef typename traits2::reference r2;

    bool const use_swap = boost::is_same<v1, v2>::value
      && boost::is_reference<v1>::value
      && boost::is_reference<v2>::value;
    iter_swap_impl<use_swap>::do_it(i1, i2);
  }

  template<>
  struct iter_swap_impl<true>
  {
    template <class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
    {
      std::swap(*i1, *i2);
    }
  };

  template<>
  struct iter_swap_impl<false>
  {
    template <class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
    {
      typename iterator_traits<ForwardIterator1>::value_type tmp = *i1;
      *i1 = *i2;
      *i2 = tmp;
    }
  };
}

#endif

/**
 * ex01
 * 元函数： add_const_ref<T>
 * 如果T是一个引用类型，则返回T，
 × 否则返回T const &
*/

namespace std {

  template <bool is_reference>
  struct convert_reference
  {
    template <class T> struct result_
    {
      typedef T type;
    };
  };

  template<>
  struct convert_reference<false>
  {
    template <class T> struct result_
    {
      typedef T const& type;
    };
  };
  
  template <class T>
  struct add_const_ref
  {
    typedef typename convert_reference<boost::is_reference<T>::value>::template result_<T> result;
    typedef typename result::type type;
  };
}

/**
 * ex02:
 * replace_type<c,x,y>
 * 接受任一个复合类型c作为其第一个参数
 * 并将c中出现的所有type x替换为y
 */
namespace std {
  template <class C, class X, class Y>
  struct replace_type
  {
    typedef Y type;
  };

  template <class X, class Y>
  struct replace_type<X*, X, Y>
  {
    typedef Y* type;
  };

  template <class X, class Y>
  struct replace_type<X* (*)(X), X, Y>
  {
    typedef typename Y* (*)(Y) type;
  };
#if 0
  template <class C, class X, class Y, size_t N>
  struct replace_type<X**, Y>
  {
    typedef Y*[N] type;
  }
#endif
  
}

int main(int argc, char *argv[])
{
  //ex01 test
  std::cout<<boost::is_same<add_const_ref<int>::type, int const&>::value<<std::endl;

  //ex02 test
  std::cout<<boost::is_same<replace_type<void*, void, int>::type, int*>::value<<std::endl;
  //std::cout<<boost::is_same<replace_type<int const *[10], int const, long>::type, long*[10]>::value<<std::endl
  std::cout<<boost::is_same<replace_type<char& (*)(char&), char&, long&>::type, long& (*)(long&)>::value<<std::endl;

  return 0;
}
