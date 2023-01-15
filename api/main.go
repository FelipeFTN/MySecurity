package main

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/handler"
)

func main() {
	var IP string = "127.0.0.1"
	var PORT int16 = 8079
	var err error

	// Initialize application
	err = handler.App(IP, PORT)
	if err != nil {
		fmt.Println(err)
		return
	}

	// Initialize web server at port 80
	// handler.Server(":80")
}
