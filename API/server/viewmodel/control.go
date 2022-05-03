package viewmodel

type ControlInstance struct {
	Name    string `json:"instance_name"`
	IP      string `json:"instance_ip"`
	Token   string `json:"instance_token"`
	Command string `json:"instance_command"`
}
