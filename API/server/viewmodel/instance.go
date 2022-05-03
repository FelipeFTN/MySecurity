package viewmodel

import "github.com/FelipeFTN/mySecurity/domain/entity"

type Instance struct {
	Name  string `json:"instance_name"`
	IP    string `json:"instance_ip"`
	Token string `json:"instance_token"`
}

func ParseInstance(instance entity.Instance) Instance {
	instanceResponse := Instance{
		Name:  instance.Name,
		IP:    instance.IP,
		Token: instance.Token,
	}

	return instanceResponse
}
