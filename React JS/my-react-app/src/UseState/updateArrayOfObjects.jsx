import React from "react";
import { useState } from "react";
export default function CarCollection() {
  const [cars, setCars] = useState([]);
  const [carYear, setCarYear] = useState([new Date().getFullYear]);
  const [carMake, setCarMake] = useState("");
  const [carModel, setCarModel] = useState("");

  function handleAddCar() {
    const newCar = { year: carYear, make: carMake, model: carModel };
    setCars((c) => [...c, newCar]);
    setCarYear(new Date().getFullYear());
    setCarMake("");
    setCarModel("");
  }
  function handleRemoveCar(index) {
    setCars((c) => c.filter((_, i) => i !== index));
  }
  function handleYearChange(event) {
    setCarYear(event.target.value);
  }
  function handleMakeChange(event) {
    setCarMake(event.target.value);
  }
  function handleModelChange(event) {
    setCarModel(event.target.value);
  }
  return (
    <>
      <div>
        <h2>List of Car Objects</h2>
        <ul>
          {cars.map((car, index) => (
            <li key={index} onClick={() => handleRemoveCar(index)}>
              {car.year} {car.make} {car.model}
            </li>
          ))}
        </ul>
        <input
          placeholder="Enter Car Year"
          type="number"
          name="inptYear"
          id="inptYear"
          value={carYear}
          onChange={handleYearChange}
        />{" "}
        <input
          placeholder="Enter Car Make"
          type="text"
          name="inptMake"
          id="inptMake"
          value={carMake}
          onChange={handleMakeChange}
        />{" "}
        <input
          placeholder="Enter Car Model"
          type="text"
          name="inptModel"
          id="inptModel"
          value={carModel}
          onChange={handleModelChange}
        />{" "}
        <button onClick={handleAddCar}>Add Car</button>
      </div>
    </>
  );
}
