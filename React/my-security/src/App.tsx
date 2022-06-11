import React from "react";
import { Instance } from "./components/instance/";
import "./App.css";

const App: React.FC = () => {
  return (
    <div className="App">
      <h1 className="mysecurity-header">MySecurity</h1>
      <div className="online-instances">
        <Instance name="FelipeFTN" ip="127.0.0.1" />
      </div>
      <br />
      <div className="offline-instances">
        <Instance name="FelipeFTN" ip="127.0.0.1" />
      </div>
    </div>
  );
}

export default App;
