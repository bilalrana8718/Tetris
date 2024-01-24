/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */


//---Piece Starts to Fall When Game Starts---//


void fallingPiece(float& timer, float& delay, int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
       
        }
	delay=0.5;
        if (!anamoly())
        {
        	for(int i=0; i<4; i++)
        	        gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
              		colorNum=1+rand()%7;
            		int n=rand()%8;
            
                	for (int i=0;i<4;i++)
                	{
                    		point_1[i][0] = BLOCKS[n][i] % 2;
                    		point_1[i][1] = BLOCKS[n][i] / 2;
                	}
            
        }
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

//*********************************************************************************************
// Adding one to the X Coordinate will move the block to the right side so we used the column
// to stop block going out of the Grid on right Anomoly function is used .
//********************************************************************************************
void moveright(int& delta_x)
{
	  						 
	    if (delta_x==1)
	    {
	      
		for (int i=0;i<4;i++)
		{        
		    point_1[i][0]+=1;               
		}
		if(!anamoly())
		{         	   	               
			 for(int i=0;i<4;i++)
			 {point_1[i][0]-=1;}
		}
		delta_x=0;
             }
}

//*********************************************************************************************
// Subtracting one the X Coordinate will move the block to the Left side so we used the column
// // to stop block going out of the Grid on left Anomoly function is used .
//********************************************************************************************

void moveleft(int& delta_x)
{						       
    	if (delta_x==-1) 
    	{
        	for (int i=0;i<4;i++)
        	{
            	point_1[i][0]-=1;               
        	}
        if(!anamoly())
              {                                      
		 for(int i=0;i<4;i++)
		 {point_1[i][0]+=1;}
	      }
              delta_x=0;
        }
}       
 // -----------------------------------------------------------------------------------------------------------------------
 /*                           LINE ELIMINATION
     1. gameGrid, M, N are taken as argument because it is the field on which game is played.
     2. We check if there is a block on a position through checking if a array position in the grid is true.
     3. As largest array position (rows) is (size - 1) so we take M-1 and run a loop from the bottom position to the top
     4. I also ran a nested loop to check blocks in the Columns (width) too.
     5. A counter was added in the nested loop for checking if all the columns in the row are filled
        and that row is stored in gameGrid[rows][j].
     6. if the counter is ==N (columns) than that row is not stored. hence, eliminated   
 */
 //------------------------------------------------------------------------------------------------------------------------
 void lineEliminate(int gameGrind[20][10],int M,int N,int& Score)		
 								 
 {								
 
      int rows=M-1,line=0;						
      								    
      for(int i=rows; i>0; i--)
      {
        int counter=0,column=0;
        while(column<N)
        {
           if(gameGrid[i][column])
           counter++;
           gameGrid[rows][column]=gameGrid[i][column];
           column++;
        }
        if(counter<N)
        rows--;        
          else if (counter == N) line= line+1;
        
      }
       switch(line)
        {
             case 1: Score= Score+10; break; 
             case 2: Score= Score+30; break;
             case 3: Score= Score+60; break;
             case 4: Score= Score+100; break;
             
        }
     
 }	
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    1. If rotate true, we take a center of rotation which we store in Xo and Yo .
    2.  we use a for loop of iteration 4 because all blocks have 4 small blocks.
    3. Store point_1 in point_2 for Uncertain conditions
    4. take displaced coordinate (int x) in which we store displaced coordinate of Y(point_1[i][1]) by subtracting centre of rotation Yo
    5. take displaced coordinate (int y) in which we store displaced coordinate of X(point_1[i][0]) by subtracting centre of rotation Xo
    6. then subtract x from Xo and store in point_1[i][0]  to get the x coordinate after 90 degree rotation
    7. then subtract y from Yo and store in point_1[i][1]  to get the y coordinate after 90 degree rotation
    8. anomoly is used to eliminate uncertain conditions such as when blocks reach the frame end as original coordinates of point_1 are stored in point_2.
      
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void rotation(bool& rotate){
      if (rotate)
      { int Xo=0,Yo=0;
      // here we will take a centre of rotation
        Xo = point_1[1][0];
        Yo = point_1[1][1]; 
        for (int i=0;i<4;i++)
          { 
            point_2[i][0]=point_1[i][0];   point_2[i][1]=point_1[i][1];
            int x = point_1[i][1]- Yo;
            int y = point_1[i][0]- Xo;
            point_1[i][0] = Xo - x;
            point_1[i][1] = Yo + y;
           }
           if (!anamoly()) {for (int i=0;i<4;i++) {point_1[i][0]=point_2[i][0];   point_1[i][1]=point_2[i][1];}}
          
      }
      rotate = false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 1. In this gameover function, the first row of gameGrid (0) will be checked if there is any blocks in the first row of gameGrid.
 2. for this we take gameGrid[20][10], M, and N as parameters because gameGrid is used.
 3. Then we run a for loop the columns (less than N times) and check if gameGrid is true in any column, counter (j) will be
    added (j++). 
 4. if j is not equal to 0 function will return 1 and if j is equal to zero function will return 0;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int gameover(int gameGrid[20][10],int M,int N)
{       
        int j=0;
	for(int i=0; i<N; i++)
	{
		if(gameGrid[0][i])
		j++;
	}
	if(j > 0)
	return 1;
	else 
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //void spacebar(bool& space, float& delay,float& timer)									 
 //{	//do{
 	//if(space)
 	//{
 	//	delay=0.005;
 	//}
 	//   } while(gameGrid[point_1[3][]][]);
      
 //}	  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void Levels(int& Score, float& delay)
 {
 	if(Score < 60)
 	delay = 0.5;
 	else if (Score < 120 && Score >= 60)
 	delay = 0.4;
 	else if (Score < 180 && Score >= 120)
 	delay = 0.3;
 	else if (Score < 320 && Score >= 180)
 	delay = 0.2;
 	else if (Score >= 320)
 	delay = 0.1;
 
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //------------------------------------------------------------------------------------------------------------------------//

bool Champion(int& Score,int& highscore)
{
	if(Score > highscore)
	{
	   highscore = Score;
	   //champ = str;
	   return 1;
	}else return 0;
}
	
 	
 	
 	
 	

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
