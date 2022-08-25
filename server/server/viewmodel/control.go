package viewmodel

import "github.com/FelipeFTN/mySecurity/domain/entity"

type CommandInstance struct {
	entity.Instance
	Command string `json:"command"`
	Message string `json:"message"`
}
