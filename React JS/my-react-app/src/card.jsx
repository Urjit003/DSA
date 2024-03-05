import ProfilePic from './assets/aegon_200x200.jpg';
function Card(props) {
    return (
        <div className="card" style={{height:"auto"}}>
            
            <img src={props.ProfilPicSrc} alt="Profile Photo of {props.ProfileTitle}" className='ProfilePic'/>
            <h2 className='card-title'>{props.ProfileTitle}</h2>
            <p className='card-text'>
                {props.ProfileDescription}
            </p>
        </div>
    );
}
export default Card;