#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int screenWidht = 800;
    const int screenHeight = 450;

    InitWindow(screenWidht, screenHeight, "Teste Scroll do Mouse");

    int boxPositionY = screenHeight/2 -40; //esse -40 é metade do tamanho do quadrado
    int scrollSpeed = 4;

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        /*
            Essa função retorna 1.0 se eu movi pra cima a roda
            -1.0 se eu movi pra baixo e 0 se ta parada.
            
            Como a gente quer que isso fique de uma forma intuitiva
            ou seja, roda pra cima, quadrado pra cima, etc

            Precisamos diminuir o Y pra ir pra cima, pois...
            em CG o (0,0) é no canto superior esquerdo
            E por convenção, o Y aumenta pra baixo e o X aumenta pra direita.
        */

        boxPositionY -= (int)(GetMouseWheelMove()*scrollSpeed);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(screenWidht/2 - 40, boxPositionY, 80, 80, MAROON);

            DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY);
            DrawText(TextFormat("Box Position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY);

        EndDrawing();

    }
     
    CloseWindow();
    return 0;
}