package handler

import "github.com/gin-gonic/gin"

func Server() {
	server := gin.Default()

	server.GET("/test", func(ctx *gin.Context) {
		ctx.JSON(200, gin.H{
			"message": "OK!",
		})
	})

	server.Run(":8080")

}
