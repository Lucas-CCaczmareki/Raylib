#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Screen settings
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Centralizando itens");
    SetTargetFPS(60);

    //Load Texture
    Texture2D shadowTexture = LoadTexture("resources/shadow.png");

    //Configuration for layout
    const char* myText = "SHADOW O OURICO";
    int fontSize = 20;

    /*
        Essa é uma fórmula padrão pra achar o centro. Considerando que (0, 0) é sempre o canto superior esquerdo da janela.
        Você calcula o centro (largura/2), mas se começar a desenhar sua imagem ali ele vai ficar deslocada pra ->
        
        Então você recua metade do tamanho da sua imagem pra começar a desenhar, garantindo que o meio da sua imagem
        fique alinhado com o meio da tela
    */
    
    //Para mover o shadow, a posição da imagem dele precisa ser uma variável.
    /*
    //Calculate centered X positions
    float imageX = (screenWidth / 2.0f) - (imageDrawWidth / 2.0f);
    float textX = (screenWidth / 2.0f) - (textWidth / 2.0f);

    //Centralize the entire block.
    float totalContentHeight = imageDrawHeight + padding + fontSize;

    //Calculate stacked Y positions
    
    float textY = imageY + imageDrawHeight + padding; //ao somar o padding ele vem pra baixo
    */

    
    //Usamos um Vector2 para guardar a posição (x, y) do Shadow
    //Inicializa ele no centro da tela
    Vector2 shadowPosition = { (screenWidth / 2.0f), (screenHeight / 2.0f) };

    //Velocidade do personagem (em pixels por quadro)
    float speed = 5.0f;

    //Define new, smaller dimensions for the image
    //Let's suppose 128x128 pixels
    float imageDrawWidth  = 128;
    float imageDrawHeight = 128;

    //Define Rectangles for DrawTextPro
    //1. Source rectangle (selects the entire original image)
    Rectangle sourceRect = {0.0f, 0.0f, (float)shadowTexture.width, (float)shadowTexture.height};

    //2. Destination rectangle (where to draw on screen and at what size)
    Rectangle destRect = { shadowPosition.x, shadowPosition.y, imageDrawWidth, imageDrawHeight };

    Vector2 origin = { imageDrawWidth / 2.0f, imageDrawHeight / 2.0f };

    //Main game loop
    while(!WindowShouldClose()) { //detect window close button or esc key
        //UPTADE THE VARIABLES HERE
        
        // Essa seção verifica os inputs e atualiza as variáveis ANTES de desenhar

        // IsKeyDown verifica se a tecla ESTÁ SENDO pressionada
        if (IsKeyDown(KEY_W)) shadowPosition.y -= speed; //Em computação gráfica, o Y diminui para subir
        if (IsKeyDown(KEY_A)) shadowPosition.x -= speed;
        if (IsKeyDown(KEY_S)) shadowPosition.y += speed;
        if (IsKeyDown(KEY_D)) shadowPosition.x += speed;

        //Atualiza a posição onde o shadow vai ser desenhado
        destRect.x = shadowPosition.x;
        destRect.y = shadowPosition.y;

        //Draw
        BeginDrawing();
            //Limpa a janela pra não ter nenhum shadow residual.
            ClearBackground(RAYWHITE);

            /*
                Essa função recebe a imagem, faz uma seleção em formato de retângulo (sourceRect) e 
                pinta no retângulo que foi selecionado (destRect) dentro da janela.

                Vector2 é o ponto aonde a imagem vai rotacionar, e 0.0f é o ângulo que ela vai rotacionar.
                É como se você fixasse a imagem naquele ponto, e ao girá-la ela gira em relação à ele
            */
            DrawTexturePro(shadowTexture, sourceRect, destRect, origin, 0.0f, WHITE);    //use white to keep the original colors

            DrawText(myText, 10, 10, fontSize, RED);

        EndDrawing();
    }

    //Finaliza o programa quando o cara fecha
    UnloadTexture(shadowTexture);
    CloseWindow();

    return 0;

}