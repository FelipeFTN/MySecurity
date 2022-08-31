package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/domain/data"
	"github.com/FelipeFTN/mySecurity/domain/service"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func Instance(c echo.Context) error {
	var vm viewmodel.Instance
	err := c.Bind(&vm)
	if err != nil {
		c.Logger().Errorf("JSON Bind Error: %s", err)
	}

	instance, err := service.Instance(vm)
	if err != nil {
		return c.String(http.StatusBadRequest, "Invalid Request Body")
	}

	return c.JSON(http.StatusOK, instance)
}

func GetInstances(c echo.Context) error {
	instances := data.GetInstanceData()

	return c.JSON(http.StatusOK, instances)
}
