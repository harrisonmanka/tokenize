/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Harrison Manka and Matthew Agudelo
 * @version 03/23/2023
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

char* line; //global pointer to our line of input
char* token_type = ""; //global char* variable to keep track of token type
char* grammar = "";

/**
 * Main method which takes in three command line arguments where we utilize an input and output file.
 * The single while loop loops through lines of input while our algorithm below finds each and
 * every lexeme where it gets passed into get_token to set the global token_type variable. Then,
 * prints the output message into the output file specified in the main method parameter.
 * @param argc - number of arguments
 * @param argv - argument array
 * @return 0 if executes correctly
 */
int main(int argc, char* argv[]) {
   char  token[TSIZE];      /* Spot to hold a token, fixed size */
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   
   int   line_count,        /* Number of lines read             */
         //start,    /* is this the start of a new statement? */
         count = 0;             /* count of tokens                  */

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

   int cnt = 0;
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
      if(line_count == 0){
        line_count++;
        fprintf(out_file, "Statement #" "%d \n", line_count);
        line_count++;
      }
      //this is here because the first time around token has unknown chars not sure why.
      memset(token, 0, strlen(token));
      for(int i = 0; i < strlen(line);){
        //skips blanks 
        if(line[i] == ' '){
          i++;
      }
      if(line[i] == '\t'){
          i++;
      }
      //skips just empty lines
        if(line[i] == '\n'){
          line++;
          i++;
        }
      else{
        token[0] = line[i];
        
        if(line[i] == LESS_THEN_OP || line[i] == GREATER_THEN_OP || line[i] == NOT_OP || line[i] == ASSIGN_OP) {
          token[cnt] = line[i];
          
          if(line[i + 1] == ASSIGN_OP){
            token[cnt + 1] = line[i + 1];
            i++;
          }
        }
        if(isdigit(line[i]) && isdigit(line[i + 1])){
          
            token[cnt] = line[i];
            token[cnt + 1] = line[i + 1];
            cnt++;
            i++;
        }//end of while
        get_token(token);
        //some blanks got through, so I had to add this  here
        if(line[i] != ' '){
          if(strcmp(token_type,"INVALID") == 0){
            fprintf(out_file, "===> '%s'\nLexical error: not a lexeme\n", token);
          }
          else{
            fprintf(out_file,"Lexeme " "%d" " is " "%s" " and is %s " "%s\n", count, token, grammar, token_type);
            //printf("Lexeme " "%d" " is " "%s" " and is an " "%s\n", count, token, token_type);
            count++;
          }
        }
        if(line[i] == ';'){
          fprintf(out_file,"%s", "-----------------------------------------------\n");
          fprintf(out_file, "Statement #" "%d \n", line_count);
          line_count++;
          count = 0;
        }
        memset(token, 0, strlen(token));
        i++;
        cnt = 0;
      }//end of else
    }//end of for
   }
   fclose(in_file);
   fclose(out_file);
   return 0;
}

/**
 * get_token method that takes in a char* variable from the main method where the if/else statements decide
 * what type of token our char* variable is.
 * @param token_ptr
 */
void get_token(char *token_ptr){
    if(isdigit(token_ptr[0])){
      token_type = "INT_LITERAL"; grammar = "an"; }

    else if(token_ptr[0] == ADD_OP){
      token_type = "ADD_OP"; grammar = "an";}

    else if(token_ptr[0] == SUB_OP){
      token_type = "SUB_OP"; grammar = "a";}

    else if(token_ptr[0] == MULT_OP) {
        token_type = "MULT_OP";
        grammar = "a"; }

    else if(token_ptr[0] == LESS_THEN_OP){
      token_type = "LESS_THAN_OP";
      token_ptr++; grammar = "a";
      if(token_ptr[0] == ASSIGN_OP){
        token_type = "LESS_THAN_OR_EQUAL"; grammar = "a";}}

    else if(token_ptr[0] == DIV_OP){
      token_type = "DIV_OP"; grammar = "a";}
    
    else if(token_ptr[0] == NOT_OP){
      token_type = "NOT_OP";
      token_ptr++; grammar = "a";
      if(token_ptr[0] == ASSIGN_OP){
        token_type = "NOT_EQUAL_OP"; grammar = "a";}}

    else if(token_ptr[0] == ASSIGN_OP){
      token_type = "ASSIGN_OP";
      token_ptr++; grammar = "an";
      if(token_ptr[0] == ASSIGN_OP){
        token_type = "EQUALS_OP"; grammar = "an";}}

    else if(token_ptr[0] == SEMI_COLON){
      token_type = "SEMI_COLON"; grammar = "a";}

    else if(token_ptr[0] == LEFT_PAREN){
      token_type = "LEFT_PAREN"; grammar = "a";}

    else if(token_ptr[0] == RIGHT_PAREN){
      token_type = "RIGHT_PAREN"; grammar = "a";}

    else if(token_ptr[0] == EXPON_OP){
      token_type = "EXPON_OP"; grammar = "an";}

    else{
      token_type = "INVALID";}
}


