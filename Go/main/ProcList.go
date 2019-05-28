package main

import (
	"fmt"
	"sort"
	"io/ioutil"
	"strconv"
	"log"
)

func isNum(v string) bool {
	_, err := strconv.ParseFloat(v,64)
	return err == nil
}


func main() {
	count := 0

	pidStringSlice := make([]string,0)
	pidIntSlice := make([]int,0)

	proc := "/proc/"
	files, err := ioutil.ReadDir(proc)
	if err != nil {
		log.Fatal(err)
	}
	for _, pid := range files {
		if isNum(pid.Name()) == true {
			pidStringSlice = append(pidStringSlice, pid.Name())
			count += 1
			
		}
	}
	for _, pidString := range pidStringSlice {
		pidInt, err := strconv.Atoi(pidString)
		if err != nil {
			panic(err)
		}
		pidIntSlice = append(pidIntSlice,pidInt)
	}
sort.Ints(pidIntSlice)

fmt.Println("Contents:", pidIntSlice)

}




