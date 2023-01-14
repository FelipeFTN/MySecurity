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
	err = handler.InitApp(IP, PORT)
	if err != nil {
		fmt.Println("error")
		return
	}

	err = handler.SendToApp("Selfless")
	if err != nil {
		fmt.Println("error")
		return
	}

	message, err := handler.ReceiveFromApp()
	if err != nil {
		fmt.Println("error")
		return
	}

	fmt.Println(message)

	// Initialize web server at port 80
	// handler.Server(":80")
}
