package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/domain/service"
	"github.com/FelipeFTN/mySecurity/domain/utils"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func CommandInstance(c echo.Context) error {
	var vm viewmodel.ControlInstance
	err := c.Bind(&vm)
	if err != nil {
		return c.String(http.StatusBadRequest, "Invalid Request Body")
	}

	return c.String(http.StatusOK, "")
}

func ControlInstance(c echo.Context) error {
	command := c.QueryParam("command")
	instanceHeader := c.Request().Header.Values("instance_token")

	instanceData, err := utils.SecretDecode(instanceHeader[0])
	if err != nil {
		return c.String(http.StatusInternalServerError, "Error while Decoding Instance Token")
	}

	instanceParseData := viewmodel.ControlInstance{
		Name:    instanceData.Name,
		IP:      instanceData.IP,
		Secret:  instanceData.Secret,
		Command: command,
	}

	instanceResponse, err := service.ControlInstance(instanceParseData)
	if err != nil {
		return c.String(http.StatusInternalServerError, "Service error during APP Comunication")
	}

	return c.String(http.StatusOK, instanceResponse)
}
