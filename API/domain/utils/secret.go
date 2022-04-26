package utils

import (
	"encoding/base64"
	"strings"

	"github.com/FelipeFTN/mySecurity/server/viewmodel"
)

func SecretDecode(secret string) (viewmodel.Instance, error) {
	instanceInfo, err := base64.StdEncoding.DecodeString(secret)
	if err != nil {
		return viewmodel.Instance{}, err
	}

	instanceData := strings.Split(string(instanceInfo), " ")

	instanceParseData := viewmodel.Instance{
		Name:   instanceData[0],
		IP:     instanceData[1],
		Secret: secret,
	}

	return instanceParseData, nil
}
