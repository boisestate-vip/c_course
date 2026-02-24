
/* file manipulation stuff is in stdio as well. */
#include <stdio.h>
#include <stdlib.h>

/* a function like this is always nice to have */
/* returns a null terminated string full of the
 * file contents.                               */
char * fload(char * fname) {
   FILE * fptr = fopen(fname,"r");
   fseek(fptr,0,SEEK_END);
   long length = ftell(fptr);

   char * buf = malloc(sizeof(char)*length + sizeof('\0'));

   fseek(fptr,0,SEEK_SET);

   fread(buf,length,sizeof(char),fptr);
   buf[length] = '\0';

   fclose(fptr);

   return buf;
}

int main(void) {

   /* there are a few file modes.
    * If you do w as the second argument,
    * then the file is write only. If you
    * do r as the second argument, you
    * are read only. I am pretty sure that
    * w+ is read/write and a is append,
    * but I don't use this stuff much so I
    * am not sure...                      */
   FILE * fptr = fopen("file.txt","w");

   /* works basically the same as printf but into a file */
   fprintf(fptr,"hi there\n");

   /* if you don't fclose, your changes
    * may not showup.                  */
   fclose(fptr);

   char * buf = fload("file.txt");

   /* should say hi there... */
   printf("%s\n",buf);

   free(buf);






































































































   /* fine to reuse fptr */
   fptr = fopen("main.c","w");

   fprintf(fptr,
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"char * fload(char * fname) {\n"
"}\n"
"/* you fool! now reimpliment fload to work xD */\n"
"/* use fseek and ftell to get the length, then fread\n"
"   to write out the file contents */\n\n\n"
"int main(void) {\n"
"FILE * fptr = fopen(\"file.txt\",\"w\");\n"
"fprintf(fptr,\"hi there\\n\");\n"
"fclose(fptr);\n"
"char * buf = fload(\"file.txt\");\n"
"printf(\"%%s\\n\",buf);\n"
"free(buf);\n"
"return 0;\n"
"}\n");

   fclose(fptr);

   return 0;
}
