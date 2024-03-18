// Hello world prog

// -> console.log("Hello world");

//Add to vars

// const name = "Urjit";
//  console.log("Hello " + name);

// INNER HTML 

// var name = "Urjit";
// var age = 20 ;
// document.getElementById("p1").innerHTML = "Hello " + name ;
// document.getElementById("p2").innerHTML =  name + "'s age is " + age ;  

// getelementById() will set the value of the element in the document
// to the value of the element in the HTML document.
// In this case, the value of the element in the HTML document
// is "Hello Urjit" and the value of the element in the document
// is "Hello Urjit's age is 20"
// The value of the element in the HTML document is not changed.
// The value of the element in the document is not changed.

// let v = 1 + 2 * (3 - 1);

// console.log(v);

// USER INPUT 
// Using the prompt
// $name = window.prompt("Enter your name: ");
// console.log($name);

// HTML way 
// let username;

// document.getElementById("MyButton").onclick= function () {
//     username = document.getElementById("myName").value;
//     // console.log(username);
//     document.getElementById("MyLabel").innerHTML = "Hello " + username ;
// }

// TYPE CONVERSION
// let age = window.prompt("Enter your age: ");
// console.log(typeof age);
// age = Number(age);
// console.log(age);
// console.log(typeof age);

// ex 2
// let x , y , z ;
// x = Number("20");
// y = String(20);
// z = Boolean();
// console.log(x ,typeof x);
// console.log(y ,typeof y);
// console.log(z ,typeof z);

// const
// give whole value of pi

// const pi = 3.14159 ;
// let radius ;
// let circumference;

// radius = window.prompt("radius of circle : ");
// radius = Number(radius)

// circumference = 2 * pi * radius ;
// console.log(circumference);

// counter program that increments the counter and decrements the counter

// var counter = 0;
// document.getElementById("MyLabelForCounter").innerHTML = counter;
// document.getElementById("BtnIncrement").onclick = function () {

//     counter ++ ;
//     document.getElementById("MyLabelForCounter").innerHTML = counter;
// }
// document.getElementById("BtnDecrement").onclick = function () {
//     counter -- ;
//     document.getElementById("MyLabelForCounter").innerHTML = counter;
// }
// document.getElementById("BtnReset").onclick = function () {
//     counter = 0;
//     document.getElementById("MyLabelForCounter").innerHTML = counter;
// }

// random number generator

// let x;
// // console.log(x);

// document.getElementById("BtnForRoll").onclick = function () {
//     x=Math.floor(Math.random() * 6) + 1 ;
//     document.getElementById("lblForAnything").innerHTML = x ;
// }

// useful string methods

// let username = window.prompt("Username");
// // console.log(username.length);
// username = String(username);
// document.getElementById("lblForAnything").innerHTML = username ; 
// username = username.trim();
// console.log(username);

//  checked property

    // const myCheckbox = document.getElementById("CbxSub");
    // const visaBtn = document.getElementById("VisBtn");
    // const masterBtn = document.getElementById("MasterBtn");
    // const BtnSubmit = document.getElementById("BtnSubmit");
    // const PayPalBtn = document.getElementById("PayPalBtn");
    // const SubResult = document.getElementById("lblForSub");
    // const myCheckboxClear = document.getElementById("BtnClear");
    // const CardResult = document.getElementById("lblForCard");

    // myCheckboxClear.onclick = function () {
    //     SubResult.textContent = ``;
    //     CardResult.textContent = ``;
    //     PayPalBtn.disabled = false;
    //     masterBtn.disabled = false;
    //     visaBtn.disabled = false;

    // }
    // BtnSubmit.onclick = function () {
    //     if (myCheckbox.checked) {
    //         SubResult.textContent = `You are subbed`;
    //     } else if (!myCheckbox.checked) {
    //         SubResult.textContent = `You are not subbed`;
    //     }

    //     if (visaBtn.checked) {
    //         CardResult.textContent = `You are paying with visa`;
    //         PayPalBtn.disabled = true;
    //         masterBtn.disabled = true;
    //     } else if (masterBtn.checked) {
    //         CardResult.textContent = `You are paying with mastercard`;
    //         PayPalBtn.disabled = true;
    //         visaBtn.disabled = true;
    //     }else {
    //         CardResult.textContent = `You are paying with paypal`;
    //         masterBtn.disabled = true;
    //         visaBtn.disabled = true;
    //     }
    // }

