package viewmodel

import "github.com/FelipeFTN/mySecurity/domain/entity"

type Instance struct {
	Name string `json:"instance_name"`
	IP   string `json:"instance_ip"`
}

type ControlInstance struct {
	Name    string `json:"instance_name"`
	IP      string `json:"instance_ip"`
	Command uint8  `json:"instance_command"`
}

func ParseInstance(instance entity.Instance) Instance {
	instanceResponse := Instance{
		Name: instance.Name,
		IP:   instance.IP,
	}

	return instanceResponse
}
