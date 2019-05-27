// checkOs.h
#include <string>
using namespace std;
class osCheck {
    public:
        string getOsName() //https://stackoverflow.com/questions/15580179/how-do-i-find-the-name-of-an-operating-system
        {
            #ifdef _WIN32
            return "Windows 32-bit";
            #elif _WIN64
            return "Windows 64-bit";
            #elif __unix || __unix__
            return "Unix";
            #elif __APPLE__ || __MACH__
            return "Mac OSX";
            #elif __linux__
            return "Linux";
            #elif __FreeBSD__
            return "FreeBSD";
            #else
            return "Other";
            #endif
        }   
};