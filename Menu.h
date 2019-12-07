#ifndef MENU_H
#define MENU_H

bool puzzle(int dif)//puzzle start. 3/dif chance of solving
{
    srand((unsigned)time(0)); //random clock
    int dig1;
    dig1 = (rand()%dif+1);//random int between 0 and dif
    std::cout << "\nGuess a number between 1 and " << dif << ".\n";//text
    int number1;
    std::cin >> number1;//their guess
    if (number1==dig1)//if they guessed right
    {
        std::cout << "You solved the puzzle!\n";
        return 1;
    }
    std::cout << "That is incorrect. You have 2 more tries.\n";//if incorrect
    std::cin >> number1;//guess again
    if (number1==dig1)//if they guessed right
    {
        std::cout << "You solved the puzzle!\n";
        return 1;
    }
    std::cout << "That is incorrect. You have 1 more try.\n";//if incorrect
    std::cin >> number1;//guess again
    if (number1==dig1)//if they guess right
    {
        std::cout << "You solved the puzzle!\n\n";
        return 1;
    }
    std::cout << "You failed to solve the puzzle. The number was " << dig1 << ".\n\n";//failure
    return 0;
}

class Menu
{
    private:
        Party family;//party object
        Milestones landmarks;//milestones object
        int riverint;//number of rivers crossed
        int fortint;//number of forts crossed
        bool sick;//if someone is sick
    public:
        
