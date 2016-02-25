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
    print ("updating1");
    switch (dir) {
      default:
      case 0:  //left
      indexX++;
      break;
      
      case 1:  //right
      indexX--;
      break;
      
      case 2:  //up
      indexY--;
      break;
      
      case 3:  //down
      indexY++;
      break;
    }
    
    if (indexX < 0 || indexX > WIDTH || indexY < 0 || indexY > HEIGHT) {
      isAlive = false;
      return;
    }
    print ("updating2");
    curRoom = map[indexX][indexY];  
  }
  public void Render () {
    text ("X", curRoom.coord.x, curRoom.coord.y);
  }
}