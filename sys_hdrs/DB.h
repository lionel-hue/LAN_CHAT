#define bits 2048  //one byte of msg...
#include "../cjson_include/cJSON.h"
#include <stdio.h>


typedef struct DB{
    
    char buffer[bits];

    cJSON* layer_1;
    cJSON* layer_2;
    cJSON* layer_3;
    cJSON* layer_4;
    cJSON* layer_5;

    FILE *fp, *fp1;

    char* (* SELECT)(int, char*, char*, char*, struct DB *);
    void (* UPDATE)( char*, int, char*, char*, char*, struct DB *);

}DB;