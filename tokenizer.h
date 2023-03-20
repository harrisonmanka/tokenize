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
#define MULT_OP "*"
#define ADD_OP "+"
#define DIV_OP "-"
#define ASSIGN_OP "="
#define LESS_THAN "<"
#define EQUAL_OP "=="
#define NOT_OP "!"
#define GREATER_THAN ">"
#define NOT_EQUAL_SIGN "!="
#define SEMI_COLON ";"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* add comment
*/
char* remove_whitespace(char* );
void get_token(char *); 
void identify_lexeme(char*);


