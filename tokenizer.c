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
#include <pcre.h>




// global variables
char *line;             // Global pointer to line of input
// (optional) can declare some additional variable if you want to
char *token_type; //

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
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      while(*line != ";" || *line != "\0"){
          get_token(token);
      }
      if(*line == ";"){
          line_count++; //statement numberr
      }
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/**
* grab token
*/
void get_token(char *token_ptr){
    token_ptr = "";
    int i = 0;
    //get rid of white space
    while(strcmp(line," ") == 1){
        line++
    }
    //check current line pointer
    if(isdigit(line)){
        token_ptr[i] = line;
        line++;
        i++;
        get_token_type(line);
        //check for next number(s)
        while(isdigit(line)){
            token_ptr[i] = line;
            line++
            i++;
        }
    }
    //get_token will call get_token_type with our token array containing "1" to set our GLOBAL token_type as INT_LITERAL
    //then call print_to_file with our GLOBAL file point, token array containing "1", and our GLBOAL token_type
    //to write to the output file
    else if ((strcmp(line, "<")) || (strcmp(line, ">")) || (strcmp(line, "!")) || (strcmp(line, "="))){
        token_ptr[i] = line;
        line++;
        i++
        if(strcmp(line, "=")){
            token_ptr[i] = line;
        }
    }
    else if (strcmp(line, "*")){
        token_ptr[i] = line;
        line++;
    }
    else if (strcmp(line, ";")){
        token_ptr[i] = line;
        line++;
    }
}
/**
 *
 * @param out_file
 * @param token_arr
 * @param token_type
 */
void print_to_file(char* token_arr, char* token_type){

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
