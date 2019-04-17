#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class dirManip{
    public:

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
};