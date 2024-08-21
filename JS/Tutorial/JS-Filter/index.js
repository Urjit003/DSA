const nums = [];
for(let i = 0 ; i <= 20 ; ++i  ) {
    nums.push(i) ;
}
const lol = nums.filter((e)=> e%2==0)
console.log(lol);