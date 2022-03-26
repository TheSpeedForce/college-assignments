<?php 
    if (session_status() === PHP_SESSION_NONE) {
		session_start();
	};
	require_once "../common/dbconnect.php";
    require_once "../inc/util.php";

	include "../common/dbFetch.php";

	$submit_message = "";

	$first = "";
  	$middle = "";
	$last = "";
	$email = "";
	$emailok = "";
	$password = "";
	$passwordok = "";
	

	$fok = FALSE;
	$lok = FALSE;
	$eok = FALSE;
	$ecok = FALSE;
	$pok = FALSE;
	$pcok = FALSE;
	

	# Make required labels
	$flabel="First Name";
  	$mlabel = "Middle Name";
	$llabel="Last Name";
	$elabel="Email";
	$eoklabel="Confirm Email";
	$plabel="Password";
	$poklabel="Confirm Password";
	
	if(isset($_POST['submit']))
	{
	
	# Check for first name if empty
	if(isset($_POST['first']))
	{	$first = trim($_POST['first']);
		if ($first=="")
		{
			$flabel = '<font color="red">First Name</font>';
	
		}
		else $fok = TRUE;
	
	}

	# Check for last name if empty
	if(isset($_POST['last']))
	{	$last = trim($_POST['last']);
		if ($last=="")
		{
			$llabel = '<font color="red">Last Name</font>';
		}
		else $lok = TRUE;

	}

	# Validate email
	if(isset($_POST['email']))
	{
		$email = trim($_POST['email']);
		if (!spamcheck($email))
		{
			$elabel = '<font color="red">Email</font>';
			
		}
		else $eok = TRUE;

	}


	# Validate confirmation email
	if (isset($_POST['emailok']))
	{
		$emailok = trim($_POST['emailok']);
		if (($email != $emailok) or ($emailok == "")){
			$eoklabel = '<span style="color:red">Confirm Email Id</span>';
			
		}
		else $ecok = TRUE;
	}

	# Check password
	if(isset($_POST['password']))
	{	$password = trim($_POST['password']);
		if (!pwdValidate($password)){
			$plabel = '<font color="red">Password</font>';
			
		}
		else $pok = TRUE;
	
	}

	# Check for password confirmation
	if(isset($_POST['passwordok']))
	{	$passwordok = trim($_POST['passwordok']);
		if ($passwordok=="" || ($password!=$password)){
			$poklabel = '<font color="red">Confirm Password</font>';
			
		}
		else $pcok = TRUE;
	}

	# Check for empty data to change message
	if($fok==FALSE)
		$submit_message = "First name required";

	elseif($lok==FALSE)
		$submit_message = "Last name required";
	
	elseif($eok==FALSE)
		$submit_message = "Email required";
	elseif($ecok==FALSE)
		$submit_message = "Email confirmation required";
	elseif($pok==FALSE)
		$submit_message = "Password required";
		
	elseif($pcok==FALSE)
		$submit_message = "Password confirmation required";

	# check if emails and pasword match to confirmations
	elseif ($email != $emailok){
		$submit_message = "Emails don't match";
		$elabel = '<font color="red">Confirm email</font>';
		$eoklabel = '<font color="red">Confirm email</font>';
		
	}

	elseif ($password != $passwordok) {
		$submit_message = "Passwords don't match.";
		$plabel = '<font color="red">Password</font>';
		$poklabel = '<font color="red">Confirm password</font>';

	}
	
	# Print final result after validation
	else
	{	
	
		$username = strtolower(substr($first, 0, 2).substr($last, 0, 4));

		$query = "INSERT INTO loginInfo (email, username, fName, lName, mName, pwdHash) VALUES (?,?,?,?,?,?)";
		$array = array($email,$username,$first,$last,$middle,$password);
		$result = fetchArray($con, $query, $array);

		$query = "SELECT id  FROM loginInfo where username = ?";
		$array = array($username);
		$result = fetchArray($con, $query, $array);
		$loginInfoId = $result[0]["id"];
		$roleId = 1;
		$query = "INSERT INTO supervisor (loginInfoId, roleId) VALUES (?,?)";
		$array = array($loginInfoId, $roleId);
		$result = fetchArray($con, $query, $array);

		$submit_message = "Submission done.";
		
		$_SESSION['username'] = $username;
		$_SESSION['passphrase'] = $passphrase;
		header ("Location: ..\login\siteSupervisorLogin.php");
	}
}  
?>

