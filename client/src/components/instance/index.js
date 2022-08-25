import React from "react"
import { ShutdownInstance, AuthenticateInstance } from "../../handlers/instances";
import "./index.css";

export const Instance = ({ name, ip, token }) => {
    const handleClick = async (e) => {
        const target = e.target;
        if (target.className === "shutdown-button") { await ShutdownInstance(token); }
        if (target.className === "auth-button") { await AuthenticateInstance(token); }
    }
    return (
        <div className="instance">
            <h3>{name}</h3>
            <p>{ip}</p>
            <button className="auth-button" onClick={handleClick}>Authenticate</button>
            <button className="shutdown-button" onClick={handleClick}>Shutdown</button>
        </div>
    );
}

export const NoInstances = () => {
    return (
        <div className="no-instances">
            <h3>No Instances Found!</h3>
        </div>
    );
}

export const LoadingInstances = () => {
    return (
        <div className="loading-instances">
            <h3>Getting Instances...</h3>
        </div>
    );
}

export const NoActiveInstances = () => {
    return (
        <div>
            <h3>No Active Instances.</h3>
        </div>
    );
}