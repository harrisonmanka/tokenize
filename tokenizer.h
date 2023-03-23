/**
 * Header file for the tokenizer project 
 * @author Harrison Manka & Matthew Agudelo
 * @version 03/16/23
 */
/* Constants */
#define LINE 100
#define TSIZE 20
#define TRUE 1
#define FALSE 0

#define MULT_OP '*'
#define ADD_OP '+'
#define SUB_OP '-'
#define DIV_OP '/'
#define ASSIGN_OP '='
#define LEFT_PAREN '('
#define RIGHT_PAREN ')'
#define EXPON_OP '^'
#define LESS_THEN_OP '<'
#define LESS_THEN_OR_EQUAL_OP "<="
#define GREATER_THEN_OR_EQUAL_OP ">="
#define EQUALS_OP "=="
#define NOT_OP '!'
#define GREATER_THEN_OP '>'
#define NOT_EQUAL_OP "!="
#define SEMI_COLON ';'

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_LITERAL 'INT_LITERAL'

/**
* add comment
*/

void get_token(char *); 
void identify_lexeme(char*);
void get_token_type(char);


