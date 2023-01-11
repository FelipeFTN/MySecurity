package handler

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/services/api"
)

func InitApp(HOST string, PORT int16) error {
	var err error

	// Init socket
	_, err = api.InitSocket(HOST, PORT)

	// First handshake
	_, err = api.SendToSocket("handshake")
	if err != nil {
		fmt.Println("error while sending to socket")
		return err
	}

	// Receive confirmation handshake
	_, err = api.ReceiveFromSocket()
	if err != nil {
		fmt.Println("error while receiving from socket")
		return err
	}

	return nil
}

func SentToApp(message string) error {
	var err error

	// Send message to application
	_, err = api.SendToSocket(message)
	if err != nil {
		return err
	}

	return nil
}
