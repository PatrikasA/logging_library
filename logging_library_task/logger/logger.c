#include "logger.h"

FILE *LOG = NULL;

void get_current_time(char** time_string)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(*time_string,"%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

char* get_message_level(int message_level)
{
    switch(message_level){
        case 1:
            return "INFO   ";
            break;
        case 2:
            return "WARNING";
            break;
        case 3:
            return "ERROR  ";
            break;
        default:
            return "MISC   ";
            break;
    }
}

void open_log_file(char *mode)
{
    LOG = fopen(LOG_LOCATION, mode);
        if(LOG == NULL){
            printf("Failed to open file\n");
            exit(1);
        }
}

void close_log_file()
{
    fclose(LOG);
}

void write_to_log(char* program, char* log_message, int message_level)
{
    char* time_string=malloc(sizeof(char)*255);
    get_current_time(&time_string);

    fprintf(LOG,"%s | %s | %s | %s", get_message_level(message_level), time_string, program, log_message);

    free(time_string);
}

FILE** get_file_pointer()
{
    return &LOG;
}