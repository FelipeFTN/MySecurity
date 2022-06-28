package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
	"github.com/labstack/echo"
)

func ControlInstance(c echo.Context) error {
	var vm viewmodel.CommandInstance
	err := c.Bind(&vm)
	if err != nil {
		return c.String(http.StatusBadRequest, "Invalid Request Body")
	}

	return c.String(http.StatusOK, "")
}
