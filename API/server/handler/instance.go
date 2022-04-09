package handler

import (
	"fmt"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func SaveInstance(c echo.Context) error {
	var vm viewmodel.Instance
	err := c.Bind(&vm)
	if err != nil {
		c.Logger().Errorf("JSON Bind Error: %s", err)
	}

	fmt.Print(vm.Name)

	return nil
}
