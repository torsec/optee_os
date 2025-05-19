#include <ctype.h>
#include <string.h>

# define TOLOWER(Ch) tolower (Ch)

int strcasecmp (const char *s1, const char *s2)
{
  const unsigned char *p1 = (const unsigned char *) s1;
  const unsigned char *p2 = (const unsigned char *) s2;
  int result;
  if (p1 == p2)
    return 0;
  while ((result = TOLOWER (*p1) - TOLOWER (*p2++)) == 0)
    if (*p1++ == '\0')
      break;
  return result;
}
