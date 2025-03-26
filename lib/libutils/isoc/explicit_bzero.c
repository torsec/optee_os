#include <string.h>

void
explicit_bzero (void *s, size_t len)
{
  memset (s, '\0', len);
}
