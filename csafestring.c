#include "csafestring.h"
#include <string.h>

void safe_resizeBuffer(safestring_t *, size_t);

safestring_t *safe_create() {
	safestring_t *obj = (safestring_t *) malloc(sizeof(safestring_t));
	obj->buffer_length = INIT_LENGTH;
	obj->data = (char *) calloc(sizeof(char), INIT_LENGTH);
	return obj;
}

void safe_destroy(safestring_t *obj) {
	free(obj->data);
	free(obj);
}

void safe_resizeBuffer(safestring_t *obj, size_t newLength) {
	char hit = 0;
	newLength++;

	while ( obj->buffer_length < newLength ) {
		hit = 1;
		obj->buffer_length <<= 1;
	}
	if ( hit ) {
		obj->data = (char *) realloc(obj->data, newLength);
	}
}

char *safe_strcat(safestring_t *obj, const char *str) {
	size_t length = strlen(str);
	size_t newLength = length + strlen(obj->data);

	safe_resizeBuffer(obj, newLength);
	return strcat(obj->data, str);
}

int safe_strncmp(safestring_t *obj, const char *str, size_t size) {

	size_t length = size;
	if ( str == NULL ) {
		return 1;
	}

	size_t strLength = strlen(str);

	if ( obj->buffer_length < length ) {
		length = obj->buffer_length;
	}

	if ( strLength < length ) {
		length = strLength;
	}

	return strncmp(obj->data, str, length);
}

void *safe_memchr(safestring_t *obj, int chr, size_t size) {
	if ( obj->buffer_length < size ) {
		return memchr(obj->data, chr, obj->buffer_length);
	} else {
		return memchr(obj->data, chr, size);
	}
}


int safe_memcmp(safestring_t *obj1, safestring_t *obj2, size_t size) {
	size_t length = size;
	if ( obj1->buffer_length < length ) {
		length = obj1->buffer_length;
	}
	if ( obj2->buffer_length < length ) {
		length = obj2->buffer_length;
	}
	return memcmp(obj1->data, obj2->data, length);
}

void *safe_memcpy(safestring_t *dest, safestring_t *src, size_t size) {
	size_t length = size;
	if ( src->buffer_length < size ) {
		length = src->buffer_length;
	}

	safe_resizeBuffer(dest, length);
	return memcpy(dest->data, src->data, length);
}

void *safe_memmove(safestring_t *dest, safestring_t *src, size_t size) {
	size_t length = size;
	if ( src->buffer_length < size ) {
		length = src->buffer_length;
	}

	safe_resizeBuffer(dest, length);
	return memmove(dest->data, src->data, length);
}

void *safe_memset(safestring_t *obj, int chr, size_t size) {
	safe_resizeBuffer(obj, size);
	return memset(obj->data, chr, size);
}

char *safe_strcpy(safestring_t *obj, const char *str) {
	size_t length = strlen(str);
	safe_resizeBuffer(obj, length);
	return strcpy(obj->data, str);
}

char *safe_strncat(safestring_t *obj, const char *str, size_t size) {
	size_t newLength = size + strlen(obj->data);

	safe_resizeBuffer(obj, newLength);
	return strncat(obj->data, str, size);
}

char *safe_strncpy(safestring_t *obj, const char *str, size_t size) {
	safe_resizeBuffer(obj, size);
	return strncpy(obj->data, str, size);
}

size_t safe_strxfrm(safestring_t *dest, safestring_t *src, size_t size) {
	safe_resizeBuffer(dest, size * 2);
	return strxfrm(dest->data, src->data, size);
}
