#pragma once

// Usage of #include "NamedDebug.h" and #include "TestNamedDebug.g"
// require setting DEBUG_NAME:
//
// #define DEBUG_NAME "This will be the prefix for debug_msg outputs"

// Put the messages which are debug()'d into an array
// which is exported so tests can verify debug messages.
export variable __TestNamedDebug__Messages__Export;

// Hack: the compiler does not support array syntx
// when using export/import variables
variable __TestNamedDebug__Messages;

// Read the variable name (lol)
// Some of our macros end on `end` which you cannot add a ; semicolon after.
// So we just finish the macro with:
//    __test_named_debug__use_in_macro_to_support_semicolon = 0
// It's dumb but it provides a consistent syntax for developer experience
variable __test_named_debug__use_in_macro_to_support_semicolon;

// When this debug is called, it adds messages to an array instead of
// actually outputting via debug_msg. Although there is an option to
// have it *also* print out to debug_msg using: enable_test_debug_output.
// Output is disabled by default.
#define debug(text) debug_with_debug_name(text, DEBUG_NAME)

// Provides a way of explicitly providing DEBUG_NAME for testing
#define debug_with_debug_name(text, debug_name) \
    begin \
        if not __TestNamedDebug__Messages then begin \
            __TestNamedDebug__Messages__Export = {}; \
            fix_array(__TestNamedDebug__Messages__Export); \
            __TestNamedDebug__Messages = __TestNamedDebug__Messages__Export; \
        end \
        if not map_contains_key(__TestNamedDebug__Messages, debug_name) then begin \
            __TestNamedDebug__Messages[debug_name] = []; \
            fix_array(__TestNamedDebug__Messages); \
        end \
        call array_push(__TestNamedDebug__Messages[debug_name], text); \
    end \
    __test_named_debug__use_in_macro_to_support_semicolon = 0

// Returns array of messages (for the DEBUG_NAME)
#define test_debug_messages test_debug_messages_for_debug_name(DEBUG_NAME)
#define test_debug_messages_for_debug_name(debug_name) (__TestNamedDebug__Messages[debug_name] if __TestNamedDebug__Messages and map_contains_key(__TestNamedDebug__Messages, debug_name) else [])

// Returns count of messages (for the DEBUG_NAME)
#define test_debug_message_count test_debug_message_count_for_debug_name(DEBUG_NAME)
#define test_debug_message_count_for_debug_name(debug_name) (len_array(__TestNamedDebug__Messages[debug_name]) if len_array(__TestNamedDebug__Messages__Export) != -1 and  map_contains_key(__TestNamedDebug__Messages, debug_name) else 0)

// Returns the most recent debug message (or 0)
#define most_recent_test_debug_message most_recent_test_debug_message_for_debug_name(DEBUG_NAME)
#define most_recent_test_debug_message_for_debug_name(debug_name) (get_array(__TestNamedDebug__Messages[debug_name], (len_array(__TestNamedDebug__Messages[debug_name]) - 1)) if __TestNamedDebug__Messages and map_contains_key(__TestNamedDebug__Messages, debug_name) else 0)

// Returns debug message at index (or 0)
#define test_debug_message_at(index) test_debug_message_at_for_debug_name(index, DEBUG_NAME)
#define test_debug_message_at_for_debug_name(index, debug_name) (get_array(__TestNamedDebug__Messages[debug_name], index) if __TestNamedDebug__Messages and map_contains_key(__TestNamedDebug__Messages, debug_name) and len_array(__TestNamedDebug__Messages[debug_name]) > index else 0)

// Clear debug messages (for the DEBUG_NAME)
#define clear_test_debug_messages clear_test_debug_messages_for_debug_name(DEBUG_NAME)
#define clear_test_debug_messages_for_debug_name(debug_name) \
    begin \
        if __TestNamedDebug__Messages and map_contains_key(__TestNamedDebug__Messages, debug_name) then \
            call array_cut(__TestNamedDebug__Messages[debug_name], 0, len_array(__TestNamedDebug__Messages[debug_name])); \
    end \
    __test_named_debug__use_in_macro_to_support_semicolon = 0
