package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	addressList := []string{"127.0.0.1", "0.0.0.0", "999.999.999.999", "192.168.zero.91", "212.3.4", "8.8.8.8.8"}

	for _, v := range addressList {
		if validIPv4(v) {
			fmt.Printf("The address %s is valid", v)
		} else {
			fmt.Printf("The address %s is not a valid IP (v4) address", v)
		}
		fmt.Println()
	}
}

func validIPv4(ip string) bool {
	ip = strings.Trim(ip, " ")

	re, _ := regexp.Compile(`^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$`)
	if re.MatchString(ip) {
		return true
	}
	return false
}
