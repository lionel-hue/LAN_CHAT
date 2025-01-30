::Intelligent compiler v1;
@echo off
 
gcc -c ../sys_src_files/*.c ../Pages/*.c ../Pages/disc_pg/*.c  ../Pages/settings_pg/*c ../cjson_include/cJSON.c ../*.c

gcc ./*.o -o ./main -lws2_32

mv ./main.exe ./.. 

pause