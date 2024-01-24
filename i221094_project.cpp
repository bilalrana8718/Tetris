/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include "cstdlib"
#include <string>
#include <fstream>


using namespace sf;
using namespace std;
int main(){
    srand(time(0));
    string str="\0", champ="\0";
    int highscore=0,chscore=0;
    
    ifstream file;
    file.open("file.txt");
    while(file>>highscore)
    {
    	
    	chscore=highscore;
    	
    }
    file.close();
    
    cout<< "Username: "; cin>> str;
    
    bool win=false;
    
///////////////////////////////////////////////////STARTUP MENU WINDOW////////////////////////////////////////////////////////////////////////     
                           
   RenderWindow menu(VideoMode(800,600), "MENU");
                           
   Texture bg;
   bg.loadFromFile("img/index.png");
   
   Sprite backg(bg);
                           
                           
                    	 	while (menu.isOpen())
                    	 	{    Event event;
                    	 	     while (menu.pollEvent(event))
                    	 	     {   
                    	 	     	if (event.type == Event::Closed)                  
         			     	 menu.close();  
         			     	 if (event.type == Event::KeyPressed)
         			      		{
         			      		if(event.key.code == Keyboard::R)
         			      		menu.close(); 
         			      		else if (event.key.code == Keyboard::Q)
         			      		{menu.close();
         			      		}
         			      		else if (event.key.code == Keyboard::W)
         			      		  {menu.close();
         			      		  win=true;}
         			      		}
                    	 	     }	
                    	 	     menu.clear(Color::White);
                    	 	     menu.draw(backg);
                    	 	     menu.display();

                    	 	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    	

   if(win){  
    RenderWindow window(VideoMode(640, 480), title);
    window.setFramerateLimit(60);
    window.setTitle("BR TETRIS");
    RenderWindow Menu;
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------------------------------------//  
    Font font;
    font.loadFromFile("Amatic-Bold.ttf");
    Text text, goal, hs, hsnum, text3;
    text.setFont(font);
    text.setString("Score: ");
    text.setCharacterSize(30);        			  
    text.setPosition(380.f, 70.f);
    
    hs.setFont(font);
    hs.setString("Highest Score: ");
    hs.setCharacterSize(28);        			  
    hs.setPosition(380.f, 115.f);
    
    goal.setFont(font);
    goal.setCharacterSize(30);        			  
    goal.setPosition(460.f, 70.f);
    
    hsnum.setFont(font);
    hsnum.setCharacterSize(30);        			  
    hsnum.setPosition(510.f, 115.f);
   
    
   
    
//------------------------------------------------------------------------------------------------------------------------------//    
    
    Texture obj1, obj2, obj3, obj4, obj5, obj6;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/back.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/over.png");                        // here we are loading textures from folder to draw sprites
    obj5.loadFromFile("img/rect.png");
    obj6.loadFromFile("img/index.png");
    
    
    Sprite sprite(obj1), background(obj2), frame(obj3), over(obj4), rect(obj5),pause(obj6);
    int delta_x=0, colorNum=4, Score=0;
    float timer=0, delay=0.5;
    
    bool rotate=0, space=0, restart=false;
    
    Clock clock;
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
 
    while (window.isOpen()){
    
        goal.setString(to_string(Score));
        hsnum.setString(to_string(chscore));
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
       
        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
                    else if (e.key.code == Keyboard::Space)
                    	space=true;
                    	else if (e.key.code == Keyboard::Q)
                    	window.close();
 /////////////////////////////////////////////MENU WINDOW///////////////////////////////////////////////////////////
                    	else if (e.key.code == Keyboard::H)
                    	{  

                    	Menu.create(VideoMode(800,600), "Pause Menu" );
                    	while (Menu.isOpen())
                    	 	{    Event event;
                    	 	     while (Menu.pollEvent(event))
                    	 	     {   
                    	 	     	if (event.type == Event::Closed)                  
         			     	 Menu.close();  
         			     	 if (event.type == Event::KeyPressed)
         			      		{
         			      		if(event.key.code == Keyboard::R)
         			      		Menu.close(); 
         			      		else if (event.key.code == Keyboard::Q)
         			      		{Menu.close();  window.close();
         			      		}
         			      		//else if (event.key.code == Keyboard::W)
         			      		  //{Menu.close(); restart = true; window.close();
         			      		  //}
         			      		}
                    	 	     }	
                    	 	           Menu.clear(Color::White);
                    	 	           Menu.draw(pause);
                    	 	           Menu.display();

                    	 	}
                    	
                    	}
                    	
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
            


   
  
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
       
       
        fallingPiece(timer, delay, colorNum);               //Example: fallingPiece() function is called here
        moveright(delta_x);
        moveleft(delta_x); 
        lineEliminate(gameGrid,M,N,Score);  
      	rotation(rotate);
      	Levels(Score, delay); 
      
        if (Champion(Score, highscore));
         { champ = str;}
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
   

        window.clear(Color::White);
        window.draw(background);
        
        window.draw(text);         //with this we draw text and scores on the window.
        window.draw(goal);
         window.draw(hs);
         window.draw(hsnum);
         
         
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
         window.draw(rect);
         rect.setPosition(-30.f, 30.f);
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
         if(gameover(gameGrid,M,N)==1)
           { timer=0;
             window.draw(over);
             over.setPosition(200.f, 50.f);
             
           }
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
//////////////////////////////////////////////////File Handling//////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------------------//     
if (Score > chscore)
{
fstream file("file.txt", ios::app);

file<<Score<<endl;
 
file.close();
}
//----------------------------------------------------------------------------------------------------------------------------//		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	


   
    }
    return 0;
}
