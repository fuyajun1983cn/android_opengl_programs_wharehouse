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

int main(int argc, char** argv) {
  GSList* list = g_slist_append(NULL, "Anaheim "), *iterator = NULL;
  list = g_slist_append(list, "Elkton ");
  printf("Before inserting 'Boston', second item is: '%s'\n", g_slist_nth(list, 1)->data);
  g_slist_insert(list, "Boston ", 1);
  printf("After insertion, second item is: '%s'\n", g_slist_nth(list, 1)->data);
  list = g_slist_insert_before(list, g_slist_nth(list, 2), "Chicago ");
  printf("After an insert_before, third item is: '%s'\n", g_slist_nth(list, 2)->data);
  list = g_slist_insert_sorted(list, "Denver ", (GCompareFunc)g_ascii_strcasecmp);
  printf("After inserting 'Denver', here's the final list:\n");
  g_slist_foreach(list, (GFunc)printf, NULL);
  g_slist_free(list);
  return 0;
}
