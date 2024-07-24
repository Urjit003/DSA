function validate () {
    const num1 = Number ( document.getElementById("inptNum1").value);
    const num2 = Number (document.getElementById("inptNum2").value);
    const ans = document.getElementById("answer");

    ans.textContent += ` ${(num1+num2).toPrecision(3)}`;

}