#ifndef PARTY_H
#define PARTY_H

class Party
{
    private: 
        double money;//tracks money
        Player member[5];//party of 5 members
        int aliveplayers;//number of alive players
        int miles;//miles traveled
        int milestogo;//miles to go
        int food;//amount of food
        int oxen;//number of oxen
        int bullets;//number of bullets
        int wagonparts;//number of spare wagon parts
        int medicalaidkits;//number of medical kits
        int date;//number representing the date
    public:
        Party()
        {
            money=1200.00;//starting money
            aliveplayers=5;//5 alive players
            miles=0;//starting miles
            milestogo=2040;//starting miles to go
            food=0;//no food to start
            oxen=0;//no oxen to start
            bullets=0;//no bullets to start
            wagonparts=0;//no wagon parts to start
            medicalaidkits=0;//no med kits to start
            date=28;//starting date march 28
        }
        
        void setName(std::string inputname, int inputmember)
        {
            member[inputmember].setName(inputname);
        }
        std::string getName(int input)
        {
            return member[input].getName();
        }
        void setStatus(int inputstatus, int inputmember)
        {
            member[inputmember].setStatus(inputstatus);
        }
        int getStatus(int input)
        {
            return member[input].getStatus();
        }
        std::string getDiseaseName(int input)
        {
            return member[input].getDiseaseName();
        }
        void killPlayer()
        {
            aliveplayers--;
        }
        int getAlivePlayers()
        {
            return aliveplayers;
        }
        void changeMoney(double input)
        {
            money+=input;
        }
        double getMoney()
        {
            return money;
        }
        void changeMiles(int input)
        {
            miles+=input;
            milestogo-=input;
        }
        void setMiles(int imput)
        {
            miles=imput;
            milestogo=2040-imput;
        }
        int getMiles()
        {
            return miles;
        }
        int getMilesToGo()
        {
            return milestogo;
        }
        void changeFood(int input)
        {
            food+=input;
        }
        void setFood(int imput)
        {
            food=1000;
        }
        int getFood()
        {
            return food;
        }
        void changeBullets(int input)
        {
            bullets+=input;
        }
        int getBullets()
        {
            return bullets;
        }
        void changeOxen(int input)
        {
            oxen+=input;
        }
        int getOxen()
        {
            return oxen;
        }
        void changeWagonParts(int input)
        {
            wagonparts+=input;
        }
        int getWagonParts()
        {
            return wagonparts;
        }
        void changeAidKits(int imput)
        {
            medicalaidkits+=imput;
        }
        int getAidKits()
        {
            return medicalaidkits;
        }
        void changeDate(int input)
        {
            date+=input;
        }
        void setDate(int imput)
        {
            date=imput;
        }
        int getDateInt()
        {
            return date;
        }
        void getDateString()//prints the month and day
        {
            if (date<32)
            {
                std::cout << "March " << date;
            }
            else if(date<62)
            {
                std::cout << "April " << date-31;
            }
            else if(date<93)
            {
                std::cout << "May " << date-61;
            }
            else if(date<123)
            {
                std::cout << "June " << date-92;
            }
            else if(date<154)
            {
                std::cout << "July " << date-122;
            }
            else if(date<185)
            {
                std::cout << "August " << date-153;
            }
            else if(date<215)
            {
                std::cout << "September " << date-184;
            }
            else if(date<246)
            {
                std::cout << "October " << date-214;
            }
            else if(date<276)
            {
                std::cout << "November " << date-245;
            }
            else if(date<307)
            {
                std::cout << "December " << date-275;
            }
        }
        
        
};


#endif