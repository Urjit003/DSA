function List() {
    const fruits =
        [
            { id: 1, Name: "Apple", Calories: 15 },
            { id: 2, Name: "Orange", Calories: 125 },
            { id: 3, Name: "Banana", Calories: 135 },
            { id: 4, Name: "PineApple", Calories: 155 }
        ];
            // Sorting
            fruits.sort();
    const ListItems = fruits.map(i => <li i={i.id}>
                                            
                                            {i.Name}&nbsp;
                                           <b>{i.Calories}</b> 
                                        </li>);
        
    return (
        <ol>
            {ListItems}
        </ol>

    );
}
export default List;