public class Player {
  final int maxHealth = 15;
  int health;
  int x;
  int y;
  Room curRoom;
  Facing facing;
  
  public Player (int _x, int _y) {
    x = _x;
    y = _y;
    facing = Facing.Right;
    health = maxHealth;
    curRoom = map[_x][_y];
  }
  
  public void Render () {
    float angle = 0;
    int _offX = 0;
    int _offY = 0;
    switch (facing) {
      default:
      case Right:
      break;
      
      case Left:
      angle = PI;
      _offX = -7;
      _offY = 6;
      break;
      
      case Up:
      angle = HALF_PI + PI;
      _offX = -3;
      _offY = 6;
      break;
      
      case Down:
      angle = HALF_PI;
      _offX = -7;
      _offY = 1;
      break;
    }
    
    if (angle > 0) {
      pushMatrix ();
      translate (curRoom.coord.x, curRoom.coord.y);
      rotate (angle);
      text (">", _offX, _offY);
      popMatrix ();
    } else {
      text (">", curRoom.coord.x, curRoom.coord.y);
    }
  }
  
  public void Input () {
    if (key == CODED) {
      switch (keyCode) {
        default:
        break;
        
        case UP:
        //facing = Facing.Up;
        Update (Facing.Up);
        break;
        case DOWN:
        //facing = Facing.Down;
        Update (Facing.Down);
        break;
        case LEFT:
        //facing = Facing.Left;
        Update (Facing.Left);
        break;
        case RIGHT:
        //facing = Facing.Right;
        Update (Facing.Right);
        break;
      } 
    }
  }
  
  void Update (Facing dir) {
    if (dir == facing) {
      switch (dir) {
        default:
        case Right:
        if (x < WIDTH -1) x++;
        break;
        
        case Left:
        if (x > 0) x--;
        break;
        
        case Up:
        if (y > 0) y--;
        break;
        
        case Down:
        if (y < HEIGHT - 1) y++;
        break;
      }
      curRoom = map[x][y];
    } else {
      float angle = 0;
      int _offX = 0;
      int _offY = 0;
      switch (dir) {
        default:
        case Right:
        break;
        
        case Left:
        angle = PI;
        _offX = -7;
        _offY = 6;
        break;
        
        case Up:
        angle = HALF_PI + PI;
        _offX = -3;
        _offY = 6;
        break;
        
        case Down:
        angle = HALF_PI;
        _offX = -7;
        _offY = 1;
        break;
      }
      facing = dir;
      
      if (angle > 0) {
        pushMatrix ();
        translate (curRoom.coord.x, curRoom.coord.y);
        rotate (angle);
        text (">", _offX, _offY);
        popMatrix ();
      } else {
        text (">", curRoom.coord.x, curRoom.coord.y);
      }
    }
  }
}