#pragma once

/*
    Logging module for Fallout 2 ~ by Mrowr Purr ~
*/

// Log levels
#define LOGGER_LEVEL_ALL   (7)
#define LOGGER_LEVEL_TRACE (6)
#define LOGGER_LEVEL_DEBUG (5)
#define LOGGER_LEVEL_INFO  (4)
#define LOGGER_LEVEL_WARN  (3)
#define LOGGER_LEVEL_ERROR (2)
#define LOGGER_LEVEL_FATAL (1)
#define LOGGER_LEVEL_NONE  (0)

#define LOGGER_LEVEL_ALL_NAME   "ALL"
#define LOGGER_LEVEL_TRACE_NAME "TRACE"
#define LOGGER_LEVEL_DEBUG_NAME "DEBUG"
#define LOGGER_LEVEL_INFO_NAME  "INFO"
#define LOGGER_LEVEL_WARN_NAME  "WARN"
#define LOGGER_LEVEL_ERROR_NAME "ERROR"
#define LOGGER_LEVEL_FATAL_NAME "FATAL"
#define LOGGER_LEVEL_NONE_NAME  "NONE"

// By default, show all logs.
variable                     LOGGER_LOG_LEVEL = LOGGER_LEVEL_ALL;
#define set_log_level(level) LOGGER_LOG_LEVEL = level
#define disable_logging      LOGGER_LOG_LEVEL = LOGGER_LEVEL_NONE
#define enable_logging_all   LOGGER_LOG_LEVEL = LOGGER_LEVEL_ALL

// By default, output logs to debug_msg.
variable                         LOGGER_DEBUG_MSG = true;
#define enable_log_to_debug_msg  LOGGER_DEBUG_MSG = true
#define disable_log_to_debug_msg LOGGER_DEBUG_MSG = false

// By default, do not output logs to display_msg.
variable                           LOGGER_DISPLAY_MSG = false;
#define enable_log_to_display_msg  LOGGER_DISPLAY_MSG = true
#define disable_log_to_display_msg LOGGER_DISPLAY_MSG = false

// By default, do not store output logs in memory for testing log output.
variable                     LOGGER_TEST = false;
#define enable_test_logging  LOGGER_TEST = true
#define disable_test_logging LOGGER_TEST = false

// By default, log output includes the log level as a prefix, e.g. [WARN]
variable                              LOGGER_DISPLAY_LOG_LEVEL = true;
#define enable_test_log_level_output  LOGGER_DISPLAY_LOG_LEVEL = true
#define disable_test_log_level_output LOGGER_DISPLAY_LOG_LEVEL = false

// When test logging is enabled, this is an array of all log messages.
// #include "TestHelpers/Logging.h" for macros for working with logs in tests.
variable LOGGER_TEST_LOGS;

// Reset logger to default configuration values
#define logger_reset \
    begin \
        LOGGER_LOG_LEVEL = LOGGER_LEVEL_TRACE; \
        LOGGER_DEBUG_MSG = true; \
        LOGGER_DISPLAY_MSG = false; \
        LOGGER_TEST = false; \
        free_array(LOGGER_TEST_LOGS); \
        LOGGER_TEST_LOGS = 0; \
    end \
    false

// The log procedure!
// Procedure because it uses local variables.
// Do not call directly.
// Only invoked if the current log level if >= the level provided to #log
procedure __log(variable level, variable text)
    if LOGGER_LOG_LEVEL and level <= LOGGER_LOG_LEVEL then begin
        if LOGGER_DEBUG_MSG then debug_msg(text);
        if LOGGER_DISPLAY_MSG then display_msg(text);
        if LOGGER_TEST then begin
            if not LOGGER_TEST_LOGS then begin
                LOGGER_TEST_LOGS = [];
                fix_array(LOGGER_TEST_LOGS);
            end
            resize_array(LOGGER_TEST_LOGS, len_array(LOGGER_TEST_LOGS) + 1);
            LOGGER_TEST_LOGS[len_array(LOGGER_TEST_LOGS) - 1] = text;
        end
    end
end

// The log() macro!
#define log(level, text) \
    HERE!!

// Helpers for logging for different levels
#define log_trace(text) log(LOGGER_LEVEL_TRACE, text)
#define log_debug(text) log(LOGGER_LEVEL_DEBUG, text)
#define log_info(text)  log(LOGGER_LEVEL_INFO, text)
#define log_warn(text)  log(LOGGER_LEVEL_WARN, text)
#define log_error(text) log(LOGGER_LEVEL_ERROR, text)
#define log_fatal(text) log(LOGGER_LEVEL_FATAL, text)

// #define LOGGER_LEVEL_ALL   (7)
// #define LOGGER_LEVEL_TRACE (6)
// #define LOGGER_LEVEL_DEBUG (5)
// #define LOGGER_LEVEL_INFO  (4)
// #define LOGGER_LEVEL_WARN  (3)
// #define LOGGER_LEVEL_ERROR (2)
// #define LOGGER_LEVEL_FATAL (1)
// #define LOGGER_LEVEL_NONE  (0)