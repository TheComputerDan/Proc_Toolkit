//https://stackoverflow.com/questions/14668850/list-directory-in-go
//https://stackoverflow.com/questions/45686163/how-to-write-isnumeric-function-in-golang/45686455

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"strconv"
)

func isNumber(s string) bool {
	_, err := strconv.ParseFloat(s, 64)
	return err == nil
}

func main() { 
	var ProcNum[8]string
	
	files, err := ioutil.ReadDir("/proc/")
	if err != nil {
		log.Fatal(err)
	}
	for _, f := range files {
		fmt.Println(f.Name())
		
		//fmt.Println(isNumber(f.Name()),"\n")
		
	}
}