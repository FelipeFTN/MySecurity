import { useEffect, useState } from "react";
import { Instance } from "./components/instance/";
import { GetAllInstances } from "./api";
import "./App.css";

function App() {
  const [instances, setInstances] = useState([]);

  useEffect(() => {
    const GetInstances = async () => {
      const allInstances: any = await GetAllInstances();
      if (allInstances !== undefined) { setInstances(allInstances); }
      console.log("Instances: ", allInstances); // Debugging Console.log - Remove!
    };
    GetInstances(); 
  }, []);

  return (
    <div className="App">
      <h1 className="mysecurity-header">MySecurity</h1>
      <div className="online-instances">
        {instances && instances.map((instance: any, index: number) => {
          return (<Instance name={instance.Name} ip={instance.IP} token={instance.Token} key={index} />);
        })}
      </div>
      <br />
    </div>
  );
}

export default App;
