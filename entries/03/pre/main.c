
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sleep.h"
#include "env.h"

#define BUFLEN 128

int main(void) {

   srand(time(NULL)*clock());

   fprintf(stderr,"enter number of players:");

   char inbuf[BUFLEN];
   fgets(inbuf,BUFLEN-1,stdin);

   int player_count = strtol(inbuf,NULL,0);

   env e;
   init_env(player_count,&e);

   int done = 0;

   while (done != 1) {

      done = step_env(&e);
      render_env(&e);

      sleep_s(0.0125);
   }

   player * winner = get_winner(&e);
   printf("\n");


   if (winner == NULL)
      printf("all players dead :(\n");

   else {
      printf("winner is: %s!\n",winner->name);
      printf("health: %d\n",winner->health);
      printf("kills: %d\n",winner->kills);
      printf("anger: %d\n",winner->anger);
   }

   destroy_env(&e);
   return 0;
}
