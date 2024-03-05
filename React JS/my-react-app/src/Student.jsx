import PropType from 'prop-types'
function Student(props) {
    return(
        <div className="student">
            <p>Name : {props.name} </p>
            <p>Age : {props.age} </p>
            <p>Cool : {props.IsCool ? "Cool 😎" : "Not Cool🤢"} </p>
        </div>
    );
}
Student.propTypes = {
    Name:PropType.string ,
    Age:PropType.number ,
    Cool : PropType.bool,
}
export default Student;