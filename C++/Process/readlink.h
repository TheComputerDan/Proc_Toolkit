#include <unistd.h>
#include <limits.h>
#include <string>
using namespace std;

class readSym
{
    public: 
        string do_readlink(string const& path) {
        char buff[PATH_MAX];
        ssize_t len = ::readlink(path.c_str(), buff, sizeof(buff)-1);
        if (len != -1) {
            buff[len] = '\0';
            return string(buff);
        }
            /* handle error condition */
        }
};