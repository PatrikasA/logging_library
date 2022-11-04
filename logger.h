#include <stdio.h>
#include <time.h>
#include <string.h>

#define LOG_LOCATION "/var/log/tarpine_uzduotis.log"
const FILE *LOG;
void get_current_time(char** time_string);
void open_log_file(char *mode);