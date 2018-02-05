#include <stdio.h>
#include <stdlib.h>
int checkLegalMove(int size, int currentR,int currentC,int* queenPos,
  int queenNum){
  for(int i = 0; i < queenNum; i++){
    // int row = queenPos[i*2];
    // int column = queenPos[i*2+1];
    int row = currentR;
    int column = currentC;
    for(int t = 0; t < queenNum; t++){
      if(queenPos[t*2] == row && t != i){
        return 0;
      }
    }
    for(int o = 0; o < queenNum; o++){
      if(queenPos[o*2+1] == column && o != i){
        return 0;
      }
    }

    for(int j = 0; j < queenNum; j++){

      if((row-queenPos[j*2]) == (column - queenPos[j*2+1]) && j != i){

        return 0;
      }
    }
    for(int h = 0; h < queenNum; h++){
      if((queenPos[h*2] - row) == (column - queenPos[h*2+1]) && h != i){
        return 0;
      }
    }
  }
  return 1;

}
int solve(int currentR, int currentC,int* queenPos,int queenNum, int* queenSaved,
  int* count, int size,int displayFlag){

  // printf("currentR: %d  currentC: %d \n",currentR,currentC);
  // printf("queenPos: %d",queenPos[1]);
  // printf("queenNum: %d\n", queenNum);
  // printf("count: %d\n",*count);
  if (solve(currentR, currentC, queenPos, queenNum,queenSaved, count,
    size,displayFlag) == -1){
    printf("made it here");
    return -1;
  }
  // else{
    // printf("made it into the else");
    // if(checkLegalMove(size,currentR,currentC,queenPos,queenNum) == 1){
    //
    //   if(currentC == size - 1){
    //     if(*count == 0){
    //       queenSaved = queenPos;
    //     }
    //     *count = *count + 1;
    //     return 1;
    //   }
    //   queenPos[(queenNum-1)*2] = currentR;
    //   queenPos[(queenNum-1)*2+1] = currentC;
    // }
    // else if (currentR == size - 1){
    //   return -1;
    // }
  // }
  // while(currentR <= size-1 && (displayFlag == 1 && *count == 0)){
  //   printf("made it into the while loop");
  //   solve(currentR+1,currentC,queenPos,queenNum,queenSaved,count,size,displayFlag);
  // }
  // printf("made it out of the while loop");
  // solve(currentR,currentC+1,queenPos,queenNum+1,queenSaved,count, size,displayFlag);





    return -1;
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
        // queenPos[0] = 0;
        // queenPos[1] = 3;
        // queenPos[2] = 1;
        // queenPos[3] = 6;
        // queenPos[4] = 2;
        // queenPos[5] = 2;
        // queenPos[6] = 3;
        // queenPos[7] = 7;
        // queenPos[8]  = 4;
        // queenPos[9]  = 1;
        // queenPos[10]  = 5;
        // queenPos[11]  = 4;
        // queenPos[12]  = 6;
        // queenPos[13]  = 0;
        // queenPos[14]  = 6;
        // queenPos[15]  = 5;
        printf("size: %d",size);

        int result = solve(0,0,queenPos,0,queenSaved,&count,size,displayFlag);
        printf("result is : %d ", result);
        //draw(queenSaved,size,size);

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
