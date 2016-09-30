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

//Finding an element
gint my_finder(gconstpointer item) {
  return g_ascii_strcasecmp(item, "second");
}

int main(int argc, char** argv) {
  GSList* list = g_slist_append(NULL, "first");
  list = g_slist_append(list, "second");
  list = g_slist_append(list, "third");
  GSList* item = g_slist_find(list, "second");
  printf("This should be the 'second' item: '%s'\n", item->data);
  item = g_slist_find_custom(list, NULL, (GCompareFunc)my_finder);
  printf("Again, this should be the 'second' item: '%s'\n", item->data);
  item = g_slist_find(list, "delta");
  printf("'delta' is not in the list, so we get: '%s'\n", item ? item->data : "(null)");
  g_slist_free(list);
  return 0;
}

