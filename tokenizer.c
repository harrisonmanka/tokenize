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
char *token_type = "";
char *grammar = "";
/**
* add comment
*/
int main(int argc, char* argv[]) {
   char  token[TSIZE];      /* Spot to hold a token, fixed size */
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count = 0;        /* Number of lines read             */
         //start,    /* is this the start of a new statement? */
         //count = 0;             /* count of tokens                  */

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
      int count = 0;
      while((strcmp(line, SEMI_COLON) == 1) || strcmp(line, "\0") == 1){
          get_token(token);
          print_to_file(out_file, token, count);
          if(strcmp(token_type, "ERROR") == 1){
              count++;
          }
      }
      if(strcmp(line, SEMI_COLON) == 0){
          line_count++; //statement number
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
    while((strcmp(line," ") == 1) || (strcmp(line,"\t")) == 1){
        line++;
    }
    //check current line pointer
    if(isdigit(*line)){
        token_ptr[i] = *line;
        line++;
        i++;
        get_token_type(line);
        //check for next number(s)
        while(isdigit(*line)){
            token_ptr[i] = *line;
            line++;
            i++;
        }
        token_type = "INT_LITERAL"; grammar = "an";
    }
    else if (!(strcmp(line, LESS_THEN_OP)) || !(strcmp(line, GREATER_THEN_OP)) || !(strcmp(line, ASSIGN_OP)) ||
            !(strcmp(line, EQUALS_OP))){
        token_ptr[i] = *line;
        line++;
        i++;
        if(strcmp(line, ASSIGN_OP)){
            token_ptr[i] = *line;
        }
    }
    else if (!(strcmp(line, MULT_OP)) || !(strcmp(line, SEMI_COLON)) || !(strcmp(line, LEFT_PAREN)) ||
            !(strcmp(line, RIGHT_PAREN)) || !(strcmp(line, ADD_OP)) || !(strcmp(line, SUB_OP)) ||
            !(strcmp(line, EXPON_OP)) || !(strcmp(line, DIV_OP))){
        token_ptr[i] = *line;
        line++;
    }
    else if (strcmp(line,"@")){
        token_ptr[i] = *line;
        line++;
    }
}
/**
 *
 * @param out_file
 * @param token_arr
 * @param token_type
 */
void print_to_file(FILE* out_file, char* token_arr, int count){
    if(!(strcmp(token_type, "ERROR"))) {
        fprintf(out_file, "===> '%s'\nLexical error: not a lexeme\n", token_arr);
    }
    else{
        fprintf(out_file, "Lexeme " "%d" " is " "%s" " and is %s " "%s\n", count, token_arr, grammar, token_type);
    }
}

/**
 * get token type
 */
void get_token_type(char* token){
        if(strcmp(token, ADD_OP) == 0) {
            token_type = "ADD_OP";
            grammar = "an";
        }
        else if (strcmp(token, SUB_OP) == 0) {
            token_type = "SUB_OP";
            grammar = "a";
        }
        else if (strcmp(token, MULT_OP) == 0) {
            token_type = "MULT_OP";
            grammar = "a";
        }
        else if (strcmp(token, DIV_OP) == 0) {
            token_type = "DIV_OP";
            grammar = "a";
        }
        else if (strcmp(token, LEFT_PAREN) == 0) {
            token_type = "LEFT_PAREN";
            grammar = "a";
        }
        else if (strcmp(token, RIGHT_PAREN) == 0){
            token_type = "RIGHT_PAREN";
            grammar = "a";
        }
        else if (strcmp(token, EXPON_OP) == 0) {
            token_type = "EXPON_OP";
            grammar = "an";
        }
        else if (strcmp(token, ASSIGN_OP) == 0) {
            token_type = "ASSIGN_OP";
            grammar = "an";
        }
        else if (strcmp(token, LESS_THEN_OP) == 0) {
            token_type = "LESS_THEN_OP";
            grammar = "a";
        }
        else if (strcmp(token, LESS_THEN_OR_EQUAL_OP) == 0) {
            token_type = "LESS_THEN_OR_EQUAL_OP";
            grammar = "a";
        }
        else if (strcmp(token, GREATER_THEN_OP) == 0) {
            token_type = "GREATER_THEN_OP";
            grammar = "a";
        }
        else if (strcmp(token, GREATER_THEN_OR_EQUAL_OP) == 0) {
            token_type = "GREATER_THEN_OR_EQUAL_OP";
            grammar = "a";
        }
        else if (strcmp(token, EQUALS_OP) == 0) {
            token_type = "EQUALS_OP";
            grammar = "an";
        }
        else if (strcmp(token, NOT_OP) == 0) {
            token_type = "NOT_OP";
            grammar = "a";
        }
        else if (strcmp(token, NOT_EQUAL_OP) == 0) {
            token_type = "NOT_EQUAL_OP";
            grammar = "a";
        }
        else if (strcmp(token, SEMI_COLON) == 0) {
            token_type = "SEMI_COLON";
            grammar = "a";
        }
        else {
            token_type = "ERROR";
        }
}