const textbox = document.getElementById("txtBox")
const toFaranheit = document.getElementById("toFaranheit");
const toCelcius = document.getElementById("toCelcius");
let temp;
const result = document.getElementById("result");
function convert() {
    if (toFaranheit.checked) {
        temp = Number(textbox.value);
        temp = temp * 9 / 5 + 32;
        result.textContent = temp.toFixed(1) + "°F";
    } else if (toCelcius.checked) {
        temp = Number(textbox.value);
        temp = (temp - 32) * (5 / 9);
        result.textContent = temp.toFixed(1) + "°C";
    } else {
        result.textContent = "Select a unit"
    }
    return false;
}