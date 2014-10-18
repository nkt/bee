
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * @author Nikita Gusakov <dev@nkt.me>
 */
ZEPHIR_INIT_CLASS(Bee_Serializer) {

	ZEPHIR_REGISTER_CLASS(Bee, Serializer, bee, serializer, bee_serializer_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Bee_Serializer, serialize) {

	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_6;
	HashPosition _0, _5;
	zval *keys = NULL;
	zval *obj, *keys_param = NULL, *data, *key = NULL, *value = NULL, *property = NULL, **_2, *_3 = NULL, **_7, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &obj, &keys_param);

	zephir_get_arrval(keys, keys_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	if (Z_TYPE_P(obj) == IS_ARRAY) {
		zephir_is_iterable(obj, &_1, &_0, 0, 0, "bee/Serializer.zep", 16);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(value, _2);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "serialize", &_4, value, keys);
			zephir_check_call_status();
			zephir_array_append(&data, _3, PH_SEPARATE, "bee/Serializer.zep", 14);
		}
	} else {
		zephir_is_iterable(keys, &_6, &_5, 0, 0, "bee/Serializer.zep", 34);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			if (Z_TYPE_P(key) == IS_STRING) {
				ZEPHIR_CALL_METHOD(&property, this_ptr, "getproperty", &_8, obj, key);
				zephir_check_call_status();
				if (Z_TYPE_P(property) == IS_NULL) {
					zephir_array_update_zval(&data, key, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_CALL_METHOD(&_3, this_ptr, "serialize", &_4, property, value);
					zephir_check_call_status();
					zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_CALL_METHOD(&property, this_ptr, "getproperty", &_8, obj, value);
				zephir_check_call_status();
				if (zephir_is_instance_of(property, SL("DateTime") TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_10);
					ZVAL_STRING(_10, "Y-m-d\\TH:i:sO", 0);
					ZEPHIR_CALL_METHOD(&_9, property, "format", NULL, _10);
					zephir_check_temp_parameter(_10);
					zephir_check_call_status();
					zephir_array_update_zval(&data, value, &_9, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&data, value, &property, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Bee_Serializer, getProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property = NULL, *method = NULL, *classname = NULL;
	zval *obj, *property_param = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &obj, &property_param);

	zephir_get_strval(property, property_param);


	ZEPHIR_INIT_VAR(classname);
	zephir_get_class(classname, obj, 0 TSRMLS_CC);
	
        zend_class_entry *_obj_ce = zephir_fetch_class(classname TSRMLS_CC);
        zval *_property_value = zend_read_property(_obj_ce, obj, Z_STRVAL_P(property), Z_STRLEN_P(property), 1 TSRMLS_CC);
        if (Z_TYPE_P(_property_value) != IS_NULL) {
            RETURN_ZVAL(_property_value, 1, 0);
        }

	ZEPHIR_INIT_VAR(method);
	ZEPHIR_CONCAT_SV(method, "get", property);
	if ((zephir_method_exists(obj, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(obj, Z_STRVAL_P(method), NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_INIT_BNVAR(method);
		ZEPHIR_CONCAT_SV(method, "is", property);
		if ((zephir_method_exists(obj, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(obj, Z_STRVAL_P(method), NULL);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_BNVAR(method);
			ZEPHIR_CONCAT_SV(method, "has", property);
			if ((zephir_method_exists(obj, method TSRMLS_CC)  == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(obj, Z_STRVAL_P(method), NULL);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, spl_ce_RuntimeException);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, obj, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, _1, " has no accessor for ", property);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "bee/Serializer.zep", 66 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

