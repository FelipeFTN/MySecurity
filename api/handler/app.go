package handler

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/services/app"
)

func InitApp(HOST string, PORT int16) error {
	var err error

	// Init socket
	_, err = app.InitSocket(HOST, PORT)
	if err != nil {
		fmt.Println("error while initiating to socket")
		return err
	}

	return nil
}

func SendToApp(message string) error {
	var err error

	// Send message to application
	_, err = app.SendToSocket(message)
	if err != nil {
		return err
	}

	return nil
}

func ReceiveFromApp() (string, error) {
	var err error

	// Receive message from application
	message, err := app.ReceiveFromSocket()
	if err != nil {
		return "", nil
	}

	return message, nil
}
