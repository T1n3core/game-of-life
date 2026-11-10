#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

#define GRID_DEFAULT_SIZE 64

typedef struct {
    uint8_t **data;
    size_t rows;
    size_t cols;
} grid;

grid grid_create() {
    grid g = {NULL, 0, 0};

    size_t rows = GRID_DEFAULT_SIZE;
    size_t cols = GRID_DEFAULT_SIZE;

    uint8_t **data = malloc(rows * sizeof(uint8_t *));

    if (!data) {
        errno = ENOMEM;
        return g;
    }

    for (int i = 0; i < rows; i++) {
        data[i] = malloc(cols * sizeof(uint8_t));

        if (!data[i]) {
            errno = ENOMEM;
            return g;
        }
    }

    g.data = data;
    g.rows = rows;
    g.cols = cols;

    return g;
}

void grid_init(grid *g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            g->data[i][j] = 0;
        }
    }
}

void grid_destroy(grid *g) {
    for (int i = 0; i < g->rows; i++) {
        free(g->data[i]);
    }

    free(g->data);
    g->rows = 0;
    g->cols = 0;
}