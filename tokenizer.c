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
#include <ctype.h>
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
      //remove_whitespace(line);
      //printf("%s", line);
      //identify_lexeme(line);
      // Add code here. Keep this file no longer than 50 lines of code.
      // Use helper functions.
      while(*line != ";"){
          get_token(line);
      }
      line_count++;


   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/// @brief remove whitespace from the current line
/// @param line - the current line that is being read
//char* remove_whitespace(char* line){
  //  int count = 0;
    //for (int i = 0; line[i]; i++)
      //  if (line[i] != ' ')
        //    line[count++] = line[i];
    //line[count] = '\0';
//}



/**
* grab token
*/
void get_token(char *token_ptr){
  line = token_ptr;
  char token_arr[] = "";
  int len = strlen(token_ptr);
  //iterates through the entire char array
  for(int i= 0; i < len; i++){
    //this is checking if the char is an int
    if(isdigit(token_ptr[i])){
      token_arr[i] =  token_ptr[i];
      get_token_type(token_arr[i]);
      //need to check ahead if next char is also an int

    }
    //since this is a op no need to check ahead same with others
    if(token_ptr[0] = '+'){
      token_arr[0] = token_ptr[i];
      get_token_type(token_arr[0]);
      
    }
  }
}
    //reinitialize TOKEN ARRAY
    //check current line pointer
    /**if number{
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
}*/

/**
 * get token type
 */
void get_token_type(char token){
    switch(token){
        case '+':
        //print to file maybe
        //fprintf(out_file, "Token" + ADD_OP + " is a " );
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case '(':
            break;
        case ')':
            break;
        case '^':
            break;
        case '=':
            break;
}
}