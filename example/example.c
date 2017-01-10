#include <printf.h>
#include "../csafestring.h"

int main(int argc, char **argv) {
	csafestring_t *test = safe_create(NULL);
	
	safe_strcpy(test, "Hello");
	safe_strchrappend(test, ' ');
	safe_strcat(test, "World!");
	
	printf("%s\n", test->data);
	return 0;
}