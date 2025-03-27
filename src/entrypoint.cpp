#include "entrypoint.h"
#include "raylib.h"
#include <time.h>
#define MAX_COL 14
#define MAX_ROW 14
#define WIN_W MAX_COL * RECT_SIZE
#define WIN_H MAX_ROW * RECT_SIZE
#define RECT_SIZE 64
class Vector{
    private:
    float MovementX, MovementY;
    public:
    Vector();
    void Set(float x, float y);
    void Show();
};
//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
bool zombies[MAX_ROW][MAX_COL] = {0}; 
void raylib_start(void)
{
    InitWindow(WIN_W, WIN_H, "conways.test");
    SetRandomSeed(time(NULL));
    for(int i= 0; i < MAX_ROW;++i){
        for(int z = 0; z < MAX_COL;++z ){
            zombies[i][z] = GetRandomValue(0,1);
        }
    }
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        for(int y = 0; y < MAX_ROW;y++){
            for(int x = 0; x < MAX_COL;++x){
                float offset = (y % 2 == 0) * RECT_SIZE;
                if(zombies[y][x]){
                    DrawRectangle(x*RECT_SIZE,y*RECT_SIZE,RECT_SIZE,RECT_SIZE, BLACK);
                }
                if(x % 2 == 0){
                    Rectangle get_rekt = CLITERAL(Rectangle){
                        (float)(x*RECT_SIZE + offset),(float)(y*RECT_SIZE),
                        RECT_SIZE,RECT_SIZE
                    };
                    DrawRectangleLinesEx(
                        get_rekt,
                        4,
                        RED
                    );
                }
                else{
                    Rectangle get_rekt = CLITERAL(Rectangle){
                        (float)(x*RECT_SIZE - offset),(float)(y*RECT_SIZE),
                        RECT_SIZE,RECT_SIZE
                    };
                    DrawRectangleLinesEx(
                        get_rekt,
                        4,
                        BLUE
                    );
                }
            }
        }
        bool tempZombie[MAX_ROW][MAX_COL] = {0};
        for(int y = 0; y < MAX_ROW;y++){
            for(int x = 0; x < MAX_COL;++x){
                float offset = (y % 2 == 0) * RECT_SIZE;
                if(tempZombie[y][x]){
                    DrawRectangle(x*RECT_SIZE,y*RECT_SIZE,RECT_SIZE,RECT_SIZE, YELLOW);
                    if(zombies[y][x] == 3){
                       
                    }
                    if(zombies[y][x] == 2 || zombies[y][x] == 3){
                        
                    }
                    else{
                    return;
                    }
                }   
            }  
        }
        EndDrawing(); 
        //calculer prochaine etape: voir les voisins, appliquer les regles de vie, inserer les resultats dans un zombie temporaire, ecraser les zombies avec le zombie temporaire
    }
}       
                     