
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "env.h"
#include "names.h"

#define MAP_WIDTH  100
#define MAP_HEIGHT 40

#define MAX_ANGER 15
#define STARTING_HEALTH 25

static int has_player[MAP_WIDTH][MAP_HEIGHT];

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

   p->x = x;
   p->y = y;
   p->name = player_name;
   p->health = health;
   p->anger = anger;
   p->lastdir = -1;
   p->kills = 0;
   p->color = color;
   p->symbol = symbol;
   p->alive = 1;

   return p;
}

void init_env(int player_count, env * e) {

   e->players = malloc(sizeof(player *)*player_count);
   e->player_count = player_count;

   for (int i = 0; i < player_count; ++i)
      e->players[i] = allocate_player();

}

void destroy_env(env * e) {

   for (int i = 0; i < e->player_count; ++i)
      free(e->players[i]);
   free(e->players);

}

static void apply_movement(player * p) {

   int action = rand() % 6;

restart:
   switch (action) {
      case UP:
         p->y = p->y + 1;
         p->lastdir = UP;
         break;
      case DOWN:
         p->y = p->y - 1;
         p->lastdir = DOWN;
         break;
      case LEFT:
         p->x = p->x - 1;
         p->lastdir = LEFT;
         break;
      case RIGHT:
         p->x = p->x + 1;
         p->lastdir = RIGHT;
         break;
      case 4:
      case 5:
         if (p->lastdir == -1)
            return;
         else {
            action = p->lastdir;
            goto restart;
         }
         break;
   }

   if (p->x >= MAP_WIDTH) {
      p->x = MAP_WIDTH - 1;
      p->lastdir = -1;
   }
   else if (p->x < 0) {
      p->x = 0;
      p->lastdir = -1;
   }
   else if (p->y >= MAP_HEIGHT) {
      p->y = MAP_HEIGHT - 1;
      p->lastdir = -1;
   }
   else if (p->y < 0) {
      p->y = 0;
      p->lastdir = -1;
   }
}

int step_env(env * e) {
   memset(has_player,0,sizeof(has_player));

   int live_players = 0;

   // movement step
   for (int i = 0; i < e->player_count; ++i) {
      player * p = e->players[i];

      has_player[p->x][p->y] = i+1;

      if (p->alive != 1)
         continue;

      apply_movement(p);
   }

   // attack step
   for (int i = 0; i < e->player_count; ++i) {
      player * p = e->players[i];

      if (p->alive != 1)
         continue;

      for (int j = 0; j < e->player_count; ++j) {
         if (j == i)
            continue;

         player * other = e->players[j];

         if (other->alive != 1)
            continue;

         if (p->x == other->x && p->y == other->y) {

            int roll = rand() % MAX_ANGER+1;

            if (roll < p->anger) {
               // attack

               int damage = rand() % p->anger;

               other->health -= damage;
               if (other->health <= 0)
                  p->kills += 1;
            }
         }
      }
   }

   // die step
   for (int i = 0; i < e->player_count; ++i) {
      player * p = e->players[i];

      if (p->alive == 0)
         continue;

      if (p->health <= 0)
         p->alive = 0;

      else live_players = live_players + 1;
   }
   
   if (live_players <= 1)
      return 1;
   return 0;
}

static void clear_screen() {
   printf("\033[J\033[H");
}

static void set_color(int num) {
   printf("\033[38;5;%dm",num);
}

static void unset_color() {
   printf("\033[39m");
}

static void render_player_symbol(player * p) {
   if (p->alive) {
      set_color(p->color);
      printf("%c",p->symbol);
   }
   else {
      set_color(196);
      printf("*");
   }
   unset_color();
}

static void render_map(env * e) {

   printf("#");
   for (int i = 0; i < MAP_WIDTH; ++i)
      printf("-");
   printf("#\n");

   for (int y = 0; y < MAP_HEIGHT; ++y) {

      for (int x = 0; x < MAP_WIDTH; ++x) {
         if (x == 0)
            printf("|");

         if (has_player[x][y]) {
            render_player_symbol(e->players[has_player[x][y]-1]);
         }
         else printf(" ");


         if (x == MAP_WIDTH-1)
            printf("|\n");
      }
   }

   printf("#");
   for (int i = 0; i < MAP_WIDTH; ++i)
      printf("-");
   printf("#\n");

}

static int name_width = 19;

static void print_player_name(player * p) {
   if (p->alive) {
      set_color(p->color);
      printf("%10s %2d %2d %2d",p->name,p->health,p->kills,p->anger);
   }
   else {
      set_color(196);
      printf("\033[9m"); // strikethrough!
      printf("%10s %2d %2d %2d",p->name,p->health,p->kills,p->anger);
      printf("\033[29m"); // strikethrough!
   }
   unset_color();
}

static void render_names(env * e) {

   int names_per_line = (MAP_WIDTH / name_width) + 3;

   int counter = 0;
   for (int i = 0; i < e->player_count; ++i) {
      if (counter == names_per_line) {
         printf("\n");
         counter = 0;
      }
      print_player_name(e->players[i]);
      counter += 1;
   }

}

void render_env(env * e) {
   clear_screen();
   render_map(e);
   render_names(e);
}

player * get_winner(env * e) {
   for (int i = 0; i < e->player_count; ++i) {
      if (e->players[i]->alive == 1)
         return e->players[i];
   }
   return NULL;
}
