#include <string.h>
#include <printf.h>
#include "../csafestring.h"

#define TESTCALL(TESTNAME, TESTMETHOD)\
    if ( argv[1] == NULL ) \
        TESTMETHOD();\
    else\
		if (!strcmp(argv[1], TESTNAME))\
			return TESTMETHOD();

#define ASSERTSTR(EXPECTED, ACTUAL)\
    printf("Expected: \t%s\nActual: \t%s\n\n", EXPECTED, ACTUAL);\
    if (strcmp(EXPECTED, ACTUAL))\
        return 1;

#define ASSERTINT(EXPECTED, ACTUAL)\
    printf("Expected: \t%d\nActual: \t%ld\n\n", EXPECTED, ACTUAL);\
    if (EXPECTED != ACTUAL)\
        return 1;

#define STRING "abcdefghijklmnopqrstuvwxyz 0123456789 "
#define STRING_10 "abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 "
#define STRING_10_X "abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 \
abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 !"
#define STRING_11 "abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz \
0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 abcdefghijklmnopqrstuvwxyz 0123456789 "

int test_createEmpty() {
	csafestring_t *string = safe_create(NULL);

	ASSERTINT(4, string->buffer_length);

	safe_destroy(string);
	return 0;
}

int test_createFull() {
	csafestring_t *string = safe_create(STRING);

	ASSERTSTR(STRING, string->data);
	ASSERTINT(64, string->buffer_length);

	safe_destroy(string);
	return 0;
}

int test_concatination() {
	int i;
	csafestring_t *string = safe_create(STRING);
	for ( i = 0; i < 9; i++ ) {
		safe_strcat(string, STRING);
	}

	ASSERTSTR(STRING_10, string->data);
	ASSERTINT(512, string->buffer_length);

	safe_destroy(string);
	return 0;
}

int test_copy() {
	csafestring_t *string = safe_create(STRING_10);
	safe_strcpy(string, STRING);

	ASSERTSTR(STRING, string->data);
	ASSERTINT(512, string->buffer_length);

	safe_destroy(string);
	return 0;
}

int test_clone() {
	csafestring_t *string = safe_create(STRING_10);
	csafestring_t *clone = safe_clone(string);
	safe_strcat(clone, STRING);

	ASSERTSTR(STRING_10, string->data);
	ASSERTINT(512, string->buffer_length);
	ASSERTSTR(STRING_11, clone->data);
	ASSERTINT(512, clone->buffer_length);

	safe_destroy(string);
	safe_destroy(clone);
	return 0;
}

int test_strchrappend() {
	csafestring_t *string = safe_create(STRING_10);
	safe_strchrappend(string, '!');

	ASSERTSTR(STRING_10_X, string->data);
	ASSERTINT(512, string->buffer_length);

	safe_destroy(string);
	return 0;
}

int main(int argc, char **argv) {
	TESTCALL("createEmpty", test_createEmpty);
	TESTCALL("createFull", test_createFull);
	TESTCALL("concatination", test_concatination);
	TESTCALL("copy", test_copy);
	TESTCALL("clone", test_clone);
	TESTCALL("strchrappend", test_strchrappend);

	return -1;
}