<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
    <script src="../iudesign/js/rivet.min.js"></script>
    <!-- Change Title here for each module !-->
    <title>Internship Application Reporting System</title>
</head>
<body>
<header class="rvt-header" role="banner">
    <a class="rvt-skip-link" href="#main-content">Skip to content</a>
    <!-- Trident -->
    <div class="rvt-header__trident">
        <svg class="rvt-header__trident-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 41 48" aria-hidden="true">
            <title id="iu-logo">Indiana University Logo</title>
            <rect width="41" height="48" fill="#900"/>
            <polygon points="24.59 12.64 24.59 14.98 26.34 14.98 26.34 27.78 22.84 27.78 22.84 10.9 24.59 10.9 24.59 8.57 16.41 8.57 16.41 10.9 18.16 10.9 18.16 27.78 14.66 27.78 14.66 14.98 16.41 14.98 16.41 12.64 8.22 12.64 8.22 14.98 9.97 14.98 9.97 30.03 12.77 33.02 18.16 33.02 18.16 36.52 16.41 36.52 16.41 39.43 24.59 39.43 24.59 36.52 22.84 36.52 22.84 33.02 28 33.02 31.01 30.03 31.01 14.98 32.78 14.98 32.78 12.64 24.59 12.64" fill="#fff"/>
        </svg>
    </div>
    <!-- App title -->
    <span class="rvt-header__title">
        <a href="#" class = "inactiveLink">Internship Application Reporting System</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
    </div>
</header>
    <main role="main" id="main-content">
<div class="rvt-box">
  <div class="rvt-box__header">
    Create New Site Supervisor Account
  </div>
  <form class="rvt-p-lr-lg" action="createAccount.php" method="post">
            <fieldset>
				</br>
				<small id="username-info" class="rvt-display-block rvt-m-bottom-md">Username will be FFLLLL, i.e. first 2 letters of first name and first 4 letters of last name.</small>
                <label for="first"><?php print $flabel?>*</label>
                <input type="text" id="first" name="first" value=<?php print $first?>><br>

                <label for="mname"><?php print $mlabel?></label>
                <input type="text" id="middle" name=<?php print $middle?>><br>

                <label for="last"><?php print $llabel?>*</label>
                <input type="text" id="last" name="last" value=<?php print $last?>><br>
				

                <label for="email"><?php print $elabel?>*</label>
                <input type="email" id="email" name="email" value=<?php print $email?>><br>

                <label for="emailok"><?php print $eoklabel?>*</label>
                <input type="email" id="emailok" name="emailok" value=<?php print $emailok?>><br>

                <label for="password"><?php print $plabel?>*</label>
                <input type="password" id="password" name="password" value=<?php print $password?>>
                <small id="password-info" class="rvt-display-block rvt-m-bottom-md">Password needs to have a number and at least 10 characters.</small>

                <label for="passwordok"><?php print $poklabel?>*</label>
                <input type="password" id="passwordok" name="passwordok" value=<?php print $passwordok?>><br>

                
            </fieldset>
            <label><?php print $submit_message ?></label>
			<div class="rvt-box__row rvt-button-group">
           		<input type="submit" class="rvt-button rvt-button--full-width" name="submit" value="Create Account">
            	<a class="rvt-button rvt-button--secondary rvt-button--full-width " href = ".././">Cancel</a>
			</div>
			</br>
        </form>

  </div>
  <div class="rvt-box__footer rvt-text-right">
    <a>Help</a>
  </div>
</div>


<?php include "../common/footer.php" ?>
