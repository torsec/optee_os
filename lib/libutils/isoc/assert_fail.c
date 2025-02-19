#include <compiler.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>


void __assert_fail (const char *__assertion, const char *__file,
			   unsigned int __line, const char *__function)
     {
     	abort();
     }

void exit(int status){
};