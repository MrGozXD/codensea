# TFTP

## Synthesys Practical Work  : TFTP client

**Objectives**: Develop a client programm that should be able to exchange files with a server using the TFTP protocol.

-[x] gettftp : get a file from the server
-[ ] puttftp : send a file to the server

### TFTP protocol: 
https://tools.ietf.org/html/rfc1350

### How to use it 

1. From the terminal, go to the directory *server* 
2. Start your local server with the command ./go.sh (port 1069)
3. From another terminal, go to the directory *gettftp*
4. Compile main.c and functions.c with the command *gcc -o gettftp main.c functions.c*
5. Run the programm with the command *./gettftp localhost 1069 file.txt* (file.txt is the file you want to get from the server)

*realised by* **Yannis PELOUTIER** *and* **Chloé GABARREN** **2G1 TD2 TP3**