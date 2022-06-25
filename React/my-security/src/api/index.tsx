import axios from "axios";

export const GetAllInstances = async (): Promise<any> => {
    try {
        const instances = await axios.get("http://localhost:8000/instance")
        if (instances.status != 200) { throw instances.statusText }
        return instances.data
    } catch(e) { return e }
}