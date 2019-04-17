#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <regex>
#include "checkOs.h"
#include "parser.h"
#include "dirManip.h"

using namespace std;

int main()
{
    osCheck checkOS;
    parser parse;
    dirManip dirm;
    string searchStrings[7] = {"Name","Umask","State","Pid","PPid","Uid","Gid"};
    

    if(checkOS.getOsName() == "Linux" || checkOS.getOsName() == "Unix")
    {
    
    ifstream statusStream;
    string ProcStatusPath;
    string FileContents; 
    string dir = string("/proc/");
    vector<string> files = vector<string>();

    dirm.getDir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) 
        {

         ProcStatusPath = "/proc/"+files[i]+"/status";

        cout << endl;
        for (unsigned int e = 0; e < 7; e++) 
            {
                statusStream.open(ProcStatusPath);
                parse.Keyword(statusStream,searchStrings[e]);
                statusStream.close();    
            }
   
        }
    }
    else
    {
        cout << checkOS.getOsName() << " is currently not supported." << endl;
    }
        
    return 0;
}
