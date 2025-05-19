#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *
__memcpy_chk (void *dstpp, const void *srcpp, size_t len, size_t dstlen)
{
  if (dstlen < len){
  	const char *error_message = "Error: destination buffer is too small.\n";
    	fwrite(error_message, 1, strlen(error_message), stderr);
    	abort();
  }
  return memcpy (dstpp, srcpp, len);
}