        Menu()
        {
            riverint=0;//no rivers passed
            fortint=0;//no forts passed
            sick=0;//noone's sick
        }
        int getMilesToGo()
        {
            family.getMilesToGo();
        }
        int getAidKits()
        {
            family.getAidKits();
        }
        int getAlivePlayers()
        {
            family.getAlivePlayers();
        }
        void getDateString()
        {
            family.getDateString();
        }
        int getDateInt()
        {
            family.getDateInt();
        }
        int getMoney()
        {
            return family.getMoney();
        }
        int getOxen()
        {
            family.getOxen();
        }
        int getWagonParts()
        {
            family.getWagonParts();
        }
        int getBullets()
        {
            family.getBullets();
        }
        int getFood()
        {
            family.getFood();
        }
        int getFortInt()
        {
            return fortint;
        }
        int getRiverDepth()
        {
            return landmarks.getRiverDepth(riverint);
        }
        bool getSick()
        {
            return sick;
        }
        void printAliveNames()
        {
            bool first=1;
            for (int n=0;n<5;n++)
            {
                
                if (family.getStatus(n)>=0)
                {
                    if (first==0)
                    {
                        std::cout << ", ";
                    }
                    std::cout << family.getName(n);
                    first=0;
                }
            }
        }
        
        
        void setup()//to start the game
        {
            std::cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE MUST COVER THE 2040 MILE OREGON TRAIL BEFORE DECEMBER COMES. --- IF YOU MAKE IT ALIVE.\n\n";
            std::cout << "What is your name?\n";//opening text
            std::string name;//players name
            int name1;
            bool pass1=0;//to tell whether to pass a loop or not
            std::cin >> name;//get players name
            family.setName(name, 0);
            std::cout << "What is the name of your first companion?\n";
            std::cin >> name;//set first friends name
            family.setName(name, 1);
            std::cout << "What is the name of your second companion?\n";
            std::cin >> name;//set second friends name
            family.setName(name, 2);
            std::cout << "What is the name of your third companion?\n";
            std::cin >> name;//sets third friends name
            family.setName(name, 3);
            std::cout << "What is the name of your final companion?\n";
            std::cin >> name;//sets fourth friends name
            family.setName(name, 4);
            std::cout << "\nYour journey is scheduled to start on March 28. You may change your starting date if you would like. Would you like to change your start day?\n1.Yes\n2.No\n";
            std::cin >> name1;//do they want to change dates?
            if (name1==1)//if they want to change names
            {
                std::cout << "In which month would you like to begin your journey?\n1.March\n2.April\n";
                std::cin >> name1;//choose starting month
                if (name1==1)//march
                {
                    while (pass1==0)//until they choose a vild date
                    {
                        std::cout << "On what day in March would you like to begin your journey?\n";
                        std::cin >> name1;//day of start
                        if (name1>0 && name1<32)//1-31
                        {
                            family.setDate(name1);//set date to correct date
                            pass1=1;//exit loop
                            std::cout << "Your journey will start on ";
                            family.getDateString();
                            std::cout << ".\n";
                        }
                        else
                        {
                            std::cout << "Invalid Imput\n";//whoops
                        }
                    }
                }
                else//april
                {
                    while (pass1==0)//until they choose a valid date
                    {
                        std::cout << "On what day in April would you like to begin your journey?\n";
                        std::cin >> name1;//starting day
                        if (name1>0 && name1<31)//1-30
                        {
                            family.setDate(name1+31);//set date in april
                            pass1=1;//exit loop
                            std::cout << "Your journey will start on ";
                            family.getDateString();
                            std::cout << ".\n";
                        }
                        else
                        {
                            std::cout << "Invalid Imput\n";//whoopsie
                        }
                    }
                }
            }
            else
            {
                std::cout << "Your journey will start on March 28.\n";//standard date
            }
            std::cout << "\nYou are in Independence, Missouri. There are " << family.getMilesToGo() << " miles to go until the arrival in Oregon City.\n\nYou had saved $1200 to spend for the trip, and you've just paid $200 for a wagon. You can spend the rest on other helpful materials.\n";
            family.changeMoney(-200);//buy wagon
            bool pass=0;//in order to exit loop
            while (pass==0)//until oxen are purchased
            {
            std::cout << "You must spend between $120 and $200 on oxen. There are 2 oxen in a yoke and each yoke costs $" << 40 << ". How many yokes would you like to purchase?\n";
                        int number7;//number of oxen they want to buy
                        std::cin >> number7;
                        family.changeMoney(-40*number7);//buy oxen
                        if (40*number7<100 || 40*number7>200)//is it a valid number?
                        {
                           std::cout << "Invalid number of yokes.\n\n";
                           family.changeMoney(40*number7);//refund money
                        }
                        else if (family.getMoney()<0)//if they dont have money
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(40*number7);//refund money
                        }
                        else
                        {
                            std::cout << "You paid $" << 40*number7 << " for " << 2*number7 << " oxen.\n";
                            family.changeOxen(2*number7);//give oxen to player
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                            pass=1;//exit loop
                        }
            }
        }
        void rest()
        {
            srand((unsigned)time(0)); //random clock
            int dig;
            dig = (rand()%3+1);//between 1 and 3 
            family.changeDate(dig);//change date
            std::cout << "You rested for " << dig << " days.\n";//text
            family.changeFood(dig*-1*family.getAlivePlayers());//eat 1 pound of food per day. (Game was too hard at 3)
        }
        int trail()//1 for fort, 2 for river, 3 for win, 0 for nothing
        {
            family.changeDate(14);//change date by 2 weeks
            family.changeFood(-14*family.getAlivePlayers());//eat 1 pound of food each day per alive player(3 was too hard)
            int dist=150-70*pow(1.2,-1*family.getOxen()+1);//distance is determined by number of oxen.
            family.changeMiles(dist);//travel
            if (family.getMiles()>landmarks.getFortDistance(fortint) && landmarks.getFortDistance(fortint)<landmarks.getRiverDistance(riverint))//if a fort was hit
            {
                std::cout << "You were prepared to travel " << dist << " miles, but you encountered " << landmarks.getFortName(fortint) << " after traveling " << landmarks.getFortDistance(fortint)+dist-family.getMiles() << " miles!\n";
                dist=landmarks.getFortDistance(fortint)+dist-family.getMiles();//reset distance traveled
                family.setMiles(landmarks.getFortDistance(fortint));//set miles to landmark distance
                fortint++;//fort encountered!
                return 1;//fort hit
            }
            else if (family.getMiles()>landmarks.getRiverDistance(riverint) && landmarks.getFortDistance(fortint)>landmarks.getRiverDistance(riverint))//if a river was hit
            {
                std::cout << "You were prepared to travel " << dist << " miles, but you encountered " << landmarks.getRiverName(riverint) << " after traveling " << landmarks.getRiverDistance(riverint)+dist-family.getMiles() << " miles!\n";
                dist=landmarks.getRiverDistance(riverint)-family.getMiles()+dist;//reset distance travelled
                family.setMiles(landmarks.getRiverDistance(riverint));//set miles to landmark distance
                riverint++;//river encountered!
                return 2;//river hit
            }
            else if (family.getMiles()>=2040)//if game was won
            {
                std::cout << "You finally made it to Oregon City!\n";//winning text
                return 3;//game won
            }
            else
            {
                std::cout << "You traveled " << dist << " miles.\n"; 
                return 0;//nothing happened
            }
        }
        void hunt()
        {
            bool encounter=0;//did an encounter occur?
            family.changeDate(1);//change date by 1
            int answer;//input by user
            srand((unsigned)time(0));//random clock
            int rand1;//rabbit chance
            rand1 = (rand()%2);//50% chance
            if (rand1==1)//if we encountered a rabbit
            {
                encounter=1;
                std::cout << "You encountered a rabbit! Do you want to hunt? (1) Yes, (2) No\n";
                std::cin >> answer;//if they want to hunt
                if (answer==1)
                {
                    if (family.getBullets()<2)//see if they have enough bullets
                    {
                        std::cout << "You do not have enough bullets to hunt.\n";
                    }
                    else//if they have enough bullets
                    {
                        std::cout << "You must solve a puzzle to hunt this animal.\n";
                        if (puzzle(4)==1)//if puzzle was solved
                        {
                            std::cout << "You successfully hunted the rabbit! You got 2 pounds of food and used 2 bullets.\n";
                            family.changeFood(2);//give 2 pounds of food
                            family.changeBullets(-2);//used 2 bullets
                        }
                        else
                        {
                            std::cout << "You failed to hunt the rabbit. You wasted 2 bullets in the process.\n";
                            family.changeBullets(-2);//used 2 bullets
                        }
                    }
                }
            }
            int rand2;//fox
            rand2 = (rand()%4);//25% chance
            if (rand2==1)//if fox was encountered
            {
                encounter=1;
                std::cout << "You encountered a fox! Do you want to hunt? (1) Yes, (2) No\n";
                std::cin >> answer;//if they want to hunt or not
                if (answer==1)
                {
                    if (family.getBullets()<3)//check if they have enough bullets to hunt
                    {
                        std::cout << "You do not have enough bullets to hunt.\n";
                    }
                    else//if they have enough bullets
                    {
                        std::cout << "You must solve a puzzle to hunt this animal.\n";
                        if (puzzle(5)==1)//if puzzle was solved
                        {
                            std::cout << "You successfully hunted the fox! You got 5 pounds of food and used 3 bullets.\n";
                            family.changeFood(5);//get 5 food
                            family.changeBullets(-3);//use 3 bullets
                        }
                        else
                        {
                            std::cout << "You failed to hunt the fox. You wasted 3 bullets in the process.\n";
                            family.changeBullets(-3);//use 3 bullets
                        }
                    }
                }
            }
            int rand3;//deer
            rand3 = (rand()%20);//15%chance
            if (rand3<3)//if encountered
            {
                encounter=1;
                std::cout << "You encountered a deer! Do you want to hunt? (1) Yes, (2) No\n";
                std::cin >> answer;//if they want to hunt or not
                if (answer==1)//if they do
                {
                    if (family.getBullets()<5)//if they dont have enough bullets
                    {
                        std::cout << "You do not have enough bullets to hunt.\n";
                    }
                    else//if they do
                    {
                        std::cout << "You must solve a puzzle to hunt this animal.\n";
                        if (puzzle(6)==1)//if solved
                        {
                            int rand4;
                            rand4 = (rand()%26+30);
                            std::cout << "You successfully hunted the deer! You got " << rand4 << " pounds of food and used 5 bullets.\n";
                            family.changeFood(rand4);//get food
                            family.changeBullets(-5);//use 5 bulets
                        }
                        else
                        {
                            std::cout << "You failed to hunt the deer You wasted 5 bullets in the process.\n";
                            family.changeBullets(-5);//use 5 bullets
                        }
                    }
                }
            }
            int rand5;
            rand5 = (rand()%100);
            if (rand5<7)//7% chance of getting bear
            {
                encounter=1;
                std::cout << "You encountered a bear! Do you want to hunt? (1) Yes, (2) No\n";
                std::cin >> answer;//if they want to hunt
                if (answer==1)//they do
                {
                    if (family.getBullets()<10)//do they have enough bullets?
                    {
                        std::cout << "You do not have enough bullets to hunt.\n";
                    }
                    else//if they do
                    {
                        std::cout << "You must solve a puzzle to hunt this animal.\n";
                        if (puzzle(7)==1)//puzzle solved
                        {
                            int rand6;
                            rand6 = (rand()%251+100);//100-350
                            std::cout << "You successfully hunted the bear! You got " << rand6 << " pounds of food and used 10 bullets.\n";
                            family.changeFood(rand6);//get food
                            family.changeBullets(-10);//use 10 bullets
                        }
                        else
                        {
                            std::cout << "You failed to hunt the bear You wasted 10 bullets in the process.\n";
                            family.changeBullets(-10);//use 10 bullets
                        }
                    }
                }
            }
            int rand7;//moose
            rand7 = (rand()%20);//5%chance
            if (rand7==4)//if encountered
            {
                encounter=1;
                std::cout << "You encountered a moose! Do you want to hunt? (1) Yes, (2) No\n";
                std::cin >> answer;//will they hunt?
                if (answer==1)
                {
                    if (family.getBullets()<12)//if they dont have enough bullets
                    {
                        std::cout << "You do not have enough bullets to hunt.\n";
                    }
                    else
                    {
                        std::cout << "You must solve a puzzle to hunt this animal.\n";
                        if (puzzle(8)==1)
                        {
                            int rand8;
                            rand8 = (rand()%301+300);//300-600
                            std::cout << "You successfully hunted the moose! You got " << rand8 << " pounds of food and used 12 bullets.\n";
                            family.changeFood(rand8);//get food
                            family.changeBullets(-12);//use 12 bullets
                        }
                        else
                        {
                            std::cout << "You failed to hunt the moose You wasted 12 bullets in the process.\n";
                            family.changeBullets(-12);//use 12 bullets
                        }
                    }
                }
            }
            if (encounter==0)//if no animal was encountered
            {
                std::cout << "You could not find any animals today.\n";
            }
            std::cout << "How well would you like to eat today?\n1.Poorly (2 pounds of food, per person)\n2.Moderately (3 pounds of food, per person)\n3.Well (5 pounds of food, per person)\n";
            std::cin >> answer;//a man's gotta eat
            if(answer==1)//eat poorly
            {
                family.changeFood(-2*family.getAlivePlayers());
            }
            else if(answer==2)//eat medium
            {
                family.changeFood(-3*family.getAlivePlayers());
            }
            else//eat well
            {
                family.changeFood(-5*family.getAlivePlayers());
            }
            if(family.getFood()>1000)//if they have too much food
            {
                family.setFood(1000);
                std::cout << "You could not carry all the food you got and had to leave some behind.";
            }
            std::cout << "You now have " << family.getFood() << " pounds of food.\n";
        }
        bool misfortune(int prob)//0=game over
        {
            if (prob<2)//sick 13.3% chance
            {
                srand((unsigned)time(0));//random clock
                int answer2;
                int dig2;
                bool pass2=0;//to exit the loop
                while (pass2==0)
                {
                    dig2 = (rand()%5);//pick random person
                    if (family.getStatus(dig2)>-1)//if that person is alive
                    {
                        pass2=1;//exit loop
                    }
                }
                int dig3;
                dig3 = (rand()%6+1);//random disease
                family.setStatus(dig3, dig2);//give disease
                std::cout << "\nOh no! " << family.getName(dig2) << " has " << family.getDiseaseName(dig2) << "!\n";
                if (family.getAidKits()>0)//if they have a med kit
                {
                    std::cout << "Would you like to use a medical aid kit? (1)Yes, (2)No\n";//use it?
                    std::cin >> answer2;//use it?
                    if (answer2==1)//if they used it
                    {
                        family.changeAidKits(-1);//use it
                        std::cout << "You have " << family.getAidKits() << " medical aid kits left.\n";
                        int dig4;
                        dig4 = (rand()%2);//50% chance of it helping
                        if (dig4==0)
                        {
                            std::cout << family.getName(dig2) << " was cured of " << family.getDiseaseName(dig2) << "!\n";
                            family.setStatus(dig3, 0);//make person healthy
                            return 1;
                        }
                        else
                        {
                            std::cout << "The medical aid kit didn't seem to help...\n";//whoopsie
                            sick=1;//man is sick
                            return 1;//game not over
                        }
                    }
                }
                sick=1;//someone's sick
                return 1;
            }
            else if (prob<4)//oxen dead
            {
                family.changeOxen(-1);//kill oxen
                std::cout << "\nOh no! One of your oxen has died! You have " << family.getOxen() << " oxen left.\n";
                if (family.getOxen()==0)//if it was the last oxen
                {
                    "You don't have any more oxen! You cannot continue your journey!\n";
                    return 0;//game over
                }
                return 1;//game not over
            }
            else if (prob<6)//wagon broke
            {
                std::cout << "\nOh no! Your wagon broke!\n";
                if (family.getWagonParts()==0)//if they don't have another part
                {
                    std::cout << "You don't have any parts to fix it! You cannot continue your journey!\n";
                    return 0;//game over
                }
                else
                {
                    std::cout << "You used a spare wagon part to fix the wagon. You have " << family.getWagonParts() << " spare wagon parts left.\n";
                    return 1;//game not over
                }
            }
            else//nothing happened
            {
                return 1;//game not over
            }
        }
        void raider()
        {
            srand((unsigned)time(0)); 
            double prob2;
            prob2 = (rand()%1000/1000.0000);//random number between 0 and 1
            if (((pow(family.getMiles()/100-4,2)+72)/(pow(family.getMiles()/100-4,2)+12)-1)/10>prob2)//do they attack?
            {
                std::cout << "\nRiders ahead! They look hostile!\n";//attack happened
                std::cout << "How do you want to respond?\n1.Run\n2.Attack\n3.Surrender\n";
                int answer3;//respond
                std::cin >> answer3;
                if (answer3==1)//run
                {
                    std::cout << "You safely escaped the raiders, but you had to leave behind 1 ox, 10 pounds of food and 1 wagon part!\n";
                    family.changeOxen(-1);//lose oxen
                    family.changeFood(-10);//lose food
                    if (family.getWagonParts()>0)//lose spare wagon part if they have one
                    {
                        family.changeWagonParts(-1);
                    }
                }
                else if(answer3==2)//fight
                {
                    if (family.getBullets()<50)//can they fight at all?
                    {
                        std::cout << "You do not have enough bullets to fight the raiders! They stole $" << family.getMoney()/4.00 << " from you!\n";
                        family.changeMoney(-family.getMoney()/4.00);//lose money
                    }
                    else
                    {
                        std::cout << "You must solve a puzzle to defeat the raiders.\n";
                        if (puzzle(10)==1 && family.getBullets()>49)//won battle
                        {
                            std::cout << "You defeated the raiders! You found 50 pounds of food and 50 bullets in their supplies!\n";
                            family.changeFood(50);//get food
                            family.changeBullets(50);//get bullets
                        }
                        else
                        {
                            std::cout << "You could not defeat the raiders. You used 50 bullets in the struggle and they stole $" << family.getMoney()/4.00 << " from you!\n";
                            family.changeBullets(-50);//lose bullets
                            family.changeMoney(-family.getMoney()/4.00);//lose money
                        }
                    }
                }
                else
                {
                    std::cout << "You surrendered to the raiders! They stole $" << family.getMoney()/4.00 << " from you!\n";
                    family.changeMoney(-family.getMoney()/4.00);//lose money
                }
            }
        }
        void fortNite(int fort)//price dependant on fort
        {
            int number;
            int choice;
            while (choice!=8)//until fort is exited
            {
                 std::cout << "\nYou have $" << family.getMoney() << ". What would you like to purchase?\n1.Oxen\n2.Food\n3.Bullets\n4.Wagon Parts\n5.Medical Aid Kits\n6.View Supplies\n7.More Info\n8.Exit Shop\n";
                 std::cin >> choice;//what choice did they make?
                 switch (choice)
                 {
                    case 1://oxen
                        std::cout << "There are 2 oxen in a yoke and each yoke costs $" << 40*(1+0.25*fort) << ". How many yokes would you like to purchase?\n";
                        std::cin >> number;//number of yokes
                        family.changeMoney(-40*(1+0.25*fort)*number);//charge money
                        if (family.getMoney()<0)//if they cant afford it
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(40*(1+0.25*fort)*number);//refund money
                        }
                        else if (number<=0)//if negative
                        {
                           std::cout << "Invalid number of yokes.\n\n";
                           family.changeMoney(number*40*(1+0.25*fort));//refund money
                        }
                        else
                        {
                            std::cout << "You paid $" << 40*(1+0.25*fort)*number << " for " << 2*number << " oxen.\n";
                            family.changeOxen(2*number);//give oxen
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                        }
                        break;
                    case 2://food
                        std::cout << "Your wagon can only hold 1000 pounds of food. Food costs " << 40*(1+0.25*fort) << " cents per pound. How many pounds would you like to buy?\n";
                        std::cin >> number;//amount of food
                        family.changeMoney(-number*.40*(1+0.25*fort));//charge money
                        family.changeFood(number);//give food
                        if (number<=0)//if negative
                        {
                           std::cout << "Invalid amount of food.\n\n";
                           family.changeMoney(number*.40*(1+0.25*fort));//refund money
                           family.changeFood(-number);//refund food
                        }
                        else if (family.getMoney()<0)//if insufficient funds
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(number*.40*(1+0.25*fort));//refund money
                            family.changeFood(-number);//take back food
                        }
                        else if (family.getFood()>1000)//if too much food was bought
                        {
                            std::cout << "You cannot carry that much food!\n";
                            family.changeMoney(number*.40*(1+0.25*fort));//refund money
                            family.changeFood(-number);//take back food
                        }
                        else//if valid purchase
                        {
                            std::cout << "You paid $" << number*.40*(1+0.25*fort) << " for " << number << " pounds of food.\n";
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                        }
                        break;
                    case 3://bullets
                        std::cout << "Bullets cost $" << 2*(1+0.25*fort) << " for a box of 20 bullets. How many boxes would you like to buy?\n";
                        std::cin >> number;
                        family.changeMoney(-2*(1+0.25*fort)*number);
                        if (number<=0)
                        {
                           std::cout << "Invalid number of bullets.\n\n";
                           family.changeMoney(2*(1+0.25*fort)*number);
                        }
                        else if (family.getMoney()<0)
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(2*(1+0.25*fort)*number);
                        }
                        else
                        {
                            std::cout << "You paid $" << 2*(1+0.25*fort)*number << " for " << 20*number << " bullets.\n";
                            family.changeBullets(20*number);
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                        }
                        break;
                    case 4://wagon parts
                        std::cout << "A spare wagon part costs $" << 20*(1+0.25*fort) << ". How many would you like to buy?\n";
                        std::cin >> number;
                        family.changeMoney(-20*(1+0.25*fort)*number);//charge money
                        if (number<=0)//if negative
                        {
                           std::cout << "Invalid number of wagon parts.\n\n";
                           family.changeMoney(20*(1+0.25*fort)*number);//refund
                        }
                        else if (family.getMoney()<0)//if not enough money
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(20*(1+0.25*fort)*number);//refund
                        }
                        else
                        {
                            std::cout << "You paid $" << 20*(1+0.25*fort)*number << " for " << number << " spare wagon parts.\n";
                            family.changeWagonParts(number);//give parts
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                        }
                        break;
                    case 5://med kits
                        std::cout << "A medical aid kit costs $" << 25*(1+0.25*fort) << ". How many would you like to buy?\n";
                        std::cin >> number;
                        family.changeMoney(-25*(1+0.25*fort)*number);//charge money
                        if (number<=0)//if negative
                        {
                           std::cout << "Invalid number of medical aid kits.\n\n";
                           family.changeMoney(25*(1+0.25*fort)*number);//refund
                        }
                        else if (family.getMoney()<0)//if insufficient funds
                        {
                            std::cout << "You do not have enough money to purchase that.\n";
                            family.changeMoney(25*(1+0.25*fort)*number);//refund
                        }
                        else
                        {
                            std::cout << "You paid $" << 25*(1+0.25*fort)*number << " for " << number << " medical aid kits.\n";
                            family.changeAidKits(number);//give med kit
                            std::cout << "You have $" << family.getMoney() << " remaining.\n";
                        }
                        break;
                    case 6://list stats
                        std::cout << "Currently taveling with ";//list alive members
                        {
                            bool first=1;//for correct grammar
                            for (int n=0;n<5;n++)
                            {
                
                                if (family.getStatus(n)>=0)
                                {
                                 if (first==0)
                                    {
                                        std::cout << ", ";//puts a comma before evefry name cept the first
                                    }
                                    std::cout << family.getName(n);
                                    first=0;
                                }
                            }
                        }
                        std::cout << "\nMoney: $" << family.getMoney();
                        std::cout << "\nOxen: " << family.getOxen();
                        std::cout << "\nFood: " << family.getFood() << " pounds";
                        std::cout << "\nBullets: " << family.getBullets();
                        std::cout << "\nSpare Wagon Parts: " << family.getWagonParts();
                        std::cout << "\nMedical Aid Kits: " << family.getAidKits() << "\n\n";
                            break;
                    case 7://more info
                        {
                            std::cout << "- OXEN. THE MORE YOU HAVE, THE FASTER YOU'LL GO. YOU WON'T BE ABLE TO CONTINUE THE JOURNEY WITHOUT OXEN.\n- FOOD. YOU NEED IT TO SURVIVE. IT IS RECOMMENDED TO BUY AS MUCH AS YOU CAN CARRY. YOU CAN ONLY CARRY 1000 POUNDS OF FOOD AT A TIME.\n- AMMUNITION. YOU WILL NEED BULLETS FOR ATTACKS BY BANDITS, AND FOR HUNTING FOOD\n- WAGON PARTS. IF YOUR WAGON BREAKS, YOU WILL NEED PARTS TO FIX IT. OTHERWISE, YOUR JOURNEY MIGHT COME TO AN ABRUPT END\n- MEDICAL AID KITS. THIS WILL HELP PARTY MEMBERS SURVIVE DISEASES IF THEY GET SICK ALONG THE WAY. IF A MEMBER GETS SICK, IT MIGHT BE BEST TO REST IN ORDER TO HELP THEM RECOVER.\n";
                            break;
                        }
                    case 8://exit
                        {
                            std::cout << "Take care!\n";
                            break;
                        }
                    default://invalid
                        std::cout << "Invalid imput.\n";
                }
            }
        }
        void riverNite(int depth)//actions dependant on depth
        {
            int answer4=2;//loop breaker
            while (answer4==2)//while resting
            {
                if (depth<4)//shallow river
                {
                    
                    std::cout << "\nThis river looks crosable!\nWhat will you do?\n1.Ford the River\n2.Rest\n";
                    std::cin >> answer4;
                    if (answer4==2)//rest
                    {
                        family.changeDate(1);// day passes
                        std::cout << "You rested for 1 day.\n";
                        family.changeFood(-1*family.getAlivePlayers());//eat
                    }
                    else//continue
                    {
                        std::cout << "You crossed the river!\n";
                    }
                }
                else//deep river
                {
                    std::cout << "\nThis river doesn't look crosable. You will need to buy a ferry ticket for $10 if you want to cross.\nWhat would you like to do?\n1.Buy a Ferry Ticket\n2.Rest\n";
                    std::cin >> answer4;
                    if (answer4==2)//if resting
                    {
                        family.changeDate(1);//1 day passes
                        std::cout << "You rested for 1 day.\n";
                        family.changeFood(-1*family.getAlivePlayers());//eat
                    }
                    else
                    {
                        if (family.getMoney()<10.00)//if they cant afford a ticket
                        {
                            std::cout << "You do not have enough money for a ticket! Instead, you sold 50 pounds of food to cover your ticket.\n";
                            family.changeFood(-50);//pay with food at a bad rate
                        }
                        else//if they can afford a ticket
                        {
                            std::cout << "You paid $10 for a ferry ticket!\n";
                            family.changeMoney(-10);//pay
                        }
                        std::cout << "You safely crossed the river!\n";
                    }
                }
            }
        }
        bool killTheSick(bool dead)//0-leader died, 1-leader lived
        {
            int m;//to find the sick
            for (int n=0;n<5;n++)
            {
                if (family.getStatus(n)>0)
                {
                    m=n;//m=sick
                }
            }
            if (dead==1)
            {
                family.killPlayer();//kill someone
                std::cout << "\n" << family.getName(m) << " has died of " << family.getDiseaseName(m) << "!\n";
                family.setStatus(-1,m);//set to dead
                if (m==0)//if leader
                {
                    return 0;
                }
            }
            else
            {
                std::cout << "\n" << family.getName(m) << " survived " << family.getDiseaseName(m) << "!\n";
            }
            sick=0;//not sick anymore
            return 1;
        }
};


#endif