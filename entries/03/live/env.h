

#ifndef ENV

#define ENV

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

typedef struct player {
   int x;
   int y;
   int health;
   int anger;
   int lastdir;
   int kills;
   int color;
   int symbol;
   int alive;
   const char * name;
} player;

typedef struct env {
   player ** players;
   int player_count;
} env;

player * allocate_player();

void init_env(int player_count, env * e);
void destroy_env(env * e);

int step_env(env * e);
void render_env(env * e);

player * get_winner(env * e);

#endif

