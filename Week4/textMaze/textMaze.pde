
//final PVector SIZE = new PVector(15,15);
final int WIDTH = 15;
final int HEIGHT = 15;
final float ROOM_SIZE = 20;
final float MAZE_BUFFER = 200;

enum Facing {
  Up,
  Down,
  Left,
  Right
}

Room[][]map;
Player player;
RoomEater eater;
//ArrayList<ArrayList<Room>> map;
PFont myFont;

void setup () {
   size (800, 800);
   map = new Room[WIDTH][HEIGHT];
   populateRoom();
   player = new Player (2, 8);
   eater = new RoomEater (7, 7);
   pressed = false;
}

void draw () {
  background (0);
  drawRoom(); 
  player.Render ();
  eater.Render ();
}



void populateRoom () {
  PVector coord = new PVector (MAZE_BUFFER, MAZE_BUFFER);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      map[j][i]= new Room (coord);
      coord.x += (ROOM_SIZE + 10);
    }
    coord.y += (ROOM_SIZE + 10);
    coord.x = MAZE_BUFFER;
  }
}

void drawRoom () {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      map[j][i].Render ();
    }
  }
}


boolean pressed;
void keyPressed () {
  eater.Update();
  player.Input ();
}