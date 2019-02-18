//***************************************************
// Filename: othello.c
//
// CIS343
@author: Nandigam
@author: Kelly Hancox
@version: Winter 2019
//***************************************************

#include "othello.h"

/* **************************************************
 * Displays the board (as SIZE x SIZE grid) on console
 * @param board the board for othello with size as the
 * height and length
 * **************************************************/
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/* ****************************************************
 * Initializes the board with start configuration
 * of discs
 * @param board the board for othello with size as the
 * height and length
 * ***************************************************/
void initializeBoard(char board[][SIZE])
{
	//parse through board and make them all '-'
	for(int i = 0; i < SIZE; i++){
	    for(int j = 0; j < SIZE; j++){
	        board[i][j] = '-';
	    }
	}

    //make declare the middle 4 variables as Bs and Ws
    board[(SIZE/2)-1][(SIZE/2)-1] = 'W';
	board[SIZE/2][SIZE/2] = 'W';
    board[SIZE/2][(SIZE/2)-1] = 'B';
    board[(SIZE/2)-1][SIZE/2] = 'B';
}

/* ****************************************************
 * This method is one of 8 and checks the upper
 * left discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkUpLeft(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row-1][col-1] == oppositeDisc){

        while(row - 1 >= 0 && col-1 >= 0){

            oppositeCount++;

            if(board[row-1][col-1] == disc){
                return oppositeCount;
            }
            else if(board[row-1][col-1] != disc &&
                    board[row-1][col-1] != oppositeDisc){
                return 0;
            }
            
            row--;
            col--;
            
        }
    }

    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the upper
 * discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkUp(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc) {

    int oppositeCount = 0;

    if (board[row-1][col] == oppositeDisc) {

        while (row - 1 >= 0){

            oppositeCount++;

            if(board[row-1][col] == disc){

                return oppositeCount;
            }
            else if(board[row-1][col] != disc &&
                    board[row-1][col] != oppositeDisc){
                return 0;
            }

            row--;
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the upper
 * right discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkUpRight(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row-1][col+1] == oppositeDisc){

        while (row - 1 >= 0 && col + 1 < SIZE){

            oppositeCount++;

            if(board[row-1][col+1] == disc){
                return oppositeCount;
            }
            else if(board[row-1][col+1] != disc &&
                    board[row-1][col+1] != oppositeDisc){
                return 0;
            }

            row--;
            col++;
        
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the right
 * discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkRight(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row][col+1] == oppositeDisc){

        while(col + 1 <= SIZE){
            
            oppositeCount++;

            if(board[row][col+1] == disc){
                return oppositeCount;
            }
            else if(board[row][col+1] != disc &&
                    board[row][col+1] != oppositeDisc){
                return 0;
            }
            
            col++;
            //}
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the lower
 * right discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkDownRight(char board[][SIZE], int row,
        int col, char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row+1][col+1] == oppositeDisc){

        while (row + 1 <= SIZE && col + 1 <= SIZE){

            oppositeCount++;

            if(board[row+1][col+1] == disc){
                return oppositeCount;
            }
            else if(board[row+1][col+1] != disc &&
                    board[row+1][col+1] != oppositeDisc){
                return 0;
            }
            
            row++;
            col++;
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the lower
 * discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkDown(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row+1][col] == oppositeDisc){

        while (row + 1 <= SIZE){
            
            oppositeCount++;

            if(board[row+1][col] == disc){
                return oppositeCount;
            }
            else if(board[row+1][col] != disc &&
                    board[row+1][col] != oppositeDisc){
                return 0;
            }
            
            row++;
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the lower
 * left discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkDownLeft(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row+1][col-1] == oppositeDisc){

        while (row + 1 <= SIZE && col-1 >= 0){
            
            oppositeCount++;

            if(board[row+1][col-1] == disc) {
                return oppositeCount;
            }
            
            else if(board[row+1][col-1] != disc &&
                    board[row+1][col-1] != oppositeDisc){
                return 0;
            }
            row++;
            col--;
        
        }
    }
    return 0;
}

/* ****************************************************
 * This method is one of 8 and checks the
 * left discs to count how many opposite discs
 * there are in a row until you
 * reach the original disc or a blank
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @param oppositeDisc the other player's disc
 * @return int the number of opposite discs between
 * disc and another disc of same
 * ***************************************************/
