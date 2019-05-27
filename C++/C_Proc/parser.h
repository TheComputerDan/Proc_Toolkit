#include <iostream>
#include <fstream>
#include <string>
#include "readlink.h"
using namespace std;

class parser {
    public:
        void Keyword(ifstream & stream, string token, bool is_first) //https://stackoverflow.com/questions/22800879/how-to-search-for-a-word-in-a-text-file-and-if-found-print-out-the-entire-line
            {
                string line;
                bool first_enter;
                while (getline(stream, line))
                    {
                        if (line.find(token) != string::npos)
                        {
                            if (is_first == true)
                            {
                                printf("\033[1;36m");
                                cout << line << endl;           // Will be replaced with cleaner formatting 
                                printf("\033[0m");
                                
                            }
                            else if (is_first == false)
                            {
                                cout << line << endl; 
                            }
                            else 
                            {
                                cout << "Invalid bool value!\nExiting" << endl;
                            }
                        }
                        else
                        {
                            //cout << token << " not found" << endl;

                            // This is constantly triggered when uncommnented even though the others are still found, find out why and what to use in place of this.
                        }
        
                    }
    
            }
        string fd_search(string linkSym) // search through fd for symlinks to associate with ports
        {
            //readSym readl;
            //socket = readl.do_readlink(linkSym);
            //return socket;
            //cout << "function currently unavailable" << endl;
        }   
    private:
        //string socket;           
};