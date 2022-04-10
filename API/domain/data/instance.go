package data

import "github.com/FelipeFTN/mySecurity/domain/entity"

var instancesData = []entity.Instance{}

func InstanceData(Name string, IP string) []entity.Instance {

	currentInstance := entity.Instance{
		Name: Name,
		IP:   IP,
	}

	instancesData = append(instancesData, currentInstance)

	return instancesData
}

func GetInstanceData() []entity.Instance {

	return instancesData
}
