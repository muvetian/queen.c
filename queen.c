#include <stdio.h>
#include <stdlib.h>
int checkLegalMove(int size, int* queenPos, int queenNum){
  for(int i = 0; i < queenNum; i++){
    int row = queenPos[(queenNum-1)*2];
    int column = queenPos[(queenNum-1)*2+1];
    for(int t = 0; t < i; t++){
      if(queenPos[t*2] == row){
        return -1;
      }
    }
    for(int o = 0; o < i; o++){
      if(queenPos[o*2+1] == column){
        return -1;
      }
    }
    int r = row;
    int c = column;
    for(int j = 0; j < i; j++){
      if((row-queenPos[j*2]) == (column - queenPos[j*2+1])){
        return -1;
      }
    }
    for(int h = 0; h < i; h++){
      if((queenPos[h*2] - row) == (column - queenPos[h*2+1])){
        return -1;
      }
    }
  }
  return 0;

}
int solve(int* current,int* queenPos,int queenNum, int* queenSaved,
  int* count, int size){

  if (solve(current,queenPos,queenNum,queenSaved,count,size) == -1){
    int* next = (int*) malloc((sizeof(int))*2);
    next = current;
    next[1] = current[1] + 1;

    solve(next,queenPos,queenNum,queenSaved,count,size);
  }
  else if (checkLegalMove(size,queenPos,queenNum)){

  }
  return 1;
}
void draw(int* queenPos,int board_size,int queen_size){

  for(int i = 0; i < 2*board_size+1;i++){
    printf("-");
  }
  printf("\n");
  for(int j = 0; j < board_size; j++){
    printf("|");
    for(int l = 0;l < board_size; l++){
        int isQueen = 0;
        for(int k = 0; k < queen_size ; k++){
          if(queenPos[k*2] == j && queenPos[k*2+1] == l){
            printf("Q|");
            isQueen = 1;
          }
        }

        if (!isQueen){
          printf("_|");
        }

      }


    printf("\n");
  }
  // TODO: print the board
}
int main(){
  int quitFlag = 0;
  int countFlag = 0;
  int displayFlag = 0;
  int size = 0;
  int count = 0;
  while(!quitFlag){
    printf("Enter c for count, d for display, or q to quit: ");
    char input;
    scanf(" %c",&input);

    if(input == 'c' || input == 'd'){
      printf("Enter size of chessboard: ");
      scanf(" %d", &size);
      int* queenPos = (int*)malloc(sizeof(int)*size*2);
      int* queenSaved = (int*)malloc(sizeof(int)*size*2);
      for(int i = 0; i < 2*size; i++){
        queenPos[i] = -1;
      }
      int* bottomLeft = (int*)malloc(sizeof(int)*2);
      bottomLeft[0] = size - 1;
      bottomLeft[1] = 0;
      if(input == 'c'){
        countFlag = 1;
      }
      else{
        displayFlag = 1;
      }
      int result = 0;
      // int result = solve(bottomLeft,queenPos,0,queenSaved,&count,size);

      if(result == -1){
        printf("No solutions exist!\n");
      }
      else if(displayFlag == 1 && countFlag == 0){
        queenPos[0] = 0;
        queenPos[1] = 3;
        queenPos[2] = 1;
        queenPos[3] = 6;
        queenPos[4] = 2;
        queenPos[5] = 2;
        queenPos[6] = 3;
        queenPos[7] = 7;
        queenPos[8]  = 4;
        queenPos[9]  = 1;
        queenPos[10]  = 5;
        queenPos[11]  = 4;
        queenPos[12]  = 6;
        queenPos[13]  = 0;
        queenPos[14]  = 6;
        queenPos[15]  = 5;
        printf("size: %d",size);
        draw(queenPos,size,8);
        int checkTest = checkLegalMove(size,queenPos,4);
        printf("The move is: %d",checkTest);
      }
      else{
        printf("Total number of solutions: %d\n", count);
      }
    }

    else if(input == 'q'){
      quitFlag = 1;
    }
    else{
      printf("Error, invlaid command.\n");
    }
    countFlag = 0;
    displayFlag = 0;



  }
  return 0;
}
