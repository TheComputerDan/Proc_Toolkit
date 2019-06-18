# Proc_Toolkit

## A toolkit for parsing /proc for system information

**Notice: This tool is still in its early stages and has some missing or not completely functional components that will be added in future pushes.**

#### Purpose

- The original purpose of this toolkit was to create close to bash core functionality scripts that parse data from `/proc` which is already consulted by many commands like `netstat` and `ps`. 
    - This toolkit has since evolved into a multi-language platform for learning how to interface with `/proc`
    - The goal here for me personally is to broaden my ability to work with Linux via both compiled and interpreted languages.
- This toolkit also serves its purpose to be used educationally as those who wish to learn more about `/proc` and/or the inner workings of Linux will be able to look at the script and tear it down to better understand `/proc`. 
- The original inspiration for this script was to create a tool that, in the event of an active red team where system tools like `netstat`, `ps`, etc. have  either been removed or tampered with to falsify information, this tool would use bash core functionality to parse through `/proc` and act as a tool to verify the results the user is being fed. The assumption here is that what is left is there so a red team can run their own scripts. 

### File Breakdown

| Tool  |            Purpose            |
| :---: | :---------------------------: |
| ps.sh |   A ps replacement script.    |
| ns.sh | A netstat replacement script. |
| ProcList.cpp | A proc parser written in C++ |
| ProcList.go | A proc parser written in Go |

### Development Notes
- The compiled versions of the toolkit are being developed to wrap `ps` and `netstat`/`ss` like functionality into one executable program. This is in place to remove the need for too many different tools and allow for easy information gathering.
- The Go `netstat`/`ss` like functionality will be implemented first as it will be taking less time due to the `os` library having inbuilt functionality for reading symbolic links. The symbolic links in `/proc/PID/fd/` can correlate to an open socket which can be matched with an `inode` in `/proc/net/tcp`, `/proc/net/tcp6`, `/proc/net/udp`, or `/proc/net/udp6` that will then give us the port number and other information that is of use in replicating `netstat`/`ss` functionalities












##### Disclaimer: This tool should only be used for the collection of data on systems you own or those of which you have been granted permission to administer. This tool can be used for educational or systems verification purposes. 