import React, { useState } from "react";

export default function FoodList() {
  const [foods, setFood] = useState(["apple", "banana", "kiwi","ORANGE","grapes"]);
  function handleAddFood() {
    const newFood = document.getElementById("inptFood").value;
    document.getElementById("inptFood").value = "";

    setFood((f) => [...f, newFood]);
  }
  function handleRemoveFood(index) {
    setFood(foods.filter((_, i) => i !== index));
  }
  return (
    <>
      <div className="food-item-container">
        <h2>List of Foods</h2>
        <ul>
          {foods.map((food, index) => (
            <li key={index} onClick={() => handleRemoveFood(index)}>
              {food}
            </li>
          ))}
        </ul>
        <input
          type="text"
          name="inptFood"
          id="inptFood"
          placeholder="Enter food name"
        />
        <button onClick={handleAddFood}>Add Item</button>
      </div>
    </>
  );
}
``