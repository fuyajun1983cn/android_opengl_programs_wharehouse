/**
 * core plugin, main entry for the test programs
 */

#include <stdlib.h>
#include <stdio.h>
#include <cpluff.h>

/* ------------------------------------------------------------------------
 * Data types
 * ----------------------------------------------------------------------*/
/** Plug-in instance data */
struct plugin_data_t {
	
	/** The plug-in context */
	cp_context_t *ctx;
	

};

/* ------------------------------------------------------------------------
 * Internal functions
 * ----------------------------------------------------------------------*/

/**
 * A run function for the core plug-in. In this case this function acts as
 * the application main function so there is no need for us to split the
 * execution into small steps. Rather, we execute the whole main loop at
 * once to make it simpler.
 */
static int run(void *d) {
	plugin_data_t *data = d;
	char **argv;
	int argc;
	int i;

	// Read arguments and print usage, if no arguments given
	argv = cp_get_context_args(data->ctx, &argc);
    #if 0
	if (argc < 2) {
		fputs("usage: test \n", stdout);
		return 0;
	}
    #endif

	return 0;
} 

/**
 * Creates a new plug-in instance.
 */
static void *create(cp_context_t *ctx) {
	plugin_data_t *data = malloc(sizeof(plugin_data_t));
	if (data != NULL) {

	} else {
		cp_log(ctx, CP_LOG_ERROR,
			"Insufficient memory for plug-in data.");
	}
	return data;
}


/**
 * Initializes and starts the plug-in.
 */
static int start(void *d) {
	plugin_data_t *data = d;
	cp_extension_t **test_exts;
	int num_exts;
	cp_status_t status;
	int i;
	
	test_exts = cp_get_extensions_info(
		data->ctx,
		"ifjy.me.core.ext",
		&status,
		&num_exts
	);
	if (test_exts == NULL) {
		
		// An error occurred and framework logged it
      cp_log(ctx, CP_LOG_ERROR,
             "no test program found.")
		return status;
	}
	
	// Allocate memory for classifier information, if any
	if (num_exts > 0) {
      
	} 
	
	/* Resolve classifier functions. This will implicitly start
	 * plug-ins providing the classifiers. */
	for (i = 0; i < num_exts; i++) {
		const char *str;
		
		// Resolve classifier data pointer
		str = cp_lookup_cfg_value(
			cl_exts[i]->configuration, "@type");
		if (str == NULL) {
			
			// Classifier symbol name is missing
			cp_log(data->ctx, CP_LOG_ERROR,
				"Unkown test type.");
			continue;
		}
		
	}
	
	// Release extension information
	cp_release_info(data->ctx, test_exts);
	
	// Register run function to do the real work
	cp_run_function(data->ctx, run);
	
	// Successfully started
	return CP_OK;
}

/**
 * Releases resources from other plug-ins.
 */
static void stop(void *d) {

}

/**
 * Destroys a plug-in instance.
 */
static void destroy(void *d) {
	free(d);
}


/* ------------------------------------------------------------------------
 * Exported runtime information
 * ----------------------------------------------------------------------*/

/**
 * Plug-in runtime information for the framework. The name of this symbol
 * is stored in the plug-in descriptor.
 */
CP_EXPORT cp_plugin_runtime_t ex_test_core_funcs = {
	create,
	start,
	stop,
	destroy
};
