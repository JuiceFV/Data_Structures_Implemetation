#include "../includes/error.h"

void write_error_log(const char* error_message, int line, const char* file,
                     const char* specific_dir) {
  FILE* fout;
  fout = fopen("error_logs.txt", "a");
  fprintf(fout, "Assertion error %s:%d %s\t%s\n\n", file, line, specific_dir,
          error_message);
  fclose(fout);
}

#if defined(__GNUC__)
static void itoa(int value, char* buf, int base){	
int i = 30;			
buf = "";				
for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;				
}
#endif

char* cat_dir_and_num(const char const* dir, int line) {
    char* result = (char*)malloc(sizeof(char) * 4);
    strcpy(result, "-> ");

    int len = strlen(dir);
    char buff[4];
    itoa(line, buff, 10);
    len += strlen(buff);
    if (!(result = (char*)realloc(result, sizeof(char) * len + 4))) {
        exit(-1);
    }
    
    int i = 3;
    int k = 0;
    while (dir[k])
        result[i++] = dir[k++];

    k = 0;
    while (buff[k])
        result[i++] = buff[k++];
    result[i] = '\0';
    return result;
}
