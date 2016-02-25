
//final PVector SIZE = new PVector(15,15);
final int WIDTH = 15;
final int HEIGHT = 15;
final float ROOM_SIZE = 20;
final float MAZE_BUFFER = 200;

Room[][]map;
RoomEater eater;
//ArrayList<ArrayList<Room>> map;
PFont myFont;

void setup () {
  //size((int)((SIZE.x * ROOM_SIZE) + (MAZE_BUFFER * 2)), (int)((SIZE.y * ROOM_SIZE) + (MAZE_BUFFER * 2)));
  size (800, 800);
   
   map = new Room[WIDTH][HEIGHT];
   
   
   populateRoom();
   
   eater = new RoomEater (7, 7);
   pressed = false;
   //text ((int)((WIDTH * ROOM_SIZE) + (MAZE_BUFFER * 2)), 100, 100);
   //text ((int)((HEIGHT * ROOM_SIZE) + (MAZE_BUFFER * 2)), 100, 200);
}

void draw () {
  background (0);
  drawRoom(); 
  //if (updateBoard ()) eater.Update ();
  eater.Render ();
}



void populateRoom () {
  PVector coord = new PVector (MAZE_BUFFER, MAZE_BUFFER);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      map[j][i]= new Room (coord);
      //print (coord);
      //print ("\n");
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
  //if (key == RETURN) {
  //  if (!pressed) {
  //    pressed = true;
  //    return true;
  //  } else {
  //    return false;
  //  }
  //} else {
  //  if (pressed) {
  //    pressed = false;
      
  //  }
  //  return false;
  //}
}