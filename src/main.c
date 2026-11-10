#include "raylib.h"

int main(int argc, char *argv[]) {
  InitWindow(800, 600, "My Raylib Window");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
