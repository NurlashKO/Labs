#include <bits/stdc++.h>

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include <arpa/inet.h>

using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int player_socket[5];
int sfd;
struct sockaddr_in addr, cli_addr[5];

void cr_ser() {
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t clilen;
    if (sfd == -1){
        printf("Error socket %s\n", strerror(errno));
        exit(0);
    }

    bzero((char *) &addr, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(addr.sin_zero, '\0', sizeof addr.sin_zero);

    //strncpy(addr.sun_path, SOCKNAME, sizeof(addr.sun_path) - 1);
    int x = ::bind(sfd, (struct sockaddr *) &addr, sizeof addr);
    if (x < 0) {
      printf("ERROR: Couldn't bind socket");
      exit(0);
    }
    if (listen(sfd, 2) == -1){
        printf("listening error %s\n", strerror(errno));
        exit(0);
    }

    for (int i = 0; i < 2; i++) {
      clilen = sizeof(cli_addr[i]);
      player_socket[i] = ::accept(sfd, (struct sockaddr *) &cli_addr[i], &clilen);
      if (player_socket[i] == -1){
         printf("accepting error %s\n", strerror(errno));
         exit(0);
      } else {
        printf("Player %d connected.\n", i + 1);
      }
    }
}

int N = 9;
char board[81];

int will_die, color;
int die[81], was[81];

void dfs(int v) {
  if (v < 0 || v > 80) return ;
  if (board[v] == '-') {
    will_die = 0;
    return ;
  }
  if (board[v] != color) return;
  if (was[v]) return;
  was[v] = 1;
  dfs(v + 1);dfs(v - 1);
  dfs(v + N);dfs(v - N);
}

void mark_fated(int v) {
  if (v < 0 || v > 80) return ;
  if (board[v] != color || die[v]) return ;
  die[v] = 1;
  mark_fated(v + 1);mark_fated(v - 1);
  mark_fated(v + N);mark_fated(v - N);
}

void process_board() {
  for (int i = 0; i < N * N; i++) die[i] = was[i] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i * N + j] != '-' && !was[i * N + j]) {
        will_die = 1;
        color = board[i * N + j];
        dfs(i * N + j);
        if (will_die) mark_fated(i * N + j);
      }
    }
  }

  for (int i = 0; i < N*N; i++) if (die[i]) board[i] = '-';

}


int main() {

  srand(time(NULL));
  for (int i = 0; i < N * N; i++) board[i] = '-';
  printf("Waiting for players...\n");
  cr_ser();
  printf("Server created\n");

  if (rand() % 2) swap(player_socket[0], player_socket[1]);

  char move[2];
  move[0] = 0;
  move[1] = 1;
  send(player_socket[0], move, 1, 0);
  send(player_socket[1], move + 1, 1, 0);
  int turn = 0;
  while (1) {
    printf("Playing..\n");
    send(player_socket[0], board, N*N, 0);
    send(player_socket[1], board, N*N, 0);
    recv(player_socket[turn], move, 2, 0);
    board[move[0] * N + move[1]] = !turn ? 'X' : 'O';
    process_board();
    turn ^= 1;
  }

}
