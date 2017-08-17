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

static void
printarray(GArray *garray)
{
  for (gint i = 0; i < garray->len; i++) {
    if (i == 0)
      g_printf("{ %d", g_array_index(garray, gint, i));
    else if (i == garray->len - 1)
      g_printf(" , %d }\n", g_array_index(garray, gint, i));
    else
      g_printf(" , %d", g_array_index(garray, gint, i));
  }
}

static int
int_compare (gconstpointer p1, gconstpointer p2)
{
  const gint *i1 = p1;
  const gint *i2 = p2;

  return *i1 - *i2;
}

int
main(int argc, char *argv[])
{
  GArray *garray;
  gint i;

  garray = g_array_new(TRUE, TRUE, sizeof(gint));
  /*向后添加元素 */
  for (i = 0; i < 10; i++)
    g_array_append_val(garray, i);
  printarray(garray);
  g_array_free(garray, TRUE);

  garray = g_array_new(FALSE, FALSE, sizeof(gint));
  /*向前插入元素*/
  for (i = 0; i < 10; i++)
    g_array_prepend_val(garray, i);
  printarray(garray);
  g_array_free(garray, TRUE);

  /*删除特定元素*/
  garray = g_array_new(FALSE, FALSE, sizeof(gint));
  for (i = 0; i < 10; i++)
    g_array_append_val(garray, i);

#if 0
  g_array_remove_index (garray, 1);
  g_array_remove_index (garray, 3);
  g_array_remove_index (garray, 5);
#endif

  g_array_remove_index_fast (garray, 1);
  g_array_remove_index_fast (garray, 3);
  //g_array_remove_index_fast (garray, 5);
  
  printarray(garray);
  g_array_free(garray, TRUE);

  /*数组排序*/
  garray = g_array_new(FALSE, FALSE, sizeof(gint));
  for (i = 0; i < 10; i++) {
    gint temp = g_random_int_range(10, 50);
    g_array_append_val(garray, temp);
  }
  printarray(garray);
  g_array_sort(garray, int_compare);
  printarray(garray);
  
  return 0;
}


