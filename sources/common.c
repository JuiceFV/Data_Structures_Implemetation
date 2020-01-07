#include "../includes/common.h"

void write_error_log(const char* error_message, int line,
                            const char* file, const char* specific_dir) {
  FILE* fout;
  fout = fopen("error_logs.txt", "w");
  fprintf(fout, "Assertion error line %d, file(%s) %s\n%s\n", line, file,
          specific_dir, error_message);
  fclose(fout);
}