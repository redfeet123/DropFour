#include <iostream>
#include <limits> // Include the limits header for numeric_limits

using namespace std;

char board[6][7]; // Board for the game 2D array   [ [1,2,3,4,5,6], [1,2,3,4,5,6], [1,2,3,4,5,6]]

void initializeBoard() {
	//nested loop
   for (int i = 0; i < 6; i++) { 	 //rows
       for (int j = 0; j < 7; j++) { // column
           board[i][j] = ' '; 		 // Fill the board with empty spaces
       }
   }
}
 
void displayBoard() { //diisgning the board
   cout << " 1 2 3 4 5 6 7\n"; // Display column numbers
   for (int i = 0; i < 6; i++) {
       cout << "|";
       for (int j = 0; j < 7; j++) {
           cout << board[i][j] << "|"; // Print each cell of the board
       }
       cout << endl;
   }
}
// responsible for putting char 
bool placePiece(char piece, int column) {
   for (int i = 5; i >= 0; i--) { 		  // Start from the bottom row
       if (board[i][column - 1] == ' ') { // Check for empty space in the specified column..
           board[i][column - 1] = piece;  // Place the piece in the first available empty space...
           return false;   //to show that the piece is placed sucessfully on the place
       }
   }
   return true; // No empty space found in the specified column
}

// Simplified check for a win (only checks horizontal, vertical, and diagonal)
bool checkWin(char piece) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            // Horizontal check
            if (board[i][j] == piece && board[i][j + 1] == piece && board[i][j + 2] == piece && board[i][j + 3] == piece) {
                return true; // Four consecutive pieces in a row horizontally
            }
            // Vertical check
            if (board[j][i] == piece && board[j + 1][i] == piece && board[j + 2][i] == piece && board[j + 3][i] == piece) {
                return true; // Four consecutive pieces in a column vertically
            }
        }
    }

    // Diagonal checks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // Diagonal down-right
            if (board[i][j] == piece && board[i + 1][j + 1] == piece && board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece) {
                return true; // Four consecutive pieces diagonally down-right
            }
            // Diagonal down-left
            if (board[i + 3][j] == piece && board[i + 2][j + 1] == piece && board[i + 1][j + 2] == piece && board[i][j + 3] == piece) {
                return true; // Four consecutive pieces diagonally down-left
            }
        }
    }
  


    return false; // No winning combination found
}

bool checkDraw() {
    // Check if the entire board is filled
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == ' ') {
                // If there's an empty space, the game is not a draw
                return false;
            }
        }
    }
    // If no empty spaces are found, the game is a draw
    return true;
}

int main() {
   initializeBoard();
   char currentPlayer = 'X'; // Start with player X
//infinite loop untill we control it from inside
   while (true) { 
       displayBoard(); // displays designming the board
       int column; 	   
       cout << currentPlayer << "'s turn. Choose a column (1-7): ";
       
       // Input validation loop error handling purpose
       while (!(cin >> column) || column < 1 || column > 7) {
           cout << "Invalid input. Please enter a valid column number (1-7): ";
           cin.clear(); // Clear the error flag
           cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
       }

       if (placePiece(currentPlayer, column)) {   
           cout << "Invalid column. Try again.\n";
           continue;
       }

       if (checkWin(currentPlayer)) {
           displayBoard();
           cout << currentPlayer << " wins!\n";
           break;
       }
       if(checkDraw()){
       		displayBoard();
           cout << "the game is draw!\n";
           break;
	   }
		//ternary operator
       currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
   }

   return 0;
}

