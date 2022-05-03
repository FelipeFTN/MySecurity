package utils

import (
	"encoding/base64"
	"strings"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func SecretDecode(token string) (viewmodel.Instance, error) {
	instanceInfo, err := base64.StdEncoding.DecodeString(token)
	if err != nil {
		return viewmodel.Instance{}, err
	}

	instanceData := strings.Split(string(instanceInfo), " ")

	instanceParseData := viewmodel.Instance{
		Name:  instanceData[0],
		IP:    instanceData[1],
		Token: token,
	}

	return instanceParseData, nil
}
