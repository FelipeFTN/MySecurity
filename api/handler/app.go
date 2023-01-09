package handler

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/services/api"
)

func App() {
	api.InitSocket("127.0.0.1", 8079)

	message, err := api.ReceiveFromSocket()
	if err != nil {
		fmt.Println("error while receiving from socket")
		return
	}

	fmt.Printf("< %s\n", message)
}
