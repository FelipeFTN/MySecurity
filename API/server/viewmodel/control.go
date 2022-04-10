package viewmodel

type ControlInstance struct {
	Name    string `json:"instance_name"`
	IP      string `json:"instance_ip"`
	Command uint8  `json:"instance_command"`
}
