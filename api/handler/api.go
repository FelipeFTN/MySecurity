package handler

import (
	"github.com/gin-gonic/gin"
)

func Server(PORT string) {
	server := gin.Default()

	server.GET("/", func(ctx *gin.Context) {
		ctx.JSON(200, gin.H{
			"message": "OK!",
		})
	})

	server.Run(PORT)
}
