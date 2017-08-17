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

void print_iterator(gpointer item, gpointer prefix) {
  printf("%s %s\n", prefix, item);
}
void print_iterator_short(gpointer item) {
  printf("%s\n", item);
}

int main(int argc, char** argv) {
  GSList* list = g_slist_append(NULL, g_strdup("first"));
  list = g_slist_append(list, g_strdup("second"));
  list = g_slist_append(list, g_strdup("third"));
  printf("Iterating with a function:\n");
  g_slist_foreach(list, print_iterator, "-->");
  printf("Iterating with a shorter function:\n");
  g_slist_foreach(list, (GFunc)print_iterator_short, NULL);
  printf("Now freeing each item\n");
  g_slist_foreach(list, (GFunc)g_free, NULL);
  g_slist_free(list);
  return 0;
}
