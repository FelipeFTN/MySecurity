package handler

import (
	"net/http"

	"github.com/FelipeFTN/mySecurity/domain/service"
	"github.com/labstack/echo"
)

func Auth(c echo.Context) error {

	instanceToken := c.Request().Header.Values("Authorization")
	if len(instanceToken) == 0 {
		return c.String(http.StatusUnauthorized, "Error invalid token")
	}

	err := service.Authenticate(instanceToken[0])
	if err != nil {
		return c.String(http.StatusAlreadyReported, err.Error())
	}

	return c.String(http.StatusOK, "Authenticated")

}
