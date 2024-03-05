import React, { useState, useEffect } from "react";

export default function Counter() {
    const [number, setNumber] = useState(0);
    const [trend, setTrend] = useState(null);


    
    const Increment = () => {
        // USE OF UPDATER FUNCTION
        setNumber(n => n + 3)
        // setNumber(number + 1)
     
        setTrend("increased")
    }
    const Decrement = () => {
        setNumber(n => n - 3)
        setTrend("decreased")
    }
    const Reset = () => {
        setNumber(0)
        setTrend("set to 0")

    }
    return (
        <div className="bTnContainer">
            <p>{number}</p>
            <button onClick={Increment}>Increment</button>
            <button onClick={Decrement}>Decrement</button>
            <button onClick={Reset}>Reset</button>
            <p>The count was <b>{trend}</b> </p>
        </div>
    );
}
