
extern zend_class_entry *bee_serializer_ce;

ZEPHIR_INIT_CLASS(Bee_Serializer);

PHP_METHOD(Bee_Serializer, serialize);
PHP_METHOD(Bee_Serializer, getProperty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bee_serializer_serialize, 0, 0, 2)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bee_serializer_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bee_serializer_method_entry) {
	PHP_ME(Bee_Serializer, serialize, arginfo_bee_serializer_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Bee_Serializer, getProperty, arginfo_bee_serializer_getproperty, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
