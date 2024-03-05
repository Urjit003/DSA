function ProfilePicture(props) {
    const HandleClick = (e) => {
        e.target.style.display="none";
    }
    return(
        <>
        <img src={props.ProfileUrl} alt="PROFILE PHOTO"></img>
        </>
    );
}

export default ProfilePicture;              