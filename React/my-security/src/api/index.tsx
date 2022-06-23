import axios from "axios";

export const GetAllInstances = async (): Promise<any> => {
    try {
        const instances = await axios.get("http://localhost:8000/instance")
        return instances
    } catch(e) {
        return e
    }
}