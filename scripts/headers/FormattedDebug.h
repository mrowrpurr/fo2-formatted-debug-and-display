#pragma once

#include "sfall/lib.arrays.h"  // for debug_array_str
#include "sfall/lib.strings.h" // for sprintf_array

#define debug(text) debug_msg(DEBUG_PREFIX + text)
#define debug_array(arr) debug(debug_array_str(arr))
#define debug_formatted_array(arr) debug_array(arr)

#define debug1(text, arg1) \
    debug(text + " (" + arg1 + ")")

#define debug2(text, arg1, arg2) \
    debug(text + " (" + arg1 + ") (" + arg2 + ")")

#define debug3(text, arg1, arg2, arg3) \
    debug(text + " (" + arg1 + ") (" + arg2 + ") (" + arg3 + ")")

#define debug4(text, arg1, arg2, arg3, arg4) \
    debug(text + " (" + arg1 + ") (" + arg2 + ") (" + arg3 + ") (" + arg4 + ")")

#define debug5(text, arg1, arg2, arg3, arg4, arg5) \
    debug(text + " (" + arg1 + ") (" + arg2 + ") (" + arg3 + ") (" + arg4 + ") (" + arg5 + ")")

#define debug6(text, arg1, arg2, arg3, arg4, arg5, arg6) \
    debug(text + " (" + arg1 + ") (" + arg2 + ") (" + arg3 + ") (" + arg4 + ") (" + arg5 + ") (" + arg6 + ")")

#define debug1f(text, arg1)                               debug(sprintf(text, arg1))
#define debug2f(text, arg1, arg2)                         debug(sprintf_array(text, [arg1, arg2]))
#define debug3f(text, arg1, arg2, arg3)                   debug(sprintf_array(text, [arg1, arg2, arg3]))
#define debug4f(text, arg1, arg2, arg3, arg4)             debug(sprintf_array(text, [arg1, arg2, arg3, arg4]))
#define debug5f(text, arg1, arg2, arg3, arg4, arg5)       debug(sprintf_array(text, [arg1, arg2, arg3, arg4, arg5]))
#define debug6f(text, arg1, arg2, arg3, arg4, arg5, arg6) debug(sprintf_array(text, [arg1, arg2, arg3, arg4, arg5, arg6]))
