#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;

int IsMouseOverButton(Rectangle button)
{
    Vector2 mousePoint = GetMousePosition();
    return CheckCollisionPointRec(mousePoint, button);
}

int *geraVet(int *vet, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }

    shuffle(vet, vet + tam, default_random_engine());

    return vet;
}

int main()
{
    int *vet, tam = (widthScreen / widthRect), exit = 0, ret = 0, opt, originalWidth = 800, originalHeight = 500;

    vet = (int *)malloc(tam * sizeof(int));

    if (!vet)
    {
        return 0;
    }

    InitWindow(originalWidth, originalHeight, "Visualização de Algoritmos de Ordenação");

    SetTargetFPS(0);

    Rectangle bubble = {300, 150, 200, 40};
    Rectangle seletion = {300, 200, 200, 40};
    Rectangle insertion = {300, 250, 200, 40};
    Rectangle merge = {300, 300, 200, 40};
    Rectangle quick = {300, 350, 200, 40};
    Rectangle heap = {300, 400, 200, 40};

    while (!WindowShouldClose() && !exit)
    {
        

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (IsMouseOverButton(bubble))
            {
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                bubbleSort(vet, tam);
                ViewOrd(vet, tam);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
            else if (IsMouseOverButton(seletion))
            {
                SetTargetFPS(200);
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                seletionSort(vet, tam);
                ViewOrd(vet, tam);
                SetTargetFPS(0);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
            else if (IsMouseOverButton(insertion))
            {
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                insertionSort(vet, tam);
                ViewOrd(vet, tam);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
            else if (IsMouseOverButton(merge))
            {
                SetTargetFPS(200);
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                mergeSort(vet, tam, 0, tam - 1);
                ViewOrd(vet, tam);
                SetTargetFPS(0);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
            else if (IsMouseOverButton(quick))
            {
                SetTargetFPS(200);
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                quickSort(vet, tam, 0, tam - 1);
                ViewOrd(vet, tam);
                SetTargetFPS(0);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
            else if (IsMouseOverButton(heap))
            {
                SetTargetFPS(200);
                vet = geraVet(vet, tam);
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
                SetWindowPosition(0, 0);
                ToggleFullscreen();

                heapSort(vet, tam);
                ViewOrd(vet, tam);
                SetTargetFPS(0);
                ToggleFullscreen();
                SetWindowSize(originalWidth, originalHeight);
                SetWindowPosition((GetMonitorWidth(0) - originalWidth) / 2, (GetMonitorHeight(0) - originalHeight) / 2);
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("SORTING - VIEWER", 170, 30, 50, DARKGRAY);

        DrawText("Escolha um dos Algoritmos de Ordenação", 200, 100, 20, DARKGRAY);

        DrawRectangleRec(bubble, GRAY);
        DrawRectangleLinesEx(bubble, 2, DARKGRAY);
        DrawText("Bubble Sort", bubble.x + 30, bubble.y + 10, 20, WHITE);

        DrawRectangleRec(seletion, GRAY);
        DrawRectangleLinesEx(seletion, 2, DARKGRAY);
        DrawText("Selection Sort", seletion.x + 30, seletion.y + 10, 20, WHITE);

        DrawRectangleRec(insertion, GRAY);
        DrawRectangleLinesEx(insertion, 2, DARKGRAY);
        DrawText("Insertion Sort", insertion.x + 30, insertion.y + 10, 20, WHITE);

        DrawRectangleRec(merge, GRAY);
        DrawRectangleLinesEx(merge, 2, DARKGRAY);
        DrawText("Merge Sort", merge.x + 30, merge.y + 10, 20, WHITE);

        DrawRectangleRec(quick, GRAY);
        DrawRectangleLinesEx(quick, 2, DARKGRAY);
        DrawText("Quick Sort", quick.x + 30, quick.y + 10, 20, WHITE);

        DrawRectangleRec(heap, GRAY);
        DrawRectangleLinesEx(heap, 2, DARKGRAY);
        DrawText("Heap Sort", heap.x + 30, heap.y + 10, 20, WHITE);

        DrawText("Desenvolvido por: Tiago de Figueiredo Reis", 10, 470, 20, DARKGRAY);

        if (IsMouseOverButton(bubble))
            DrawRectangleLinesEx(bubble, 3, BLACK);
        if (IsMouseOverButton(seletion))
            DrawRectangleLinesEx(seletion, 3, BLACK);
        if (IsMouseOverButton(insertion))
            DrawRectangleLinesEx(insertion, 3, BLACK);
        if (IsMouseOverButton(merge))
            DrawRectangleLinesEx(merge, 3, BLACK);
        if (IsMouseOverButton(quick))
            DrawRectangleLinesEx(quick, 3, BLACK);
        if (IsMouseOverButton(heap))
            DrawRectangleLinesEx(heap, 3, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
