const app = Vue.createApp({
	data() {
		return {
			InstanceName: "MyInstance",
			InstanceIP: "127.0.0.1",
			InstanceOutput: "Hello World",
			InstanceOptions: ["Shutdown", "Disable Security"],
			InstanceOptionsValue: ["shutdown", "disable"],
		};
	},
	methods: {
		command() {
			console.log("Command Instance!");
		},
	},
});

app.mount('#app')
