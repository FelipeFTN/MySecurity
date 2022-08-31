package service

import (
	"errors"

	"github.com/FelipeFTN/mySecurity/domain/data"
	"github.com/FelipeFTN/mySecurity/domain/entity"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func Instance(vm viewmodel.Instance) (entity.Instance, error) {

	if vm.Name == "" || vm.IP == "" || vm.Token == "" {
		return entity.Instance{}, errors.New("invalid request body")
	}

	instances := data.GetInstanceData()

	for _, i := range instances {
		if i.Name == vm.Name || i.IP == vm.IP {
			instance, err := data.GetInstanceByToken(vm.Token)
			if err != nil {
				return entity.Instance{}, errors.New("internal error")
			}
			return instance, nil
		}
	}

	instanceData := entity.Instance{
		Name:  vm.Name,
		IP:    vm.IP,
		Token: vm.Token,
		Auth:  vm.Auth,
	}
	newInstance := data.InsertInstance(instanceData)

	go Authentication(instanceData.Token)

	return newInstance, nil
}
