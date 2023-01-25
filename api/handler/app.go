package handler

import (
	// #include "../../app/app.h"
	"C"
)
import "errors"

func App() error {

	err := C.app(C.CString("Hello World!"))
	if err != 0 {
		return errors.New("App")
	}

	return nil
}
