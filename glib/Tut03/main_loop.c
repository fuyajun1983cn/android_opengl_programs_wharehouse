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

static gboolean
quit_loop (gpointer data)
{
  GMainLoop *loop = data;
  g_printf("timeout, quit the main loop\n");
  g_main_loop_quit (loop);

  return G_SOURCE_REMOVE;
}

int main(int argc, char *argv[])
{
  GMainLoop *loop;
  GSource *source;

  loop = g_main_loop_new(NULL, FALSE);
  source = g_timeout_source_new (2000);/* 2 seconds */
  g_source_set_callback (source, quit_loop, loop, NULL);
  g_source_attach (source, g_main_loop_get_context (loop));
  g_source_unref (source);

  g_main_loop_run (loop);

  g_main_loop_unref (loop);
  
  return 0;
}