// ternery operation example
    // var a = window.prompt("Enter for a");
    // var b = window.prompt("Enter for b");
    // var c = window.prompt("Enter for c");

    // find largest from three
    // if( a> b && a > c ) {
    //     var largest = a;
    // } else if( b> a && b > c ) {
    //     var largest = b;
    // } else {
    //     var largest = c;
    // }
    // // var largest = (a > b && a > c) ? a : (b > a && b > c) ? b : c;
    // var largest = (a > b && a >c ) ? a : (b > a && b > c) ? b : c;
    // console.log(largest);

// method chaining

    // var username= window.prompt("Enter your name :") 
    // username = username.trim().charAt(0).toUpperCase() + username.trim().slice(1).toLowerCase();

    // console.log(username);
    
// example of array

    // var arr = [1,2,3,4,5,6,7,8,9,'c','d','e','f',true,false];
    // var arr = [1,[2,3,4],
    //            2,[5,6,7],
    //         3 , [8,9,10]];
    // arr.push(10);
    // document.getElementById("randomlbl").innerHTML = arr ;
    // console.log(arr);
    
// example of map
    // var CountryCapital = new Map();
    // CountryCapital.set("India", "New Delhi");
    // CountryCapital.set("China", "Beijing");
    
    // for(const [key, value] of CountryCapital) {
    //     setTimeout(() => {
    //         document.getElementById("ParaRandom").textContent = `${key} -> ${value}`;
    //         console.log("this is the first message");
    //       }, 5000);
    //     console.log(key, value);
    // }

// example of set
    // let city = new Set();
    //     let city1 = {x:"DELHI" };
    //     let city2 = {x:"Agra" };

    //     city.add(city1 );
    //     city.add(city2);

    //     city.forEach((i,city)=> {
    //     console.log(i)
    //      })

var label = document.getElementById("ParaRandom");
// example of function
    // function getSum(n , m) {
    //     return n + m;
    // }
    // label.innerHTML = (getSum(10, 20));


// example of arrow function
    // const hello = (n , m) => {
    //     return n*m;
    // }
    // label.innerHTML = hello(10,20);

    // let arr = [10,20,30,40,50,60];
    // let x = arr.filter((n)=>n>10)
    // label.innerHTML= (x);

    // hello = val =>  `Hello ${val}`;
    // label.innerHTML = hello("Urjit");

// example of IIFE function
    // (function xyz(){label.innerHTML="HELLO WORLD"}())
    // label.innerHTML="";
    
    // var x = (function abc () {
    //     return "ABC";
    // })
    // ()
    // label.innerHTML = x;

// example of argument object
    // function foo(a,b,c) {
    //     console.log(arguments[0]);
    //     console.log(arguments[1]);
    //     console.log(arguments[2]);
    // } 
    // foo(10,20,30);

// scope of a function

        // var x = 10 ;
        // function foo() {
        //     x = 20 ;
        //     console.log(x);
        // }
        // console.log(x); // 10
        // foo(); // 20

        // if(true) {
        //     var x = 10 ;
        // }
        // console.log(x); 
            // 'var' is function scope , not a block scope 
            // where as 'let' is a function scope & block scope both

        // Global scope: The default scope for all code running in script mode.
        // Module scope: The scope for code running in module mode.
        // Function scope: The scope created with a function.
        // Block scope: The scope created with a pair of curly braces (a block).

// example of recursive function 
    // function foo(n) { 
    //     if(n == '10') {
    //         return ;
    //     } 
    //     console.log(n);
    //     n++;
    //     foo(n); 
    // }
    // foo(1);

// example of lexical function
    // var a = 'static';

    // function f1() {
    //    console.log(a);
    // }

    // function f2() {
    //    var a = 'dynamic';
    //    f1();
    // }

    // f2(); 
    // answer ->  static
// example of closures

    // function foo() {
    //     var a = 10;
    //     function bar() {
    //         console.log(a);
    //     }
    //     return bar;
    // }
    // var b1 = foo();
    
    // b1(); // 10

