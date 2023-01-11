package main

import "github.com/FelipeFTN/MySecurity/handler"

func main() {
	var IP string = "127.0.0.1"
	var PORT int16 = 8079

	// Initialize application
	handler.InitApp(IP, PORT)

	// Initialize web server at port 80
	handler.Server(":80")
}
