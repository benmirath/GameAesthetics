public class RoomEater {
  //PVector coord;
  public boolean isAlive;
  Room curRoom;
  int indexX;
  int indexY;
  
  public RoomEater (int _x, int _y) {
    isAlive = true;
    //curRoom = _room;
    indexX = _x;
    indexY = _y;
    
    if (indexX < 0 || indexX > WIDTH || indexY < 0 || indexY > HEIGHT) {
      isAlive = false;
    } else {
      curRoom = map[indexX][indexY];
    }
  }
  
  public void Update () {
    int dir = (int)random (4);
    boolean valid = false;
    switch (dir) {
      default:
      case 0:  //right
      if (indexX < WIDTH) {
        map[indexX][indexY].goRight = true;
        indexX++;
        map[indexX][indexY].goLeft = true;
        valid = true;
      }
      
      break;
      
      case 1:  //left
      if (indexX > 0) {
        map[indexX][indexY].goLeft = true;
        indexX--;
        map[indexX][indexY].goRight = true;
        valid = true;
      }
      break;
      
      case 2:  //up
      if (indexY > 0) {
        map[indexX][indexY].goUp = true;
        indexY--;
        map[indexX][indexY].goDown = true;
        valid = true;
      }
      break;
      
      case 3:  //down
      if (indexY < HEIGHT) {
        map[indexX][indexY].goDown = true;
        indexY++;
        map[indexX][indexY].goUp = true;
        valid = true;
      }
      break;
    }
    
    if (!valid) {
      isAlive = false;
      return;
    }
    
    //if (indexX < 0 || indexX > WIDTH || indexY < 0 || indexY > HEIGHT) {
    //  isAlive = false;
    //  return;
    //}
    
    curRoom = map[indexX][indexY];  
  }
  public void Render () {
    text ("X", curRoom.coord.x, curRoom.coord.y);
  }
}