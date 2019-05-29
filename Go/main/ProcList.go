package main

import (
	"fmt"
	"strings"
	"sort"
	"io/ioutil"
	"strconv"
	"log"
	//"os"
)

func isNum(v string) bool {
	_, err := strconv.ParseFloat(v,64)
	return err == nil
}
func joinStr(strs ...string) string {
	var ret string
	for _, str := range strs{
		ret += str 
	}
	return ret
}

func parseStatus(str []string) { //Parse based on line, split string used to acccess via elements
	
	fmt.Println(str[0]) // Name
	fmt.Println(str[2]) //State
	fmt.Println(str[5]) //Pid
	fmt.Println(str[6]) //PPid
	fmt.Println(str[8]) //Uid
	fmt.Println(str[9]) //Gid
	fmt.Println("") //Newline

}

func main() {

	pidStringSlice := make([]string,0)
	pidIntSlice := make([]int,0)
	pSlice := make([]string,0)
	strParse := make([]string,0)

	proc := "/proc/"
	files, err := ioutil.ReadDir(proc)
	if err != nil {
		log.Fatal(err)
	}
	for _, pid := range files { //Attempt to break down into a function 
		if isNum(pid.Name()) == true {
			pidStringSlice = append(pidStringSlice, pid.Name())
			
		}
	}
	for _, pidString := range pidStringSlice { //Attempt to break down into a function 
		pidInt, err := strconv.Atoi(pidString)
		if err != nil {
			panic(err)
		}
		pidIntSlice = append(pidIntSlice,pidInt)
	}
	
	sort.Ints(pidIntSlice) // Sorts the slice so the Pids come out in order 
	
for _, p := range pidIntSlice { 
		fullPath := joinStr(proc, strconv.Itoa(p),"/status")
		pSlice = append(pSlice,joinStr(proc, strconv.Itoa(p),"/status"))
			
		b, err := ioutil.ReadFile(fullPath)
		if err != nil {
				fmt.Println(err)
			}
			str := string(b)
			strParse = strings.Split(str,"\n")
			
			parseStatus(strParse) //Used to parse the status file to get info
		
	} // Clean this one up and remove the reading from here

}




