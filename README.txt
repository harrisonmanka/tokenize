Authors: Harrison Manka and Matthew Agudelo

Date of Submission: 03/23/2023

How to Run: 1) Inside of the tokenize directory: gcc -Wall tokenizer.c -o tokenizer
            2) Execution: "./tokenizer.out inputFile outputFile"
            3) vim outputFile: see results of the tokenizer program

Description: Our tokenizer project is a project in which we are given a text file full of lexemes. Our algorithm,
             written in the C language, detects each lexeme, identifies it, and prints them out to the given output
             file as well as catching any non-lexemes.

DISCLAIMER: If the input file is brought in from a Windows system, the windows end of file character, '^M',
            will be displayed as an error inside in the outputFile.