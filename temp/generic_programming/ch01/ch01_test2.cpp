/**
 * Copyright (c)  2016     Yajun Fu (fuyajun1983cn@163.com)
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class line_iterator
{
  istream *in;
  string line;
  bool is_valid;
  void read()
  {
    if (*in)
      getline(*in, line);
    is_valid = (*in) ? true : false;
  }

public:
  typedef input_iterator_tag iterator_category;
  typedef string value_type;
  typedef ptrdiff_t difference_type;
  typedef const string *pointer;
  typedef const string &reference;

  line_iterator(): in(&cin), is_valid(false) {}
  line_iterator(istream &s): in(&s) { read(); }
  reference operator *() const { return line; }
  pointer operator ->() const { return &line; }
  line_iterator operator++()
  {
    read();
    return *this;
  }

  line_iterator operator++(int)
  {
    line_iterator tmp = *this;
    read();
    return tmp;
  }

  bool operator==(const line_iterator &i) const
  {
    return (in == i.in && i.is_valid == is_valid) ||
      (i.is_valid ==  false  && is_valid == false);
  }

  bool operator!=(const line_iterator &i) const
  {
    return !(i == *this);
  }
};

int main(int argc, char *argv[])
{
  line_iterator iter(cin);
  line_iterator end_of_line;
  vector<string> V(iter, end_of_line);
  sort(V.begin(), V.end());
  copy(V.begin(), V.end(), ostream_iterator<string>(cout, "\n"));
  return 0;
}

