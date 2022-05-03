package service

import (
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	"net/http"
	"time"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func ControlInstance(vm viewmodel.ControlInstance) (string, error) {

	host := fmt.Sprintf("http://%s:5000", vm.IP)
	client := &http.Client{
		Timeout: time.Second * 10,
	}

	switch vm.Command {
	case "shutdown":
		err := shutdown(client, host, vm.Secret)
		if err != nil {
			return "", err
		}
	case "logout":
		err := logout(client, host, vm.Secret)
		if err != nil {
			return "", err
		}
	case "message":
		err := message(client, host, vm.Secret, "Testing")
		if err != nil {
			return "", err
		}
	default:
		return "No command was found!", nil
	}

	return "Done!", nil
}

func shutdown(client *http.Client, host string, secret string) error {
	req, err := http.NewRequest("GET", host+"/shutdown", nil)
	if err != nil {
		return err
	}
	req.Header.Add("instance_secret", secret)
	res, err := client.Do(req)
	if err != nil {
		return err
	}
	defer res.Body.Close()

	return nil
}

func logout(client *http.Client, host string, secret string) error {
	req, err := http.NewRequest("GET", host+"/logout", nil)
	if err != nil {
		return err
	}
	req.Header.Add("instance_secret", secret)
	res, err := client.Do(req)
	if err != nil {
		return err
	}
	defer res.Body.Close()

	return nil
}

func message(client *http.Client, host string, secret string, message string) error {
	jsonData := make(map[string]string)

	jsonData["message"] = message

	data, _ := json.Marshal(jsonData)

	req, err := http.NewRequest("POST", host+"/message", bytes.NewBuffer(data))
	if err != nil {
		return err
	}

	req.Header.Add("instance_secret", secret)
	req.Header.Set("Content-Type", "application/json")

	res, err := client.Do(req)
	if err != nil || res.StatusCode != 200 {
		return errors.New(res.Status)
	}
	defer res.Body.Close()

	return nil
}
