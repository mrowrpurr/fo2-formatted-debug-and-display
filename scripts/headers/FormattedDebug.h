/*
    Usage:

        #define DEBUG_NAME "MyMod"
        
        procedure start begin
            // Prints to debug.log (depending on ddraw.ini configured DebugMode)
            // as "[MyMod] hello"
            debug("hello");
            
            variable x = 69;
            variable y = 420;
            
            // Print out a variable value
            debug1("hello", x); // <--- prints "[MyMod] hello (69)"
            
            // Print out multiple variable values
            debug1("hello", x, y); // <--- prints "[MyMod] hello (69) (420)"
            
            // Or specify where in the text the value(s) should go using "%s" as a placeholder
            // Must use the debug*f functions. If you use "%s" with the normal functions, Fallout will crash.
            debug1f("hello %s world", x);    // <--- prints "[MyMod] hello 69 world"
            debug2f("hi %s there %s", x, y); // <--- prints "[MyMod] hi 69 there 420"
        end
*/

#include "sfall/lib.strings.h"
#include "sfall/lib.arrays.h"

#define debug(text) debug_msg("[" + DEBUG_NAME + "] " + text)
#define debug_array(arr) debug(debug_array_str(arr))

#define debug1(text, a1)                     debug(sprintf(text +       " (%s)", a1))
#define debug2(text, a1, a2)                 debug(sprintf_array(text + " (%s) (%s)", [a1, a2]))
#define debug3(text, a1, a2, a3)             debug(sprintf_array(text + " (%s) (%s) (%s)", [a1, a2, a3]))
#define debug4(text, a1, a2, a3, a4)         debug(sprintf_array(text + " (%s) (%s) (%s) (%s)", [a1, a2, a3, a4]))
#define debug5(text, a1, a2, a3, a4, a5)     debug(sprintf_array(text + " (%s) (%s) (%s) (%s) (%s)", [a1, a2, a3, a4, a5]))
#define debug6(text, a1, a2, a3, a4, a5, a6) debug(sprintf_array(text + " (%s) (%s) (%s) (%s) (%s) (%s)", [a1, a2, a3, a4, a5, a6]))

#define debug1f(text, a1)                     debug(sprintf(text, a1))
#define debug2f(text, a1, a2)                 debug(sprintf_array(text, [a1, a2]))
#define debug3f(text, a1, a2, a3)             debug(sprintf_array(text, [a1, a2, a3]))
#define debug4f(text, a1, a2, a3, a4)         debug(sprintf_array(text, [a1, a2, a3, a4]))
#define debug5f(text, a1, a2, a3, a4, a5)     debug(sprintf_array(text, [a1, a2, a3, a4, a5]))
#define debug6f(text, a1, a2, a3, a4, a5, a6) debug(sprintf_array(text, [a1, a2, a3, a4, a5, a6]))
