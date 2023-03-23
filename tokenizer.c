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

char* token_type = "";
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
   int cnt = 0;
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      // Add code here. Keep this file no longer than 50 lines of code.
      // Use helper functions.
      //work on right format.
      //printf("Statement" "%d\n", count);
      fprintf(out_file, "%s", "-----------------------------------------------\n");
      count = 0;
      //this is here because the first time around token has unknown chars not sure why.
      memset(token, 0, strlen(token));
      for(int i = 0; i < strlen(line);){
        if(line[i] == ' '){
          i++;
          
      }
      if(line[i] == '\n'){
        line++;
        i++;
      }
      else{
        token[0] = line[i];
        cnt++;
        if(line[i] == LESS_THEN_OP || line[i] == GREATER_THEN_OP || line[i] == NOT_OP) {
          token[0] = line[i];
          
          if(line[i + 1] == ASSIGN_OP){
            token[1] = line[i + 1];
            get_token(token);
            i++;
          }
          
        }
        //problem here with statement 2
        while(isdigit(line[cnt])){
          //the problem is here
            token[cnt] = line[cnt];
            cnt++;
        }//end of while
        get_token(token);
        //print token line
        fprintf(out_file,"Lexeme " "%d" " is " "%s" " and is an " "%s\n", count, token, token_type);
        //clear token
        memset(token, 0, strlen(token));
        count++;
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
* grab token
*/
void get_token(char *token_ptr){
  //attempt to convert
  long int value = strtol(token_ptr, NULL, 10);
    if(value != 0){
      token_type = "INT_LITERAL";
    }
    else if(token_ptr[0] == ADD_OP){
      token_type = "ADD_OP";
    }
    else if(token_ptr[0] == SUB_OP){
      token_type = "SUB_OP";
    }
    else if(token_ptr[0] == MULT_OP){
      token_type = "MULT_OP";
    }
    else if(token_ptr[0] == LESS_THEN_OP){
      token_type = "LESS_THAN_OP";
      token_ptr++;
      if(token_ptr[0] == ASSIGN_OP){
        token_type = "LESS_THAN_OR_EQUAL";
    }
      
      
    }
    else if(token_ptr[0] == DIV_OP){
      token_type = "DIV_OP";
    }
    else if(token_ptr[0] == ' '){
    }
    else if(token_ptr[0] == NOT_OP){
      token_type = "NOT_OP";
      token_ptr++;
      if(token_ptr[0] == ASSIGN_OP){
        token_type = "NOT_EQUAL_OP";
    }
    }
    else if(token_ptr[0] == ASSIGN_OP){
      token_type = "ASSIGN_OP";
    }
    else if(token_ptr[0] == SEMI_COLON){
      token_type = "SEMI_COLON";
    }
    else if(token_ptr[0] == LEFT_PAREN){
      token_type = "LEFT_PAREN";
    }
    else if(token_ptr[0] == RIGHT_PAREN){
      token_type = "RIGHT_PAREN";
    }
     

    
}


/**
 * get token type
 */


