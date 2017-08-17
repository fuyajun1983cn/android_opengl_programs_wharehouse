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

static gint repeats = 2;  
static gint max_size = 8;  
static gboolean verbose = FALSE;  
static gboolean beep = FALSE;  
static gboolean rand = FALSE;  
static gchar *string;  
static GOptionEntry entries[] =  
  {  
    { "repeats", 'r', 0, G_OPTION_ARG_INT, &repeats, "Average over N repetitions", "N" },  
    { "max-size", 'm', 0, G_OPTION_ARG_INT, &max_size, "Test up to 2^M items", "M" },  
    { "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "Be verbose", NULL },  
    { "beep", 'b', 0, G_OPTION_ARG_NONE, &beep, "Beep when done", NULL },  
    { "rand", 0, 0, G_OPTION_ARG_NONE, &rand, "Randomize the data", NULL },  
    { "str_test", 's', 0, G_OPTION_ARG_STRING, &string, "test the stirng", NULL},  
    { NULL }  
  };

int main(int argc, char *argv[])
{
  GError *error = NULL;  
  GOptionContext *context;  
  context = g_option_context_new ("- test tree model performance");  
  g_option_context_add_main_entries (context, entries, NULL);  
  // g_option_context_add_group (context, gtk_get_option_group (TRUE));  
  if (!g_option_context_parse (context, &argc, &argv, &error))  
    {  
      g_print ("option parsing failed: %s/n", error->message);  
      return 1;
    }
  
  return 0;
}

