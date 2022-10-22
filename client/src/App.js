import { Instance, NoInstances, LoadingInstances, NoActiveInstances } from "./components/instance/index";
import { GetAllInstances } from "./handlers/instances";
import { useEffect, useState } from "react";
import "./App.css";

function App() {
  const [instances, setInstances] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const GetInstances = async () => {
      const allInstances = await GetAllInstances();
      setLoading(false);
      if (allInstances === undefined) { setInstances(null); return; }
      setInstances(allInstances);
      console.log("Instances: ", allInstances); // Debugging Console.log - Remove!
    };
    GetInstances(); 
  }, []);

  return (
    <div className="App">
      <h1 className="mysecurity-header">MySecurity</h1>
      <div className="online-instances">
        { loading && <LoadingInstances/> }
        { (!loading && instances.length === 0) && <NoActiveInstances/> }
        {
          instances ? instances.map((instance, index) => {
            return (<Instance name={instance.Name} ip={instance.IP} token={instance.Token} key={index} />);
          }) : <NoInstances/>
        }
      </div>
      <br />
    </div>
  );
}

export default App;
