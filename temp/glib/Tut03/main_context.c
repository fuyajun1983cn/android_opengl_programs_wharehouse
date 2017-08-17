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

/**
 *  GContext使用示例
 */

static gboolean cb (gpointer data)
{
  return FALSE;
}

static gboolean prepare (GSource *source, gint *time)
{
  return FALSE;
}
static gboolean check (GSource *source)
{
  return FALSE;
}
static gboolean dispatch (GSource *source, GSourceFunc cb, gpointer date)
{
  return FALSE;
}

GSourceFuncs funcs = {
  prepare,
  check,
  dispatch,
  NULL
};

int main(int argc, char *argv[])
{
  GMainContext *ctx;
  GSource *source;
  guint id;
  gpointer data = &funcs;

  ctx = g_main_context_new();

  source = g_source_new (&funcs, sizeof (GSource));
  g_source_set_can_recurse (source, TRUE);
  g_source_set_name (source, "d");

  id = g_source_attach (source, ctx);/* 将事件源与Main Context关联 */
  g_source_set_priority (source, G_PRIORITY_HIGH);

  g_source_destroy (source);
  g_main_context_unref (ctx);
  g_source_unref (source);
  
  return 0;
}

