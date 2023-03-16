If you create text files on a windows machine they will have '\r' and '\n' for each newline. The '\r' is a carriage return.
They also do not have any tab characters. If they had been created on a linux machine there would be no '\r' character at a newline.

On agora a windows text file can be converted into the UNIX style (just ‘\n’) by using the command

dos2unix input.txt unix_input.txt
