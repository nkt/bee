
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BEE_H
#define PHP_BEE_H 1

#include "kernel/globals.h"

#define PHP_BEE_NAME        "bee"
#define PHP_BEE_VERSION     "0.0.1"
#define PHP_BEE_EXTNAME     "bee"
#define PHP_BEE_AUTHOR      "Nikita Gusakov"
#define PHP_BEE_ZEPVERSION  "0.5.4a"
#define PHP_BEE_DESCRIPTION "The dead simple serializer"



ZEND_BEGIN_MODULE_GLOBALS(bee)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(bee)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(bee)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(bee_globals_id, zend_bee_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (bee_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_bee_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(bee_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(bee_globals)
#endif

#define zephir_globals_def bee_globals
#define zend_zephir_globals_def zend_bee_globals

extern zend_module_entry bee_module_entry;
#define phpext_bee_ptr &bee_module_entry

#endif
