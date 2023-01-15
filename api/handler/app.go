package handler

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/services/app"
)

func App(HOST string, PORT int16) error {
	var err error

	// Init socket
	_, err = app.InitSocket(HOST, PORT)
	if err != nil {
		return err
	}

	err = app.SendToSocket("handshake")
	if err != nil {
		return err
	}

	message, err := app.ReceiveFromSocket()
	if err != nil {
		return err
	}

	fmt.Println(message)

	return nil
}
