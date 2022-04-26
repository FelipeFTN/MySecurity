package viewmodel

import "github.com/FelipeFTN/mySecurity/domain/entity"

type Instance struct {
	Name   string `json:"instance_name"`
	IP     string `json:"instance_ip"`
	Secret string `json:"instance_secret"`
}

func ParseInstance(instance entity.Instance) Instance {
	instanceResponse := Instance{
		Name:   instance.Name,
		IP:     instance.IP,
		Secret: instance.Secret,
	}

	return instanceResponse
}
