package app

import (
	"bufio"
	"fmt"
	"net"
)

var c net.Conn

func InitSocket(HOST string, PORT int16) (net.Conn, error) {
	l, err := net.Listen("tcp", fmt.Sprintf("%s:%d", HOST, PORT))
	if err != nil {
		fmt.Println("[x] Error while initiating socket")
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

func SendToSocket(buffer string) error {
	_, err := c.Write([]byte(buffer))
	if err != nil {
		fmt.Println("[x] Error while receiving from socket")
		return err
	}
	return nil
}

func ReceiveFromSocket() (string, error) {
	buffer, err := bufio.NewReader(c).ReadBytes('\n')
	if err != nil {
		fmt.Println("[x] Error while receiving from socket")
		c.Close()
		return "", err
	}

	return string(buffer[:len(buffer)-1]), nil
}
