#include "raylib.h"
#include "tabshow.h"
#include "tablogica.h"



void DesenharTabuleiro(Jogador* j) {
    for (int i = 0; i < 56; i++) {
        int x = (i % 28) * 40 + 20;
        int y = (i / 28) * 50 + 50;
        
        // Desenha o quadrado da casa (simplificado)
        DrawRectangle(x, y, 35, 45, LIGHTGRAY);
        
        // Se o jogador estiver nesta posição, desenha o peão
        if (j->posi == i) {
            DrawCircle(x + 17, y + 22, 10, MAROON);
        }
    }
}

void DesenharBotaoDado() {
    DrawRectangle(50, 400, 150, 50, GRAY);
    DrawText("LANÇAR DADO", 65, 415, 16, BLACK);
}







int main() {
    // Inicialização do modelo (Lógica)
    Jogador jogador1 = { .spcartas = 0, .posi = 0, .vez = 1 };
    Carta baralhoCompleto[max_baralho] = {}; // Preenche com as tuas cartas
    Pilhas pilhasDoJogo = makePilhas(baralhoCompleto);

    // Inicialização do Front-End
    InitWindow(800, 400, "Interface Separada da Lógica");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        // Exemplo: Se carregar no ESPAÇO, a lógica processa a casa atual do mapa
        if (IsKeyPressed(KEY_SPACE)) {
            int casaAtual = mapa[jogador1.posi];
            gereTiles(&jogador1, casaAtual, &pilhasDoJogo); // Passamos com '&' (ponteiro)
        }

        // --- DESENHO ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Prime ESPAÇO para ativar a tile atual!", 20, 20, 20, DARKGRAY);
        DrawText(TextFormat("Posição do Jogador: %d", jogador1.posi), 20, 60, 20, BLUE);
        DrawText(TextFormat("Cartas na Mão: %d", jogador1.spcartas), 20, 90, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
