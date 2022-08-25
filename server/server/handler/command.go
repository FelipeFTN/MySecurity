package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/domain/data"
	"github.com/FelipeFTN/mySecurity/domain/service"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func CommandInstance(c echo.Context) error {
	var vm viewmodel.CommandInstance
	err := c.Bind(&vm)
	if err != nil {
		return c.String(http.StatusBadRequest, "Invalid Request Body")
	}

	instanceHeader := c.Request().Header.Values("instance_token")

	instance, err := data.GetInstanceByToken(instanceHeader[0])
	if err != nil {
		return c.String(http.StatusInternalServerError, "Could not find the instance Token")
	}

	instanceParseData := viewmodel.CommandInstance{
		Instance: instance,
		Command:  vm.Command,
		Message:  vm.Message,
	}

	instanceResponse, err := service.CommandInstance(instanceParseData)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Service error during APP Comunication")
	}

	return c.String(http.StatusOK, instanceResponse)
}
