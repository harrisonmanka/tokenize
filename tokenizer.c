/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Your Name
 * @version current date
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"




// global variables
char *line;             // Global pointer to line of input

// (optional) can declare some additional variable if you want to

/**
* add comment
*/
int main(int argc, char* argv[]) {
   char  token[TSIZE];      /* Spot to hold a token, fixed size */
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count,        /* Number of lines read             */
         start,    /* is this the start of a new statement? */
         count;             /* count of tokens                  */

  if (argc != 3) {
    printf("Usage: tokenizer inputFile outputFile\n");
    exit(1);
  }

  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
    exit(1);
  }

  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
    exit(1);
  }

   // (optional) can add some code here if you want some here
 
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      remove_whitespace(line);
      printf("%s", line);
      identify_lexeme(line);
      // Add code here. Keep this file no longer than 50 lines of code.
      // Use helper functions.
      


   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}
/// @brief remove whitespace from the current line
/// @param line - the current line that is being read
char* remove_whitespace(char* line){
    int count = 0;
    for (int i = 0; line[i]; i++)
        if (line[i] != ' ')
            line[count++] = line[i];
    line[count] = '\0';
}

void identify_lexeme(char* line){
  int cnt = 0;
  char* lex = line;
  for(cnt = 0; cnt  < strlen(lex); cnt++){
    switch (lex[cnt])
    {
    case '+':
          
      /* code */
      break;
    
    default:
      break;
    }

  }
}

/**
* add javadoc-like comment
*/
void get_token(char *token_ptr)
{
   // Add code here. Keep this file no longer than 50 lines of code.
   // Use helper functions. No duplicate code!
}
