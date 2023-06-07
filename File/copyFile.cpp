#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *source, *target;
  char buffer[4096];
  size_t bytes_read;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s source_file target_file\n", argv[0]);
    return 1;
  }

  source = fopen(argv[1], "rb");
  if (!source) {
    perror("Failed to open source file");
    return 1;
  }

  target = fopen(argv[2], "wb");
  if (!target) {
    perror("Failed to open target file");
    fclose(source);
    return 1;
  }

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
    if (fwrite(buffer, 1, bytes_read, target) != bytes_read) {
      perror("Failed to write to target file");
      fclose(source);
      fclose(target);
      return 1;
    }
  }

  fclose(source);
  fclose(target);
  return 0;
}
