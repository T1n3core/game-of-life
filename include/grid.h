#ifndef GRID_H
#define GRID_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define GRID_DEFAULT_SIZE 64
#define GRID_RESIZE_FACTOR 2

// flattened 2D grid, always square, size represents one of the square's sides
typedef struct {
  uint8_t *data;
  size_t size;
} grid;

int grid_index(const grid *const g, int i, int j);
grid grid_create();
void grid_init(grid *const g);
void grid_resize(grid *const g);
uint8_t grid_check(const grid *const g, int i, int j);
void grid_flip(grid *const g, int i, int j);
void grid_destroy(grid *const g);

#ifdef __cplusplus
}
#endif

#endif
