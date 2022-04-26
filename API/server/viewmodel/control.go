package viewmodel

type ControlInstance struct {
	Name    string `json:"instance_name"`
	IP      string `json:"instance_ip"`
	Secret  string `json:"instance_secret"`
	Command string `json:"instance_command"`
}
