#ifndef MY_E
#define MY_E 
#include <string>

class Unique
{
    private:
    std::string s_p;
    
    public:

    Unique(std::string s): s_p(s)
    {
    }
     
    std::string get_s()
    {
        return s_p;
    }
};

class Short
{
    private:
    std::string s_p;
    
    public:

    Short(std::string s): s_p(s)
    {
    }
     
    std::string get_s()
    {
        return s_p;
    }
};

class Long
{
    private:
    std::string s_p;
    
    public:

    Long(std::string s): s_p(s)
    {
    }
     
    std::string get_s()
    {
        return s_p;
    }

};

class ShortPassword
{
    private:
    std::string s_p;
    
    public:

    ShortPassword(std::string s): s_p(s)
    {
    }
     
    std::string get_s()
    {
        return s_p;
    }
};

#endif
