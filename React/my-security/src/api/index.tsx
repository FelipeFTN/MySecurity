import axios from "axios";


export const GetAllInstances = async (): Promise<any> => {
    try {
        const instances = await axios.get("http://localhost:8000/instance")
        if (instances.status !== 200) { throw instances.statusText }
        return instances.data;
    } catch(e) { console.log(e); return e; }
}

export const ShutdownInstance = async (instanceToken: string): Promise<any> => {
    try {
        if (instanceToken === "") { throw Error("Invalid Token"); }
        const config = { headers:{ instance_token: instanceToken } };
        const shutdown = await axios.post("http://localhost:8000/instance/command", {"command":"shutdown"}, config);
        if (shutdown.status !== 200) { throw shutdown.statusText; }
        return shutdown.data;
    } catch(e) { console.log(e); return e; }
}

export const AuthenticateInstance = async (instanceToken: string): Promise<any> => {
    try {
        const auth = await axios.get("http://localhost:8000/auth", {
            headers: {
                "instance_token": instanceToken
            }
        })
        if (auth.status !== 200) { throw auth.statusText; }
    } catch(e) { console.log(e); return e;}
}