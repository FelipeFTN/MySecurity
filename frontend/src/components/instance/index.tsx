import React from "react"
import { ShutdownInstance, AuthenticateInstance } from "../../api";
import "./index.css";

interface Props {
    name: string;
    ip: string;
    token: string;
}

export const Instance: React.FC<Props> = ({ name, ip, token }) => {
    const handleClick = async (e: any) => {
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
    )
}