#pragma once

// TODO! Include a Logger.h please :) With LOG LEVELS!
//       Make it totally separate (all of them)
//       so folks can use it without the rest :)
//
//       Maybe same repo, maybe not...

// Note: do not use sprintf_array because ...

// For debug_array_str().
#include "sfall/lib.arrays.h"

// Whether or not calls to debug() actually output to debug_msg()
variable __formatted_debug__output_enabled = true;
#define enable_debug_output 

// When configured, all text sent to debug() is prefixed with this text.
variable                         __formatted_debug__prefix;
#define set_debug_prefix(prefix) __formatted_debug__prefix = prefix
#define clear_debug_prefix       __formatted_debug__prefix = 0

// When configured, the prefix (if set) is added to each line of debug() text.
// Default: true
variable                           __formatted_debug__prefix_each_line = true;
#define enable_debug_lines_prefix  __formatted_debug__prefix_each_line = true
#define disable_debug_lines_prefix __formatted_debug__prefix_each_line = false

// When configured, all text sent to debug() is suffixed with this text.
variable                         __formatted_debug__suffix;
#define set_debug_suffix(suffix) __formatted_debug__suffix = suffix
#define clear_debug_suffix       __formatted_debug__suffix = 0

// When configured, the suffix (if set) is added to each line of debug() text.
// Default: true
variable                           __formatted_debug__suffix_each_line = true;
#define enable_debug_lines_suffix  __formatted_debug__suffix_each_line = true
#define disable_debug_lines_suffix __formatted_debug__suffix_each_line = false

// Silly variable so you can call debug(); with a semicolon
variable __formatted_debug__use_in_macro_to_support_semicolon;

// Variable used to build the output text of debug()
// (because #debug is currently a pure macro sans procedure)
variable __formatted_debug__output_text;






// ADD THE TESTING STUFF HERE!

// Simply calls debug_msg but will prepend/append a configured prefix/suffix
#define debug(text) \
    begin \

    end

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
