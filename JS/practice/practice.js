let x = {
    "name": "Urjit",
    "HasPassed": true,
    "age": 25,
    "gender": "male",
    "city": "Ahmedabad",
    "country": "India",
    "state": "Gujarat",
    "school": {
        "name": "SNVV",
        "Year": 1969,
        "color": "white"
    }
}
class MyClass {
    constructor(name) {
        console.log(name)
    }
}
function print(obj) {
    (Object.keys(obj)).forEach(element => {
        // console.log(element)
        const ul = document.createElement("ul");
        if (typeof obj[element] === "object") {
            print(obj[element])
        } else {
            const li = document.createElement("li");
            li.innerText = `${element} : ${obj[element]}`
            // document.getElementById("liForPrinting").innerText = obj[element]; 
            // console.log(obj[element])
            ul.appendChild(li);
        }
        document.getElementById("forPrinting").appendChild(ul);
    });
}
// document.getElementById("btnSubmit").onclick = function () {
//     print(x);
// }
a1 = new MyClass("Good Bye World");