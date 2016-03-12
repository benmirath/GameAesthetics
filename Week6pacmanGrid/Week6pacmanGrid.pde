int[][] grid = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 1, 2, 2, 1, 0, 1, 2, 2, 2, 1, 0, 1, 1, 0, 1, 2, 2, 2, 1, 0, 1, 2, 2, 1, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 3, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 3, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 0, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 3, 0, 0, 0, 0, 0, 1}, 
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1}, 
  {0, 0, 0, 0, 0, 0, 3, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 1, 3, 2, 2, 3, 0, 0, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {2, 2, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 2, 2, 2, 2, 2}, 
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 0, 0, 1, 1, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 1, 1, 0, 0, 0, 1}, 
  {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1}, 
  {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1}, 
  {1, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int playerX = 13;
int playerY = 23;

int ghostX = 1;
int ghostY = 1;
int ghostDirX = 1;
int ghostDirY = 0;

float cellW;
float cellH;
  


void setup () {
  size (786, 776);
  cellW = width / grid[0].length;
  cellH = height / grid.length;
  updateGhosts();
  drawUrrything ();
}

void draw () {
  

}

void keyPressed () {
  if (keyCode == UP) {
    if (grid[playerY-1][playerX] != 1) {
      playerY--;
    }
    
  } 
  if (keyCode == DOWN) {    
    if (grid[playerY+1][playerX] != 1) {
      playerY++;
    }
  }
  if (keyCode == LEFT) {
    if (playerX == 0) {
      playerX = grid.length - 1;
    } else {
      if (grid[playerY][playerX-1] != 1) {
        playerX--;
      }
    }
    
  }
  if (keyCode == RIGHT) {
    if (playerX == grid.length - 1) {
      playerX = 0;
    } else {
      if (grid[playerY][playerX+1] != 1) {
        playerX++;
      }
    }
    
  }
  
  if (playerX < 0) {
    playerX = grid.length;
  } else if (playerX > grid.length) {
    playerX = 0;
  }
  
  if (grid[playerY][playerX] == 0) {
    grid[playerY][playerX] = 2;
    //fill(255);
    //ellipse (playerX * cellW + cellW/2, playerY * cellH + cellH/2, 3, 3);
  }
  
  updateGhosts();
  drawUrrything();
}

void updateGhosts() {
  //needs to have a direction
  //if not in a decision cell
  //  if the position ahead is free
        //move in current direction
  //   if it is not free
  //      find the other open position and move to it
  //
  if (grid[ghostY][ghostX] != 3) {
    if (grid[ghostY + ghostDirY][ghostX + ghostDirX] == 1) {
      //if its moving vertically:
      if (ghostDirX != 0) {
        //if theres space below
        if (grid[ghostY + 1][ghostX] != 1) {
          //change direction to down
          ghostDirX = 0;
          ghostDirY = 1;
        }
        //if theres space above
        if (grid[ghostY - 1][ghostX] != 1) {
          //change direction to up
          ghostDirX = 0;
          ghostDirY = -1;
        }
      }
      else if (ghostDirY != 0) {                  
        if (grid[ghostY][ghostX + 1] != 1) {      
          ghostDirX = 1;                          
          ghostDirY = 0;
        }
        if (grid[ghostY][ghostX - 1] != 1) {     
          ghostDirX = -1;                        
          ghostDirY = 0;
        }
      }
    }
  } else {  //is in decision cell
     if (ghostDirX != 0) {
       boolean upFree = false, downFree = false, contFree = false;
       float upDist = 0, downDist = 0, contDist = 0;
       
       if (grid[ghostY - 1][ghostX] != 1) {
         upFree = true;
         upDist = dist(ghostX, ghostY-1, playerX, playerY);
       }
       if (grid[ghostY + 1][ghostX] != 1) {
         downFree = true;
         downDist = dist(ghostX, ghostY+1, playerX, playerY);
       }
       if (grid[ghostY][ghostX + ghostDirX] != 1) {
         contFree = true;
         contDist = dist(ghostX + ghostDirX, ghostY, playerX, playerY);
       }
       
       if (upFree && downFree) {
         if (upDist < downDist) {
           ghostDirX = 0;
           ghostDirY = -1;
         } else {
           ghostDirX = 0;
           ghostDirY = 1;
         }  
       } else if (downFree && contFree) {
         if (downDist < contDist) {
           ghostDirX = 0;
           ghostDirY = 1;
         } else {}
       } else if (contFree && upFree) {
         if (contDist < upDist) {
           
         } else {
           ghostDirX = 0;
           ghostDirY = -1;
         }
       }
       
     } else if (ghostDirY != 0) {
       boolean leftFree = false, rightFree = false, contFree = false;
       float leftDist = 0, rightDist = 0, contDist = 0;
       
       if (grid[ghostY][ghostX - 1] != 1) {
         leftFree = true;
         leftDist = dist(ghostX - 1, ghostY, playerX, playerY);
       }
       if (grid[ghostY][ghostX + 1] != 1) {
         rightFree = true;
         rightDist = dist(ghostX + 1, ghostY, playerX, playerY);
       }
       if (grid[ghostY + ghostDirY][ghostX] != 1) {
         contFree = true;
         contDist = dist(ghostX, ghostY + ghostDirY, playerX, playerY);
       }
       
       if (rightFree && leftFree) {
         if (rightDist < leftDist) {
           ghostDirX = -1;
           ghostDirY = 0;
         } else {
           ghostDirX = 1;
           ghostDirY = 0;
         }  
       } else if (leftFree && contFree) {
         if (leftDist < contDist) {
           ghostDirX = 1;
           ghostDirY = 0;
         } else {}
       } else if (contFree && rightFree) {
         if (contDist < rightDist) {
           
         } else {
           ghostDirX = -1;
           ghostDirY = 0;
         }
       }
       
     } 
  }
  
  ghostX += ghostDirX;
  ghostY += ghostDirY;
}

void drawUrrything () {
  noStroke();
  for (int i = 0; i < grid[0].length; i++) {
    for (int j = 0; j < grid.length; j++) {
      int val = grid[j][i];
      switch (val) {
        default:
        case 0:
        fill (0,0,0);
        break;
        
        case 1:
        fill (255,255,255);
        break;
        
        case 3:
        fill (0, 255, 0);
        break;
        
        //case 2:
        //break;
        
        //case 3:
        //break;
      }
      
      rect (i * cellW, j * cellH, cellW, cellH);
      
      if (grid[j][i] == 0) {
        fill(255);
        ellipse (i * cellW + cellW/2, j * cellH + cellH/2, 3, 3);
      }
    }
  }
  
  //ghosts
  fill (255, 0, 0);
  rect (ghostX * cellW, ghostY * cellH, cellW, cellH);
  
  //player
  fill (255, 255, 0);
  ellipseMode (CORNER);
  ellipse (playerX * cellW, playerY * cellH, cellW, cellH);
}