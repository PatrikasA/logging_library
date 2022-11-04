#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "logger.h"

void get_current_time(char** time_string)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(*time_string,"now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void open_log_file(char *mode)
{
    fopen(LOG_LOCATION, mode);
}

void close_log_file()
{

}

int main(int argc, char* argv[])
{
  char* time_string = malloc(sizeof(char)*255);
  get_current_time(&time_string);
  printf("%s",time_string);
}