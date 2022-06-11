import React from "react"
import "./index.css";

interface Props {
    name: string;
    ip: string;
}

export const Instance: React.FC<Props> = ({ name, ip }) => {
    return (
        <div className="instance">
            <h3>{name}</h3>
            <p>{ip}</p>
            <button>Shutdown</button>
        </div>
    )
}