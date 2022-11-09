#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define LOG_LOCATION "/var/log/tarpine_uzduotis.log"
//#define LOG_LOCATION "logas.txt"

void create_database();
void get_current_time(char** time_string);
char* get_message_level(int message_level);
void open_log_file();
void close_log_file();
void write_to_log(char* program, char* log_message, int message_level);
sqlite3** get_database_pointer();