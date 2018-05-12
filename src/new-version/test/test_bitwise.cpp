// test_bitwise.cpp
#include <stdio.h>
int main(int argc, char const* argv[]) {
  /* code */
  int x, y, val;

  int None = 0, NorthWall = 2, EastWall = 4, SouthWall = 6, WestWall = 8,
      AllWalls = NorthWall | EastWall | SouthWall | WestWall;
  printf("%s %i\n", "None ", None);
  printf("%s %i\n", "N ", NorthWall);
  printf("%s %i\n", "E ", EastWall);
  printf("%s %i\n", "S ", SouthWall);
  printf("%s %i\n", "W ", WestWall);
  printf("%s %i\n", "A ", AllWalls);
  printf("%s %i\n", "N | E", NorthWall | EastWall);
  printf("\n");
  printf("%s %i\n", "None | N", None | NorthWall);
  printf("%s %i\n", "None | E", None | EastWall);
  printf("%s %i\n", "None | S", None | SouthWall);
  printf("%s %i\n", "None | W", None | WestWall);
  printf("%s %i\n", "None | A", None | AllWalls);
  printf("\n");
  printf("%s %i\n", "N | E", NorthWall | EastWall);
  printf("%s %i\n", "N | S", NorthWall | SouthWall);
  printf("%s %i\n", "N | W", NorthWall | WestWall);
  printf("\n");
  printf("%s %i\n", "E | S", EastWall | SouthWall);
  printf("%s %i\n", "E | W", EastWall | WestWall);
  printf("\n");
  printf("%s %i\n", "S | W", SouthWall | WestWall);
  printf("\n");
  printf("%s %i\n", "N | E & N", NorthWall | EastWall & NorthWall);  // 1 = N
  // adding values that already exists
  // will not affect value
  printf("%s %i\n", "N | E | N", NorthWall | EastWall | NorthWall);  // 3 = N|E
  printf("\n");
  for (int TURN = 1; TURN < 4; TURN++) {
    /* code */
    printf("%s %i %s %i\n", "N <<", TURN, " = ", NorthWall << TURN);
    printf("%s %i %s %i\n", "E <<", TURN, " = ", EastWall << TURN);
    printf("%s %i %s %i\n", "S <<", TURN, " = ", SouthWall << TURN);
    printf("%s %i %s %i\n", "W <<", TURN, " = ", WestWall << TURN);
    printf("\n");
  }
    printf("\n");
    for (int TURN = -3; TURN < 0; TURN++) {
    /* code */
    printf("%s %i %s %i\n", "N >>", -TURN, " = ", NorthWall >> -TURN);
    printf("%s %i %s %i\n", "E >>", -TURN, " = ", EastWall >> -TURN);
    printf("%s %i %s %i\n", "S >>", -TURN, " = ", SouthWall >> -TURN);
    printf("%s %i %s %i\n", "W >>", -TURN, " = ", WestWall >> -TURN);
    printf("\n");
  }
  /*
  if (y % 2) {
    walls[x][y / 2] = walls[x][y / 2] | val;
  } else {
    walls[x][y / 2] = walls[x][y / 2] | (val << 4);
  }
  cin >> x;
  cin >> y;
  cin >> val;
  cout << "Wall at that pos is now: ";
  cout << walls[x][y / 2];*/
  return 0;
}