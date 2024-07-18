// for each() method used to iterate over the elements  
//             of an array and applly a specified callback to              each element

// let numbers = [] 
// for(let i = 1 ;i <= 15 ;i ++) {
//     numbers.push(i);
// }
// numbers.forEach(triple)
// numbers.forEach(display)
// function double(element, index, array) {
//     array[index] = 2 * element
// }
// function triple(element, index, array) {
//     array[index] = 3 * element
// }
// function triple(element, index, array) {
//     array[index] = element * element
// }
// function display(element) {
//     console.log(element)
// }

// let fruits = ["apple" ,"banana" , "orange" ,"grapes","watermalone","kiwi","lichi","tomatoe"]


// function upperCase(element,index,array) {
//     array[index] = element.charAt(0).toUpperCase() + element.slice(1);

// }

// fruits.forEach(upperCase)
// fruits.forEach(display)
// function display(params) {
//     console.log(params);
// }

// .map() = accepts a callback and applies that function to each element of an array , then returns             a new array

// let numbers = [1,2,3,4,5]
// const squres = numbers.map(square);
// const cubes = numbers.map(cube);

// console.log(cubes);

// function square(element) {
//    return Math.pow(element,2);
// }
// function cube(element) {
//     return Math.pow(element,3);
//  }

// const  dates = [ "2021-10-2" , "2020-12-4","2019-12-23"];
// console.log(dates.map(formate));
// function formate(element) {
//     const dates = element.split("-");
//     return `${dates[2]}-${dates[1]}-${dates[0]}`;
// }

// filter() = creates a new array by filtering out elements.

// let numbers = [1, 2, 3, 4, 5, 6]

// const evenNumbers = numbers.filter(isOdd)
// console.log(evenNumbers);


// function isEven(ele) {
//     return ele % 2 === 0
// }

// function isOdd(ele) {
//     return ele % 2 !== 0
// }

// let ages = [16, 17, 18, 25, 55, 25, 45, 63, 67];

//function delcarion

// function hello () {
//     console.log("hello world");
// }

// setTimeout(() =>{
//     console.log("hello world")
// }
// ,3000);

const numbers = [1, 2, 3, 4, 5, 6];
const squaredNums = numbers.map((e) => {
    return Math.pow(e, 2);
});
console.log(squaredNums);

const cubedNums = numbers.map(
    (e) => {
        return Math.pow(e, 3);
    }
)

const evenNumbers = numbers.filter(
    (e) => {
        return e % 2 === 0;
    }
)

const total = numbers.reduce(
    (accumulator, element) => {
        return accumulator + element
    }
);
console.log(total);