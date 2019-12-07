#ifndef MILESTONES_H
#define MILESTONES_H
#include "Split.h"//good old split function

class Milestones
{
    private:
        std::string FortTitles[7];//array of fort names
        int FortMiles[7];//array of fort distances
        std::string RiverTitles[5];//array of river names
        int RiverMiles[5];//array of river distances
        int Depth[5];//array of river depths
        std::ifstream forts;//open fort document
        std::ifstream rivers;//open river document
        std::string line="";
    public:
        Milestones()
        {
            FortTitles[6]="You Shouldn't See This Error";//error handler
            FortMiles[6]=6969;
            RiverTitles[4]="I Hope You Don't See This Error";//error handler
            RiverMiles[4]=42069;
            Depth[4]=69;
            forts.open("fort-milestones.txt");//open document
            std::string array1[2];//make 3 string arrays
            std::string array2[2];
            std::string array3[2];
            for (int n=0;n<6;n++)//fill array with fort names and distance
            {
                getline(forts, line);
                FortTitles[n]=line;//fort names
                getline(forts, line);
                split(line, 'm', array1, 2);
                FortMiles[n]=stoi(array1[0]);//mort mile length
            }
            rivers.open("river-milestones.txt");//open document
            for (int m=0;m<4;m++)//fill river arrays with depths distances and names
            {
                getline(rivers, line);
                RiverTitles[m]=line;//river names
                getline(rivers, line);
                split(line, 'm', array1, 2);
                RiverMiles[m]=stoi(array1[0]);//river distances
                split(array1[1], ' ', array2, 2);
                split(array2[1], 'f', array3, 2);
                Depth[m]=stoi(array3[0]);//river depths
            }
        }
        std::string getFortName(int i)
        {
            return FortTitles[i];
        }
        int getFortDistance(int i)
        {
            return FortMiles[i];
        }
        std::string getRiverName(int i)
        {
            return RiverTitles[i];
        }
        int getRiverDistance(int i)
        {
            return RiverMiles[i];
        }
        int getRiverDepth(int i)
        {
            return Depth[i];
        }
};


#endif