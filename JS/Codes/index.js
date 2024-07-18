function isPalindrome(num) {
    const strNum = num.toString();
    const stack = [];

    // Push all characters onto the stack
    for (let i = 0; i < strNum.length; i++) {
        stack.push(strNum[i]);
    }

    // Build the reversed string
    let reversedStrNum = '';
    while (stack.length > 0) {
        reversedStrNum += stack.pop();
    }

    return strNum === reversedStrNum;
}


function isArmstrong(num) {
    const strNum = num.toString();
    const length = strNum.length;
    let sum = 0;
    for (let digit of strNum) {
        sum += Math.pow(parseInt(digit), length);
    }
    return sum === num;
}

function CheckSubmit() {
    const inputNum = parseInt(document.getElementById('inputTxt').value);
    const selectedColor = document.querySelector('input[name="color"]:checked').value;
    const selectedFunction = document.querySelector('input[name="functionCall"]:checked').value;
    let result;

    if(inputNum === "") {
        window.alert("Give a value")
        return false; 
    }
    if (selectedFunction === "palindrome") {
        result = isPalindrome(inputNum) ? "Yes ! it is palindrome" : "no it is not palindrome";
    } else if (selectedFunction === "Armstrong") {
        result = isArmstrong(inputNum) ? "Yes ! it is Armstrong" : "no it is not Armstrong";
    }   
    const lblAnswer = document.getElementById("labelAnswer");
    lblAnswer.textContent = result;
    lblAnswer.style.color = selectedColor;

    return false;
}