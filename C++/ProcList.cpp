#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <regex>

using namespace std;

bool is_number(const string& s);
int getDir(string dir, vector<string> &files);
//void Keyword(ifstream & stream, string token);
void Keyword(ifstream & stream, string token1,string token2,string token3,string token4,string token5,string token6,string token7);
string getOsName(); //Modify this do do more rigorous OS checks 

int main()
{
    if(getOsName() == "Linux" || getOsName() == "Unix")
    {
    string dir = string("/proc/");
    
    ifstream statusStream;
    string ProcStatusPath;
    string FileContents; 
    vector<string> files = vector<string>();

    getDir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) 
        {

         ProcStatusPath = "/proc/"+files[i]+"/status";
          //cout << endl << ProcStatusPath << endl;
          statusStream.open(ProcStatusPath);
          cout << endl;
          Keyword(statusStream,"Name","Umask","State","Pid","PPid","Uid","Gid"); // Find a more efficient way to handle this function

          //cout << statusStream.rdbuf() << endl;

            statusStream.close();    
        }
    }
    else
    {
        cout << getOsName() << " is currently not supported." << endl;
    }
        
    return 0;
}

int getDir (string dir, vector<string> &files) //https://www.linuxquestions.org/questions/programming-9/c-list-files-in-directory-379323/
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if(is_number(dirp->d_name) == true) // This was added to allow only numeric directories to be stored to the files variable
            files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

bool is_number(const string& s) //https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


void Keyword(ifstream & stream, string token1,string token2,string token3,string token4,string token5,string token6,string token7)//https://stackoverflow.com/questions/22800879/how-to-search-for-a-word-in-a-text-file-and-if-found-print-out-the-entire-line
{

    /* This function needs some serious overhauling to make it run in the desired manner.
    It would be most adventageous to be able to handle each searched term seperately 
    Such that I can use OS agnostic formatters to ensure whichever OS that has /proc on it 
    can still have a readable format.
    Additionally the current state of the program is grabbing all input with Pid in it instead of only Pid
    Can this be fixed with regex?
    */

    string line;    
    array<string,7> tokenList;

    for(int i=0; i < tokenList.size();i++ )
    {
        while (getline(stream, line))
        {
            
            if (line.find(token1) != string::npos || line.find(token2)!= string::npos || line.find(token3)!= string::npos || 
            line.find(token4)!= string::npos ||line.find(token5)!= string::npos || line.find(token6)!= string::npos ||
            line.find(token7)!= string::npos) //how can I get this to work based on each token 
            {
            cout << line << endl;
            }
            else
            {
            //cout << tokenList[i] << " not found" << endl;
            }
        }
        
    }
    
}
/*
void Keyword(ifstream & stream, string token)//https://stackoverflow.com/questions/22800879/how-to-search-for-a-word-in-a-text-file-and-if-found-print-out-the-entire-line
{
    string line;
    while (getline(stream, line))
    {
        if (line.find(token) != string::npos)
        {
            cout << line << endl;
        }
        else
        {
            //cout << token << " not found" << endl;
        }
        
    }
    
}
*/
std::string getOsName() //https://stackoverflow.com/questions/15580179/how-do-i-find-the-name-of-an-operating-system
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