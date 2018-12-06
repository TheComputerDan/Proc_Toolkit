# Proc_Toolkit

## A bash based toolkit for parsing /proc for system information

**Notice: This tool is still in its early stages and has some missing or not completely functional components that will be added in future pushes.**

#### Purpose

- The main purpose of this toolkit is to create close to bash core functionality scripts that parse data from `/proc` which is already consulted by many commands like `netstat` and `ps`. 
- This toolkit also serves its purpose to be used educationally as those who wish to learn more about `/proc` and/or the inner workings of Linux will be able to look at the script and tear it down to better understand `/proc`. 
- The original inspiration for this script was to create a tool that, in the event of an active red team where system tools like `netstat` , `ps`, etc. have  either been removed or tampered with to falsify information, this tool would use bash core functionality to parse through `/proc` and act as a tool to verify the results the user is being fed. The assumption here being that what is left is there so a red team can run their own scripts. 

### Tools included

| Tool  |            Purpose            |
| :---: | :---------------------------: |
| ps.sh |   A ps replacement script.    |
| ns.sh | A netstat replacement script. |













##### Disclaimer: This tool should only be used for data collection on systems you own or have been given permission to. This tool can be used for education or system verification purpose