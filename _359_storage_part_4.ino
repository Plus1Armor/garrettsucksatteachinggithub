/////////////////////
// Connect Four Game
// play with 'qwertyu'
/////////////////////
int array[6][7];
int turn;
int value;
char var; // test variable
int variable;
int wincount;
int sensor0 = 2;
int sensor1 = 3;
int sensor2 = 4;
int sensor3 = 5;
int sensor4 = 6;
int sensor5 = 7;
int sensor6 = 8;



void setup() 
{
  pinMode(sensor0, INPUT_PULLUP);
  pinMode(sensor1, INPUT_PULLUP);
  pinMode(sensor2, INPUT_PULLUP);
  pinMode(sensor3, INPUT_PULLUP);
  pinMode(sensor4, INPUT_PULLUP);
  pinMode(sensor5, INPUT_PULLUP);
  pinMode(sensor6, INPUT_PULLUP);
  //wincount = 0;
  turn = 1;
  Serial.begin(9600); // testing
  for(int i=0;i<6;i++) //rows 0-6 amd columns 0-5
  {
    for(int j=0;j<7;j++)
    {  
      array[i][j] = 0;
    }
  }
  printBoard(array);
}
void loop() //PLAYER = 1   CPU = 2
{
  if(digitalRead(sensor0) == LOW)
    var = 'q';
  else if(digitalRead(sensor1) == LOW)
    var = 'w';
  else if(digitalRead(sensor2) == LOW)
    var = 'e';
  else if(digitalRead(sensor3) == LOW)
    var = 'r';
  else if(digitalRead(sensor4) == LOW)
    var = 't';
  else if(digitalRead(sensor5) == LOW)
    var = 'y';
  else if(digitalRead(sensor6) == LOW)
    var = 'u';
  // testing block start
//var = Serial.read(); // for testing
//  if(var == 'q')
//    variable = 0;
//  else if(var == 'w')
//    variable = 1;
//  else if(var == 'e')
//    variable = 2;
//  else if(var == 'r')
//    variable = 3;
//  else if(var == 't')
//    variable = 4;
//  else if(var == 'y')
//    variable = 5;
//  else if(var == 'u')
//    variable = 6;
  // testing block end
  switch (var)
  {
    case 'q':
      variable = 0;
      updateBoard(turn, variable, array);
      break;
    case 'w':
      variable = 1;
      updateBoard(turn, variable, array);
      break;
    case 'e':
      variable = 2;
      updateBoard(turn, variable, array);
      break;
    case 'r':
      variable = 3;
      updateBoard(turn, variable, array);
      break;
    case 't':
      variable = 4;
      updateBoard(turn, variable, array);
      break;
    case 'y':
      variable = 5;
      updateBoard(turn, variable, array);
      break;
    case 'u':
      variable = 6;
      updateBoard(turn, variable, array);
      break;
  }
}
void printBoard(int array[6][7]) //test board
{
  for(int i=0;i<6;i++)
  {
    Serial.print("[");
    for(int j=0;j<7;j++)
    {
      Serial.print(array[i][j]);
      Serial.print(' ');
    }
    Serial.println("]");
  }
}
int turnChange(int turn)
{
  if(turn == 1)
    return 2;
  else
    return 1;
}
void updateBoard(int turnSub, int variable, int array[6][7])
{
  Serial.print("sensor ");
  Serial.println(variable);
  for(int i=0;i<6;i++)
  {
    if(array[i][variable] != 0)
    {
      array[i-1][variable] = turn;
      goto loopbreak;      
    }
  }
  if(array[5][variable] == 0)
  {
    array[5][variable] = turn;
  }
  loopbreak:
  turn = turnChange(turnSub);
  printBoard(array);
}
// everything below here is new. everything above here works
//void winCheck(int array[6][7], int turn)
//{
//  //Horizontal check
//  for(int i=0;i<6;i++) //rows 0-6 amd columns 0-5
//  {
//    for(int j=0;j<7;j++)
//    {  
//      if (array[i][j] == turn)
//        count++;
//      else
//        count=0;
//    }
//  }
//}
//void winEnding(int turn)
//{
//  if(turn == 1)
//    Serial.println("Player 1 wins");
//  else
//    Serial.println("Player 2 wins");
//  exit 1;  
//}

