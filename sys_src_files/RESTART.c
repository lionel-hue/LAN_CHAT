#include <stdlib.h>
#include <string.h>

#include "../sys_hdrs/DECLARE.h"

void restart( char *app_name ){

    char sys_exit[bits] = "cls && ";
    system( strncat( sys_exit, app_name, sizeof sys_exit -1 ) );
}