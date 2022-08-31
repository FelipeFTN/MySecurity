package data

import (
	"errors"

	"github.com/FelipeFTN/mySecurity/domain/entity"
)

// Save all instances into this array
var instancesData = []entity.Instance{}

func InsertInstance(instance entity.Instance) entity.Instance {

	currentInstance := entity.Instance{
		Name:  instance.Name,
		IP:    instance.IP,
		Token: instance.Token,
		Auth:  instance.Auth,
	}

	for i, v := range instancesData {
		if v.Token == instance.Token {
			instancesData[i].Auth = instance.Auth
			return currentInstance
		}
	}

	instancesData = append(instancesData, currentInstance)

	return currentInstance
}

func GetInstanceData() []entity.Instance {

	return instancesData
}

func GetInstanceByToken(token string) (entity.Instance, error) {
	for i, v := range instancesData {
		if v.Token == token {
			return instancesData[i], nil
		}
	}

	return entity.Instance{}, errors.New("instance not found")
}
