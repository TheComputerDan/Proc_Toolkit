#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class parser {
    public:
        void Keyword(ifstream & stream, string token) //https://stackoverflow.com/questions/22800879/how-to-search-for-a-word-in-a-text-file-and-if-found-print-out-the-entire-line
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
};