public class Room {
  //public char graphic;
  public PVector coord;
  public boolean goLeft;
  public boolean goRight;
  public boolean goUp;
  public boolean goDown;
  
  //public PVector size;
  
  public Room (PVector _coord) {
    coord = new PVector (_coord.x, _coord.y);
    goLeft = false;
    goRight = false;
    goUp = false;
    goDown = false;
  }
  
  public Room (PVector _coord, boolean _left, boolean _right, boolean _up, boolean _down) {
    coord = new PVector (_coord.x, _coord.y);
    goLeft = _left;
    goRight = _right;
    goUp = _up;
    goDown = _down;
  }
    
  //public void SetDoors (boolean _left, boolean _right, boolean _up, boolean _down) {
  //  goLeft = _left;
  //  goRight = _right;
  //  goUp = _up;
  //  goDown = _down;
  //}
  public void Render () {
    text ("-", coord.x, coord.y);
    
    float buffer = ROOM_SIZE * 0.5;
    if (!goDown) text ("--", coord.x - 3, coord.y + buffer);
    if (!goUp) text ("--", coord.x - 3, coord.y - buffer);
    if (!goRight) text ("|", coord.x + buffer, coord.y);
    if (!goLeft) text ("|", coord.x - buffer, coord.y);
  }

  
  
}