#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  
#include <libintl.h>  
#include <cpluff.h>


#define LOCALEDIR "/usr/share/locale/"  
#define _(string) gettext(string)  
/* -----------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------*/

/// The level of verbosity
static int verbosity = 1;
cp_context_t *ctx = NULL;


/* -----------------------------------------------------------------------
 * Functions
 * ---------------------------------------------------------------------*/

/**
 * Prints an error message and exits. In quiet mode the error message is
 * not printed.
 * 
 * @param msg the error message
 */
static void error(const char *msg)
{
  if (verbosity >= 1) {
    /* TRANSLATORS: A formatting string for loader error messages. */
    fprintf(stderr, _("main: ERROR: %s\n"), msg);
  }
  exit(-1);
}

static void handle_fatal_error(const char *msg)
{

  // ... log error, flush logs, send bug report, etc. ...

  fprintf(stderr, "A fatal error occurred: %s\n", msg);
  abort();
}

static void logger(cp_log_severity_t severity, const char *msg, const char *apid, void *dummy)
{
  const char *level;
  int minv;
  switch (severity) {
  case CP_LOG_DEBUG:
    /* TRANSLATORS: A tag for debug level log entries. */
    level = _("DEBUG");
    minv = 4;
    break;
  case CP_LOG_INFO:
    /* TRANSLATORS: A tag for info level log entries. */
    level = _("INFO");
    minv = 3;
    break;
  case CP_LOG_WARNING:
    /* TRANSLATORS: A tag for warning level log entries. */
    level = _("WARNING");
    minv = 2;
    break;
  case CP_LOG_ERROR:
    /* TRANSLATORS: A tag for error level log entries. */
    level = _("ERROR");
    minv = 1;
    break;
  default:
    /* TRANSLATORS: A tag for unknown severity level. */ 
    level = _("UNKNOWN");
    minv = 1;
    break;
  }
  if (verbosity >= minv) {
    if (apid != NULL) {
      /* TRANSLATORS: A formatting string for log messages caused by plug-in activity. */ 
      fprintf(stderr, _("C-Pluff: %s: [%s] %s\n"), level, apid, msg);
    } else {
      /* TRANSLATORS: A formatting string for log messages caused by loader activity. */ 
      fprintf(stderr, _("C-Pluff: %s: [loader] %s\n"), level, msg);
    }
  } 
}

/**
 * Plugin loading utils
 */
static const char pluginListFile[] = "/etc/example/plugins.list";

static void load_plugins_1(void)
{
  char plugindir[128];
  FILE *lf;

  // Open plug-in list file
  lf = fopen(pluginListFile, "r");
  if (lf == NULL) {
    // ... handle loading failure ...
    error("Loading plugins list failed.");
    return;
  }

  // Load each listed plug-in
  while (fgets(plugindir, 128, lf) != NULL) {
    cp_plugin_info_t *plugininfo;
    cp_status_t status;
    int i;

    // Remove possible trailing newline from plug-in location
    for (i = 0; plugindir[i + 1] != '\0'; i++);
    if (plugindir[i] == '\n') {
      plugindir[i] = '\0';
    }

    // Load plug-in descriptor
    plugininfo = cp_load_plugin_descriptor(ctx, plugindir, &status);
    if (plugininfo == NULL) {
      // ... handle loading failure ...
      fprintf(stderr, "Loading  plugin: %s failed!", plugininfo->name);
      break;
    }

    // Install plug-in descriptor
    status = cp_install_plugin(ctx, plugininfo);
    if (status != CP_OK) {
      // ... handle loading failure ...
      fprintf(stderr, "install plugin: %s failed!", plugininfo->name);
      break;
    }

    // Release plug-in descriptor information
    cp_release_info(ctx, plugininfo);
  }

  // Close plug-in list file
  fclose(lf);
}

static const char pluginCollectionDir[] = "plugins";

void load_plugins_2(void)
{
  cp_status_t status;

  status = cp_register_pcollection(ctx, pluginCollectionDir);
  if (status != CP_OK) {
    // ... handle loading failure ...
    error("register Plug-in collections failed.");
  }
  status = cp_scan_plugins(ctx, 0);
  if (status != CP_OK) {
    // ... handle loading failure ...
    // (notice that some plug-ins might have been loaded)
    error("scanning plugins failed");
  }
}

static const char corePluginId[] = "org.c-pluff.examples.cpfile.core";
static void run_plugins(char *argv[])
{
  cp_status_t status;

  // Set plug-in startup arguments
  cp_set_context_args(ctx, argv);

  // Start the core plug-in, possibly activating other plug-ins as well
  status = cp_start_plugin(ctx, corePluginId);
  if (status != CP_OK) {
    // ... handle startup failure ...
  }

  // Execute plug-ins until there is no more work to be done
  cp_run_plugins(ctx);
}

int main(int argc, char *argv[])
{
  cp_status_t status;

  setlocale(LC_ALL, "");
  bindtextdomain ("main", LOCALEDIR);  
  textdomain ("main");  
  cp_set_fatal_error_handler(handle_fatal_error);
  status = cp_init();
  if (status != CP_OK) {
    error("failed to init c-pluff.");
  }

  ctx = cp_create_context(&status);
  if (ctx == NULL) {
    error("failed to create c-pluff context.");
  }

  // Register logger
  if (verbosity >= 1) {
    cp_log_severity_t mv = CP_LOG_DEBUG;
    switch (verbosity) {
    case 1:
      mv = CP_LOG_ERROR;
      break;
    case 2:
      mv = CP_LOG_WARNING;
      break;
    case 3:
      mv = CP_LOG_INFO;
      break;
    }
    cp_register_logger(ctx, logger, NULL, mv);
  }

  load_plugins_2();
  run_plugins(argv);

  // Destroy framework
  cp_destroy();
    
  return 0;
}

