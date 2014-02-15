Author:

 - Bipul Islam
 
---
##Unix Socet IPC Implementation

We use socket programming for inter process communications to design a simple console based chat application.

###Contents:
 - chatserv.c (Contains server code, on execution sets up the server to listen for connections)
 - charcli.c (Contains client code, set your server IP in the code it will connect to the server, use 127.0.0.1 to test on localhost)

###Usage:
```
gcc chatserv.c -o serv
gcc chatcli.c -o cli
./serv
```
(in a new tab)
```
./cli
```
Then chat away!

#####Notes: 
*It's possible to generalize both server and client by accepting the ip of the machines in command line, or even supply server ip to client in commadline.*
