package api

import (
	"bufio"
	"fmt"
	"net"
)

var c net.Conn

func InitSocket(HOST string, PORT int16) (net.Conn, error) {
	l, err := net.Listen("tcp", fmt.Sprintf("%s:%d", HOST, PORT))
	if err != nil {
		return c, err
	}
	defer l.Close()

	for {
		c, err = l.Accept()
		if err != nil {
			return c, err
		}
		return c, nil
	}
}

func SendToSocket(buffer string) (net.Conn, error) {
	c.Write([]byte(buffer))
	return c, nil
}

func ReceiveFromSocket() (string, error) {
	buffer, err := bufio.NewReader(c).ReadBytes('\n')
	if err != nil {
		c.Close()
		return "", err
	}

	return string(buffer[:len(buffer)-1]), nil
}
