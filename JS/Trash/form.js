function validate()
{
    let uname=document.getElementById('uname').value;
    if(uname =='' || uname == null )
    {
        alert("Please enter username");
        return false;
    }
    let pwd=document.getElementById('pwd').value;
    if(pwd =='' || pwd == null)
    {
        alert("Please enter password");
        return false;
    }
    let validatepwd=/^.{8,15}$/;
    if(!validatepwd.test(pwd))
    {
        alert("Password must be between 8 and 15 characters long");
    }
    let cpwd=document.getElementById('cpwd').value;
    if(cpwd==''|| cpwd == null)
    {
        alert("Please enter again for confirmation");
        return false;
    }
    if(pwf!=cpwd)
    {
        alert("Password not match");
        return false;
    }
    let email=document.getElementById('email').value;
    if(email==''|| email == null)
    {
        alert("Please enter your email address");
        return false;
    }
    let filter=/^[A-Za-z0-9_]+@[a-zA-Z]+\.[a-zA-Z]{2,4}$/;
    if(!filter.test(email))
    {
        alert("Enter valid email");
        return false;
    }
    let mobile=document.getElementById('pnumber').value;
    if(mobile==''|| mobile == null)
    {
        alert("kindly enter phone number");
        return false;
    }
    let verify=/^\d{10}$/;
    if(!verify.test(mobile))
    {
        alert("Enter valid phone number");
        return false;
    } 

    
    
}