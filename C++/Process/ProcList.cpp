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
    string proc = "/proc/";
    string ProcStatusPath;
    string ProcfdPath;
    string FileContents; 
    string dir = string("/proc/");
    vector<string> files = vector<string>();
    bool is_line_one = true;

    dirm.getDir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) 
        {
        
         ProcStatusPath = proc+files[i]+"/status";
         ProcfdPath = proc+files[i]+"fd";

        cout << endl;
        for (unsigned int e = 0; e < 7; e++) 
            {
                if (e == 0)
                {
                is_line_one = true; 
                statusStream.open(ProcStatusPath);
                parse.Keyword(statusStream,searchStrings[e],is_line_one);
                statusStream.close();
                is_line_one = false;   
                }
                else if (e >= 0)
                {
                statusStream.open(ProcStatusPath);
                parse.Keyword(statusStream,searchStrings[e],is_line_one);
                statusStream.close();
                statusStream.clear();
                
                statusStream.open(ProcfdPath);
                parse.fd_search(statusStream);
                statusStream.close();
                statusStream.clear();
                }
                else 
                {
                    cout << "Loop Error: Likely source is e" << endl; // Replace with better error handling
                }    
            }
        }
        cout << endl; // Final Endline for readability
    }
    else
    {
        cout << checkOS.getOsName() << " is currently not supported." << endl;
    }
        
    return 0;
}
