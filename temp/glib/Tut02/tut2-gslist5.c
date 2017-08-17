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
#include <stdlib.h>

//Working with a user-defined type
typedef struct {
  char* name;
  int shoe_size;
} Person;

int main(int argc, char** argv) {
  GSList* list = NULL;
  Person* tom = (Person*)malloc(sizeof(Person));
  tom->name = "Tom";
  tom->shoe_size = 12;
  list = g_slist_append(list, tom);
  Person* fred = g_new(Person, 1); // allocate memory for one Person struct
  fred->name = "Fred";
  fred->shoe_size = 11;
  list = g_slist_append(list, fred);
  printf("Tom's shoe size is '%d'\n", ((Person*)list->data)->shoe_size);
  printf("The last Person's name is '%s'\n", ((Person*)g_slist_last(list)->data)->name);
  g_slist_free(list);
  free(tom);
  g_free(fred);
  return 0;
}
