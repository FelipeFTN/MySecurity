package data

import "github.com/FelipeFTN/mySecurity/domain/entity"

// Save all instances into this array
var instancesData = []entity.Instance{}

func InstanceData(Name string, IP string, Secret string) []entity.Instance {

	currentInstance := entity.Instance{
		Name:   Name,
		IP:     IP,
		Secret: Secret,
	}

	instancesData = append(instancesData, currentInstance)

	return instancesData
}

func GetInstanceData() []entity.Instance {

	return instancesData
}
