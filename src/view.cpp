#include "../include/View.h"
#include "../include/raylib.h"

int viewVet(int *vet, int tam, Color color)
{
    for (int i = 0; i < tam; i++)
    {
        if(IsKeyPressed(KEY_ESCAPE)){
            return 1;
        }
        
        DrawRectangle(widthRect * i, heightScreen - vet[i], widthRect, vet[i], color);
    }

    return 0;
}

int ViewOrd(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        BeginDrawing();

        if(IsKeyPressed(KEY_ESCAPE)){
            return 1;
        }

        ClearBackground(BLACK);

        if(viewVet(vet, tam, WHITE)){
            return 1;
        }

        if(viewVet(vet, i, GREEN)){
            return 1;
        }

        EndDrawing();
    }

    return 0;
}

int viewIt(int *vet, int tam, int i, int j)
{

    BeginDrawing();

    ClearBackground(BLACK);

    if(viewVet(vet, tam, WHITE)){
        return 1;
    };

    if(IsKeyPressed(KEY_ESCAPE)){
        return 1;
    }

    DrawRectangle(i * widthRect, heightScreen - vet[i], widthRect, vet[i], RED);

    DrawRectangle(j * widthRect, heightScreen - vet[j], widthRect, vet[j], RED);

    EndDrawing();

    return 0;
}