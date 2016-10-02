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

struct strtab_cmp
{
  typedef vector<char>::iterator strtab_iterator;
  bool operator()(const pair<strtab_iterator, strtab_iterator>& x,
                  const pair<strtab_iterator, strtab_iterator>& y) const
  {
    return lexicographical_compare(x.first, x.second, y.first, y.second);
  }
};

struct strtab_print
{
  ostream& out;
  strtab_print(ostream& os): out(os) {}

  typedef vector<char>::iterator strtab_iterator;
  void operator() (const pair<strtab_iterator, strtab_iterator>& s) const
  {
    copy(s.first, s.second, ostream_iterator<char>(out));
  }
};


int main(int argc, char *argv[])
{
  vector<char> strtab; //产生字符串表格
  char c;
  while (cin.get(c))
    strtab.push_back(c);
  //剖析字符串表格， 予以断行。
  typedef vector<char>::iterator strtab_iterator;
  vector<pair<strtab_iterator, strtab_iterator> > lines;
  strtab_iterator start = strtab.begin();
  while (start != strtab.end()) {
    strtab_iterator next = find(start, strtab.end(), '\n');
    if (next != strtab.end())
      ++next;
    lines.push_back(make_pair(start, next));
    start = next;
  }

  //对于文本行所形成的vector排序
  sort(lines.begin(), lines.end(), strtab_cmp());
  //将排序结果写到标准输出设备
  for_each(lines.begin(), lines.end(), strtab_print(cout));
  return 0;
}

