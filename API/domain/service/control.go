package service

import (
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
		req, err := http.NewRequest("GET", host+"/shutdown", nil)
		if err != nil {
			return "", err
		}
		req.Header.Add("instance_secret", vm.Secret)
		res, err := client.Do(req)
		if err != nil {
			return "", err
		}
		defer res.Body.Close()
	case "logout":
		req, err := http.NewRequest("GET", host+"/logout", nil)
		if err != nil {
			return "", err
		}
		req.Header.Add("instance_secret", vm.Secret)
		res, err := client.Do(req)
		if err != nil {
			return "", err
		}
		defer res.Body.Close()
	default:
		return "No command was found!", nil
	}
	return "Done!", nil
}
