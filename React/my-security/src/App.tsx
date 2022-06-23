import React from "react";
import { Instance } from "./components/instance/";
import { GetAllInstances } from "./api";
import "./App.css";

async function App() {
  let instances: undefined | any;
  const GetInstances = async () => {
    instances = (await GetAllInstances()).data;
    console.log(instances)
  };
  await GetInstances();
  return (
    <div className="App">
      <h1 className="mysecurity-header">MySecurity</h1>
      <div className="online-instances">
        {(instances).map((instance: any, index: number) => {
          return (<Instance name={instance.Name} ip={instance.IP} key={index} />);
        })}
      </div>
      <br />
      <div className="offline-instances">
        <Instance name="FelipeFTN" ip="127.0.0.1" />
      </div>
    </div>
  );
}

export default App;
