package service

import (
	"errors"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func Instance(vm viewmodel.Instance) error {

	if vm.Name == "" || vm.IP == "" {
		return errors.New("invalid request body")
	}

	return nil
}
