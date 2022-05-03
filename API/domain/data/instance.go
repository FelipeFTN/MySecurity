package data

import (
	"errors"

	"github.com/FelipeFTN/mySecurity/domain/entity"
)

// Save all instances into this array
var instancesData = []entity.Instance{}

func InstanceData(Name string, IP string, Token string) []entity.Instance {

	currentInstance := entity.Instance{
		Name:  Name,
		IP:    IP,
		Token: Token,
	}

	instancesData = append(instancesData, currentInstance)

	return instancesData
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
