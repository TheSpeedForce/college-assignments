<?php
	
	if (session_status() === PHP_SESSION_NONE) {
    		session_start();
	}
	require_once "../common/dbconnect.php";
	
	$email_label = 'Email';
	$cemail_label = 'Confirm Email';
	$email = '';
	$cemail = '';
	$cmessage = 'Enter email above to get reset password link.';
	$sendemail = 0;

	if(isset($_POST['submit'])){
	
		if(isset($_POST['email'])){
		
			$email = $_POST['email'];

		}
		if(isset($_POST['cemail'])){
		
			
			$cemail = $_POST['cemail'];
		}
		if($email != $cemail){
			$email_label = '<font color = "red">Email</font>';
			$cemail_label = '<font color = "red">Confirm Email</font>';
			$cmessage = "Emails not matching";
		}
		else{
			
			$row = NULL;
			$stmt = $con->prepare("SELECT email FROM loginInfo WHERE email = ?");
			$stmt->execute(array($email));
			$row = $stmt->fetch(PDO::FETCH_ASSOC);
			
			if($row == NULL){
			
				$email_label = '<font color = "red">Email</font>';
				$cemail_label = '<font color = "red">Confirm Email</font>';
				$cmessage = "Email not found";

			
			}
			else{
			
				$sendemail = 1;
			
			}
			
		}
	}
		
		if($sendemail == 1){

			$to = $email;
			$subject = 'Passphrase Reset';
			$headers[0]= 'Content-type: text/html';
			$headers[1] = 'To: ' + $email;
			$headers[2] = 'From: Internship Application Reporting System';
			$emailContent = '
				<html>
					<head>
						<title>Password Reset</title>
					</head>
					<body>
						<p>A Password reset has been requested for ' .$email. '</p>
						<p>If you did not request this, please ignore this message.</p>
						<p>If you did request your password be reset, please copy the following link into your browser</p>
						<a href="corsair.cs.iupui.edu:24641/final_project/login/passphrasereset.php">corsair.cs.iupui.edu:24641/final_project/login/passphrasereset.php</a>
						
					</body>
				</html>
			';
			mail($to, $subject, $emailContent, implode("\r\n", $headers));
			$cmessage = "An email has been sent to your account for activation";

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
		<title>Reset Password</title>
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
        				<a href="#" class = "inactiveLink">Reset Password</a>
    			</span>
    			<!-- Wrapper for header interactive elements -->
    			<div class="rvt-header__controls">
       			<!-- Main inline nav element -->
        			<nav class="rvt-header__main-nav" role="navigation">
                    			</nav>
        			<!-- ID menu w/ dropdown -->
        			<div class="rvt-header-id">
                			</div>
		</header>
		<div class="rvt-box__body">
			
			<form action="passresetemail.php" method="post">
				<div class="rvt-box__row">
					<label for="email"><?php print $email_label;?></label><br>
					<input id="email" name="email" type="email" value="<?php print $email; ?>" size="25" required>
				</div>
				<div class="rvt-box__row">
					<label for="cemail"><?php print $cemail_label;?></label><br>
					<input id="cemail" name="cemail" type="email" value="<?php print $cemail; ?>" size="25" required>
				</div>

				<div class="rvt-box__row">
					<?php print "<h2>".$cmessage."</h2>"; ?>
				</div>

				<div class="rvt-box__row rvt-button-group">
					<button id="submit" name="submit" class="rvt-button rvt-button--full-width " type="submit" >Submit</button>
					<a class="rvt-button rvt-button--secondary rvt-button--full-width" href = "../.">Cancel</a>
				</div>
			</form>			
		</div>
<?php include "../common/footer.php" ?>

			