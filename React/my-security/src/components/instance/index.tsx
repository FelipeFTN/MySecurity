import React from "react"
import { GetAllInstances } from "../../api";
import "./index.css";

interface Props {
    name: string;
    ip: string;
}


export const Instance: React.FC<Props> = ({ name, ip }) => {
    const handleClick = async (e: any) => {
        console.log(await GetAllInstances());

    }

    return (
        <div className="instance">
            <h3>{name}</h3>
            <p>{ip}</p>
            <button id="shutdown" onClick={handleClick}>Shutdown</button>
        </div>
    )
}