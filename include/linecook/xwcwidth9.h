#ifndef __linecook__xwcwidth9_h__
#define __linecook__xwcwidth9_h__

#include <uchar.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
from https://github.com/joshuarubin/wcwidth9

Return values:

 1: default value when other tests fail
 2: the width emoji or east asian / non-latin char
 0: non-printable, control character, etc
-1: invalid char, outside range [0-0x10ffff]

other cases deleted and will return 1 (don't expect them)
-1  combining or unassigned character
-2: ambiguous width character
-3: private-use character
*/

int xwcwidth9( char32_t c ); /* table lookup */

static inline int wcwidth9( char32_t c ) { /* terminal width of character */
  return ( c >= ' ' && c < 128 ) ? 1 : xwcwidth9( c );
}

#ifdef __cplusplus
}
#endif

#endif /* WCWIDTH9_H */
