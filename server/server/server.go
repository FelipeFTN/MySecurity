package server

import (
	"io/ioutil"

	"github.com/FelipeFTN/mySecurity/server/handler"
	"github.com/labstack/echo"
	"github.com/labstack/echo/middleware"
)

func Routes(e *echo.Echo) {

	e.GET("/auth", handler.Auth)
	e.GET("/instance", handler.GetInstances)
	e.POST("/instance", handler.Instance)
	e.POST("/instance/command", handler.CommandInstance)
	e.POST("/instance/control", handler.ControlInstance)
}

func Server() {

	e := echo.New()
	e.Logger.SetOutput(ioutil.Discard)
	// Middleware
	e.Use(middleware.Recover())
	// CORS
	e.Use(middleware.CORSWithConfig(middleware.CORSConfig{
		AllowOrigins: []string{"*"},
		AllowMethods: []string{echo.GET, echo.HEAD, echo.PUT, echo.PATCH, echo.POST, echo.DELETE},
	}))
	// Root Route ==> handler
	Routes(e)
	// Run Server
	e.Start(":8000")
}
