package main

import (
	"fmt"

	"github.com/FelipeFTN/MySecurity/api/handler"
)

func main() {
	var err error

	// Initialize application
	err = handler.App()
	if err != nil {
		fmt.Println(err)
		return
	}
}
