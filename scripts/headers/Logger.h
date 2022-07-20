#pragma once

/*
    Logging module for Fallout 2 ~ by Mrowr Purr ~
*/

// Log levels
#define LOGGER_LEVEL_TRACE (6)
#define LOGGER_LEVEL_DEBUG (5)
#define LOGGER_LEVEL_INFO  (4)
#define LOGGER_LEVEL_WARN  (3)
#define LOGGER_LEVEL_ERROR (2)
#define LOGGER_LEVEL_FATAL (1)
#define LOGGER_LEVEL_NONE  (0)

// By default, show all logs.
variable                     LOGGER_LOG_LEVEL = LOGGER_LEVEL_TRACE;
#define set_log_level(level) LOGGER_LOG_LEVEL = level
#define disable_logging      LOGGER_LOG_LEVEL = LOGGER_LEVEL_NONE

// By default, output logs to debug_msg.
variable                         LOGGER_DEBUG_MSG = true;
#define enable_log_to_debug_msg  LOGGER_DEBUG_MSG = true
#define disable_log_to_debug_msg LOGGER_DEBUG_MSG = false

// By default, do not output logs to display_msg.
variable                           LOGGER_DISPLAY_MSG = false;
#define enable_log_to_display_msg  LOGGER_DISPLAY_MSG = true
#define disable_log_to_display_msg LOGGER_DISPLAY_MSG = false

// By default, do not store output logs in memory for testing log output.
variable                    LOGGER_TEST = false;
#define enable_test_logging LOGGER_TEST = true

// When test logging is enabled, this is an array of all log messages.
// #include "TestHelpers/Logging.h" for macros for working with logs in tests.
variable LOGGER_TEST_LOGS;

// The log macro!
#define log(level, text) \
    if LOGGER_LOG_LEVEL and level <= LOGGER_LOG_LEVEL then begin \
        if LOGGER_DEBUG_MSG then debug_msg(text); \
        if LOGGER_DISPLAY_MSG then display_msg(text); \
        if LOGGER_TEST then begin \
            if not LOGGER_TEST_LOGS then begin \
                LOGGER_TEST_LOGS = [];
                fix_array(LOGGER_TEST_LOGS);
            end \
            resize_array(LOGGER_TEST_LOGS, len_array(LOGGER_TEST_LOGS) + 1); \
            LOGGER_TEST_LOGS[len_array(LOGGER_TEST_LOGS) - 1] = text; \
        end \
    end \
    if false then debug_msg("")
