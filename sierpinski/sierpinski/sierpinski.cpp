// sierpinski.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>

using namespace sf;
using namespace std;

/* I need to make a makefile for this if we're running thisin linux, just rip it off of timber champter 1 */
int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Sierpinski Triangle!!", Style::Default);

   //text and font
    /*
    Text userPrompt;
    userPrompt.setString("Click 4 spots using the mouse. The first 3 will be used to define the triangle and the last will be used to start the program.");
    userPrompt.setCharacterSize(20);
    userPrompt.setFillColor(Color::White);

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    userPrompt.setFont(font);
    
    //positioning the text
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f,	1080 / 2.0f);
    scoreText.setPosition(20, 20);
    */

    //declaring variables
    Vector2f v = { 10,10 }; //vector of size 2 of floats
    RectangleShape rect(v);

    vector<Vector2f> verticies; //use push_back to get shit in here
    vector<Vector2f> points; //again use push_back for this

    Vector2f clicked;

    rect.setFillColor(Color::Red); //change the color, it might be nice to set the verticies a different color than the initial mouse click

    while (window.isOpen())

    {
        Event event;
        while (window.pollEvent(event))
        {
            //close using the x button
            if (event.type == Event::Closed)
            {
                window.close();
            }
            //mouse clicky
            if (event.type == Event::MouseButtonPressed)
            {
                cout << "Clicked!\n"; //replace this with whatever needs to get clicked :>
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;
                
                clicked.x = event.mouseButton.x;
                clicked.y = event.mouseButton.y;
            }
        }


        //close the program if esc is pressed
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //update scene
        rect.setPosition(clicked.x, clicked.y);

        //draw the scene
        //clear all
        window.clear();
        //draw
        window.draw(rect);
        
        
        window.display();

 


        // check for the mouse click from the user
        // event poll (event mouse click)
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
