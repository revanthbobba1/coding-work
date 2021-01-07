#include <iostream>

using namespace std;

struct location{
	int color=0;
	int numPieces=0;
};
class Piece{
	private:
		int location;	// 0 thru 25 	0 Goal for White,  25 will goal for Red	26 Will be Bar
		int color;	// Red = 1, White = 2;
	public:
		Piece(){
            color =0;
            location =0;
            }				// Default Constructor	Location – 99	Color – 0
		void setPiece (int c, int l){
            color = c;
            location= l;}		// Sets Pieces at their default location

		int getColor();			// Returns color
		int getLocation(){
            return location;}		// Returns present location
		void display(){             // Shows what a piece looks like based on color
            if (color == 1)
                cout<<'R';
            else if (color == 2)
                cout<<'W';
            else
                cout<<"Nothing to see here";
            }


};

class Board {
private:
        		Piece list[20];			// 10 pieces each. 0-9 Player 1, 10-19 Player 2
        		location loc[26];		//  1-24 on the board (0, 25 are home),
        		void display();			// Controls what to print and where on the screen

    	public:
       	 	Board(){
            cout<<"hi";
       	  	list[0].setPiece(1,1);
       	 	for (int i=1;i<5;i++)
                list[i].setPiece(i,i);

       	 	int x;
                for (int k = 0;k<5;k++){
                  x = list[k].getLocation();
                  loc[x].numPieces++;
                }
       	 		// This is fairly long and a lot of hard coding of the
                                // position, and using a loop to place them on board.
             }                   // Also include the numbers 1-24 and the Bar area  from the previous handout
       	 	void execute()
       	 	{
       	 	   for (int y=0;y<26;y++){
                cout<<"original number "<<y<<"  ";
                if (loc[y].numPieces> 0)
                    cout<<"numpieces "<<loc[y].numPieces<<" ";
                list[y].display();
                cout<<endl;
       	 	   }

       	 	}			//runs the game.

};
int main(){
    Board b;
    b.execute();
    return 0;

}
