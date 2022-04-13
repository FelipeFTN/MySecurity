package handler

import (
	"fmt"
	"net"
	"net/http"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

const (
	APP_HOST = "127.0.0.1"
	APP_PORT = "9000"
	APP_TYPE = "tcp"
)

func ControlInstance(c echo.Context) error {
	var vm viewmodel.ControlInstance
	err := c.Bind(&vm)
	if err != nil {
		return c.String(http.StatusBadRequest, "Invalid Request Body")
	}

	return c.String(http.StatusOK, "")
}

func GetInstanceCommands(c echo.Context) error {
	service := fmt.Sprintf("%s:%s", APP_HOST, APP_PORT)

	conn, err := net.Dial(APP_TYPE, service)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Can't Connect to TCP Address")
	}

	// _, err = conn.Write([]byte("Enviar Mensagem"))
	// if err != nil {
	// 	return c.String(http.StatusInternalServerError, "Write to server failed")
	// }

	responseByte := make([]byte, 1024)

	response, err := conn.Read(responseByte)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Can't Read Server Response")
	}

	fmt.Printf("Receive %d bytes in response: %#v", response, responseByte[:response])

	return c.String(http.StatusOK, string(responseByte[:response]))
}
