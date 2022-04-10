package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/domain/data"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func Instance(c echo.Context) error {
	var vm viewmodel.Instance
	err := c.Bind(&vm)
	if err != nil {
		c.Logger().Errorf("JSON Bind Error: %s", err)
	}

	instances := data.InstanceData(vm.Name, vm.IP)

	return c.JSON(http.StatusOK, instances)
}
