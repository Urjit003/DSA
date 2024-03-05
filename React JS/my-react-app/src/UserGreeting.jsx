import propsType from 'prop-types'
function UserGreeting(props) {
    const welcomeMsg = <h1 className='welcome-message'>Welcome {props.username}</h1> ;
    const loginPrompt = <h1 className='login-prompt'>Please Login</h1> ;
    
      
    return (props.isLoggedIn ? welcomeMsg : loginPrompt );
}
UserGreeting.propTypes = {
    username: propsType.string ,
    isLoggedIn : propsType.bool,
}
export default UserGreeting;