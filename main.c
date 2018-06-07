#define PLAYER 1
#define ENEMY 2


#define BLUE 0
#define RED 1
float myState[12];
float myPos[3];
float myVelocity[3];

float enemyPos[3];
float enemyState[12];
float enemyVelocity[3];

float target[3];
int step;
typedef struct _coord {
    int x;
    int y;
} Coord; 

typedef enum state {
    PLACING_SPS,
    DOCKING, 
    ASSEMBLY_DROPPING,
} states;

typedef struct sphere {
    int id;
    int blueOrRed; 
    float ZRState[12];
    float pos[3];
    float vel[3];
} Sphere;

Coord items[6];
Sphere player; 
Sphere enemy;
float spsDrop2[3];
float spsDrop3[3];

int blueOrRed;
int howMany;
void init() {

    step = 0;
    howMany = 0;
}

void loop() {
    updateInfo();

}


void updateInfo() {
    static int counter = 0;
    api.getMyZRState(player.ZRState);
    api.getOtherZRState(enemy.ZRState);
    for (int i = 0; i < 3; i++) {
        player.pos[i] = player.ZRState[i];
        enemy.pos[i] = enemy.ZRState[i];
        player.vel[i] = player.ZRState[i+3];
        enemy.vel[i] = enemy.ZRState[i+3];
    }
    if (counter == 0) {
        if (player.pos[2] > 0) {
            blueOrRed = BLUE;
        } else {
            blueOrRed = RED;
        }
    }
    counter++;
}
