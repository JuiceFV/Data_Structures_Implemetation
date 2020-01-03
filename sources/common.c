#include "../includes/common.h"

void write_error_log(const char* error_message, int line,
                            const char* file, const char* specific_dir) {
  FILE* fout;
  fout = fopen("error_logs.txt", "at");
  fprintf(fout, "Assertion error line %d, file(%s) %s\n%s\n", line, file,
          specific_dir, error_message);
  fclose(fout);
}

void write_log(const char* message, const char* function) {
  FILE* fout;
  fout = fopen("logs.txt", "at");
  fprintf(fout, "Function %s has successfully completed.\nDetails: %s\n\n",
          function, message);
  fclose(fout);
}
