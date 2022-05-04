package service

import (
	"errors"
	"time"

	"github.com/FelipeFTN/mySecurity/domain/data"
	"github.com/FelipeFTN/mySecurity/domain/entity"
	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func Authenticate(instanceToken string) error {

	instance, err := data.GetInstanceByToken(instanceToken)
	if err != nil {
		return err
	}

	if instance.Auth {
		return errors.New("instance already authenticated")
	}

	instance.Auth = true
	_ = data.InsertInstance(instance)

	return nil
}

func Authentication(instanceToken string) error {

	var instance entity.Instance
	var err error
	futureTime := time.Now().Add(time.Second * 120) // 2 minutes to authenticate at /auth

	for {
		currentTime := time.Now()

		instance, err = data.GetInstanceByToken(instanceToken)
		if err != nil {
			return err
		}

		timerCountdown := currentTime.After(futureTime)
		if timerCountdown && !instance.Auth {
			break
		}
	}
	shutdownInstance := viewmodel.ControlInstance{
		Instance: instance,
		Command:  "shutdown",
		Message:  "",
	}
	ControlInstance(shutdownInstance)
	return nil
}
