// CS1300 Fall 2018
// Author: Brandon Cage
// Recitation: 203 – Sebastian Laudenschlager
// Cloud9 Workspace Editor Link: https://ide.c9.io/brca6216/csci1300bcage
// HOMEWORK/REC # - Problem #

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include "Player.h"
#include "Party.h"
#include "Milestones.h"
#include "Player.h"
#include "Party.h"
#include "Menu.h"

using namespace std;

/**
* Algorithm: 
* 1. 

* Parameters: 
* Output: 
* Returns: 
*/


int main()
{
    bool gameover=1;//tells if game is over
    int result;
    Menu jackson;//menu object
    jackson.setup();//sets up game
    jackson.fortNite(0);//starts a fort
    int choice;//menu choice
    int random1;//random int
    int random2;//random int
    bool turn;//did a turn pass?
    while (gameover==1)//while the game has not yet ended
    {
    turn=1;//turn will be taken if this is not changed
    std::cout << "\nIt is ";//text
    jackson.getDateString();//Day of the year
    std::cout << ".\nStill " << jackson.getMilesToGo() << " miles to go until Oregon! What would you like to do?\n";//text
    std::cout << "1.Continue on the Trail\n2.Stop to Rest\n3.Go Hunting\n4.View Supplies\n5.Quit Game\n";//text
    std::cin >> choice;//imput is the users choice
        switch (choice)
        {
            case 1:
                result=jackson.trail();//go on the trail
                if (result==1)//if we hit a fort
                {
                    jackson.fortNite(jackson.getFortInt());//enter fort
                }
                if (result==2)//if we hit a river
                {
                    jackson.riverNite(jackson.getRiverDepth());//enter river
                }
                if (result==3)//if we reached the end
                {
                    gameover=0;//game over
                }
                else if (jackson.getSick()==1)//decides if the sick dies
                {
                    srand((unsigned)time(0));//random clock
                    random2=(rand()%10);//0-9
                    if (random2<7)//70% chance of death
                    {
                        gameover=jackson.killTheSick(1);//kills the sick player. If the leader died, game over
                    }
                    else//30% chance of living
                    {
                        jackson.killTheSick(0);//Heal the sick
                    }
                }
                break;
            case 2:
                jackson.rest();//rest up
                if (jackson.getSick()==1)//if someone's sick
                {
                    srand((unsigned)time(0));//random clock
                    random2=(rand()%10);//0-9
                    if (random2<3)//30% chance
                    {
                        gameover=jackson.killTheSick(1);//kills the sick player. If the leader died, game over
                    }
                    else//70% chance
                    {
                        jackson.killTheSick(0);//heals the sick player
                    }
                }
                break;
            case 3:
                jackson.hunt();//hunt
                if (jackson.getSick()==1)//if someone's sick
                {
                    srand((unsigned)time(0));//random clock
                    random2=(rand()%10);//0-9
                    if (random2<7)//70% chance of death
                    {
                        gameover=jackson.killTheSick(1);//kill the sick. If the leader died, game over
                    }
                    else//30% chance
                    {
                        jackson.killTheSick(0);//heals the sick
                    }
                }
                break;
            case 4:
                std::cout << "Currently traveling with ";
                jackson.printAliveNames();//lists alive players
                std::cout << "\nMoney: $" << jackson.getMoney();
                std::cout << "\nOxen: " << jackson.getOxen();
                std::cout << "\nFood: " << jackson.getFood() << " pounds";
                std::cout << "\nBullets: " << jackson.getBullets();
                std::cout << "\nSpare Wagon Parts: " << jackson.getWagonParts();
                std::cout << "\nMedical Aid Kits: " << jackson.getAidKits() << "\n\n";//text
                
                turn=0;//turn did not pass
                break;
            case 5:
                std::cout << "You chose to end your journey early. You ended your journey a quitter.\n";//boooooo noone likes a quitter
                gameover=0;//end game
            default:
                std::cout << "Ivalid imput\n";//not 1-5
                turn=0;//turn did not pass
        }
        if (turn==1 && gameover==1)//if turn passed and game is not over
        {
            srand((unsigned)time(0));//random clock
            random1=(rand()%15);//0-14
            gameover=jackson.misfortune(random1);//does a misfortune occur? Also tells if game is over
            if (gameover==1)//if game is not over
            {
                jackson.raider();//raider attack
                if (jackson.getDateInt()>275)//if december has come
                {
                    std::cout << "Oh no! Winter has set in! It is impossible to reach Oregon City now!\n";
                    gameover=0;//game over
                }
                if (jackson.getOxen()<1)//if you have no more oxen
                {
                    std::cout << "You have no more Oxen! You cannot continue your journey!\n";
                    gameover=0;//game over
                }
                if (jackson.getFood()<0)//if you ran out of food
                {
                    std::cout << "Oh no! You ran out of food! You have died from starvation!\n";
                    gameover=0;//game over
                }
            }
        }
    }
}
