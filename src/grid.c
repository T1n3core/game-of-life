#include "../include/grid.h"

// returns -1 if index is out of bounds
int grid_index(const grid *const g, int i, int j) {
  if (i >= g->size || j >= g->size)
    return -1;

  return i * g->size + j;
}

grid grid_create() {
  uint8_t *data =
      malloc(GRID_DEFAULT_SIZE * GRID_DEFAULT_SIZE * sizeof(uint8_t));

  if (!data) {
    errno = ENOMEM;
    return (grid){NULL, 0};
  }

  return (grid){data, GRID_DEFAULT_SIZE * GRID_DEFAULT_SIZE};
}

void grid_init(grid *const g) {
  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      g->data[grid_index(g, i, j)] = 0;
    }
  }
}

void grid_resize(grid *const g) {
  uint8_t *data =
      realloc(g->data, g->size * GRID_RESIZE_FACTOR * sizeof(uint8_t));

  if (!data)
    return;

  g->data = data;
  g->size *= GRID_RESIZE_FACTOR;
}

// returns 0 for off, 1 for on and 2 for error
uint8_t grid_check(const grid *const g, int i, int j) {
  int idx = grid_index(g, i, j);

  if (idx == -1)
    return 2;

  return (g->data[idx]) ? 1 : 0;
}

// if the index is out of bounds nothing happens
void grid_flip(grid *const g, int i, int j) {
  int idx = grid_index(g, i, j);

  if (idx == -1)
    return;

  g->data[idx] = (g->data[idx] == 0) ? 1 : 0;
}

void grid_destroy(grid *const g) {
  free(g->data);
  g->size = 0;
}
