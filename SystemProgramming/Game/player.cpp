#define _XOPEN_SOURCE 700
#include <unistd.h>

#include <bits/stdc++.h>

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <termios.h>

#include <arpa/inet.h>

using namespace std;

int clientSocket;
struct sockaddr_in serverAddr;
socklen_t addr_size;

void connect_to_server() {

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(10000);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*---- Connect the socket to the server using the address struct ----*/
  int e = connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof serverAddr);
  if (e < 0) {
    printf("ERROR connecting player!\n");
    exit(0);
  }
  printf("Connected\n");
}

int N = 9;
char board[81];

void show_board() {
  system("clear");
 /*
   1 2
 1 O--O
   |  |
 2 X--X
   | |
 3 ---
 */
  cout << "  ";
  for (int i = 0; i < N*2 - 1; i++) {
    if (i & 1) cout << "  ";
    else cout << i/2 + 1;
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 2*N - 1; j++) {
      if (j % 2 == 0)
        cout << board[i*N + j/2];
      else
        cout << "--";
    }
    cout << "\n";

    if (i == N - 1) break;
    cout << "  ";
    for (int j = 0; j < 2*N - 1; j++) {
      if (j & 1) cout << "  ";
        else cout << "|";
    }
    cout << "\n";
  }
}

bool valid_move(int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= N) return false;
  if (board[x * N + y] != '-') return false;
  return true;
}

int main () {
  system("clear");
  connect_to_server();
  printf("Please wait for other players to connect...\n");

  /////////////// GAME PREPARATION
  char cturn[1];
  recv(clientSocket, cturn, 1, 0);
  int turn = cturn[0];
  cout << "Your opponent is ready.\nGame starts in 5 seconds!\n";
  if (!turn) {
    cout << "You move first.\n";
  } else {
    cout << "Your opponent starts.\n";
  }
  sleep(5);
  ///////////////

  int ch;
  string s;
  int key;
  char move[2];
  while (1) {
    recv(clientSocket, board, N*N, 0);
    show_board();
    if (!turn) {
      int x, y;
      bool is_valid = 1;
      fflush(stdin);
      do {
        if (!is_valid) { cout << "Invalid move!\n"; }
        cout << "Your move : ";
        cin >> x >> y;
        x--,y--;
        is_valid = 0;
      } while(!valid_move(x, y));
      move[0] = x;
      move[1] = y;
      send(clientSocket, move, 2, 0);
    } else {
      printf("Please wait for your opponents move!\n");
    }
    turn ^= 1;
  }

}
