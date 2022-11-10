#include "logger.h"

void create_database()
{
    char* err=NULL;

    char* table = "CREATE TABLE IF NOT EXISTS Logs("
                "id INT,"
                "message_level TEXT,"
                "time TEXT,"
                "program TEXT,"
                "log_message TEXT);";
    
    int rc = sqlite3_exec(DATABASE, table, NULL, NULL, &err);
    if(rc != SQLITE_OK){
        printf("Failed to create database at create_database() in logger.c\n");
    }
    sqlite3_free(err);
}

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

void open_log_file()
{
    int rc = sqlite3_open(LOG_PATH, &DATABASE); 
    if(rc!=SQLITE_OK){
        printf("Failed to open database in logger.c\n");
        return;
    }
}

void close_log_file()
{
    int rc = sqlite3_close(DATABASE); 
    if(rc!=SQLITE_OK){
        printf("Failed to close database in logger.c\n");
        return;
    }
}

void write_to_log(char* program, char* log_message, int message_level)
{
    char* err;
    char* time_string=malloc(sizeof(char)*255);
    get_current_time(&time_string);

    char* temp = "INSERT INTO Logs (message_level, time, program, log_message) VALUES";
    char dbtext[255];
    snprintf(dbtext, 255, "%s('%s', '%s', '%s', '%s');",temp, get_message_level(message_level), time_string, program, log_message);
    int rc = sqlite3_exec(DATABASE, dbtext, NULL, NULL, &err);
    if(rc != SQLITE_OK){
        printf("Failed to insert log. Try sudo !!\n");
    }
    free(time_string);
}

sqlite3** get_database_pointer()
{
    return &DATABASE;
}
