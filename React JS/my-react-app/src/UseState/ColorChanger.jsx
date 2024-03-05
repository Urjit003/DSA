import React, { useState } from "react";
export default function ColorChanger() {
        const [color,setColor] = useState("#000000")
        function handleColorChange(event) {
            setColor(event.target.value);
        }
    return(
        <>
            <div className="color-picker-container">
                <h1>Color Picker</h1>
                <div className="color-display" style={{background:color}}>
                    <p>Selected Color : {color}</p>
                </div>
                <label>Select a color</label>
                <input type="color" name="" id="" onChange={handleColorChange}
                        value={color} />
            </div>
        </>
    );
}