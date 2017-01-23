#include "csafestring.h"
static void safe_resizeBuffer(csafestring_t *, size_t);

#ifdef EXPERIMENTAL_SIZING
static unsigned int sizing_count;
static unsigned int sizing_size;

int safe_getInitSize() {
	if ( sizing_count == 0 || sizing_size == 0 ) {
		return INIT_LENGTH;
	} else {
		return (int) sizing_size / sizing_count;
	}
}
#endif

csafestring_t *safe_create(char *str) {
	csafestring_t *obj = (csafestring_t *) malloc(sizeof(csafestring_t));

#ifdef EXPERIMENTAL_SIZING
	obj->sizing_size = safe_getInitSize();
	obj->buffer_length = 1<<obj->sizing_size;
	sizing_size += obj->sizing_size;
#else
	obj->buffer_length = INIT_LENGTH_CALC;
#endif
		
	if ( str == NULL ) {
		obj->data = (char *) calloc(sizeof(char), obj->buffer_length);
	} else {
		size_t newLength = strlen(str) + 1;

		while ( obj->buffer_length < newLength ) {
			obj->buffer_length <<= 1;
			
#ifdef EXPERIMENTAL_SIZING
			obj->sizing_size++;
			sizing_size++;
#endif
			
		}
		obj->data = (char *) malloc(obj->buffer_length);
		strcpy(obj->data, str);
	}
	
#ifdef EXPERIMENTAL_SIZING
	sizing_count++;
#endif
	
	return obj;
}

csafestring_t *safe_clone(csafestring_t *obj) {
	csafestring_t *clone = (csafestring_t *) malloc(sizeof(csafestring_t));
	clone->buffer_length = obj->buffer_length;
	clone->data = malloc(clone->buffer_lenqgth);
	memcpy(clone->data, obj->data, clone->buffer_length);

#ifdef EXPERIMENTAL_SIZING
	clone->sizing_size = obj->sizing_size;
	sizing_size += clone->sizing_size;
	sizing_count++;
#endif
	
	return clone;
}

void safe_destroy(csafestring_t *obj) {
	if ( obj == NULL ) {
		return;
	}

	if ( obj->data != NULL ) {
		free(obj->data);
	}

#ifdef EXPERIMENTAL_SIZING
	sizing_size -= obj->sizing_size;
	sizing_count--;
#endif
	
	free(obj);
}

static void safe_resizeBuffer(csafestring_t *obj, size_t newLength) {
	char hit = 0;
	newLength++;

	while ( obj->buffer_length < newLength ) {
		hit = 1;
		obj->buffer_length <<= 1;
#ifdef EXPERIMENTAL_SIZING
		obj->sizing_size++;
		sizing_size++;
#endif
	}
	if ( hit ) {
		char *tmp = (char *) calloc(sizeof(char), obj->buffer_length);
		memmove(tmp, obj->data, strlen(obj->data));
		free(obj->data);
		obj->data = tmp;
	}
}

char *safe_strcat(csafestring_t *obj, const char *str) {
	size_t length = strlen(obj->data);
	size_t newLength = length + strlen(str);

	safe_resizeBuffer(obj, newLength);
	return strcat(obj->data, str);
}

int safe_strncmp(csafestring_t *obj, const char *str, size_t size) {

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

void *safe_memchr(csafestring_t *obj, int chr, size_t size) {
	if ( obj->buffer_length < size ) {
		return memchr(obj->data, chr, obj->buffer_length);
	} else {
		return memchr(obj->data, chr, size);
	}
}


int safe_memcmp(csafestring_t *obj1, void *obj2, size_t size) {
	size_t length = size;
	if ( obj1->buffer_length < length ) {
		length = obj1->buffer_length;
	}
	return memcmp(obj1->data, obj2, length);
}

void *safe_memcpy(csafestring_t *dest, void *src, size_t size) {
	safe_resizeBuffer(dest, size);
	return memcpy(dest->data, src, size);
}

void *safe_memmove(csafestring_t *dest, void *src, size_t size) {
	safe_resizeBuffer(dest, size);
	return memmove(dest->data, src, size);
}

void *safe_memset(csafestring_t *obj, int chr, size_t size) {
	safe_resizeBuffer(obj, size);
	return memset(obj->data, chr, size);
}

char *safe_strcpy(csafestring_t *obj, const char *str) {
	size_t length = strlen(str);
	safe_resizeBuffer(obj, length);
	return strcpy(obj->data, str);
}

char *safe_strncat(csafestring_t *obj, const char *str, size_t size) {
	size_t newLength = size + strlen(obj->data);

	safe_resizeBuffer(obj, newLength);
	return strncat(obj->data, str, size);
}

char *safe_strncpy(csafestring_t *obj, const char *str, size_t size) {
	safe_resizeBuffer(obj, size);
	return strncpy(obj->data, str, size);
}

size_t safe_strxfrm(csafestring_t *dest, csafestring_t *src, size_t size) {
	safe_resizeBuffer(dest, size * 2);
	return strxfrm(dest->data, src->data, size);
}

// Additional functions
char *safe_strchrappend(csafestring_t *obj, const char chr) {
	size_t newLength = strlen(obj->data) + 1;
	safe_resizeBuffer(obj, newLength);

	obj->data[newLength - 1] = chr;
	obj->data[newLength] = '\0';
	return obj->data;
}