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
    string searchStrings[7] = {"Name","Umask","State","Pid","PPid","Uid","Gid"}; // Strings from the status file for parsing
    

    if(checkOS.getOsName() == "Linux" || checkOS.getOsName() == "Unix") // Check OS before execution
    {
    
    ifstream statusStream;
    string proc = "/proc/";
    string ProcStatusPath;
    string ProcfdPath;
    string FileContents; 
    string dir = string("/proc/");
    vector<string> files = vector<string>();
    bool is_line_one = true; // Used in formating the first line for readability 

    dirm.getDir(dir,files); // Populates a vector with the numeric directories that exist at execution time

    for (unsigned int i = 0;i < files.size();i++) // For however many numeric directories there are do the following...
        {
        
         ProcStatusPath = proc+files[i]+"/status"; // Take append /proc/ with the number stored in that element of the vecor and then /status to form /proc/###/status
         ProcfdPath = proc+files[i]+"/fd"; // Does the above but with /fd 

        cout << endl;
        for (unsigned int e = 0; e < 7; e++) 
            {
                if (e == 0) // First itteration of loop, used for formatting
                {
                is_line_one = true; 
                statusStream.open(ProcStatusPath);
                parse.Keyword(statusStream,searchStrings[e],is_line_one); // Takes the passed in string and retrieves it, formats for first line
                statusStream.close();
                is_line_one = false;   
                }
                else if (e >= 0) // Every following itteration of the loop
                {
                statusStream.open(ProcStatusPath);
                parse.Keyword(statusStream,searchStrings[e],is_line_one); // Takes the passed in string and retrieves it
                statusStream.close();
                statusStream.clear();
                    if (e == 6) // This will be used eventually for reading symbolic links and matching sockets with the inode in /proc/net/{ tcp, tcp6, udp, or udp6 }
                        {
                            //cout << parse.fd_search(ProcfdPath);
                            //statusStream.open(ProcfdPath);
                            //parse.fd_search(statusStream);
                            //statusStream.close();
                            //statusStream.clear();
                        }
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
