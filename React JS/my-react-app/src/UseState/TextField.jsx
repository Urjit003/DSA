import { useState } from "react";
import InputGroup from 'react-bootstrap/InputGroup';
import Form from 'react-bootstrap/Form';
export default function TextField() {

    let [string, setString] = useState('hello world');

    function handleChange(e) {
        setString(e.target.value);
    }
    return ( 
        <>
           <input type="text" 
                placeholder="Enter something" 
                onChange={handleChange}
                // value={string}
            />
           <p >you typed <b>{string}</b></p>
        </>
    );
}
