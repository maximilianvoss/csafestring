#ifndef CSAFESTRING_CSAFESTRING_H
#define CSAFESTRING_CSAFESTRING_H

#include <stdlib.h>

typedef struct {
	char *data;
	size_t buffer_length;
} csafestring_t;

#define INIT_LENGTH 1<<2

csafestring_t *safe_create(char *);
void safe_destroy(csafestring_t *);

#define safe_strchr(obj, chr) strchr(obj->data, chr)
#define safe_strcmp(obj, str) strcmp(obj->data, str)
#define safe_strcoll(obj, str) strcoll(obj->string, str)
#define safe_strcspn(obj, str) strcspn(obj->string, str)
#define safe_strlen(obj) strlen(obj->string)
#define safe_strpbrk(obj, str) strpbrk(obj->string, str)
#define safe_strrchr(obj, chr) strrchr(obj->string, chr)
#define safe_strspn(obj, str) strspn(obj->string, str)
#define safe_strstr(obj, str) strstr(obj->string, str)
#define safe_strtok(obj, chr) strtok(obj->string, chr)
#define safe_strerror(val) strerror(val)

char *safe_strcat(csafestring_t *, const char *);
char *safe_strcpy(csafestring_t *, const char *);
char *safe_strncat(csafestring_t *, const char *, size_t);
char *safe_strncpy(csafestring_t *, const char *, size_t);
size_t safe_strxfrm(csafestring_t *, csafestring_t *, size_t);
int safe_strncmp(csafestring_t *, const char *, size_t);
void *safe_memchr(csafestring_t *, int, size_t);
int safe_memcmp(csafestring_t *, csafestring_t *, size_t);
void *safe_memcpy(csafestring_t *, csafestring_t *, size_t);
void *safe_memmove(csafestring_t *, csafestring_t *, size_t);
void *safe_memset(csafestring_t *, int, size_t);

#endif
