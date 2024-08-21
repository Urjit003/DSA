const btn = document.querySelector(".getDate");
const lbl = document.querySelector(".inptlbl");

btn.addEventListener("click",() => {
    const currdate = new Date();
    lbl.textContent = currdate.toString() ;
})
