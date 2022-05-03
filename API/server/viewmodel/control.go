package viewmodel

import "github.com/FelipeFTN/mySecurity/domain/entity"

type ControlInstance struct {
	entity.Instance
	Command string `json:"command"`
	Message string `json:"message"`
}
