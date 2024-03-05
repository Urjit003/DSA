function Button() {
    // const styles = {
    //     backgroundColor: "hsl(200, 100%, 50%)",
    //     color: "whitesmoke",
    //     padding: "10px",
    //     borderRadius: "5px",
    //     border: "none",
    //     cursor: "pointer",
    // }
    let count = 1;
    const handleClick = (e) => {
        count++;
        console.log(`${e} clicked me ${count} times`);
    }
    return (
        <button className="button" onClick={(e)=>handleClick(e)}>Click me</button>
    );

}
export default Button;