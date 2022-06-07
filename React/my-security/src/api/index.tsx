const axios: any = require('axios');

export async function GetAllInstances(): Promise<void> {
    await axios.get("127.0.0.1:8000/instance")
    .then((response: any) => {
        console.log(response)
    })
    .catch((err: any) => {
        console.log(err)
    })
}