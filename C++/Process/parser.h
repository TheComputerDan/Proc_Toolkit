#include <iostream>
#include <fstream>
#include <string>
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
                                cout << line << endl;           // Find a better way to handle this
                                printf("\033[0m");
                                
                            }
                            else if (is_first == false)
                            {
                                cout << '\t'/2 << line << endl;
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
};