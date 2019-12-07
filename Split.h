#ifndef SPLIT_H
#define SPLIT_H

int split(std::string stri, char cha, std::string my_array[], int num)
{
    std::string str=stri + cha;
    int n=0;
    int m=0;
    int l=0;
    while (str[n]==cha)
    {
        n++;
    }
    while (n<str.length())
    {
        if (str[n]==cha && l!=0)
        {
            my_array[m]=str.substr(n-l,l);
            l=0;
            m++;
            while (str[n+1]==cha)
            {
                n++;
            }
        }
        else
        {
            l++;
        }
    n++;
    }
    if (str=="")
    {
        return 0;
    }
    else if(m>=num)
    {
        return -1;
    }
    else
    {
        return m;
    }
}


#endif