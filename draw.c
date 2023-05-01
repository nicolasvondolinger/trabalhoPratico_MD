#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCALE 10

void draw_line(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(renderer, x1 * SCALE, SCREEN_HEIGHT - y1 * SCALE, x2 * SCALE, SCREEN_HEIGHT - y2 * SCALE);
}

void draw_von_koch(SDL_Renderer *renderer, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo %s\n", filename);
        exit(1);
    }

    int x = 0;
    int y = 0;
    int direction = 0;
    int stack[1000];
    int top = -1;
    char c;

    while ((c = fgetc(file)) != EOF) {
        switch (c) {
            case 'F':
                int new_x = x + (int)(cos(direction * M_PI / 180.0) * SCALE);
                int new_y = y + (int)(sin(direction * M_PI / 180.0) * SCALE);
                draw_line(renderer, x, y, new_x, new_y);
                x = new_x;
                y = new_y;
                break;
            case '-':
                direction += 60;
                break;
            case '+':
                direction -= 60;
                break;
            case 'S':
                top++;
                stack[top] = x;
                top++;
                stack[top] = y;
                top++;
                stack[top] = direction;
                break;
            case 'R':
                direction = stack[top];
                top--;
                y = stack[top];
                top--;
                x = stack[top];
                top--;
                break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Curva de Von Koch", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    draw_von_koch(renderer, argv[1]);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
