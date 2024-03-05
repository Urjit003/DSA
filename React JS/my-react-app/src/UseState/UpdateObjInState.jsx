import React, { useState } from "react";

export default function UpdateObjectInState() {
    const [car, setCar] = useState({
        year: 2023,
        make: "KIA",
        model: "Seltos",
    });
    function handleYearChange(e) {
        setCar(car => ({ ...car,year: e.target.value }));
    }
    function handleMakeChange(e) {
        setCar(car => ({...car, make: e.target.value }));
    }
    function handleModelChange(e) {
        setCar({ ...car,model: e.target.value });
    }
    return <>
        <div>
            <p>Your Favourite car is {car.make} {car.model} from {car.year}</p>
            <input type="number" name="inputYear" onChange={handleYearChange} value={car.year} /><br />
            <input type="text" name="inputMake" onChange={handleMakeChange} value={car.make} /><br />
            <input type="text" name="inputModel" onChange={handleModelChange} value={car.model} /><br />
        </div>
    </>;
}
