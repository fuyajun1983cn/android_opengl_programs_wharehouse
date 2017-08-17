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

#include <glib.h>
#include <glib/gprintf.h>

//Combining, reversing, and all that
int main(int argc, char** argv) {
  GSList* list1 = NULL;
  list1 = g_slist_append(list1, "first");
  list1 = g_slist_append(list1, "second");
  GSList* list2 = NULL;
  list2 = g_slist_append(list2, "third");
  list2 = g_slist_append(list2, "fourth");
  GSList* both = g_slist_concat(list1, list2);
  printf("The third item in the concatenated list is '%s'\n", g_slist_nth_data(both, 2));
  GSList* reversed = g_slist_reverse(both);
  printf("The first item in the reversed list is '%s'\n", reversed->data);
  g_slist_free(reversed);
  return 0;
}
