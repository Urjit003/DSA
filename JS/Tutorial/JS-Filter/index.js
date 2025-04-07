const nums = [];
for(let i = 0 ; i <= 20 ; ++i  ) {
    nums.push(i) ;
}
nums.push(null)
const lol = nums.filter((e)=> e%2==null)
console.log(lol);