#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private: 
        std::string name;//name of player
        int status;//-1=dead, 0=healty, positive numbers are diseases
    public:
        Player()
        {
            name="";//blank name
            status=0;//healthy
        }
        Player(std::string input)
        {
            name=input;//name
            status=0;//healthy
        }
        void setName(std::string input)
        {
            name=input;
        }
        std::string getName()
        {
            return name;
        }
        void setStatus(int input)
        {
            status=input;
        }
        int getStatus()
        {
            return status;
        }
        std::string getDiseaseName()
        {
            if (status==1)
            {
                return "typhoid";
            }
            if (status==2)
            {
                return "cholera";
            }
            if (status==3)
            {
                return "diarrhea";
            }
            if (status==4)
            {
                return "the measles";
            }
            if (status==5)
            {
                return "dysentery";
            }
            if (status==6)
            {
                return "fever";
            }
        }
        
};


#endif