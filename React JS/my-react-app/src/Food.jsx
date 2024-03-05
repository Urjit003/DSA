function Food() {
    const food1 = "Pineapple";
    const food2 = "ApPlE";
    
    return(
        <ul>
            <li>{food1}</li>
            <li>{food2.normalize()}</li>
        </ul>
    );
}
export default Food;