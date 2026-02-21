#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "env.h"
#include "names.h"

#define MAP_WIDTH  100
#define MAP_HEIGHT 40

#define MAX_ANGER 15
#define STARTING_HEALTH 25

const char * get_name() {

   int name = rand();

   return names[ name % TOTAL_NAMES ];
}

player * allocate_player() {

   const char * player_name = get_name();
   int x = rand() % MAP_WIDTH;
   int y = rand() % MAP_HEIGHT;
   int health = STARTING_HEALTH;
   int anger = rand() % MAX_ANGER+1;
   int color = 21 + (rand() % 209);
   int symbol = player_name[0];

   player * p = malloc(sizeof(player));

   return p;
}

void init_env(int player_count, env * e) {

   e->player_count = player_count;
   e->players = malloc(sizeof(player *) * player_count);

   for (int i = 0; i < player_count; ++i)
      e->players[i] = allocate_player();
}

player * get_winner(env * e) {
   for (int i = 0; i < e->player_count; ++i) {
      player * p = e->players[i];

      if (p->alive == 1)
         return p;
   }
   return 0;
}

void destroy_env(env * e) {

   for (int i = 0; i < e->player_count; ++i)
      free(e->players[i]);

   free(e->players);
}


