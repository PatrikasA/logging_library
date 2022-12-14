#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

sqlite3* DATABASE = NULL;
const char* LOG_PATH = "/var/log/logger.db";

void create_database();
void get_current_time(char** time_string);
char* get_message_level(int message_level);
void open_log_file();
void close_log_file();
void write_to_log(char* program, char* log_message, int message_level);
sqlite3** get_database_pointer();