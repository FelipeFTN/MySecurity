package handler

import (
	"fmt"
	"io/ioutil"
	"net"
	"net/http"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

const (
	appHost string = "127.0.0.1"
	appPort string = "9000"
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
	service := fmt.Sprintf("%s:%s", appHost, appPort)

	conn, err := net.Dial("tcp", service)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Can't connect to TCP Address")
	}

	result, err := ioutil.ReadAll(conn)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Can't Read TCP Bytes")
	}

	fmt.Print(result)

	return c.String(http.StatusOK, "Nice!")
}