int checkLeft(char board[][SIZE], int row, int col,
        char disc, char oppositeDisc){

    int oppositeCount = 0;

    if(board[row][col-1] == oppositeDisc){

        while (col - 1 >= 0){
        
            oppositeCount++;

            if(board[row][col-1] == disc){
                return oppositeCount;
            }
            
            else if(board[row][col-1] != disc &&
                    board[row][col-1] != oppositeDisc){
                return 0;
            }
            col--;
        }
    }
    return 0;
}


/* ************************************************************
 * This method checks if the input is valid
 * Returns true if moving the disc to location row,col is valid;
 * else returns false
 * @param board the othello board with size of height
 * and length
 * @param row the row of the input
 * @param col the column of the input
 * @param disc the player's disc
 * @return bool whether or not the move is valid
 * ************************************************************/
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{

    if(board[row][col]!= '-'){
        return false;
    }

    char opposite = '\0';

    if(disc == 'W'){
        opposite = 'B';
    }else{
        opposite = 'W';
    }

    //if the placement is in the middle
    if(row < SIZE-1 && row > 0 && col > 0 && col < SIZE-1){

        if(checkUpLeft(board, row, col, disc, opposite) > 0 ||
        checkUp(board, row, col, disc, opposite) > 0 ||
                checkUpRight(board, row, col, disc, opposite) > 0 ||
                checkRight(board, row, col, disc, opposite) > 0 ||
                checkDownRight(board, row, col, disc, opposite) > 0 ||
                checkDown(board, row, col, disc, opposite) > 0 ||
                checkDownLeft(board, row, col, disc, opposite) > 0 ||
                checkLeft(board, row, col, disc, opposite) > 0){
        return true;
        }
    }

    //checking bottom right corner
    else if(row == SIZE-1 && col == SIZE-1){

        if(checkUp(board, row, col, disc, opposite) > 0 ||
        checkUpLeft(board, row, col, disc, opposite) > 0 ||
        checkLeft(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //check top right corner
    else if(row == 0 && col == SIZE-1){

        if(checkDown(board, row, col, disc, opposite) > 0 ||
        checkDownLeft(board, row, col, disc, opposite) > 0 ||
                checkLeft(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //check top left corner
    else if(row == 0 && col == 0){

        if(checkDown(board, row, col, disc, opposite) > 0 ||
        checkDownRight(board, row, col, disc, opposite) > 0 ||
           checkRight(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //checking bottom Left corner
    else if(row == SIZE-1 && col == 0){

        if(checkUp(board, row, col, disc, opposite) > 0 ||
        checkUpRight(board, row, col, disc, opposite) > 0 ||
           checkRight(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //if we're from the bottom row but not in a corner
    else if(row == SIZE-1){

        if(checkLeft(board, row, col, disc, opposite) > 0 ||
        checkUpLeft(board, row, col, disc, opposite) > 0 ||
                checkUp(board, row, col, disc, opposite) > 0 ||
                checkUpRight(board, row, col, disc, opposite) > 0 ||
                checkRight(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //if we're from the top row but not in a corner
    else if(row == 0){

        if(checkLeft(board, row, col, disc, opposite) > 0 ||
        checkDownLeft(board, row, col, disc, opposite) > 0 ||
           checkDown(board, row, col, disc, opposite) > 0 ||
           checkDownRight(board, row, col, disc, opposite) > 0 ||
           checkRight(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //if we're in furthest left row but not in a corner
    else if(col == 0){

        if(checkUp(board, row, col, disc, opposite) > 0 ||
        checkUpRight(board, row, col, disc, opposite) > 0 ||
           checkRight(board, row, col, disc, opposite) > 0 ||
           checkDownRight(board, row, col, disc, opposite) > 0 ||
           checkDown(board, row, col, disc, opposite) > 0){
            return true;
        }
    }

    //if we're in furthest right row but not in a corner
    else if(col == SIZE-1){

        if(checkUp(board, row, col, disc, opposite) > 0 ||
        checkUpLeft(board, row, col, disc, opposite) > 0 ||
           checkLeft(board, row, col, disc, opposite) > 0 ||
           checkDownLeft(board, row, col, disc, opposite) > 0 ||
           checkDown(board, row, col, disc, opposite) > 0){
            return true;
        }
    }
	return false;
}


/********************************************************
 * This method flips discs in the upper left from the
 * input to the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeUpLeftDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int upLeft) {
    for (int i = 1; i <= upLeft; i++) {
        board[row - i][col - i] = disc;
    }
}


/********************************************************
 * This method flips discs in the above the input to
 * the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeUpDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int up) {
    for (int j = 1; j <= up; j++) {
        board[row - j][col] = disc;
    }
}

/********************************************************
 * This method flips discs from the upper right of  the
 * input to the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeUpRightDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int upRight) {
    for (int k = 1; k <= upRight; k++) {
        board[row - k][col + k] = disc;
    }
}

/********************************************************
 * This method flips discs to the right of the input to
 * the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeRightDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int right) {
    for (int l = 1; l <= right; l++) {
        board[row][col + l] = disc;
    }
}

/********************************************************
 * This method flips discs to the lower right of the
 * input to the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeDownRightDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int downRight) {
    for (int m = 1; m <= downRight; m++) {
        board[row + m][col + m] = disc;
    }
}

/********************************************************
 * This method flips discs below the input to
 * the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeDownDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int down) {
    for (int n = 1; n <= down; n++) {
        board[row + n][col] = disc;
    }
}

/********************************************************
 * This method flips discs down right of the input to
 * the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeDownLeftDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int downLeft) {
    for (int r = 1; r <= downLeft; r++) {
        board[row + r][col - r] = disc;
    }
}

/********************************************************
 * This method flips discs left of the input to
 * the current disc
 * @param board othello board with size dimensions
 * @param row row of the input
 * @param col column of input
 * @param disc current player's disc
 * @param opposite opposite disc
 * @param upLeft how many discs to flip
 ******************************************************/
void changeLeftDisc(char board[][SIZE], int row,
        int col, char disc, char opposite, int left) {
    for (int s = 1; s <= left; s++) {
        board[row][col - s] = disc;
    }
}


/*******************************************************
 * Places the disc at location row,col and flips the
 * opponent discs as needed
 * @param board board with size dimensions
 * @param row input row
 * @param col input column
 * @param disc current player's disc
 *******************************************************/
void placeDiscAt(char board[][SIZE], int row, int col, char disc) {

    char opposite = '\0';

    if (disc == 'W') {
        opposite = 'B';
    } else {
        opposite = 'W';
    }

    if (isValidMove(board, row, col, disc)) {

        board[row][col] = disc;

        //changed the disc within the middle
        if (row < SIZE - 1 && row > 0 && col > 0 && col < SIZE - 1) {

            int upLeft = checkUpLeft(board, row, col, disc, opposite);
            int up = checkUp(board, row, col, disc, opposite);
            int upRight = checkUpRight(board, row, col, disc, opposite);
            int right = checkRight(board, row, col, disc, opposite);
            int downRight = checkDownRight(board, row, col, disc, opposite);
            int down = checkDown(board, row, col, disc, opposite);
            int downLeft = checkDownLeft(board, row, col, disc, opposite);
            int left = checkLeft(board, row, col, disc, opposite);

            changeUpLeftDisc(board, row, col, disc, opposite, upLeft);
            changeUpDisc(board, row, col, disc, opposite, up);
            changeUpRightDisc(board, row, col, disc, opposite, upRight);
            changeRightDisc(board, row, col, disc, opposite, right);
            changeDownRightDisc(board, row, col, disc, opposite, downRight);
            changeDownDisc(board, row, col, disc, opposite, down);
            changeDownLeftDisc(board, row, col, disc, opposite, downLeft);
            changeLeftDisc(board, row, col, disc, opposite, left);

        }

            //checking bottom right corner
        else if (row == SIZE - 1 && col == SIZE - 1) {

            int upLeft = checkUpLeft(board, row, col, disc, opposite);
            int up = checkUp(board, row, col, disc, opposite);
            int left = checkLeft(board, row, col, disc, opposite);

            changeUpLeftDisc(board, row, col, disc, opposite, upLeft);
            changeUpDisc(board, row, col, disc, opposite, up);
            changeLeftDisc(board, row, col, disc, opposite, left);
        }

            //check top right corner
        else if (row == 0 && col == SIZE - 1) {

            int down = checkDown(board, row, col, disc, opposite);
            int downLeft = checkDownLeft(board, row, col, disc, opposite);
            int left = checkLeft(board, row, col, disc, opposite);

            changeDownDisc(board, row, col, disc, opposite, down);
            changeDownLeftDisc(board, row, col, disc, opposite, downLeft);
            changeLeftDisc(board, row, col, disc, opposite, left);
        }

            //check top left corner
        else if (row == 0 && col == 0) {

            int downRight = checkDownRight(board, row, col, disc, opposite);
            int down = checkDown(board, row, col, disc, opposite);
            int right = checkRight(board, row, col, disc, opposite);

            changeRightDisc(board, row, col, disc, opposite, right);
            changeDownRightDisc(board, row, col, disc, opposite, downRight);
            changeDownDisc(board, row, col, disc, opposite, down);
        }

            //checking bottom Left corner
        else if (row == SIZE - 1 && col == 0) {

            int upRight = checkUpRight(board, row, col, disc, opposite);
            int up = checkUp(board, row, col, disc, opposite);
            int right = checkRight(board, row, col, disc, opposite);

            changeUpRightDisc(board, row, col, disc, opposite, upRight);
            changeRightDisc(board, row, col, disc, opposite, right);
            changeUpDisc(board, row, col, disc, opposite, up);

        }

            //if we're from the bottom row but not in a corner
        else if (row == SIZE - 1) {

            int right = checkRight(board, row, col, disc, opposite);
            int upRight = checkUpRight(board, row, col, disc, opposite);
            int up = checkUp(board, row, col, disc, opposite);
            int upLeft = checkUpLeft(board, row, col, disc, opposite);
            int left = checkLeft(board, row, col, disc, opposite);

            changeUpLeftDisc(board, row, col, disc, opposite, upLeft);
            changeUpDisc(board, row, col, disc, opposite, up);
            changeUpRightDisc(board, row, col, disc, opposite, upRight);
            changeRightDisc(board, row, col, disc, opposite, right);
            changeLeftDisc(board, row, col, disc, opposite, left);
        }

            //if we're from the top row but not in a corner
        else if (row == 0) {

            int left = checkLeft(board, row, col, disc, opposite);
            int downLeft = checkDownLeft(board, row, col, disc, opposite);
            int down = checkDown(board, row, col, disc, opposite);
            int downRight = checkDownRight(board, row, col, disc, opposite);
            int right = checkRight(board, row, col, disc, opposite);

            changeRightDisc(board, row, col, disc, opposite, right);
            changeDownRightDisc(board, row, col, disc, opposite, downRight);
            changeDownDisc(board, row, col, disc, opposite, down);
            changeDownLeftDisc(board, row, col, disc, opposite, downLeft);
            changeLeftDisc(board, row, col, disc, opposite, left);
        }

            //if we're in furthest left row but not in a corner
        else if (col == 0) {

            int up = checkUp(board, row, col, disc, opposite);
            int upRight = checkUpRight(board, row, col, disc, opposite);
            int right = checkRight(board, row, col, disc, opposite);
            int downRight = checkDownRight(board, row, col, disc, opposite);
            int down = checkDown(board, row, col, disc, opposite);

            changeUpDisc(board, row, col, disc, opposite, up);
            changeUpRightDisc(board, row, col, disc, opposite, upRight);
            changeRightDisc(board, row, col, disc, opposite, right);
            changeDownRightDisc(board, row, col, disc, opposite, downRight);
            changeDownDisc(board, row, col, disc, opposite, down);
        }

            //if we're in furthest right row but not in a corner
        else if (col == SIZE - 1) {

            int up = checkUp(board, row, col, disc, opposite);
            int upLeft = checkUpLeft(board, row, col, disc, opposite);
            int left = checkLeft(board, row, col, disc, opposite);
            int downLeft = checkDownLeft(board, row, col, disc, opposite);
            int down = checkDown(board, row, col, disc, opposite);

            changeUpLeftDisc(board, row, col, disc, opposite, upLeft);
            changeUpDisc(board, row, col, disc, opposite, up);
            changeDownDisc(board, row, col, disc, opposite, down);
            changeDownLeftDisc(board, row, col, disc, opposite, downLeft);
            changeLeftDisc(board, row, col, disc, opposite, left);
        }

    }
}


/*******************************************************
 * True if a valid move for
 * disc is available; else returns false
 * @param board othello board with size dimensions
 * @param disc current player's disc
 * @return bool if there exists a valid move on board
 ********************************************************/
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
    //only need to find first one
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == '-'){
                if(isValidMove(board, i, j, disc)){
                    return true;
                }
            }
        }
    }
	return false;
}

/*********************************************************
 * Checks if board is entirely full
 * @param board othello board with size dimensions
 * @return bool if full or not
 *********************************************************/
bool isBoardFull(char board[][SIZE]){

    bool boardIsFull = false;

    int boardCount = 0;

    //checks if the board is full
    for (int i = 0; i < SIZE; ++i) {
        for(int j  = 0; j < SIZE; j++){
            if(board[i][j] != '-'){
                boardCount++;
            }
            if(boardCount == SIZE*SIZE){
                boardIsFull = true;
            }
        }
    }

	return boardIsFull;
}


/**********************************************************
 * Returns true if either the board is full
 * or a valid move is not available for either disc
 * @param board othello board with size dimensions
 * @return bool if game is over or not
 **********************************************************/
bool isGameOver(char board[][SIZE])
{
    bool gameIsOver = false;

    //if the board is full, then game is over
    if(isBoardFull(board)){
        gameIsOver = true;
    }

    if(!isValidMoveAvailable(board,'B') &&
    !isValidMoveAvailable(board, 'W')){
        gameIsOver = true;
    }
	return gameIsOver;
}

/*  */
/***********************************************************
 * If there is a winner, it returns the disc (BLACK or WHITE)
 * associated with the winner. In case of a tie,
 * it returns EMPTY
 * @param board othello board with size dimensions
 * @return char disc of the winner
 ***********************************************************/
char checkWinner(char board[][SIZE]) {
    int blackCount = 0;
    int whiteCount = 0;

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j< SIZE; j++){
            if (board[i][j] == 'B'){
                blackCount++;
            }
            else if(board[i][j] == 'W'){
                whiteCount++;
            }
        }
    }

    if(blackCount > whiteCount){
        return BLACK;
    }
    else if (whiteCount < blackCount){
        return WHITE;
    }
    return EMPTY;
}
