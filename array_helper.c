
#include "array_helper.h"
#include "team.h"
#include <stdio.h>

void array_dump(team a[], unsigned int length) {

  for (size_t i = 0; i < length; i++) {
    print_team(a[i]);
  }
}

unsigned int array_from_file(team array[], unsigned int max_size,
                             const char *filepath) {
  FILE *file = NULL;
  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }
  unsigned int i = 0u;
  unsigned int size = 0u;
  unsigned int res = 0u;
  while (i < max_size) {
    // team t = empty_team();
    char name[30];
    stadistics atk = 0;
    stadistics mid = 0;
    stadistics def = 0;
    res = fscanf(file, INPUT_FORMAT, name, &atk, &mid, &def);
    if (res != 4) {
      fprintf(stderr, "Invalid array.\n");
      exit(EXIT_FAILURE);
    }
    array[i] = team_to_array(atk, mid, def, name);
    i++;
  }
  fclose(file);
  return (size);
}
