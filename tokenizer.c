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
#include <pcre.h>




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

      // Add code here. Keep this file no longer than 50 lines of code.
      // Use helper functions.
      while(*line != ";"){
          get_token(token);
      }
      line_count++;


   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/// @brief remove whitespace from the current line
/// @param line - the current line that is being read
void remove_whitespace(char* line){
  char* temp = line;
  do{
    while(*temp = ' '){
      ++temp;
    }
  }
  while(*line++ = *temp++);
}

/**
* grab token
*/
void get_token(char *token_ptr){
    reinitialize TOKEN ARRAY
    check current line pointer
    if number{
        add to TOKEN ARRAY
        check for next number(s)
        while(line pointer == number)
            add to TOKEN ARRAY
    }
    if letter{
        add to TOKEN ARRAY
        check for next letter(s)
        while(line pointer == number)
            add to TOKEN ARRAY
    }
    if (< > ! =){
        add to TOKEN ARRAY
        check for =
    }
    if (*){
        add to TOKEN ARRAY
        check for **
    }
}

/**
 * get token type
 */
void get_token_type(char* token){
    switch(token_ptr){
        case ADD_OP:
            break;
        case SUB_OP:
            break;
        case MULT_OP:
            break;
        case DIV_OP:
            break;
        case LEFT_PAREN:
            break;
        case RIGHT_PAREN:
            break;
        case EXPON_OP:
            break;
        case ASSIGN_OP:
            break;
}