// example of JSON
    // let data= `{
    //     "name" : "Urjit",
    //     "marks" : [10,20,30],
    //     "HasPassed" : true,
    //     "age" : 25,
    //     "gender" : "male",
    //     "city" : "Ahmedabad",
    //     "country" : "India",
    //     "state" : "Gujarat" ,
    //     "school" :{ 
    //         "location": "Ranip" ,
    //         "name" : "SNVV" ,
    //         "year" : 1969
    
    //     }
    // }`  ;
    // console.log(JSON.parse(data));
    
// class abc
    // constuctor(n) {
    //     console.log(`$n`)
    // }

    // a1 = new abc("Urjit") ;


//  var a = {x:10 , y:20}
//  console.log(a.x,a.y)

    // for(let i = 97 ;i != 122 ; i++) {
    //     document.write(String.fromCharCode(i - 32)  + `  `)   ;
        
    // }

 // Number guessing name 
	const guess = function ()  {
		var min =1;    
		var max = 100;
		var answer = Math.floor(Math.random() * (max -  min+ 1)) + min;
        console.log(answer);

        let attemps = 0;
        let guess = 0 ;
        let isRunning = true;

        while (isRunning) {
            guess = window.prompt(`Guess a number between ${min} - ${max}`);
            guess = Number(guess);

            if(isNaN(guess)) {window.alert("ENTER A VALID NUMBER")}
            else if (guess < min || guess > max) {window.alert("ENTER A VALID NUMEBR")}
            else  {
                attemps ++ ;
                if(guess < answer) {
                    window.alert("Too low , guess high");   
                }else if(guess > answer) {
                    window.alert("Too high , guess low");   
                }else {
                    window.alert(`you have guessed ${answer} right in ${attemps} attempts`);
                }
            }
            isRunning = false ;

        }
	}
    // guess();

    // FUNCTIONS
        // function isEven(n) {
        //     return n%2 === 0;
        // }
        // for (let i = 0 ; i !== 100 ; i ++) {
        //     console.log( i ,isEven(i) ? "even" : "odd");
        // }
    
// rest parameters 

    // function getList(...list) {
    //     return list;
    // }
    // function getSum (...arr) {
    //     let sum = 0 ;
    //     for (num in arr ) {
    //         sum += arr[num];
    //     }
    //     return sum
    // }
    // function getAverage(...arr) {
    //     let sum = 0 ;
    //     for (num in arr ) {
    //         sum += arr[num];
    //     }
    //     return sum / arr.length;
    // }
    // const list1 = "Urjit" , list2= 7 ,list3 = "DCS" ;   
    // const Sum = getAverage(1,2,3,4,5) ;
    // console.log(getAverage(getSum(1,2,3,4,5))) 

// random password generator
function generatePassword(length,includeLowerCase , includeUpperCase, includeNumbers ,includeSymbols ) {
        const lowerCaseChars = "abcdefghijklmnopqrstuvwxyz" ;
        const upperCaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
        const numberChars = "0987654321" ;
        const symbolChars = "!@#$%^&*()_+-=<>?\"\\/|[]{}:;,." ;

        let allowedChars = "";
        let password = "";

        allowedChars += includeLowerCase ? lowerCaseChars : "" ;
        allowedChars += includeUpperCase ? upperCaseChars : "";
        allowedChars += includeNumbers ? numberChars : ""; 
        allowedChars += includeSymbols ? symbolChars : ""; 
        

        if (length <= 6) {
            return `required length must be 6 or above`;
        }
        if (allowedChars.length === 0 ) {
            return `1 include is required`;
        }
        for(let i = 0 ; i < length ;i ++) {
            const randomIndex = Math.floor(Math.random() * allowedChars.length);
            password += allowedChars[randomIndex];
        }
        return password;
    }
     const passwordlength = 16;
     const includeLowerCase = true ;
     const includeUpperCase = true;
     const includeNumbers = true;
     const includeSymbols = true;
     
     const password = generatePassword( 
                                        passwordlength,
                                        includeLowerCase,
                                        includeUpperCase,
                                        includeNumbers,
                                        includeSymbols
                                        );

    // console.log(`generated password ${password}`);