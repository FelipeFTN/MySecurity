import * as constants from "./constants";
import axios from "axios";

export const GetAllInstances = async () => {
    try {
        const instances = await axios.get(constants.INSTANCE_URL);
        if (instances.status !== 200) { throw instances.statusText; }
        return instances.data;
    } catch(e) { console.log(e); }
}

export const ShutdownInstance = async(instanceToken) => {
    try {
        if (instanceToken === "") { throw Error("Invalid Token"); }
        const config = { headers: { instance_token: instanceToken } };
        const shutdown = await axios.post(constants.COMMAND_URL, {"command":"shutdown"}, config);
        if (shutdown.status !== 200) { throw shutdown.statusText; }
        return shutdown.data;
    } catch(e) { console.log(e); }
}

export const AuthenticateInstance = async (instanceToken) => {
    try {
        const auth = await axios.get(constants.AUTH_URL, {
            headers: {
                "Authorization": instanceToken
            }
        });
        if (auth.status !== 200) { throw auth.statusText; }
    } catch(e) { console.log(e); }
}