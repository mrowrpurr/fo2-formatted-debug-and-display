#include "sfall/lib.strings.h"
#include "sfall/lib.arrays.h"

#define display(text) display_msg(text)
// #define display_array(arr) display(display_array_str(arr)) <--- already defined in lib.arrays.h

#define display1(text, a1) display(sprintf(text + " (%s)", a1))
#define display2(text, a1, a2) display(sprintf_array(text + " (%s) (%s)", [a1, a2]))
#define display3(text, a1, a2, a3) display(sprintf_array(text + " (%s) (%s) (%s)", [a1, a2, a3]))

#define display1f(text, a1) display(sprintf(text, a1))
#define display2f(text, a1, a2) display(sprintf_array(text, [a1, a2]))
#define display3f(text, a1, a2, a3) display(sprintf_array(text, [a1, a2, a3]))
